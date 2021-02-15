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

vvi tree;
vvi graph;
vi pho;
vector<bool> phoc;
vi visited;

int total;
int diameter;

bool dfs(int cur, int prev){
    vi ng;
    bool r = false;
    for (auto node: graph[cur]){
        if (node != prev){
            if(dfs(node, cur)){
                r = true;
                ng.PB(node);
            }
        }
    }

    if (phoc[cur]){
        r = true;
    }

    if (r){
        if (prev != -1){
            ng.PB(prev);
        }
        graph[cur] = ng;
        total+=ng.size();
    } else{
        graph[cur] = {};
    }
    


    return r;
}

si bfs(si nodes, int depth){
    si next_nodes;
    for (auto node: nodes){
        if (visited[node] == false){
            visited[node] = true;
            for (auto next_node: graph[node]){
                if (nodes.find(next_node) == nodes.end() && visited[next_node] == false){
                    // visited[next_node] = true;
                    next_nodes.insert(next_node);
                }
            }
        }
        
    }
    
    // print_set(next_nodes);

    if (next_nodes.size() == 0){
        diameter = depth;
        return nodes;
    } else{
        return bfs(next_nodes, depth+1);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    graph.resize(n);
    phoc.resize(n);
    visited.resize(n);

    REP(m){
        int temp;
        cin >> temp;
        pho.PB(temp);
        phoc[temp] = true;
    }

    REP(n - 1){
        int a, b;
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    tree.resize(n);

    dfs(pho[0], -1);

    // for (auto x: graph){
    //     print_vector(x);
    // }

    // visited[0] = true;
    
    
    si temp = bfs({pho[0]}, 0);

    int next;
    for (auto x: temp){
        next = x;
    }

    vi temp_visited(n);
    visited = temp_visited;

    // cout << "DIAMTER:  jdoifsajo9isdjf" << endl;
    // cout << "NEXT: " << next;
    bfs({next}, 0);

    // cout << "TOTAL: " << total << endl;
    // cout << "DIAMTER: " << diameter << endl;
    cout << total - diameter;






    return 0;
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