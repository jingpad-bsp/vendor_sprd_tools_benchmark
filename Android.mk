#build executable

LOCAL_PATH:= $(call my-dir)

#include $(call all-subdir-makefiles)

include $(CLEAR_VARS)
LOCAL_MODULE:= copybw
LOCAL_MODULE_PATH:= $(TARGET_OUT_OPTIONAL_EXECUTABLES)
LOCAL_SRC_FILES:= copybw.c
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE:= memverify
LOCAL_MODULE_PATH:= $(TARGET_OUT_OPTIONAL_EXECUTABLES)
LOCAL_SRC_FILES:= memverify.c
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE:= bonnie
LOCAL_MODULE_PATH:= $(TARGET_OUT_OPTIONAL_EXECUTABLES)
LOCAL_SRC_FILES:= bonnie.c
include $(BUILD_EXECUTABLE)

include $(call first-makefiles-under,$(LOCAL_PATH))
