#include<stdio.h>
#include<stdlib.h>

typedef struct Vector{
	int Size;
	int *Arr;
  	void (*push_back)(struct Vector*,int);
} vector;


void push_back(vector *A,int a)
{
	A->Arr=(int*)realloc(A->Arr,sizeof(int)*(A->Size+1));
  	A->Arr[A->Size]=a;
  	A->Size++;
}

vector Initialize(vector *A,int Size)
{
	A->Size=Size;
	A->Arr=(int*)malloc(sizeof(int)*Size);
	A->push_back=push_back;
	return *A;
}

int main()
{
	int i;
	vector v=Initialize(&v,0);
	v.push_back(&v,5);
	v.push_back(&v,6);
	v.push_back(&v,7);
	for(i=0;i<v.Size;i++)
	{
		printf("%d ",v.Arr[i]);
	}
}