from math import inf
import gymnasium as gym
import numpy as np
from typing import Optional
import subprocess
import os, os.path
import socket
import struct

class OdysseyEnv(gym.Env):
    COMMAND_OUT_FRAME = bytes([1])
    COMMAND_OUT_RESET = bytes([2])
    COMMAND_IN_ACK = bytes([1])
    COMMAND_IN_DATA = bytes([2])


    def __init__(self, stage: str, scenario: int, instance: str, display: bool = False):
        self.socket_file = "/tmp/odyssey-physics-"+instance+".sock"
        if os.path.exists(self.socket_file):
            os.remove(self.socket_file)
        
        self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.socket.bind(self.socket_file)

        self.process = subprocess.Popen(["build/OdysseyPhysics", stage, str(scenario), self.socket_file, str(display).lower()])

        self.socket.listen(1)
        self.conn, self.addr = self.socket.accept()

        self.observation_space = gym.spaces.Dict(
            {
                "playerPos": gym.spaces.Box(low=np.array([-inf, -inf, -inf]), high=np.array([inf, inf, inf]), shape=(3,), dtype=np.float32),
                "isTouchingPoison": gym.spaces.Discrete(2),
            }
        )

        self.action_space = gym.spaces.Dict(
            {
                "buttons": gym.spaces.MultiBinary(32),  # 27 usable buttons, afaik
                "stickLeft": gym.spaces.Box(low=-1, high=1, shape=(2,), dtype=np.float32),
                "stickRight": gym.spaces.Box(low=-1, high=1, shape=(2,), dtype=np.float32),
            }
        )


    def close(self):
        if self.socket is None:
            return
        
        self.process.kill()
        self.conn.close()
        self.socket.close()
        self.socket = None
        os.remove(self.socket_file)

    def readState(self):
        command = self.conn.recv(1)
        if(command != self.COMMAND_IN_DATA):
            raise Exception("OdysseyPhysics did not send COMMAND_IN_DATA! Instead: "+str(command)+", followed by "+str(self.conn.recv(300)))

        state_format = "=fff?"
        state_data = self.conn.recv(struct.calcsize(state_format))
        playerPosX, playerPosY, playerPosZ, isTouchingPoison = struct.unpack(state_format, state_data)

        return {
            "playerPos": np.array([playerPosX, playerPosY, playerPosZ], dtype=np.float32),
            "isTouchingPoison": isTouchingPoison,
        }
    
    def step(self, action):
        buttons_arr = action["buttons"].astype(bool)
        buttons = sum(v << i for i, v in enumerate(buttons_arr[::-1]))
        stickLeft = action["stickLeft"]
        stickRight = action["stickRight"]

        data = struct.pack("=cIffff", self.COMMAND_OUT_FRAME, buttons, stickLeft[0], stickLeft[1], stickRight[0], stickRight[1])
        self.conn.send(data)

        state = self.readState()

        observation = state
        reward = -1 if state["isTouchingPoison"] else 0
        terminated = state["isTouchingPoison"]
        truncated = False
        info = {}

        return observation, reward, terminated, truncated, info
    
    def reset(self, seed: Optional[int] = None, options: Optional[dict] = None):
        super().reset(seed=seed)

        self.conn.send(struct.pack("=c", self.COMMAND_OUT_RESET))

        state = self.readState()

        observation = state
        info = {}

        return observation, info
