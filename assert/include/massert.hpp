#pragma once
#include <cassert>

#ifdef DEBUG
#define XNET_ASSERT(x) assert((x))
#else
#define XNET_ASSERT(x)
#endif

#define xnet_assert(x) assert((x))
