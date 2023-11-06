LOCAL_PATH := $(call my-dir)
SRC_DIR := ../../../source

include $(CLEAR_VARS)
LOCAL_MODULE := NativeGraphics
LOCAL_C_INCLUDES += $(SRC_DIR)
LOCAL_LDLIBS := -llog
LOCAL_ARM_MODE := arm

# OpenGL ES
LOCAL_SRC_FILES += $(SRC_DIR)/RenderCallback.cpp
LOCAL_SRC_FILES += $(SRC_DIR)/OpenGLCoreES.cpp
LOCAL_LDLIBS += -lGLESv3
LOCAL_CPPFLAGS += -DSUPPORT_OPENGL_ES=1

# build
include $(BUILD_SHARED_LIBRARY)
