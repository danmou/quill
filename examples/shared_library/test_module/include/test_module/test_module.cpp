#include "test_module.h"
#include "quill/LogMacros.h"
#include "quill/Logger.h"
#include "quill_wrapper_shared/quill_wrapper_shared.h"

QUILL_EXPORT extern quill::Logger* global_logger_a;

void run_test_module() { LOG_INFO(global_logger_a, "TestModule is running"); }