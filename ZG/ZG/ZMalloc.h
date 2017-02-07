#pragma once

#ifndef _ZMALLOC_H__
#define _ZMALLOC_H__

void* ZMalloc(u32 n);
void ZFree(void *addr);

#endif
