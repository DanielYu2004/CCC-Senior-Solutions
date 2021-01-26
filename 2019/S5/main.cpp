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

unordered_map<int, map<pii, int>> mp;
vvi v;
ll sol = 0;

int calcLenTwo(int x, int y){
    int m = 0;
    m = max(v[y][x], max(v[y+1][x], v[y+1][x+1]));
    return m;
}

int calc(int x, int y, int len){
    int prev = max(mp[len-1][MP(y,x)], max(mp[len-1][MP(y-1,x)], mp[len-1][MP(y-1, x-1)]));
    sol+=prev;
    return prev;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // std::ifstream in("test.txt");
    // std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt

    int n, k;
    cin >> n >> k;


    REP(n){
        vi temp(i + 1);
        FOR(a, 0, i + 1){
            cin >> temp[a];
            // sol+=temp[a];
        }
        v.PB(temp);
    }

    if (k == 1){
        cout << sol;
        return sol;
    }

    // base calcs
    FOR(y, 0, n - 2 + 1){
        FOR(x, 0, y+1){
            int temp = calcLenTwo(x,y);
            mp[2][MP(y,x)] = calcLenTwo(x, y);
            sol+=temp;
        }
    }

    FOR(i, 3, k+1){
        FOR(y, 0, n-i+1){
            FOR(x, 0, y+1){
                // cout << "PAIR: " << x << " " << y << endl;
                int temp = calc(x, y, i);
                mp[i][MP(y,x)] = temp;
                // sol+=temp;
            }
        }
    }

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