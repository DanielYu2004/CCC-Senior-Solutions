#include <bits/stdc++.h>

using namespace std;

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

int main(){
    int n;
    cin >> n;

    vector<vector<int>> array(n);

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a;
        cin >> b;
        array[i] = vector<int>(2);
        array[i][0] = a;
        array[i][1] = b;
    }
    sort(array.begin(), array.end(), sortcol); 

    double max_speed = 0;

    for (int i = 0; i < array.size() - 1; ++i){
        // cout << array[i][1] - array[i+1][1] << " " << array[i+1][0] - array[i][0] << "\n";
        // cout << abs(array[i][1] - array[i+1][1]) / (array[i+1][0] - array[i][0] ) << "\n";
        max_speed = max(max_speed, ((double)abs(array[i][1] - array[i+1][1]) / abs(array[i+1][0] - array[i][0] )));
    }

    cout << max_speed;

    return 0;
}