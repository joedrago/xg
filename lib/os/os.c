#include "os/os.h"

#include <stdlib.h>
#include <string.h>

void osStartup()
{
}

void osShutdown()
{
}

void *osAlloc(int bytes)
{
    return calloc(1, bytes);
}

void *osAllocAligned(int bytes, int alignment)
{
    void *p = _aligned_malloc(bytes, alignment);
    if(p)
    {
        memset(p, 0, bytes);
    }
    return p;
}

void osFree(void *p)
{
    free(p);
}
