/*本程序用来写一个通讯录程序，包含两个信息。
(1)姓名 char[9](姓名最多4个字)
(2)手机号(11位)
(3)给每个元素添加一个ID
实现如下功能
浏览 编辑 增加 删除 查找 存盘 功能
*/
#include "address.h"
//**********************************************************************
//**********************************************************************
NODE * load()
{
    int i=0;
    NODE * head,* tail,* p;
     
    head=tail=(NODE *)malloc(sizeof(NODE));
 
    //采用尾插法
    tail->next=NULL;
     
    //打开文件
    FILE *fp;
    fp=fopen("list.dat","r");
    if(fp==NULL) 
    {
        printf("读取失败!文件打开失败!\n");
        return(NULL);
    }
    if(feof(fp)!=NULL)//如果文件为空,即使文件内容为空，文件也有一个文件结束符，读取文件结束符之后再看是否为空
    {
        p=(NODE *)malloc(sizeof(NODE));
 
        fread(p,sizeof(p->info),1,fp);
        if(feof(fp)!=NULL)
        {
            printf("读取失败!文件为空!\n");
            free(p);
        }
        return(NULL);
         
    }
     
    //赋值
    while(feof(fp)==NULL)
    {
        p=(NODE *)malloc(sizeof(NODE));
         
        fread(p,sizeof(p->info),1,fp);
         
        printf("正在读取第%d个数据\n",i);
        i++;
        if(feof(fp)!=NULL) 
        {
            free(p);
            break;
        }
 
    //连接链表
    p->next=NULL;
    tail->next=p;
    tail=p;
    }
    fclose(fp);
    return(head);
}
NODE * creat() //头插法
{
    //生成头结点--???
    //申请内存空间，并且用head去指向它
    NODE *head,*tail;
    head=tail=(NODE *)malloc(sizeof(NODE));
    tail->next=NULL;
     
    while(1)
    {
    //输入数据
    NODE *p=(NODE *)malloc(sizeof(NODE));
    printf("请输入姓名:\n");
    fflush(stdin);
    scanf("%s",p->info.no);
    printf("请输入手机号:\n");
    fflush(stdin);
    scanf("%s",p->info.tele);
 
    //连接链表
    p->next=NULL;
    tail->next=p;
    tail=p;
 
    printf("是否继续添加?<y/n>?\n");
    fflush(stdin);
    if(getchar()=='n') break;
    }
    /*//初始化首元结点,用p去指向
    NODE *p;
    p=(NODE *)malloc(sizeof(NODE));
    //初始化数据域
    p->no="孙越";
    p->tele="15223530300";
    //修改指针域
    head->next=p;
    p->next=NULL;
    */
    return(head);
}
//**********************************************************************
//**********************************************************************
int view(NODE * head)
{
    //定位首元结点:???
    //打印结点的值
    //移动指针，移动到下一个结点:  p=p->next;
    //移动到什么时候为止?
    //定位首元结点
    NODE *p1,*p2;
    p1=p2=head;
    //如果是空链表，直接输出链表为空就可以了
    if(head->next==NULL)
    {
        printf("链表为空!\n");
        printf("\n");
        return(0);
    }
    //打印首元结点
    printf("------------------------------------\n");
    printf("姓名         手机号码\n");
    printf("------------------------------------\n");
    //从这里开始循环
    p1=head->next;
    while(p1!=NULL)
    {
        printf("%-11s  %s\n",p1->info.no,p1->info.tele);
        //移动指针
        p2=p1;
        p1=p1->next;
    }
    return(0);
}
//**********************************************************************
//**********************************************************************
int search(NODE * head)
{
    //判断是否是空表，是空表就直接返回
    if(head->next==NULL)
    {
        printf("链表为空!\n");
        printf("\n");
        return(0);
    }
 
    //复杂一点，首先可以选择根据那种方式来进行查找
    NODE * p1,*p2;
    p1=head->next;
    p2=head;
    //定义一个辅助变量来看是找没找到
    int i=0;
    printf("您希望通过姓名来查找还是手机号码来查找?(Y=姓名/N=手机号码)?\n");
    fflush(stdin);
    char ch=getchar();
    if(ch=='Y')
    {
        //通过姓名来查找
        //输入要查找的姓名
        printf("请输入你需要查找的姓名:\n");
        char name[9];
        fflush(stdin);
        gets(name);
        //开始查找，查找的结果可能有多个，每查找到一个就输出来
        while(p1!=NULL)
        {
            if(strcmp(p1->info.no,name)==0)
            {   
                printf("\n");
                printf("%-11s  %s\n",p1->info.no,p1->info.tele);
                i=1;
            }
            //移动指针
            p2=p1;
            p1=p1->next;
 
        }
        //两种情况 一种是循环完了出来的，一种是直接跳过循环的，判断是哪一种情况
        if(i==0)
        {
            //说明是跳过循环的情况，没有找到
            printf("没有找到该信息!请检查您的输入是否有误!\n");
            return(0);
        }
        //下面的就是循环完了出来的
        return(0);
    }
    else if(ch=='N')
    {
        //通过手机号码来查找
        printf("请输入你需要查找的手机号码:\n");
        char tele1[12];
        fflush(stdin);
        gets(tele1);
        i=0;
        //开始查找，查找的结果可能有多个，每查找到一个就输出来
        while(p1!=NULL)
        {
            if(strcmp(p1->info.tele,tele1)==0)
            {   
                printf("\n");
                printf("%-11s  %s\n",p1->info.no,p1->info.tele);
                i=1;
            }
            //移动指针
            p2=p1;
            p1=p1->next;
        }
        //两种情况 一种是循环完了出来的，一种是直接跳过循环的，判断是哪一种情况
        if(i==0)
        {
            //说明是跳过循环的情况，没有找到
            printf("没有找到该信息!请检查您的输入是否有误!\n");
            return(0);
        }
        //下面的就是循环完了出来的
        return(0);
    }
    return(0);
}
//**********************************************************************
//**********************************************************************
int add(NODE * head)
{
    /*  
    //反复添加新结点
    //(1)生成新结点：为新结点开辟内存空间
    //(2)为新结点的数据域赋值
    //(3)将新结点插入到头结点与首元结点之间:  head->next:  a,b
    */
    printf("请问你是否要添加联系人?<Y/N>?\n");
    char ch;
    fflush(stdin);
    ch=getchar();
    if(ch=='Y'||ch=='y')
    {
        //采用头插法
        NODE *p1;
        while(ch=='Y'||ch=='y')
        {
        //执行添加新结点操作 
        p1=(NODE *)malloc(sizeof(NODE));
        printf("请输入姓名:\n");
        fflush(stdin);
        scanf("%s",p1->info.no);
        printf("请输入手机号:\n");
        fflush(stdin);
        scanf("%s",p1->info.tele);
        //将新结点连接
        p1->next=head->next;//将新开辟的内存空间连接到首元结点
        head->next=p1;
        //问是否继续添加
        printf("请问是否还要添加联系人?<Y/N>?\n");
        fflush(stdin);
        //通过整个循环结构来判断
        ch=getchar();
        }
        return(0);
    }
    return(0);
}
//**********************************************************************
//**********************************************************************
int del(NODE * head)
{
    if(head->next==NULL)
    {
        printf("链表为空!\n");
        printf("\n");
        return(0);
    }
 
    //首先输入要删除的人的姓名或者手机号
    NODE * p1,*p2;
    p1=head->next;
    p2=head;
    printf("您希望通过姓名来查找还是手机号码来查找?(Y=姓名/N=手机号码)?\n");
    fflush(stdin);
    char ch=getchar();
    if(ch=='Y')
    {
        //通过姓名来查找
        //输入要查找的姓名
        printf("请输入你需要查找的姓名:\n");
        char name[9];
        fflush(stdin);
        gets(name);
        //开始查找，查找的结果可能有多个，每查找到一个就输出来，询问用户是否要删除
        while(p1!=NULL)
        {
            if(strcmp(p1->info.no,name)==0)
            {   
                printf("\n");
                printf("%-11s  %s\n",p1->info.no,p1->info.tele);
                printf("请问是否要删除?<Y/N>?\n");
                ch=getchar();
                if(ch=='Y'||ch=='y')
                {
                    //进行删除操作,还要借助一个指针
                    NODE *p3=(NODE *)malloc(sizeof(NODE));
                    p3=p1;
                    p2->next=p1->next;
                    p1=p1->next;
                    free(p3);
                }
            }
            //移动指针
            p2=p1;
            p1=p1->next;
        }
        return(0);
    }
    else if(ch=='N')
    {
        //通过手机号码来查找
        printf("请输入你需要查找的手机号码:\n");
        char tele1[12];
        fflush(stdin);
        gets(tele1);
        //开始查找，查找的结果可能有多个，每查找到一个就输出来
        while(p1!=NULL)
        {
            if(strcmp(p1->info.tele,tele1)==0)
            {   
                printf("\n");
                printf("%-11s  %s\n",p1->info.no,p1->info.tele);
                printf("请问是否要删除?<Y/N>?\n");
                ch=getchar();
                if(ch=='Y')
                {
                    //进行删除操作
                    p2->next=p1->next;
                    p1=p1->next;
                }
                else return(0);
 
            }
            //移动指针
            p2=p1;
            p1=p1->next;
        }
        return(0);
 
    }
    return(0);
}
//**********************************************************************
//**********************************************************************
int freelist(NODE * head)
{
    //思路，定义两个指针p1,p2。先找到头指针，p2指向头指针，p1指向后继结点，然后删除头指针,然后又让p2=p1。
    NODE *p1,*p2;
    p1=p2=head;
    //先看是不是空链表，如果是空链表只需要删除头结点就可以了。
    if(head->next==NULL)
    {
        free(head);
        return(0);
    }
    //如果不是空链表
    p1=p1->next;
    while(p1!=NULL)
    {
        free(p2);
        p2=p1;
        p1=p1->next;
    }
    free(p2);
    return(0);
}
//**********************************************************************
//**********************************************************************
int save(NODE * head)
{
    NODE *p1;
    p1=head->next;
 
    //保存链表当中所有的信息
    //以写入的方式打开一个文件，并判断是否打开成功
    FILE *fp;
    fp=fopen("list.dat","w");
    if(fp==NULL)
    {
        printf("文件打开失败!信息存盘失败!\n");
        return(0);
    }
    if(head->next==NULL)
    {
        printf("通讯录为空!信息存盘失败!\n");
        return(0);
    }
    while(p1!=NULL)
    {
        fwrite(p1,sizeof(p1->info),1,fp);
        //移动指针
        p1=p1->next;
    }
    fclose(fp);
    printf("存盘成功!\n");
    return(0);
}
//**********************************************************************
//**********************************************************************
 
