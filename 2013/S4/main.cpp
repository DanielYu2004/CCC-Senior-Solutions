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

si visited;
si visitedd;
string sol = "unknown";
int startt, endd;
map<int, si> taller, shorter;

void recur(si nums){
    si next_nums;
    if (nums.size() > 0){
        for (auto num: nums){
            if (visited.find(num) == visited.end()){
                visited.insert(num);
                for (auto next: taller[num]){
                    if (next == endd){
                        visited.insert(next);
                        sol = "yes";
                        return;
                    } else{
                        next_nums.insert(next);
                    }
                }
            }
        }
        recur(next_nums);
    }
    
}

void recurr(si nums){
    si next_nums;
    if (nums.size() > 0){
         for (auto num: nums){
            if (visitedd.find(num) == visitedd.end()){
                visitedd.insert(num);
                for (auto next: shorter[num]){
                    if (next == endd){
                        visitedd.insert(next);
                        sol = "no";
                        return;
                    } else{
                        next_nums.insert(next);
                    }
                }
            }
        }
        recurr(next_nums);
    }
   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    std::ifstream in("s4.6-1.in");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf()); 

    int n, m;
    cin >> n >> m;


    FOR(i, 0, m){
        int x, y;
        cin >> x >> y;
        taller[x].insert(y);
        shorter[y].insert(x);
    }

    cin >> startt >> endd;

    si temp;
    temp.insert(startt);

    recur(temp);
    if (sol != "yes"){
        recurr(temp);
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