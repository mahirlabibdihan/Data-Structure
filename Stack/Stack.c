#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack stack;

struct stack{
	int size;
	int *at;
  	void (*push)(stack*,int);
  	void (*pop)(stack*);
  	int (*top)(stack*);
  	bool (*empty)(stack*);
};

void push(stack *S,int a)
{
	S->at=(int*)realloc(S->at,sizeof(int)*(S->size+1));
  	S->at[S->size]=a;
  	S->size++;
}

void pop(stack *S)
{
	if(S->size)
	{
		S->at=(int*)realloc(S->at,sizeof(int)*(S->size-1));
		S->size--;
	}
	
}

int top(stack *S)
{
	if(S->size)
	{
		return S->at[S->size-1];
	}

	else
	{
		return 0;
	}
	
}

bool empty(stack *S)
{
	return S->size==0;
}

stack Initialize(stack *S)
{
	S->size=0;
	S->at=(int*)malloc(0);
	S->push=push;
	S->pop=pop;
	S->top=top;
	S->empty=empty;
	return *S;
}

int main()
{
	int i;
	stack s=Initialize(&s);

	s.push(&s,10);
	s.push(&s,11);
	s.push(&s,12);

	while(!s.empty(&s))
	{
		printf("%d ",s.top(&s)),s.pop(&s);
	}
}

