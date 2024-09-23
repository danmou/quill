set(LIB_NAME launcher_shared)

add_library(${LIB_NAME} SHARED
        include/launcher/launcher.h
        include/launcher/launcher.cpp)

# Add include directories for this library
target_include_directories(${LIB_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

# Optional - Set the compiler flags for GCC/Clang
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${LIB_NAME} PRIVATE -fvisibility=hidden)
endif ()


target_compile_definitions(${LIB_NAME} PRIVATE QUILL_DLL_IMPORT BUILD_LAUNCHER_DLL)

target_link_libraries(${LIB_NAME} PUBLIC quill_wrapper_shared test_module_shared)