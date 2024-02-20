#include "core.h"
#include "system.h"
#include "memory.h"
#include "exception.h"
#include "process.h"

// dataCopy
int dataInt = 1;
char dataChar1 = 2;
short dataShort = 3;
char dataChar2 = 4;

// bssFill
int bssInt;
char bssChar1;
short bssShort;
char bssChar2;

int arg1 = 1;
int arg2 = 2;
int arg3 = 3;
int arg4 = 4;
uint32_t volatile sharedData;

static struct process_t process1;
static struct process_t process2;
static struct process_t process3;
static struct process_t process4;

extern void processHandler(void);

void runner1(void *args)
{

    uint32_t *ptr = (uint32_t *)args;

    while (1)
    {
        sharedData = *ptr;
    }
}

void runner2(void *args)
{

    uint32_t *ptr = (uint32_t *)args;

    while (1)
    {
        sharedData = *ptr;
    }
}

void runner3(void *args)
{

    uint32_t *ptr = (uint32_t *)args;

    while (1)
    {
        sharedData = *ptr;
    }
}

void runner4(void *args)
{

    uint32_t *ptr = (uint32_t *)args;

    while (1)
    {
        sharedData = *ptr;
    }
}

int main(void)
{

    createProcess(1024, &process1, &processHandler, 20, &runner1, &arg1, 1);

    createProcess(1024, &process2, &processHandler, 20, &runner2, &arg2, 1);

    createProcess(1024, &process3, &processHandler, 20, &runner3, &arg3, 1);

    createProcess(1024, &process4, &processHandler, 20, &runner4, &arg4, 1);

    while (1)
    {
        sharedData = 0;
    }
}
