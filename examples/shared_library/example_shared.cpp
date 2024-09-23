#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/Logger.h"
#include "quill_wrapper_shared/quill_wrapper_shared.h"

#include <iostream>
#include <string>
#include <string_view>
#include <windows.h>

// Typedefs for the functions to load from the DLL
typedef void (*SetupQuillFunc)();
typedef quill::Logger* (*GetGlobalLoggerFunc)();

int main()
{
  // Load the DLL
  HMODULE hLib = LoadLibrary("quill_wrapper_shared.dll");
  if (!hLib)
  {
    std::cerr << "Failed to load the DLL!" << std::endl;
    return 1;
  }

  // Get the function addresses
  SetupQuillFunc setup_quill = (SetupQuillFunc)GetProcAddress(hLib, "setup_quill");
  GetGlobalLoggerFunc get_global_logger =
    (GetGlobalLoggerFunc)GetProcAddress(hLib, "get_global_logger_a");

  if (!setup_quill || !get_global_logger)
  {
    std::cerr << "Failed to get function addresses!" << std::endl;
    FreeLibrary(hLib);
    return 1;
  }

  // Call the setup function
  setup_quill();

  // Get the global logger
  quill::Logger* global_logger_a = get_global_logger();

  std::string s{"string"};

  LOG_INFO(global_logger_a, "This is a log info example {}", s);

  FreeLibrary(hLib);
}