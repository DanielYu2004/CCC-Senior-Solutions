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

vector<bool> visited(10000001);
vector<bool> visitedd(10000001);
string sol = "unknown";
int startt, endd;
unordered_map<int, vi> taller, shorter;

void recur(queue<int> nums){
    while (!nums.empty()){
        int num = nums.front();
        nums.pop();
        if (visited[num] == false){
            visited[num] = true;
            for (auto& next: taller[num]){
                if (visited[next] == false){
                    nums.push(next);
                }
            }
        }
    }
}

void recurr(queue<int> nums){
    while (!nums.empty()){
        int num = nums.front();
        nums.pop();
        if (visitedd[num] == false){
            visitedd[num] = true;
            for (auto& next: shorter[num]){
                if (visitedd[next] == false){
                    nums.push(next);
                }
            }
        }
    }
   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    FOR(i, 0, m){
        int x, y;
        cin >> x >> y;
        taller[x].PB(y);
        shorter[y].PB(x);
    }

    cin >> startt >> endd;

    queue<int> temp;
    temp.push(startt);

    recur(temp);
    if (visited[endd] == true){
        sol = "yes";
    } 
    if (sol != "yes"){
        recurr(temp);
    }
    
    if (visitedd[endd] == true){
        sol = "no";
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