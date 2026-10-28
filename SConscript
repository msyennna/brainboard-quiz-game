import os
from building import DefineGroup, GetCurrentDir

cwd = GetCurrentDir()
source_directories = [
    os.path.join(cwd, 'src', 'app'),
    os.path.join(cwd, 'src', 'ui'),
    os.path.join(cwd, 'src', 'ui', 'assets'),
]

sources = []
for directory in source_directories:
    sources.extend(
        os.path.join(directory, filename)
        for filename in sorted(os.listdir(directory))
        if filename.endswith('.c')
        and os.path.isfile(os.path.join(directory, filename))
    )

group = DefineGroup(
    'BrainBoard',
    sources,
    depend=['BSP_USING_LVGL', 'BSP_USING_LVGL_DEMO'],
    CPPPATH=[os.path.join(cwd, 'src', 'ui')],
)

Return('group')
