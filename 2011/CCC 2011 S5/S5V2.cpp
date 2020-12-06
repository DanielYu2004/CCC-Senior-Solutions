#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int>);
set<vector<int>> visited;

bool is_off(vector<int> &array)
{
    for (int x : array)
    {
        if (x != 0)
        {
            return false;
        }
    }
    return true;
}

void convert(vector<int> &array)
{
    for (int i = 0; i < array.size() - 3; i++)
    {
        if (array[i] == array[i + 1] && array[i] == array[i + 2] && array[i] == array[i + 3] && array[i] == 1)
        {
            for (int t = 0; t < array.size() - i; t++){
                if (array[i+t] == 1){
                    array[i+t] = 0;
                } else{
                    break;
                }
                
            }
        }
    }
}

pair<vector<vector<int>>, int> recur(vector<vector<int>> parent_array, int steps){

    vector<vector<int>> next_array;

    for (auto arr : parent_array){
        convert(arr);
        if (visited.find(arr) == visited.end()){ // if it does not exist
            visited.insert(arr);
            if (is_off(arr))
            {
                pair <vector<vector<int>>,int> product2 ({{1,2}}, steps);
                return product2;
            }
            else{

                for (int i = 0; i < arr.size(); i++){
                    if (arr[i] == 0){
                        vector<int> temp = arr;
                        temp[i] = 1;
                        if (visited.find(temp) == visited.end() && (find(next_array.begin(), next_array.end(), arr) == next_array.end())){
                            next_array.push_back(temp);
                        }
                    }
                }
            }
        }
    }

    // for (auto x : next_array){
    //     print_vector(x);
    // }

    return recur(next_array, steps + 1);
};




int main(){
    int n;
    cin >> n;

    vector<int> lights(n);

    for (int i = 0; i < n; i++){
        cin >> lights[i];
    }

    // cout << (recur({lights}, 0)).second();
    pair<vector<vector<int>>, int> sol = recur({lights}, 0);
    cout << sol.second;

    return 0;
}





void print_vector(vector<int> arr){
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << "\n";
}