#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(n) FOR(i,0,n)
#define endl "\n";

typedef long long LL; 
typedef pair<int, int> pii; 
typedef pair<LL, LL> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<LL> vl; 
typedef vector<vl> vvl; 
typedef unordered_set<int> si;
typedef set<si> sii;
typedef vector<string> vs;

template<typename K, typename V>
void print_map(map<K,V> const &m);
template<typename Container>
void print_vector(Container v);
void print_set(si s);


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<int, int> boards;

    int n;
    cin >> n;

    FOR(i, 1, 2001){
        boards[i] = 0;
    }

    REP(n){
        int temp;
        cin >> temp;

        boards[temp]++;

    }
    
    unordered_map<int,int> mp;

    FOR(i, 1, 4001){
        mp[i] = 0;
    }

    for (auto a: mp){
       for (auto board1: boards){
            if (a.first - board1.first > 0){
                mp[a.first] += min(boards[board1.first], boards[a.first - board1.first]);
            }
           
       }
    }
    
    int longest = 0;
    int num_longest = 0;

    for (auto a: mp){
        int value = a.second;
        if (value > longest){
            num_longest = 1;
            longest = value;
        } else if (value == longest){
            num_longest++;
        }
    }

    cout << longest/2 << " " << num_longest;

    // print_map(mp);

    return 0;
}

template<typename Container>
void print_vector(Container v){
    cout << "[" ;
    for (int i = 0; i < v.size() - 1; i++){
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]" << "\n";
}

void print_set(si s){
    vi v(s.begin(), s.end());    
    print_vector(v);
}

template<typename K, typename V>
void print_map(map<K,V> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}