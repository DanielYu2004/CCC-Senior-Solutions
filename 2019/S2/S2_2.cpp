#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num)
{
    for (int a = 2; a <= sqrt(num); ++a)
    {
        if (num % a == 0)
            return false;
    }

    return true;
}


void solve(int target){
    target = target * 2;
    for (int i = 3; i < target/2; i++){
        if (isPrime(i) && isPrime(target-i)){
            cout << i << " " << target - i << "\n";
            break;
        }
    }
}

int main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        solve(temp);
    }



    return 0;
}