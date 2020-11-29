#include <bits/stdc++.h>

using namespace std;

int calculate(int& a, int& b, int& c){
    return 2 * a + 3 * b + c;
}

int main(){
    int n;
    cin >> n;

    if (n == 1){
        string name;
        cin >> name;
        cout << name;
        return 0;
    } else if(n == 0){
        return 0;
    }
    vector<string> names(n);
    vector<int> ram(n);
    vector<int> cpu(n);
    vector<int> disk(n);

    string first;
    string second;

    int first_sum = 0;
    int second_sum = 0;

    for (int i = 0; i < n; i++){
        cin >> names[i] >> ram[i] >> cpu[i] >> disk[i];
        int local = calculate(ram[i], cpu[i], disk[i]);
        // cout << local << "\n";
        if (local > first_sum){
            second_sum = first_sum;
            second = first;

            first = names[i];
            first_sum = local;
        } else if(local == first_sum){
            if (names[i] < first){
                second == first;
                first = names[i];
            } else{
                second = names[i];
            }
        } else if (local > second_sum){
            second = names[i];
            second_sum = local;
        } else if(local == second_sum){
            if (names[i] < second){
                second = names[i];
            }
        }
    }

    cout << first << "\n" << second;

    
    return 0;
}
