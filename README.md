# OdysseyPhysics

OdysseyPhysics is a simulator for the player physics of the game "Super Mario Odyssey". Opposite to the game itself, it is able to run on any Linux-based environment, and allows scaling simulation speed with host performance, resulting in faster simulation on more powerful devices. Special care is being taken to make the model behave as close as possible to the original game, meaning that model and game can be used interchangably. This allows for example training agents on the simulator at high speeds, while showing off their performance in the game to get better visuals.

## Usage

By default, `InputProviderRaylib` is used to read keyboard buttons and press respective buttons on the controller. Buttons can be re-mapped in `InputProviderRaylib.h`, by default it uses the following mapping:

| Keyboard | Controller |
|----------|------------|
| C | A |
| X | B |
| V | X |
| Y | Y |
| R | ZL|
| T | ZR |
| Q | L |
| E | R |
| UP | UP |
| DOWN | DOWN |
| LEFT | LEFT |
| RIGHT | RIGHT |
| M | PLUS |
| N | MINUS |

Additionally, the following buttons can be used to trigger actions specific to the simulator:

| Keyboard | Action |
|----------|--------|
| P | Switch between two states created on stage start |
| 0 | Dump current list of inputs to `res/out.txt` in the common TAS format |
| O | Switch between Fixed camera (default), Free and Follow |

## Building

**Install required dependencies**:
```
sudo apt install python3 ninja-build cmake ccache xdelta3 clang libssl-dev libncurses5
pip install toml
```

**Setup project**:
```
git submodule update --init --recursive
lib/smo/tools/setup.py --project-only
make configure
make build
```

**Setup RomFS**:
Replace the symbolic link `res/romfs` to a valid location containing your copy of the RomFS. Make sure that the directory `res/romfs/StageData` exists.

**Build and run**:
```
make run
```

## Configuration options

There are various configuration options listed as `#define`s at the top of `odyssey-physics.cpp`. Most testing modes can be enabled/disabled here.

| Option | Description |
|--------|-------------|
| Stage  | Which stage should be loaded and simulated. All stages are listed in `res/romfs/StageData`, files ending in `Map` and `Zone` can be loaded. |
| TASFile| Pre-written input file that should be loaded for playback, in case `TASPlayback` or `TEST_AGENT` are active. |
| TASPlayback| Create a `InputProviderTAS` from the inputs listed in `TASFile`, and use this as input device for the simulator. |
| WSL_COMPATIBILITY| As the graphics of Windows Subsystem for Linux (WSL) misses some configuration options, this option disables locking the mouse cursor. |
| TEST_FPS_HEADLESS| Disable rendering with `raylib`, but just simulate `TEST_FRAMES` frames and output the final time and FPS. |
| TEST_FPS_RAYLIB | Remove the 60 FPS lock, and try rendering as fast as possible using `raylib`. This often does not surpass 60 FPS, due to the graphics card limiting speed again. |
| TEST_FRAMES | Number of frames that should be tested for `TEST_FPS_HEADLESS` or `TEST_FPS_RAYLIB` before stopping program execution. |
| TEST_AGENT | Use the script-mutation-agent implemented in `src/agent` to mutate `TASFile`, aiming for faster completion time. |
| TEST_AGENT_ITERATIONS | Maximum number of iterations that should be ran before stopping the mutation of `TEST_AGENT`. |

## Credits

- [OdysseyDecomp](https://github.com/MonsterDruide1/OdysseyDecomp)
- [tas-studio](https://github.com/fruityloops1/tas-studio)
- [raylib](https://github.com/raysan5/raylib)
- [nlib](https://github.com/fruityloops1/nlib)
