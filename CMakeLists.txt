# Include this directory from a parent embedded CMake project.
# The parent provides LVGL and RT-Thread headers, configuration, and libraries.
# The RT-Thread entry point in src/app/lv_demo.c is integrated separately.

set(SOURCES
    src/ui/ui_comp_labeltimer.c
    src/ui/ui_comp.c
    src/ui/ui_Screen1.c
    src/ui/ui_Screen2.c
    src/ui/ui_Screen3.c
    src/ui/ui_Screen4.c
    src/ui/ui_Screen5.c
    src/ui/ui_Screen6.c
    src/ui/ui_Screen7.c
    src/ui/ui.c
    src/ui/ui_comp_hook.c
    src/ui/ui_helpers.c
    src/ui/ui_events.c
    src/ui/assets/ui_img_1354121082.c
    src/ui/assets/ui_img_1516156473.c
    src/ui/assets/ui_img_3_png.c
    src/ui/assets/ui_img_760216461.c
    src/ui/assets/ui_img_777387856.c
    src/ui/assets/ui_img_956885843.c
)

add_library(ui STATIC ${SOURCES})
target_include_directories(ui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/ui")
