#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> arr){
    cout << "[";
    for (auto x : arr){
        cout <<  x << ", ";
    }
    cout << "]";
}

int main(){
    int h, k;
    
    cin >> h;
    vector<int> houses(h);

    for (int i = 0; i < h; i++){
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());



    for (int radius = 1; radius <= 1000000; radius++){
        int pointer = 0;
        int hydrants = 1;
        for (int i = pointer + 1; i < houses.size(); i++){
            if (houses[i] > houses[pointer] + radius){

                for (int x = i + 1; x < houses.size(); x++){
                    if (houses[x] > houses[pointer] + radius + radius){
                        pointer = x-1;
                        hydrants++;
                        break;
                    }
                }
                break;


            }
        }
        cout << hydrants << "\n";

    }

    // print_vector(houses);


}