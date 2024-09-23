#pragma once

#include "quill/Logger.h"
#include "quill/core/Attributes.h"

extern "C"
{
  QUILL_EXPORT void setup_quill();
  QUILL_EXPORT quill::Logger* get_global_logger_a();
}