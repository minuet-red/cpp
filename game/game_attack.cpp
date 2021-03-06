#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

double shanghai[20]={0.6,1.1,2,3.16,5.5,7,10,20,50,100,146.23,254.13,312,403,601,1023};
double bosshealth[20]={2,3,4,5.9,8,14,19,32,73,157,200,403,801,1200,3630,20123};
double wj_shanghai=1,wj_health=10,wj_max_health=10,boss,wj_money;
void chushihua();
void game();
void gongji();
void goumai();
void shangdian();
void zhujiemian();
void fangyu();
void cend();
void chushou();
void print(char[]);
int bishou=0,caidao=0,jian=0,shenjian=0;
double bishou_1=5,caidao_1=17,jian_1=58,shenjian_1=123.1;
int hat=0,douhui=0,hudun=0,hunjia=0,shendun=0;
double hat_1=7,douhui_1=21,hudun_1=49,hunjia_1=89,shendun_1=210.4;
void cend()
{
    system("cls");
    print("GAME OVER");
    exit(1);
}
void game()
{
    int k;
    chushihua();
    IO:
    printf("请输入对手等级 (0~15)\n");
    scanf("%d",&k);
    if(k>15||k<0)
    {
        system("cls");
        goto IO;
    }
    boss=bosshealth[k];
    system("cls");
    while(wj_health>=0)
    {
        srand(time(NULL));
        QP:
        printf("1.逃跑        2.进攻\n");
        char s=getch();
        if(s<'1'||s>'2')
        {
            system("cls");
            goto QP;
        }
        if(s=='1')
        {
            system("cls");
            zhujiemian();
        }
        system("cls");
        double l=shanghai[k]*((rand()%2)+1)+fabs(double(rand()%100/100-2));
        printf("对手对你造成了%lf点伤害\n",l);
        wj_health-=l;
        printf("你当前剩余血量：%lf\n",wj_health);
        if(wj_health<=0)
            cend();
        double o=wj_shanghai*((rand()%2)+1)+double(rand()%10/10);
        boss-=o;
        printf("你对对手造成了%lf点伤害\n",o);
        printf("对手当前剩余血量：%lf\n\n",boss);
        if(boss<=0)
        {
            printf("胜利！\n获得%lf金币\n\n当前剩余血量：%lf\n",shanghai[k]+3,wj_health);
            wj_money+=shanghai[k]+3;
            printf("\n余额：%lf\n",wj_money);
            getch();
            if(k==15)
            {
                printf("恭喜玩家！游戏胜利！\n");
                getch();
                exit(1);
            }
            system("cls");
            zhujiemian();
        }
    }
}
void zhujiemian()
{
    PO:
    printf("1.商店 2.战斗 3.回血 4.状态\n");
    char k=getch();
    if(k>'4'||k<'1')
    {
        system("cls");
        goto PO;
    }
    if(k=='1')
    {
        system("cls");
        shangdian();
        return;
    }
    if(k=='2')
    {
        system("cls");
        game();
        return;
    }
    if(k=='3')
    {
        system("cls");
        if(wj_money>0)
        {
            wj_money=wj_money*4/5-1;
            chushihua();
            wj_health=wj_max_health;
            printf("回血成功！\n");
            getch();
            system("cls");
            goto PO;
        }
        else
        {
            printf("余额不足！\n");
            getch();
            system("cls");
            goto PO;
        }
    }
    if(k=='4')
    {
        chushihua(); 
        system("cls");
        printf("生命值：%lf\n",wj_health);
        printf("最大生命值：%lf\n",wj_max_health);
        printf("攻击力：%lf\n",wj_shanghai);
        printf("金币：%lf\n",wj_money); 
        getch();
        system("cls");
        goto PO;
    }
    if(k=='5')
    {
        string a;
        system("cls");
        printf("输入密码！\n");
        cin>>a;
        if(a=="songyudashuaibi"||a=="PI")
        {
            wj_money+=1000;
            printf("外挂生效\n");
            Sleep(1000);
            system("cls");
            goto PO;
        }
        printf("外挂失败\n");
        Sleep(1000);
        system("cls");
        goto PO;
    }
}
void shangdian()
{
    LK:
    printf("1.购买 2.返回主界面\n");
    char k=getch();
    if(k!='1'&&k!='2')
    {
        system("cls");
        goto LK;
    }
    if(k=='1')
    {
        system("cls");
        goumai();
        goto LK;
    }
    if(k=='2')
    {
        system("cls");
        zhujiemian();
        return;
    }
}
void goumai()
{
    ML:
    printf("1.攻击 2.防御 3.返回主界面\n");
    char k=getch();
    if(k!='1'&&k!='2'&&k!='3')
    {
        system("cls");
        goto ML;
    }
    if(k=='1')
    {
        system("cls");
        gongji();
        goto ML;
    }
    if(k=='3')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        fangyu();
    }
} 
void gongji()
{
    OP:
    system("cls");
    printf("0.返回上界面\n");
    printf("1.返回主界面\n");
    printf("2.匕首 5金币\n");
    printf("3.菜刀 17金币\n");
    printf("4.剑 68金币\n");
    printf("5.圣剑 210金币\n");
    printf("提醒：金币价格与伤害成正比\n");
    char k=getch();
    if(k<'0'||k>'5')
    {
        system("cls");
        goto OP;
    }
    if(k=='0')
    {
        system("cls");
        goumai();
        return;
    }
    if(k=='1')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        if(wj_money>=bishou_1)
        {
            chushihua();
            system("cls");
            wj_money-=bishou_1;
            bishou++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        system("cls");
        goto OP;
    }
    if(k=='3')
    {
        if(wj_money>=caidao_1)
        {
            chushihua();
            system("cls");
            wj_money-=caidao_1;
            caidao++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
    if(k=='4')
    {
        if(wj_money>=jian_1)
        {
            chushihua();
            system("cls");
            wj_money-=jian_1;
            jian++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
    if(k=='5')
    {
        if(wj_money>=shenjian_1)
        {
            chushihua();
            system("cls");
            wj_money-=shenjian_1;
            shenjian++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
}
void fangyu()
{
    OP:
    system("cls");
    printf("0.返回上界面\n");
    printf("1.返回主界面\n");
    printf("2.帽子 7金币\n");
    printf("3.头盔 21金币\n");
    printf("4.护盾 49金币\n");
    printf("5.盔甲 89金币\n");
    printf("6.圣盾 210金币\n");
    printf("提醒：金币价格与伤害成正比\n");
    char k=getch();
    if(k<'0'||k>'6')
    {
        system("cls");
        goto OP;
    }
    if(k=='0')
    {
        system("cls");
        goumai();
        return;
    }
    if(k=='1')
    {
        system("cls");
        zhujiemian();
        return;
    }
    if(k=='2')
    {
        if(wj_money>=hat_1)
        {
            chushihua();
            system("cls");
            wj_money-=hat_1;
            hat++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        system("cls");
        goto OP;
    }
    if(k=='3')
    {
        if(wj_money>=douhui_1)
        {
            chushihua();
            system("cls");
            wj_money-=douhui_1;
            douhui++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
    if(k=='4')
    {
        if(wj_money>=hudun_1)
        {
            chushihua();
            system("cls");
            wj_money-=hudun_1;
            hudun++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
    if(k=='5')
    {
            chushihua();
        if(wj_money>=hunjia_1)
        {
            system("cls");
            wj_money-=hunjia_1;
            hunjia++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
    if(k=='6')
    {
        if(wj_money>=shendun_1)
        {
            chushihua();
            system("cls");
            wj_money-=shendun_1;
            shendun++;
            goto OP;
        }
        system("cls");
        printf("余额不足！\n");
        getch();
        goto OP;
    }
}
void chushihua()
{
    wj_max_health=hat*hat_1+douhui*douhui_1+hudun*hudun_1+hunjia*hunjia_1+shendun*shendun_1+10;
    wj_shanghai=bishou*bishou_1+caidao*caidao_1+jian*jian_1+shenjian*shenjian_1+1;
}
void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        cout<<a[i];
        Sleep(400);
    }
    getch(); 
    system("cls");
}
int main()
{
    system("title game");
    print("SY出品：打怪小游戏");
    zhujiemian();
    return 0;
}