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
typedef set<pii> sii;
typedef vector<string> vs;

template<typename K, typename V>
void print_map(map<K,V> const &m);
template<typename Container>
void print_vector(Container v);
void print_set(si s);
void p(vector<vector<set<pii, PairCmp>>>> att);


void display(priority_queue <pii, vector<pii>, greater<pii>> a); 

void recur(priority_queue<pii, vector<pii>, greater<pii>> q, int hull, vector<bool> visited, vi distances){
   
    cout << "RECURSION: " << endl;
    cout << "QUEUE: "; display(q);
    cout << "HULL: " << hull << endl; 
    cout << "VISITED: "; print_vector(visited);
    cout << "DISTANCES: "; print_vector(distances);
    
    pii a = q.top();
    q.pop();
    int node, next_d = a.first; a.second;


}

using pair_type = std::pair<int, int>;
struct PairCmp
{
    bool operator()(const pair_type& lhs, const pair_type& rhs) const
    { 
        return lhs.first < rhs.first; 
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    std::ifstream in("text.in");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf()); 

    int k, n, m;
    cin >> k >> n >> m;

    vector<si> graph(n+1);

    using pair_type = std::pair<int, int>;

    vector<vector<sii>> att(n + 1, vector<set<pii, PairCmp>>(n+1));

    REP(m){
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        graph[a].insert(b);
        graph[b].insert(a);

        att[a][b].insert(MP(t, h));
        att[b][a].insert(MP(t, h));
    }

    int start, end;
    cin >> start >> end;

    for (auto x: graph){
        print_set(x);
    }

    p(att);




    priority_queue<pii, vector<pii>, greater<pii>> q;
    vi distances(n + 1, 1000000000); // change million
    distances[start] = 0;
    vector<bool> visited(n+1);
    q.push(MP(0, 0));   

    recur(q, k, visited, distances);

    return 0;
}




void display(priority_queue <pii, vector<pii>, greater<pii>> a) 
{ 
    priority_queue <pii, vector<pii>, greater<pii>> c = a; 
    while (!c.empty()) 
    { 
        cout << "{" << c.top().first << ", " << c.top().second << "}" << '\n'; 
        c.pop(); 
    } 
} 

void p(vector<vector<sii>> att){
    for (auto x: att){
        for (auto y: x){
            for (auto p: y){
                cout << "{" << p.first << ", " << p.second << "}  ";
            }
            
        }
        cout << endl;
    }
}


template<typename Container>
void print_vector(Container v){
    if (v.size() > 0){
        cout << "[" ;
        for (int i = 0; i < v.size() - 1; i++){
            cout << v[i] << ", ";
        }
        cout << v[v.size() - 1] << "]" << "\n";
    } else{
        cout << "[]" << "\n";
    }
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