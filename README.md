[**View the project on Hackster.io**](https://www.hackster.io/ps/brainboard-test-your-wits-and-score-some-bits-d3301f)

# BrainBoard

**Test your wits and score some bits!**

BrainBoard is a touchscreen quiz game for the RA6M3 HMI board. Answer five multiple-choice questions about computer fundamentals, then view your score and completion time.

The application is written in C, runs with RT-Thread, and uses an LVGL interface exported from SquareLine Studio.

## Features

- Five questions with four answer choices each
- One point for every correct answer, for a maximum score of five
- Elapsed-time tracking in minutes and seconds
- Seven screens: a start page, five question pages, and a results page
- Touch controls and animated screen transitions

## Technology

| Component | Details |
| --- | --- |
| Hardware | RA6M3 HMI board with a 480 × 272 touch display |
| Language | C |
| Operating system | RT-Thread |
| Graphics library | LVGL 8.3.11 |
| UI design tool | SquareLine Studio 1.5.4 |
| Build integration | RT-Thread SCons; CMake UI library |

The LVGL and SquareLine versions above are recorded in the exported source files. The original export does not specify an RT-Thread or BSP version.

## How to play

1. Tap **Play** to start the quiz and timer.
2. Select one answer on each question screen.
3. View your total score and elapsed time on the results screen.

## Repository structure

| Path | Contents |
| --- | --- |
| [`src/app/`](src/app/) | RT-Thread GUI initialization entry point |
| [`src/ui/`](src/ui/) | UI initialization, screen layouts, event handlers, and components |
| [`src/ui/assets/`](src/ui/assets/) | All six original image assets exported as C arrays |
| [`SConscript`](SConscript) | Source discovery and include paths for the RT-Thread build |
| [`CMakeLists.txt`](CMakeLists.txt) | UI library configuration for a parent embedded project |
| [`filelist.txt`](filelist.txt) | Complete list of C source files, relative to this directory |
| [`docs/setup.md`](docs/setup.md) | Hardware requirements and integration instructions |
| [`docs/github-upload.md`](docs/github-upload.md) | Suggested GitHub name, description, and upload steps |

## Getting started

Integrate these sources into an existing RA6M3 RT-Thread project with working LVGL display and touch drivers. Follow the [setup guide](docs/setup.md) for source paths, configuration, and build details.

This repository contains the application and exported UI sources. The full board support package, RT-Thread and LVGL dependencies, firmware toolchain, and editable SquareLine project are not included.

## Authors

**Team PS**

- Shanice Reih Tanque
- Phoebien Canete

The Hackster page linked at the top contains the project story and development walkthrough.
