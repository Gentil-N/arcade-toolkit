cmake_minimum_required(VERSION 3.0)

project(atk)

#Compilation states
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
#------------------

#Main Vars
set(SRC_DIR ${PROJECT_SOURCE_DIR}/code/sources/)
#---------

#Build Test
if(${ATK_TEST} MATCHES ON)
message(STATUS "Build Test")
set(ATK_MOD_ORION ON)
set(ATK_MOD_ASSET ON)
set(ATK_MOD_DESKTOP ON)
set(ATK_MOD_MATH ON)
set(ATK_MOD_AUDIO ON)
set(CMAKE_BUILD_TYPE Debug)
set(SRC_FILES ${SRC_FILES} ${PROJECT_SOURCE_DIR}/code/test/main.cpp)
if(${ATK_TRIANGLE_DEMO} MATCHES ON)
message(STATUS "Triangle demo enabled")
add_compile_definitions(TRIANGLE_DEMO)
elseif(${ATK_CUBE_DEMO} MATCHES ON)
message(STATUS "Cube demo enabled")
add_compile_definitions(CUBE_DEMO)
elseif(${ATK_INSTANCE_RENDERING_DEMO} MATCHES ON)
message(STATUS "Instance rendering demo enabled")
add_compile_definitions(INSTANCE_RENDERING_DEMO)
elseif(${ATK_CUBE_TEXTURED_DEMO} MATCHES ON)
message(STATUS "Cube textured demo enabled")
add_compile_definitions(CUBE_TEXTURED_DEMO)
endif()
else()
add_compile_definitions(ATK_EXPORT_LIB)
endif()
#----------

#Modules required
set(SRC_FILES ${SRC_FILES} 
              ${SRC_DIR}/core/atk_core.c
              ${SRC_DIR}/core/memory.c
              ${SRC_DIR}/core/logger.c
              ${SRC_DIR}/core/mutex.c
              ${SRC_DIR}/core/vector.c
              ${SRC_DIR}/core/array.c
              ${SRC_DIR}/core/string.c
              ${SRC_DIR}/core/file.c)
find_package(Threads)
set(REQUIRED_LIBS ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
#-
if(${ATK_MOD_ORION} MATCHES ON)
message(STATUS "Orion module enabled")
set(SRC_FILES ${SRC_FILES}
              ${SRC_DIR}/orion/buffer.c
              ${SRC_DIR}/orion/command.c
              ${SRC_DIR}/orion/device.c
              ${SRC_DIR}/orion/global.c
              ${SRC_DIR}/orion/gpu.c
              ${SRC_DIR}/orion/image.c
              ${SRC_DIR}/orion/memory_operation.c
              ${SRC_DIR}/orion/orn_core.c
              ${SRC_DIR}/orion/pipeline.c
              ${SRC_DIR}/orion/renderer.c
              ${SRC_DIR}/orion/shader.c
              ${SRC_DIR}/orion/surface.c
              ${SRC_DIR}/orion/swapchain.c
              ${SRC_DIR}/orion/sync_objects.c
              ${SRC_DIR}/orion/texture.c
              ${SRC_DIR}/orion/uniform.c
              ${SRC_DIR}/orion/vulkan_loader.c
              ${SRC_DIR}/orion/memory_allocator.c)
endif()
#-
if(${ATK_MOD_ASSET} MATCHES ON)
message(STATUS "Asset module enabled")
find_library(ASSIMP_LIB assimp)
find_library(IRR_XML_LIB IrrXML)
find_library(Z_LIB_STATIC_LIB zlibstatic)
if(NOT ASSIMP_LIB)
       message(FATAL_ERROR "assimp library not found (required for asset module)")
elseif(NOT IRR_XML_LIB)
       message(FATAL_ERROR "IrrXML library not found (required for asset module)")
elseif(NOT Z_LIB_STATIC_LIB)
       message(FATAL_ERROR "zlibstatic library not found (required for asset module)")
endif()
message(STATUS "All libraries required for asset module are available")
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${ASSIMP_LIB} ${IRR_XML_LIB} ${Z_LIB_STATIC_LIB})
set(SRC_FILES ${SRC_FILES} 
              ${SRC_DIR}/asset/model.c
              ${SRC_DIR}/asset/image.c)
endif()
#-
if(${ATK_MOD_DESKTOP} MATCHES ON)
message(STATUS "Desktop module enabled")
find_library(GLFW_LIB glfw3)
if(NOT GLFW_LIB)
       message(FATAL_ERROR "glfw3 library not found (required for desktop module)")
endif()
message(STATUS "All libraries required for desktop module are available")
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${GLFW_LIB})
set(SRC_FILES ${SRC_FILES} 
              ${SRC_DIR}/desktop/dsk_core.c
              ${SRC_DIR}/desktop/global.c
              ${SRC_DIR}/desktop/window.c
              ${SRC_DIR}/desktop/keyboard.c
              ${SRC_DIR}/desktop/mouse.c
              ${SRC_DIR}/desktop/joystick.c)
endif()
#-
if(${ATK_MOD_MATH} MATCHES ON)
message(STATUS "Math module enabled")
set(SRC_FILES ${SRC_FILES} 
              ${SRC_DIR}/math/mth_core.c
              ${SRC_DIR}/math/mat.cpp
              ${SRC_DIR}/math/vec.cpp
              ${SRC_DIR}/math/collision.c)
endif()
#-
if(${ATK_MOD_AUDIO} MATCHES ON)
message(STATUS "Audio module enabled")
find_library(OPENAL_LIB openal)
if(NOT OPENAL_LIB)
       message(FATAL_ERROR "openal library not found (required for audio module)")
endif()
message(STATUS "All libraries required for audio module are available")
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${OPENAL_LIB})
set(SRC_FILES ${SRC_FILES} 
              ${SRC_DIR}/audio/adi_core.c
              ${SRC_DIR}/audio/sound_data.c
              ${SRC_DIR}/audio/source.c
              ${SRC_DIR}/audio/listener.c)
endif()
#----------------

#Compilation
if(${ATK_TEST} MATCHES ON)
add_executable(atk ${SRC_FILES})
else()
add_library(atk SHARED ${SRC_FILES})
endif()
target_link_libraries(atk ${REQUIRED_LIBS})
#-----------