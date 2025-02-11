import gymnasium as gym
from res.OdysseyEnv import OdysseyEnv
import sys, io
from traceback import format_exception
import numpy as np
import cProfile, pstats

def handle_exception(exc_type, exc_value, exc_traceback):
    [print(x,end="") for x in format_exception(exc_type, exc_value, exc_traceback)]
    env.close()

sys.excepthook = handle_exception

gym.register(id="gym_ody", entry_point=OdysseyEnv)
env = gym.make("gym_ody", stage="SandWorldMeganeExStageMap", scenario=0, instance="0", render_mode="rgb_array")
env = gym.wrappers.RecordVideo(env=env, video_folder="/mnt/d/gym_test", name_prefix="test-video", episode_trigger=lambda x: x % 2 == 0)
env.reset()
# measure time for loop
import time
start = time.time()
with cProfile.Profile() as pr:
    for i in range(100):
        env.step({"buttons": np.array([0,0,0]), "stickLeft": np.array([-0.2,-1]), "stickRight": np.array([0,0])})
        env.render()
    ps = pstats.Stats(pr).sort_stats(pstats.SortKey.CUMULATIVE)
    ps.print_stats()
end = time.time()
print("Time for 100 steps: "+str(end-start)+" => FPS: "+str(100/(end-start)))

input("Press Enter to continue...")
env.close()


env = gym.make("gym_ody", stage="SandWorldMeganeExStageMap", scenario=0, instance="0", render_mode='human')
env.reset()
# measure time for loop
import time
start = time.time()
with cProfile.Profile() as pr:
    for i in range(100):
        env.step({"buttons": np.array([0,0,0]), "stickLeft": np.array([-0.2,-1]), "stickRight": np.array([0,0])})
        # manual "render" not needed for human or no render mode, as it is done in step automatically (if required)
        #env.render()
    ps = pstats.Stats(pr).sort_stats(pstats.SortKey.CUMULATIVE)
    ps.print_stats()
end = time.time()
print("Time for 100 steps: "+str(end-start)+" => FPS: "+str(100/(end-start)))

input("Press Enter to continue...")
