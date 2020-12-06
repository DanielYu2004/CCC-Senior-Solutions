#include <bits/stdc++.h>

using namespace std;

int factorial(long long a){
    if (a <= 1){
        return 1;
    } else{
        return a * factorial(a-1);
    }
}

int choose(int a, int b){
    cout << factorial(90);
    cout << factorial(a) / (factorial(b) * factorial(a-b));
    return factorial(a) / (factorial(b) * factorial(a-b));
}

int main(){
    long long num; 
    cin >> num;

    if (num < 4){
        cout << 0;
    }

    cout << factorial(num);

    // cout << choose(num, 4);

    return 0;
}