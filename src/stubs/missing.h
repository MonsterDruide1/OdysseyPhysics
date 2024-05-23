#pragma once

#include <cstdio>

#define DEREF_NULL *(volatile int*)0;
#define WARN_UNIMPL printf("Function not implemented: %s (%s:%d)\n", __func__, __FILE__, __LINE__)
#define CRASH {WARN_UNIMPL;DEREF_NULL}
