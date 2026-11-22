#pragma once

#include "parafusers/core/Log.h"

#include <cstdlib>

#if defined(PARAFUSERS_DEBUG)
    #define PF_ASSERT(cond, msg)                                                          \
        do {                                                                              \
            if (!(cond)) {                                                                \
                ::pf::log::error("Assert falhou: {} ({}:{}) {}", #cond, __FILE__, __LINE__, msg); \
                std::abort();                                                             \
            }                                                                             \
        } while (false)
#else
    #define PF_ASSERT(cond, msg) ((void)0)
#endif
