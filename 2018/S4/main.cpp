#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define REP(n) FOR(i,0,n)
#define endl "\n";

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
typedef set<int> si;
typedef set<si> sii;
typedef vector<string> vs;

template<typename K, typename V>
void print_map(map<K,V> const &m);
template<typename Container>
void print_vector(Container v);
void print_set(si s);


// unordered_map<ll, ll> mem;
vl mem;


ll recur(ll n){
    if(n == 1 || n == 2){
        return 1;
    } else if (mem[n] != 0){
        return mem[n];
    } else{
        ll sum = 0;

        FOR(k, 2, n+1){
            // cout << n << " " << k;
            // cout << n/k << endl; 
            ll d = n/k;

            if (mem[n] != 0){
                sum+=mem[d];
            } else{
                sum+=recur(d);
            }
        }

        mem[n] = sum;
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    mem.resize(n + 1);

    cout << "HI";

    // cout << recur(n);


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