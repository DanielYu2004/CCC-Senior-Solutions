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

unordered_map<int,unordered_map<int,int>> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t;
    int m = 0;
    int mm = 0;
    cin >> n >> t;

    REP(n){
        int x, y, xx, yy, t;
        cin >> x >> y >> xx >> yy >> t;
        m = max(m, max(x, xx));
        mm = max(mm, max(y, yy));
        
        if (xx > x){
            FOR(i, x, xx){
                if (yy > y){
                    FOR(j, y, yy){
                        // cout << i << " " << j << endl;
                        mp[i][j] += t;
                    }
                }
            }
        } else{
            FOR(i, xx, x){
                if (y > yy){
                    FOR(j, yy, y){
                        // cout << i << " " << j << endl;
                        mp[i][j] += t;
                    }
                }
            }
        }
    }

    int sol = 0;

    for (auto x: mp){
        for (auto y: x.second){
            if (y.second >= t){
                sol++;
                // cout << x.first << " " << y.first << endl;
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

// To read from text file snippet
//
// std::ifstream in("in.txt");
// std::streambuf *cinbuf = std::cin.rdbuf();
// std::cin.rdbuf(in.rdbuf()); 