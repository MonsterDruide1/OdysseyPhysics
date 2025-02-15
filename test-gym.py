import gymnasium as gym
from res.OdysseyEnv import OdysseyEnv
import sys, io
from traceback import format_exception
import numpy as np
import cProfile, pstats
import argparse

def handle_exception(exc_type, exc_value, exc_traceback):
    [print(x,end="") for x in format_exception(exc_type, exc_value, exc_traceback)]
    env.close()

sys.excepthook = handle_exception

gym.register(id="gym_ody", entry_point=OdysseyEnv)

def test_env(env, steps, render):
    env.reset()
    # measure time for loop
    import time
    start = time.time()
    with cProfile.Profile() as pr:
        for i in range(steps):
            env.step({"buttons": np.array([0,0,0]), "stickLeft": np.array([-0.2,-1]), "stickRight": np.array([0,0])})
            if render:
                env.render()
        ps = pstats.Stats(pr).sort_stats(pstats.SortKey.CUMULATIVE)
        ps.print_stats()
    end = time.time()
    print("Time for "+str(steps)+" steps: "+str(end-start)+" => FPS: "+str(steps/(end-start)))

    input("Press Enter to continue...")

parser = argparse.ArgumentParser()
parser.add_argument("--stage", type=str, default="SandWorldMeganeExStageMap")
parser.add_argument("--scenario", type=int, default=0)
parser.add_argument("--instance", type=str, default="0")
parser.add_argument("--steps", type=int, default=100)
parser.add_argument("--video_folder", type=str, default="/tmp/gym_test")
parser.add_argument("--name_prefix", type=str, default="test-video")
args = parser.parse_args()

env = gym.make("gym_ody", stage=args.stage, scenario=args.scenario, instance=args.instance, render_mode=None)
test_env(env, args.steps, False)
env.close()

env = gym.make("gym_ody", stage=args.stage, scenario=args.scenario, instance=args.instance, render_mode='rgb_array')
env = gym.wrappers.RecordVideo(env=env, video_folder=args.video_folder, name_prefix=args.name_prefix, episode_trigger=lambda x: True)
test_env(env, args.steps, True)
env.close()

env = gym.make("gym_ody", stage=args.stage, scenario=args.scenario, instance=args.instance, render_mode='human')
test_env(env, args.steps, False)
env.close()
