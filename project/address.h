#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//**********************************************************************
//**********************************************************************
struct date
{
    char no[9];
    char tele[12];      
};
 
typedef struct node
{
    //为了能够读写结构体，将这里定义的结构体改一下
    struct date info;   
    struct node * next;
}NODE; 