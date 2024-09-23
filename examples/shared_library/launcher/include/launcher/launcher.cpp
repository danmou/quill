#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/Logger.h"
#include "quill_wrapper_shared/quill_wrapper_shared.h"
#include <iostream>
#include <windows.h>

QUILL_EXPORT extern quill::Logger* global_logger_a;

typedef void (*RunTestModule)();

// Simulate loading and launching modules (DLLs)
void launch_modules()
{
  setup_quill();

  LOG_INFO(global_logger_a, "Launcher started launching modules");

  // Load TestModule
  HMODULE testModule = LoadLibrary(TEXT("test_module_shared.dll"));
  if (!testModule)
  {
    LOG_ERROR(global_logger_a, "Failed to load TestModule");
    return;
  }
  else
  {
    LOG_INFO(global_logger_a, "TestModule loaded");
  }

  // Get the function addresses
  RunTestModule run_test_module = (RunTestModule)GetProcAddress(testModule, "run_test_module");

  if (!run_test_module)
  {
    std::cerr << "Failed to get function addresses!" << std::endl;
    return;
  }

  run_test_module();

  // Simulate work with modules, then release
  // FreeLibrary(testModule);
  LOG_INFO(global_logger_a, "Modules unloaded, Launcher ending");
}