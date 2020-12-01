#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int score = 0;

    vector<string> res(n);
    vector<string> ans(n);

    for (int i = 0; i < n; i++){
        cin >> res[i];
    }

    for (int i = 0; i < n; i++){
        cin >> ans[i];
        if (ans[i] == res[i]){
            score++;
        }
    }

    cout << score;

    return 0;
}