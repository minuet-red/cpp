#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#define high 20  //�����ͼ�ĸ߶� 
#define width 30   //�����ͼ�Ŀ�� 
#define snake_maxlength 200  //�߳����ֵ 
int snake_x[snake_maxlength],snake_y[snake_maxlength]; //�ߵ����� 
int snake_length;  //�����ڵĳ��� 
int map[high][width]={0};  //��ʼ����ͼ��0��ʾ�ո�1��ʾ����2��ʾʳ�
                            //3��ʾǽ��4��ʾ��ͷ�����ڵ�ͼ��ʲôҲû�� 
int food_x,food_y; //ʳ������� 
int score;  //���ַ��� 
char input;  //��ȡ�û�������ַ� 
char primeinput='.';  //primeinput��input����wasdʱ�������洢input 
int op;   //�ٶȿ���ȫ�ֱ��� 
//���ݵĳ�ʼ������ 
void setdata()
{
	snake_x[0]=high/2;snake_y[0]=width/3;   //��ʼ����ͷ���ڵ�ͼ�ڵ�λ������ 
	snake_x[1]=high/2;snake_y[1]=width/3+1;  //��ʼ������ 
	snake_length=2;   //�ߵ�ԭʼ�ߴ磨һ��ͷһ�����ӣ� 
	food_x=high/3,food_y=width/3;  //��ʼ��ʳ���λ�ã��ڵ�ͼ��λ������ 
	score=0;
	int i,j;
	map[snake_x[0]][snake_y[0]]=4;  //��ͷ 
	map[snake_x[1]][snake_y[1]]=1;  //���� 
	map[food_x][food_y]=2;   //ʳ�� 
	for(i=0;i<high;i++)   //ǽ 
	  for(j=0;j<width;j++)
	    if(i==0||j==0||i==high-1||j==width-1)
	       map[i][j]=3;   
 } 
 //�����ӡ 
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
	 printf("�÷֣�%d",score);
 }
 //�������޹صĸ��� 
 void updatewithoutinput()
 {
 	 
 	int i;
 	if(snake_x[0]==food_x&&snake_y[0]==food_y)
 	{
 		score++;
 	    srand((unsigned)time(NULL));  //srand��rand�������ò����������һ����ʱ����Ϊ��������������� 
 	    food_x=rand()%(high-3)+1;    
 	    food_y=rand()%(width-3)+1;
 	    map[food_x][food_y]=2; 
 	    snake_length++;
	 }
	 if(snake_x[0]==0||snake_x[0]==high-1||snake_y[0]==0||snake_y[0]==width-1)  //��ǽ�� 
	 {
	 	cout<<"��Ϸ������"<<endl;
	 	getch();
	 	exit(1);  
		 	 }
	for(i=1;i<snake_length;i++)  //�����Լ��� �������������Ƿ����ͷ�ظ�  
	  if(snake_x[0]==snake_x[i]&&snake_y[0]==snake_y[i])
	  {
	  	cout<<"��Ϸ����"<<endl;
	  	getch();
	  	exit(1);
	  }
 }
 void updatewithinput()
 {
 	int i=1;
 	if(kbhit()) 
 	  input=getch();
 
    if(input!='\0')  //input!='\0'(��)��ʾ���������ʱ��ʼ���»��棬������Ϸ��ʼ������ 
 	{
 		if(input=='w'||input=='a'||input=='s'||input=='d')
 		{
 			if(primeinput=='w'&&input=='s'||primeinput=='s'&&input=='w'||primeinput=='a'&&input=='d'||primeinput=='d'&&input=='a')
 			{
 			  cout<<"̰���߽̻���ģ�������û�л�ͷ·����ͷ�����Է�"<<endl;   
			   exit(0);  //�˳����� 
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
		 	if(op>=50)  //��ʾ����ٶ�Ϊ25 msˢ��һ�� 
		 	op=op/2;
		 }
		 else if(input=='-')
		 {
		 	if(op<=1000) //��ʾ�����ٶ�Ϊ 2000 msˢ��һ�� 
		 	op=op*2;
		 }
 		map[snake_x[snake_length-1]][snake_y[snake_length-1]]=0;//���߹�һ����β����Ϊ�ո� 
		 for(i=snake_length-1;i>0;i--)   
		 {
		 	snake_x[i]=snake_x[i-1]; //�߹�һ�����������긲��ǰ������� ���Ӻ���ǰ���ǣ���ͷҲ�ᱻ�����ǣ� 
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
	    map[snake_x[0]][snake_y[0]]=4;  //��ͷ�����긲��ǰ������� 
 }
int main()
{
	setdata();//���ݳ�ʼ��
  
    cout<<"�������ƶ�һ��ĺ�����";
	cin>>op; 
	while(1)
	{
		show();  //�����ӡ 
		Sleep(op);
		updatewithoutinput();   //�������޹صĸ��� 
		updatewithinput();      //�������йصĸ��� 
	 }
	  
    
	 return 0;
}
