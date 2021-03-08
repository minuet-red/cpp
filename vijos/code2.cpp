#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    string name;
    int score1, score2;
    //string flag1, flag2;
    char flag1, flag2;
    int num_thesis;
    int money = 0;
    string result_name;
    int result_money = 0, result_sum = 0;

    cin >> num;
    for(int i=1; i <= num; i++){
        cin >> name 
            >> score1
            >> score2
            >> flag1
            >> flag2
            >> num_thesis; 
        money = 0;
        if((score1>80)&&(num_thesis>0)){
            money += 8000;
        }       
        if((score1>85)&&(score2>80)){
            money += 4000;
        }
        if(score1>90){
            money += 2000;
        }
        if((score1>85)&&(flag2 == 'Y')){
            money += 1000;    
        }
        if((score2>80)&&(flag1 == 'Y')){
            money += 850;
        }
        if(money > result_money){
            result_money = money; 
            result_name = name;
        }
        result_sum += money;
    } 

    cout << result_name << endl
         << result_money << endl
         << result_sum << endl;

    system("pause");
    return 0;
}