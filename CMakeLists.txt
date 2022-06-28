# CMake 最低的版本要求
cmake_minimum_required(VERSION 3.5)

# 定义项目名称变量PROJECT_NAME, 默认值为demo
set(PROJECT_NAME glib)

# 项目名称以及版本
project(${PROJECT_NAME})


########### Configuration ###########
# 设置C++的版本
set(CMAKE_CXX_STANDARD 14)

# 指定模式
# set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CUDA_DIRS /usr/local/cuda)
set(NVDS_DIRS /opt/nvidia/deepstream/deepstream)

########### Used Third party libs ###########
# find_package(OpenCV 3.4.1 REQUIRED)
# find_package(OpenCV REQUIRED)
# find_package(json-glib-1.0 REQUIRED)

include(FindPkgConfig)
pkg_search_module(GSTREAMER REQUIRED gstreamer-1.0)
pkg_search_module(GSTREAMER_VIDEO REQUIRED gstreamer-video-1.0)

include_directories(
    # ${OpenCV_INCLUDE_DIRS}
    ${GSTREAMER_INCLUDE_DIRS}
    ${GSTREAMER_VIDEO_INCLUDE_DIRS}
    ${NVDS_DIRS}/sources/includes/
    ${CUDA_DIRS}/include/
    src/
    includes/
    )

# 包含头文件目录
include_directories(ThirdParty/include)

# 第三方链接库的目录
# link_directories(/usr/lib/x86_64-linux-gnu)
link_directories(${NVDS_DIRS}/lib/
    /opt/nvidia/TensorRT/lib/
    ${CUDA_DIRS}/lib64/
    /usr/local/lib/)
set(NVDS_LIBS nvdsgst_meta nvds_meta nvdsgst_helper nvdsgst_smartrecord nvds_utils nvds_msgbroker nvbufsurface nvbufsurftransform)

# 当前目录下除了测试文件外所有的源文件的名称保存到 DIR_SRCS 变量
# set(DIR_SRCS deepstream_test_h264_app.c)
file(GLOB DIR_SRCS main.cc "src/*.cpp" "src/*.c")

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 链接第三方库
set(USED_3RD_LIB ${GSTREAMER_LIBRARIES} ${GSTREAMER_VIDEO_LIBRARIES} ${X11_LIBRARIES} ${JSON_GLIB_LIBRARIES} ${OpenCV_LIBS} cudart gstrtspserver-1.0 pthread m dl)

target_link_libraries(${PROJECT_NAME} ${NVDS_LIBS} ${USED_3RD_LIB})

#############################################################################################################
