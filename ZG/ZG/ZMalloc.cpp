#include "stdafx.h"

#include "ZMalloc.h"
#include "ZTypes.h"
#include <malloc.h>
void* ZMalloc(u32 n) {
	return malloc(n);
}
void ZFree(void *addr) {
	free(addr);
}