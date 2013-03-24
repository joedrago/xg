#ifndef OS_OS_H
#define OS_OS_H

void osStartup();
void osShutdown();

void *osAlloc(int bytes);
void *osAllocAligned(int bytes, int alignment);
void osFree(void *p);

struct osThread;
typedef int (*osThreadFunc)(void *userdata);
struct osThread *osThreadCreate(osThreadFunc func);
void osThreadResume(struct osThread *thread);
int osThreadJoin(struct osThread *thread, int *returnValue);

#endif
