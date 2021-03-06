#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#define high 20  //定义地图的高度 
#define width 30   //定义地图的宽度 
#define snake_maxlength 200  //蛇长最大值 
int snake_x[snake_maxlength],snake_y[snake_maxlength]; //蛇的坐标 
int snake_length;  //蛇现在的长度 
int map[high][width]={0};  //初始化地图，0表示空格，1表示蛇身，2表示食物，
                            //3表示墙，4表示蛇头，现在地图中什么也没有 
int food_x,food_y; //食物的坐标 
int score;  //本局分数 
char input;  //读取用户键入的字符 
char primeinput='.';  //primeinput在input脱离wasd时，用来存储input 
int op;   //速度控制全局变量 
//数据的初始化函数 
void setdata()
{
	snake_x[0]=high/2;snake_y[0]=width/3;   //初始化蛇头，在地图内的位置随意 
	snake_x[1]=high/2;snake_y[1]=width/3+1;  //初始化蛇身 
	snake_length=2;   //蛇的原始尺寸（一格头一格身子） 
	food_x=high/3,food_y=width/3;  //初始化食物的位置，在地图内位置随意 
	score=0;
	int i,j;
	map[snake_x[0]][snake_y[0]]=4;  //蛇头 
	map[snake_x[1]][snake_y[1]]=1;  //蛇身 
	map[food_x][food_y]=2;   //食物 
	for(i=0;i<high;i++)   //墙 
	  for(j=0;j<width;j++)
	    if(i==0||j==0||i==high-1||j==width-1)
	       map[i][j]=3;   
 } 
 //画面打印 
 void gotoxy(int x,int y)  
 {
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
 }
 void show()
 {
 	gotoxy(0,0);
 	int i,j;
 	for(i=0;i<high;i++)
 	{
 		for(j=0;j<width;j++)
 		{
 			if(map[i][j]==0)
 			cout<<" ";
 			else if(map[i][j]==1)
 			cout<<"+";
 			else if(map[i][j]==2)
 			cout<<"@";
 		    else if(map[i][j]==3)
 		    cout<<"*";
 		    else if(map[i][j]==4)
 		    cout<<"0";
		 }
		 printf("\n");
	 }
	 printf("得分：%d",score);
 }
 //与输入无关的更新 
 void updatewithoutinput()
 {
 	 
 	int i;
 	if(snake_x[0]==food_x&&snake_y[0]==food_y)
 	{
 		score++;
 	    srand((unsigned)time(NULL));  //srand和rand函数连用产生随机数，一般以时间作为产生随机数的种子 
 	    food_x=rand()%(high-3)+1;    
 	    food_y=rand()%(width-3)+1;
 	    map[food_x][food_y]=2; 
 	    snake_length++;
	 }
	 if(snake_x[0]==0||snake_x[0]==high-1||snake_y[0]==0||snake_y[0]==width-1)  //碰墙了 
	 {
	 	cout<<"游戏结束！"<<endl;
	 	getch();
	 	exit(1);  
		 	 }
	for(i=1;i<snake_length;i++)  //碰到自己了 ，遍历蛇身找是否和蛇头重复  
	  if(snake_x[0]==snake_x[i]&&snake_y[0]==snake_y[i])
	  {
	  	cout<<"游戏结束"<<endl;
	  	getch();
	  	exit(1);
	  }
 }
 void updatewithinput()
 {
 	int i=1;
 	if(kbhit()) 
 	  input=getch();
 
    if(input!='\0')  //input!='\0'(空)表示当有输入的时候开始更新画面，这是游戏开始的条件 
 	{
 		if(input=='w'||input=='a'||input=='s'||input=='d')
 		{
 			if(primeinput=='w'&&input=='s'||primeinput=='s'&&input=='w'||primeinput=='a'&&input=='d'||primeinput=='d'&&input=='a')
 			{
 			  cout<<"贪吃蛇教会你的，是世上没有回头路，回头等于自焚"<<endl;   
			   exit(0);  //退出程序 
			 }
			 
 			else
 		primeinput=input;
 	    }
 		else if(primeinput=='.')
 		primeinput='w';
 		else if(input=='p')
 		{
 			while(1)
 			{
 				char op;
 				op=getch();
 				if(op=='p')
 				{
			    input='.';	 
 				break;
 			   }
			 }
		 }
		 else if(input=='+')
		 {
		 	if(op>=50)  //表示最快速度为25 ms刷新一次 
		 	op=op/2;
		 }
		 else if(input=='-')
		 {
		 	if(op<=1000) //表示最慢速度为 2000 ms刷新一次 
		 	op=op*2;
		 }
 		map[snake_x[snake_length-1]][snake_y[snake_length-1]]=0;//蛇走过一格，蛇尾处变为空格 
		 for(i=snake_length-1;i>0;i--)   
		 {
		 	snake_x[i]=snake_x[i-1]; //走过一格后蛇身的坐标覆盖前面的坐标 （从后往前覆盖，蛇头也会被蛇身覆盖） 
		 	snake_y[i]=snake_y[i-1];  
		 	map[snake_x[i]][snake_y[i]]=1;
		  } 
 		
	 }
	 if(primeinput=='w')
	    snake_x[0]--;
	else if(primeinput=='s')
	    snake_x[0]++;
	    else if(primeinput=='a')
	    snake_y[0]--;
	    else if(primeinput=='d')
	    snake_y[0]++;
	    map[snake_x[0]][snake_y[0]]=4;  //蛇头的坐标覆盖前面的坐标 
 }
int main()
{
	setdata();//数据初始化
  
    cout<<"请输入移动一格的毫秒数";
	cin>>op; 
	while(1)
	{
		show();  //画面打印 
		Sleep(op);
		updatewithoutinput();   //与输入无关的更新 
		updatewithinput();      //与输入有关的更新 
	 }
	  
    
	 return 0;
}
