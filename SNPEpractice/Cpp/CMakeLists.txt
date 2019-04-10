cmake_minimum_required(VERSION 3.11)
PROJECT(SNPEobjDetector)
SET(SRC_LIST main.cpp)
#SET(SRC_LIST net_layer_forward.cpp)
SET(libs_DIR /home/coolpad/AI/AI_framwork/snpe-1.24/snpe-1.24.0.256/models/mobilenetSSD/NativeSNPEtest/aarch64-android-gcc4.9)

INCLUDE_DIRECTORIES(./include/zdl)
link_directories(${libs_DIR})

#LINK_LIBRARIES("${libs_DIR}/libSNPE.so" "${libs_DIR}/libsymphony-cpu.so" "${libs_DIR}/libsymphonypower.so"
#    "${libs_DIR}/libgnustl_shared.so")

add_compile_options(-std=c++11)
ADD_EXECUTABLE(SNPEojbDetector ${SRC_LIST})
TARGET_LINK_LIBRARIES(SNPEojbDetector libSNPE.so libsymphony-cpu.so libsymphonypower.so libgnustl_shared.so)
