#include <bits/stdc++.h>

using namespace std;

// use strings maybe?

map<vector<int>, int> mem;
int maxi = 0;


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

void print_vector(vector<int>);


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

void print_vector(vector<int> arr){
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[arr.size() - 1] << "]" << "\n";
}

int recurse(vector<int> array, int steps)
{

    convert(array);
    
    if ((mem.find(array) == mem.end() || mem[array] > steps) && steps <= maxi){

        mem[array] = steps;
        
        if (is_off(array))
        {
            return steps;
        }
        else
        {

            vector<vector<int>> next_array;
            
            int answer = numeric_limits<int>::max();


            for (int i = 0; i < array.size(); i++){
                if (array[i] == 0){
                    vector<int> temp = array;
                    temp[i] = 1;
                    if ((mem.find(temp) == mem.end() || mem[temp] > steps) && steps <= maxi){
                        next_array.push_back(temp);
                    }
                }
            }


            for (auto x : next_array){
                
                answer = min(answer, recurse(x, steps + 1));
            }

            return answer;
            // vector<int> answers = {};
            // // cout << "ARRAY IS: ";
            // // print_vector(array);
        
            // for (int i = 0; i < array.size(); i++){
            //     if (array[i] == 0){
            //         vector<int> temp = array;
            //         temp[i] = 1;
                    
                    
            //         if (!mem.count(temp)){
            //             // cout << "ORIGINAL" << "\n";
            //             // print_vector(array);
            //             // print_vector(temp);
            //             // cout << steps;
            //             answers.push_back(recurse(temp, steps + 1));
            //         }
            //     }   
            // }
            // // print_vector(answers);
            // if (answers.size() == 0){
            //     return numeric_limits<int>::max();
            // } else{
            //     return *min_element(answers.begin(), answers.end());
            // }

            
        }
    } else{
        return numeric_limits<int>::max();
    }
    
}


int main()
{
    int n;
    cin >> n;

    vector<int> lights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lights[i];
        if (lights[i] == 0){
            maxi++;
        }
    }

    cout << recurse(lights, 0);


    return 0;
}