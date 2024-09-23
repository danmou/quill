#pragma once
#include "quill/core/Attributes.h"

#ifdef BUILD_LAUNCHER_DLL
  #define LAUNCHER_API __declspec(dllexport)
#else
  #define LAUNCHER_API __declspec(dllimport)
#endif

LAUNCHER_API void launch_modules();