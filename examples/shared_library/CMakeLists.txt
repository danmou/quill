add_subdirectory(quill_wrapper_shared)
add_subdirectory(launcher)
add_subdirectory(test_module)

add_executable(quill_example_shared_lib example_shared.cpp)
set_common_compile_options(quill_example_shared_lib)
target_link_libraries(quill_example_shared_lib quill_wrapper_shared)

# Optional
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(quill_example_shared_lib PRIVATE -fvisibility=hidden)
endif ()

target_compile_definitions(quill_example_shared_lib PRIVATE QUILL_DLL_IMPORT)


# Post-build command to copy multiple DLLs to the executable directory
add_custom_command(TARGET quill_example_shared_lib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:quill_wrapper_shared>            # DLL 1 location
        $<TARGET_FILE:launcher_shared>                 # DLL 2 location
        $<TARGET_FILE:test_module_shared>              # DLL 3 location
        $<TARGET_FILE_DIR:quill_example_shared_lib>    # Executable directory
)

# Ensure that the dependencies are met before the copy operation
add_dependencies(quill_example_shared_lib quill_wrapper_shared launcher_shared test_module_shared)


# Custom target to copy all DLLs to the executable directory
add_custom_target(copy_dll ALL
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:quill_wrapper_shared>          # DLL 1 location
        $<TARGET_FILE:launcher_shared>               # DLL 2 location
        $<TARGET_FILE:test_module_shared>            # DLL 3 location
        $<TARGET_FILE_DIR:quill_example_shared_lib>  # Executable directory
        DEPENDS quill_wrapper_shared launcher_shared test_module_shared  # Ensure all shared libs are built before copying
)

# Ensure that the custom target is executed after quill_example_shared_lib is built
add_dependencies(quill_example_shared_lib copy_dll)
