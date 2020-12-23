#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cin >> n;

    if (n < 4){
        cout << 0;
    } else{
        cout << ((n-3) * (n-2) * (n-1))/6;
    }

    

    return 0;
}