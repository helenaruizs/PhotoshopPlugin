@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

set SDK_HEADERS=D:\Git\PhotoshopPlugin\PhotoshopSDK\headers
set SDK_LIBS=D:\Git\PhotoshopPlugin\PhotoshopSDK\libs
set PLUGIN_OUTPUT=%~dp0YourPlugin.8li
set MAIN_CPP=%~dp0main.cpp

echo Building Photoshop plugin...
echo Compiling "%MAIN_CPP%"...
cl.exe /EHsc /LD /I"%SDK_HEADERS%" /link /LIBPATH:"%SDK_LIBS%" /OUT:"%PLUGIN_OUTPUT%" /Fo"%~dp0main.obj" "%MAIN_CPP%" "PICA_sp.lib" "PICA_ui.lib"
echo Build completed.
