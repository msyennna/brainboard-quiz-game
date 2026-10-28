# Setup and integration

BrainBoard is an embedded application source export. Build and flash it through a compatible RA6M3 RT-Thread board support package (BSP).

## Requirements

- RA6M3 HMI board with a working 480 × 272 display and touch input
- RT-Thread project and board support package for that hardware
- LVGL 8.3.11, matching the generated UI source
- The board's supported compiler, flashing tools, and drivers
- RT-Thread Studio, or the build environment already used by your BSP

SquareLine Studio 1.5.4 was used to generate the interface. It is not required to compile the exported C files. The editable SquareLine design project is not included.

## LVGL configuration

Set these values in your project's LVGL configuration:

```c
#define LV_COLOR_DEPTH 16
#define LV_COLOR_16_SWAP 0
#define LV_FONT_MONTSERRAT_34 1
```

Enable the label, button, and image widgets, the default LVGL theme, and the display and input drivers required by your board. Use LVGL 8 APIs; this export has not been ported to LVGL 9.

## RT-Thread / SCons integration

1. Start with an RA6M3 BSP that already displays an LVGL demo and accepts touch input.
2. Locate the application folder that currently supplies `lv_user_gui_init()`. Place this repository's contents there, or include its root `SConscript` from the parent BSP build. Preserve the `src/` directory layout.
3. Remove the old demo/UI sources from the build if they define the same symbols. There must be only one active `lv_user_gui_init()` implementation and one copy of each UI source.
4. Enable `BSP_USING_LVGL` and `BSP_USING_LVGL_DEMO`, which are the dependency flags retained from the original `SConscript`.
5. Disable `BSP_USING_LVGL_VIDEO_DEMO` when launching BrainBoard. With that flag enabled, the supplied entry point launches the BSP's video demo instead.
6. Build and flash through the BSP's normal workflow.

The root `SConscript` includes C files from `src/app/`, `src/ui/`, and `src/ui/assets/`. It adds `src/ui/` to the include path, so the image assets can still include `ui.h` after being moved.

The BSP must provide `rtconfig.h`, `rtthread.h`, `lvgl.h`, the RT-Thread runtime, the LVGL library, and its display/input initialization. The supplied `lv_user_gui_init()` calls `ui_init()` after the platform has initialized LVGL.

## CMake integration

The root `CMakeLists.txt` is intended for `add_subdirectory()` from an existing embedded project. It builds a static library named `ui` and exposes the `src/ui/` header directory.

The parent project must make the LVGL and RT-Thread include paths and configuration available to the `ui` target, then link that target and the platform libraries into its firmware executable.

Add `src/app/lv_demo.c` to the parent firmware target if you want to use the supplied RT-Thread GUI entry point. The CMake UI library intentionally leaves that BSP-specific entry point out of its source list.

Running CMake on this repository alone does not produce complete firmware. It has no board startup files, linker script, driver package, or standalone application target.

## Editing the project

| File or directory | Purpose |
| --- | --- |
| `src/ui/ui_events.c` | Score tracking and timer callbacks |
| `src/ui/ui_Screen1.c` | Start screen and Play button |
| `src/ui/ui_Screen2.c` through `ui_Screen6.c` | Question labels, answer buttons, correct-answer callbacks, and navigation |
| `src/ui/ui_Screen7.c` | Results screen |
| `src/ui/ui.c` | UI initialization and destruction |
| `src/ui/assets/` | Original image arrays, including three additional assets not referenced by the current screens |

Generated filenames and all original C/header contents are preserved. Both build configurations have been updated for the new paths, and `filelist.txt` lists every C source. If you regenerate the UI, review the exported source lists and preserve custom event code.
