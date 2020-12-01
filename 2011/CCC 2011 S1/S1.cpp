#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string text = "";

    for (int i = 0; i < n; i++){
        string temp;
        getline(cin, temp);
        text+=temp;
    }
    
    int counterE, counterF = 0;

    counterE += count(text.begin(), text.end(), 't');
    counterE += count(text.begin(), text.end(), 'T');

    counterF += count(text.begin(), text.end(), 's');
    counterF += count(text.begin(), text.end(), 'S');

    if (counterE > counterF){
        cout << "English";
    } else{
        cout << "French";
    }

    return 0;
}