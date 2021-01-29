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
typedef set<int> si;
typedef set<si> sii;
typedef vector<string> vs;

template<typename K, typename V>
void print_map(map<K,V> const &m);
template<typename Container>
void print_vector(Container v);
void print_set(si s);

int n, k;
LL sol = 0;
// map<int, vector<vector<int>>> mp;
map<int, map<int, map<int, int>>> mp;
int solve(int x, int y, int len){
    if (mp[len][y].find(x) == mp[len][y].end()){
        int sub_len = (2 * len + 2) / 3;
        mp[len][y][x] = max(solve(x, y, sub_len), max(solve(x,y + (len - sub_len),sub_len), solve(x + (len-sub_len), y + (len-sub_len), sub_len)));
        return mp[len][y][x];
    } else{
        return mp[len][y][x];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    // std::ifstream in("test.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt

    cin >> n >> k;


    FOR(i, 0, n){
        vector<int> temp(i+1, -1);
        // FOR(a, 2, n+1){
        //     mp[a].PB(temp);
        // }
        FOR(j, 0, i+1){
            cin >> mp[1][i][j];
        }
        // mp[1].PB(temp);
    }

    FOR(i, 0, n-k+1){
        FOR(j, 0, i+1){
            sol += solve(j, i, k);
        }
    }

    // FOR(i, 1, n+1){
    //     for (auto x: mp[i]){
    //         print_vector(x);
    //     }
    // }
    cout << sol;



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