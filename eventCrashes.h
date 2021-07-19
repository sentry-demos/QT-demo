#ifndef EVENTCRASHES_H
#define EVENTCRASHES_H
#include <sentry.h>
#include <QtDebug> 

void initialize_memory(char *mem);
void startup(void);
void send_event(void);


#endif // EVENTCRASHES_H
