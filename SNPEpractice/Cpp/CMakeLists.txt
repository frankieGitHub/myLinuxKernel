cmake_minimum_required(VERSION 3.11)
PROJECT(SNPEobjDetector)
SET(SRC_LIST main.cpp udlExample.cpp)
#SET(SRC_LIST net_layer_forward.cpp)

if(UNIX AND NOT ANDROID)
    SET(libs_DIR /home/coolpad/AI/myAIGithub/myLinuxKernel/SNPEpractice/Cpp/x86_64-linux-clang)
    message("UNIX 编译设置")
else(ANDROID)
    message("Android编译设置")
    SET(libs_DIR /home/coolpad/AI/myAIGithub/myLinuxKernel/SNPEpractice/Cpp/aarch64-android-gcc4.9/)
endif()

INCLUDE_DIRECTORIES(./include/zdl)
link_directories(${libs_DIR})

#LINK_LIBRARIES("${libs_DIR}/libSNPE.so" "${libs_DIR}/libsymphony-cpu.so" "${libs_DIR}/libsymphonypower.so"
#    "${libs_DIR}/libgnustl_shared.so")

add_compile_options(-std=c++11)
ADD_EXECUTABLE(SNPEojbDetector ${SRC_LIST})
if(UNIX AND NOT ANDROID)
    TARGET_LINK_LIBRARIES(SNPEojbDetector libSNPE.so libsymphony-cpu.so)
    message("UNIX 编译设置 target link")
else(ANDROID)
    TARGET_LINK_LIBRARIES(SNPEojbDetector libSNPE.so libsymphony-cpu.so libsymphonypower.so libgnustl_shared.so)
    message("Android编译设置 target link")
endif()
