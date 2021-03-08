#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int school1, school2;
    int high = 0, day = 0;
    int value;

    for(int i = 1; i <= 7; i++){
        cin >> school1 >> school2; 
        value = school1 + school2;
        if(value > 8 && value > high){
            high = value;
            day = i;
        }
    }
    if(high > 8){
        cout << day << endl;
    }
    else{
        cout << 0 << endl;
    }

    system("pause");
    return 0;
}

// int main(){
//     int school1, school2;
//     int flag = 0, high = 0, day = 0;

//     for(int i = 1; i <= 7; i++){
//         cin >> school1 >> school2;
//         int value = 0; 
//         value = school1 + school2;
//         if(value > 8){
//             flag = 1;
//         }
//         if(value > high){
//             high = value;
//             day = i;
//         }
//     }
//     if(flag!=0){
//         cout << day << endl;
//     }
//     else{
//         cout << flag << endl;
//     }

//     system("pause");
//     return 0;
// }