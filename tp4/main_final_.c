#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task
{
    int id;
    int duration;
    int priority;
    struct Task *next;
} Task;

typedef struct StackTasks
{
    Task *top;
    Task *bottom;
} StackTasks;

// inititalise task
void initStack(StackTasks *stackTasks)
{
    stackTasks->top = NULL;
    stackTasks->bottom = NULL;
}

// check empty stack

bool isEmptyStack(StackTasks *stackTasks)
{
    return (stackTasks->top == NULL);
}

Task *createTask(int id, int duration, int priority)
{
    Task *pTask = malloc(sizeof *pTask);
    pTask->id = id;
    pTask->duration = duration;
    pTask->priority = priority;
    return pTask;
}

void pushStackTasks(StackTasks *stackTasks, int id, int duration, int priority)
{
    Task *pTask = createTask(id, duration, priority);
    if (isEmptyStack(stackTasks))
    {
        stackTasks->top = pTask;
        stackTasks->bottom = pTask;
        return;
    }

    if (stackTasks->top->priority < priority)
    {
        pTask->next = stackTasks->top;
        stackTasks->top = pTask;
        return;
    }

    Task *curr = stackTasks->top;

    // by pass all bigger priority
    while (curr->next && curr->next->priority > priority)
    {
        curr = curr->next;
    }

    // by pass all same priority
    while (curr->next && curr->next->priority == priority)
    {
        curr = curr->next;
    }

    pTask->next = curr->next;
    curr->next = pTask;
}

void popStackTask(StackTasks *stackTasks, Task *task)
{
}

void printStackTasks(StackTasks stackTasks)
{
    while (stackTasks.top != NULL)
    {
        printf("[%d: %dms, %d] -> ", stackTasks.top->id, stackTasks.top->duration, stackTasks.top->priority);
        stackTasks.top = stackTasks.top->next;
    }
    printf("NULL\n");
}

void main()
{
    StackTasks stackTasks;
    initStack(&stackTasks);
    pushStackTasks(&stackTasks, 1, 5000, 1);
    pushStackTasks(&stackTasks, 2, 2000, 1);
    pushStackTasks(&stackTasks, 3, 7000, 3);
    pushStackTasks(&stackTasks, 4, 5000, 2);
    pushStackTasks(&stackTasks, 5, 6000, 1);
    printStackTasks(stackTasks);
}