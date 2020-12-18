#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<long long> vii; 

int main(){
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maxi = v[2] - v[0];

    for (int i = 1; i < n-2; i++){
        // cout << v[i] << " " << v[i+2] << "\n";
        // cout << v[i+2] - v[i];
        maxi = min(maxi, v[i+2] - v[i]);
    }

    if (maxi % 2 == 0){
        cout  << fixed << maxi/2 << ".0";
    } else{
        cout << fixed << setprecision(1) << (float)maxi/2.0;
    }

    // if (maxi == (int)maxi){
    //     cout << (int)(maxi/2.0) << ".0";
    // } else{
    //     cout << maxi/2;
    // }

    // cout << setprecision(2);

    // cout << maxi;
    
    return 0;
}