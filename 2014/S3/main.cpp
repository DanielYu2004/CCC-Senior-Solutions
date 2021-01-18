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

void solve(){
    int n;
    cin >> n;

    stack<int> branch;
    stack<int> mountain;

    REP(n){
        int num;
        cin >> num;
        mountain.push(num);
    }

    int target = 1;

    while(target != n+1){
        // cout << "TARGET: " << target << endl;
        // cout << mountain.top() << " " << branch.top() << endl;
        if (mountain.empty()){
            if (branch.top() == target){
                branch.pop();
                target++;
            } else{
                cout << "N" << endl;
                break;
            }
        }
        else if (mountain.top() == target){
            mountain.pop();
            target++;
        } else if (!branch.empty() && branch.top() == target){
            branch.pop();
            target++;
        } else if (!mountain.empty()){
            branch.push(mountain.top());
            mountain.pop();
        } else{
            cout << "N" << endl;
            break;
        }
    }

    if (target == n+1){
        cout << "Y" << endl;
    }



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    REP(t){
        solve();
    }

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