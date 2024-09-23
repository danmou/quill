#pragma once
#include "quill/core/Attributes.h"

#ifdef BUILD_TEST_MODULE_DLL
  #define TEST_MODULE_API __declspec(dllexport)
#else
  #define TEST_MODULE_API __declspec(dllimport)
#endif

extern "C"
{
  TEST_MODULE_API void run_test_module();
}