int clearlist( NODE * head)
{
    //一键清空链表，只保留头结点，返回1表示清空成功，返回0表示清空失败
    int i=0;
    NODE *p1,*p2;
    p1=p2=head->next;
    while(p2!=NULL)
    {
        i=1;
        //删除链表
        p1=p1->next;
        free(p2);
        p2=p1;
    }
    if(i) head->next=NULL;
    return(i);
}
//**********************************************************************
//**********************************************************************
 
void menu()
{
    NODE * head;
    //建立简单链表
    //head=creat();
    //载入简单链表
     
    printf("正在读取数据，请稍后....\n");
    head = load();
    while(1)
    {
        if(head==NULL) 
        {
            printf("文件读取失败\n"); break;
        }
        else
        {
            printf("读取数据成功!\n");break;
        }
    }
    while(1)
    {
    printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
    printf("            通讯录管理系统\n");
    printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
    printf("欢迎进入本系统!");
    printf("请选择：\n");
    printf("(1)-----浏览通讯录\n");
    printf("(2)-----查找联系人\n");
    printf("(3)-----增加联系人\n");
    printf("(4)-----删除联系人\n");
    printf("(5)-----通讯录存盘\n");
    printf("(6)-----删除所有联系人\n");
    //退出系统之前需要释放内存!!!!!!!!!!!
    printf("(7)-----退出本系统\n");//!!!!!!!!
    int s;
    scanf("%d",&s);
    switch(s)
    {
    case 1:view(head);break;
    case 2:search(head);break;
    case 3:add(head);break;
    case 4:del(head);break;
    case 5:save(head);break;
    case 6:
        {
            if(clearlist(head))
                printf("删除所有联系人成功!\n");
            else printf("删除所有联系人失败!\n");
        }break;
         
    case 7:freelist(head);exit(0);
    default:printf("error!请重新输入!\n");
    }
    //每次用完了之后都清空屏幕
    }
}
 
//**********************************************************************
//**********************************************************************
void main()
{
    menu();
}