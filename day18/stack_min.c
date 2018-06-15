#include <stdio.h>
#include<stdlib.h>
typedef struct Seqstack
{
    int* data;
    int size;
}Seqstack;

void SeqstackInit(Seqstack* stack)
{
    stack->size = 0;
    stack->data = (int*)malloc(sizeof(int));
}

void SeqstackDestroy(Seqstack* stack)
{
    stack->size = 0;
    free(stack->data);
}
void SeqstackPush(Seqstack* stack,int value)
{
    if(stack == NULL)
    {
        return;
    }
    stack->data[stack->size++] = value;
}

void SeqstackPop(Seqstack* stack)
{
    if(stack == NULL)
    {
        return;
    }
    if(stack->size == 0)
    {
        return;
    }
    stack->size--;
}

int SeqstackTop(Seqstack* stack,int* value)
{
    if(stack == NULL ||value == NULL)
    {
        return 0;
    }
    *value = stack->data[stack->size-1];
    return 1;
}

int SeqstackMin(Seqstack* stack)
{
    if(stack == NULL)
    {
        return 0;
    }
    int top;
    int ret = SeqstackTop(stack,&top);

    if(ret < 0)
    {
        return 0;
    }
    int min = top;
    
//        printf("top = %d\n",top);
//        printf("min = %d\n",min);
//
    SeqstackPop(stack);
    while( SeqstackTop(stack,&top) == 1)
    {
//        printf("top = %d\n",top);
//        printf("min = %d\n",min);
        if(top < min)
        {
            min = top;
        }
            SeqstackPop(stack);
    }
    return min;

}
int main()
{
    Seqstack stack;
    SeqstackInit(&stack);
    SeqstackPush(&stack,7);
    SeqstackPush(&stack,8);
    SeqstackPush(&stack,2);
    SeqstackPush(&stack,6);
    SeqstackPush(&stack,4);

    int min =  SeqstackMin(&stack);
    printf("min expected 2,actual is %d\n",min);
    return 0;
}
