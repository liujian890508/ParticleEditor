# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = QtApplication
DESTDIR = ../Debug.win32
QT += core opengl widgets gui
CONFIG += debug
DEFINES += _WINDOWS _USE_MATH_DEFINES GL_GLEXT_PROTOTYPES CC_ENABLE_CHIPMUNK_INTEGRATION=1 COCOS2D_DEBUG=1 _CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS _VARIADIC_MAX=10 _USING_V110_SDK71_ _UNICODE WIN64 QT_DLL QT_OPENGL_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
    $(ProjectDir)cocos2d/cocos/platform/desktop \
    $(ProjectDir)cocos2d/cocos/platform \
    $(ProjectDir)cocos2d/cocos \
    $(ProjectDir)cocos2d/cocos/editor-support \
    $(ProjectDir)cocos2d/extensions \
    $(ProjectDir)cocos2d/external/chipmunk/include/chipmunk \
    $(ProjectDir)cocos2d/external \
    $(ProjectDir)cocos2d/cocos/audio/include \
    $(ProjectDir)Classes \
    $(ProjectDir) \
    $(ProjectDir)cocos2d/external/glfw3/include/win32 \
    $(ProjectDir)cocos2d/external/win32-specific/gles/include/OGLES \
    $(EngineRoot)cocos/audio/include \
    $(EngineRoot)external \
    $(EngineRoot)external/chipmunk/include/chipmunk \
    $(EngineRoot)extensions \
    $(ProjectDir)Classes \
    $(ProjectDir) \
    $(EngineRoot)cocos/editor-support \
    $(EngineRoot)cocos \
    $(EngineRoot)cocos/platform \
    $(EngineRoot)cocos/platform/desktop \
    $(EngineRoot)external/glfw3/include/win32 \
    $(EngineRoot)external/win32-specific/gles/include/OGLES
LIBS += -L"$(SolutionDir)$(Configuration).win32" \
    -lopengl32 \
    -lglu32 \
    -llibchipmunk \
    -llibbox2d \
    -llibSpine \
    -lws2_32 \
    -lwinmm \
    -lfreetype250 \
    -lglfw3 \
    -llibzlib \
    -llibpng \
    -llibjpeg \
    -llibtiff \
    -llibwebp \
    -llibiconv \
    -lglew32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(QtApplication.pri)
TRANSLATIONS += qtapplication_en.ts \
    qtapplication_zh.ts
win32:RC_FILE = QtApplication.rc
