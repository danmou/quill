add_subdirectory(quill_wrapper_shared)
add_subdirectory(launcher)
add_subdirectory(test_module)

add_executable(quill_example_shared_lib example_shared.cpp)
set_common_compile_options(quill_example_shared_lib)
target_link_libraries(quill_example_shared_lib quill_wrapper_shared launcher_shared)

# Optional
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(quill_example_shared_lib PRIVATE -fvisibility=hidden)
endif ()


    target_compile_definitions(quill_example_shared_lib PRIVATE QUILL_DLL_IMPORT)

    # Post-build command to copy the DLL to the executable directory
    add_custom_command(TARGET quill_example_shared_lib POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:quill_wrapper_shared>   # DLL location
            $<TARGET_FILE_DIR:quill_example_shared_lib>)  # Executable directory

# Post-build command to copy the DLL to the executable directory
add_custom_command(TARGET quill_example_shared_lib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:launcher_shared>   # DLL location
        $<TARGET_FILE_DIR:quill_example_shared_lib>)  # Executable directory

# Post-build command to copy the DLL to the executable directory
add_custom_command(TARGET quill_example_shared_lib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:test_module_shared>   # DLL location
        $<TARGET_FILE_DIR:quill_example_shared_lib>)  # Executable directory