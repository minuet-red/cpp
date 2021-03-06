#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
	int i,j;
    int x = 30;
    int y = 10;
 
	int TOP = 1;
	int Bottom = 10;
 
	int Left = 0;
	int Right = 50;
 
	int speed_x = 1;
	int speed_y = 1;
 
	while(1)
	{
		
		if(y>Bottom || y<TOP)
		{
			speed_y = -speed_y;
		}
 
		if(x<Left || x>Right)
		{
			speed_x = -speed_x;
		}
 
		x = x - speed_x;
		y = y - speed_y;
 
		system("cls");
	  
		for(j=0;j<y;j++)
		{
			printf("\n");
		}
 
		for(i=0;i<x;i++)
		{
			printf(" ");
		}
			printf("O\n");
	}
 
	return 0;
}
 