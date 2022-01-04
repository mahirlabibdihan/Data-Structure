#include<stdio.h>
#include<string.h>
#include<stddef.h>

size_t strlen(const char* s);
char* strlwr(char* s);
char* strupr(char* s);
char* strrev(char* s);
char* strcpy(char* s,const char* x);
char* strncpy(char* s,const char* x,size_t n);
char* strcat(char* s,const char* x);
char* strncat(char* s,const char* x,size_t n);
int strcmp(const char* s,const char* x);