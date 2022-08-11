# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.5)

# # 定义项目名称变量PROJECT_NAME, 默认值为demo
# set(PROJECT_NAME glib)

# # # 项目名称以及版本
# project(${PROJECT_NAME})

# ########## Configuration ###########
# 设置C++的版本
set(CMAKE_CXX_STANDARD 14)

# 指定模式
# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(PROJECT_NAME
    glib_byte_array
    glib_err
    glib_hook
    glib_key_value
    glib_normal_array
    glib_ptr_array
    glib_sigle_list
    glib_str
    glib_string
    glib_test
    glib_test_tool
    glib_timer
    glib_thread
    glib_thread_pools
    glib_thread_asyn_queues
)

set(CUDA_DIRS /usr/local/cuda)
set(NVDS_DIRS /opt/nvidia/deepstream/deepstream)

include(FindPkgConfig)
pkg_search_module(GSTREAMER REQUIRED gstreamer-1.0)
pkg_search_module(GSTREAMER_VIDEO REQUIRED gstreamer-video-1.0)

include_directories(
    ${GSTREAMER_INCLUDE_DIRS}
    ${GSTREAMER_VIDEO_INCLUDE_DIRS}
    ${NVDS_DIRS}/sources/includes/
    ${CUDA_DIRS}/include/

    # src/
    includes/
)

# 包含头文件目录
include_directories(ThirdParty/include)

# 第三方链接库的目录
link_directories(${NVDS_DIRS}/lib/
    /opt/nvidia/TensorRT/lib/
    ${CUDA_DIRS}/lib64/
    /usr/local/lib/)
set(NVDS_LIBS nvdsgst_meta nvds_meta nvdsgst_helper nvdsgst_smartrecord nvds_utils nvds_msgbroker nvbufsurface nvbufsurftransform)

# 链接第三方库
set(USED_3RD_LIB ${GSTREAMER_LIBRARIES} ${GSTREAMER_VIDEO_LIBRARIES} ${X11_LIBRARIES} ${JSON_GLIB_LIBRARIES} ${OpenCV_LIBS} cudart gstrtspserver-1.0 pthread m dl)

# target_link_libraries(${PROJECT_NAME} ${USED_3RD_LIB})
foreach(proj ${PROJECT_NAME})
    get_filename_component(spath "src/${proj}" ABSOLUTE)

    if(EXISTS "${spath}/")
        file(GLOB sources src/${proj}/*.c)
        add_executable(${proj} ${sources})
        target_link_libraries(${proj} ${NVDS_LIBS} ${USED_3RD_LIB})
        set_target_properties(${proj} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
        message("------${CMAKE_BINARY_DIR}-----")
    endif()
endforeach()

# ############################################################################################################
