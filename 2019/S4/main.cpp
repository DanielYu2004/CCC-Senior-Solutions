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



int calc(vvi &dp, vi &attraction, int i, int index, int k){
    int maxx = 0;
    int local_max = attraction[index];
    FOR(a, 1, k + 1){
        local_max = max(local_max, attraction[index - a + 1]);
        if (index - a >= 0 ){
            if (dp[i-1][index - a] != 0){
                maxx = max(maxx, dp[i-1][index - a] + local_max);
            }
        } else{
            break;
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    std::ifstream in("s4.1-05.in");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt

    int n, k;
    cin >> n >> k;

    vi attraction(n);
    REP(n){
        cin >> attraction[i];
    }

    int days = ceil(n/(float)k);
                                                       
    vvi dp(days, vi(n, 0));

    // dp[0][0] = 2;
    // dp[0][1] = 5;
    // dp[0][2] = 7;

    int local_max = attraction[0];
    FOR(i, 0, k){
        local_max = max(local_max, attraction[i]);
        dp[0][i] = local_max;
    }


    int start = 0;
    int end = k;
    FOR(i, 1, days){
        // cout << i << endl;
        int index = start + 1;
        while(index < end + k && index < n && ((days-i)*k) + index >= n){
            dp[i][index] = calc(dp, attraction, i, index, k);
            cout << dp[i][index] << endl;
            index++;
        }
        start++;
        end+=k;
    }

    // for (auto x: dp){
    //     print_vector(x);
    // }

    cout << dp[days - 1][n-1];
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