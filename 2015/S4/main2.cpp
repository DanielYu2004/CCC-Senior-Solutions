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

struct THREE
{
    int m_n1;
    int m_n2;
    int m_n3;

    THREE(int n1, int n2, int n3) : m_n1(n1), m_n2(n2), m_n3(n3)
    {
    }

    bool operator<(const struct THREE& other) const
    {
        //Your priority logic goes here
        return m_n2 > other.m_n2;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;

    vvi graph(n+1);

    vector<vector<vii>> paths(n+1, vector<vii>(n+1));

    REP(m){
        int a, b, t, h;
        cin >> a >> b >> t >> h;

        graph[a].PB(b);
        graph[b].PB(a);
        paths[a][b].PB(MP(t, h));
        paths[b][a].PB(MP(t, h));
    }

    int start, end;
    cin >> start >> end;


    vvi distance(n+1, vi(k, INT_MAX));
    distance[start][0] = 0;
    vector<vector<bool>> visited(n+1, vector<bool>(k)); // [node][hull]
    priority_queue<THREE> q;
    q.push(THREE(start,0,0));


    while(!q.empty()){
    // FOR(i, 0, 3){

        THREE top = q.top();
        q.pop();

        int node = top.m_n1;
        int weight = top.m_n2;
        int hull = top.m_n3;

        // cout << "WEIGHT: " <<  weight << " NODE: " << node << " HULL: " << hull << endl;
        // cout << node << " " << weight << " " << hull << endl;

        if (visited[node][hull] == true) continue;
        for (auto next_node: graph[node]){
            visited[node][hull] = true;
            // FOR(i, 1, n+1){
            for (auto next: paths[next_node][node]){
                int next_weight = next.first; 
                int next_hull = next.second;
                // cout << "FROM: " << node << " TO: " << next_node << " IN: " << next_weight << " " << next_hull << endl;
                if (hull + next_hull < k && distance[next_node][hull + next_hull] > weight + next_weight){
                    distance[next_node][hull + next_hull] = weight + next_weight;
                    q.push(THREE(next_node, weight + next_weight, hull + next_hull));
                    // cout << next_node << " " << weight + next_weight << " " << hull + next_hull << endl;
                }
            }
            // }
        }
    }

    // for (auto x: distance){
    //     print_vector(x);
    // }
    int mini = INT_MAX;

    FOR(i, 0, k){
        if (distance[end][i] != INT_MAX){
            mini = min(mini, distance[end][i]);
        }
    }
    if (mini == INT_MAX){
        cout << "-1";
    } else{
        cout << mini;
    }
    

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