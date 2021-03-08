#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    double L, V;
    double S, T;
    
    cin >> L >> V;
    T = L / V * 2/3;
    S = L * 2/3;
    cout << setiosflags(ios::fixed) 
    <<setprecision(1) <<std::fixed
    << S << endl << T << endl;

    system("pause");
    return 0;
}