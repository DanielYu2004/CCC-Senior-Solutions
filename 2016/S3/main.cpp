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


map<pii, int> pairs;
map<int, si> tree;

set<vi> perms;

void recur(si available, vi current)
{
    // if (!available.empty()){
    if (available.size() > 0)
    {

        for (int x : available)
        {
            si next_avai = available;
            next_avai.erase(x);

            // // print_set(next_avai);
            // // print_vector(next_cur);

            // recur(next_avai, next_cur);
            current.PB(x);

            // print_set(next_avai);
            // print_vector(next_cur);

            recur(next_avai, current);
            current.pop_back();
        }
    }
    else
    {
        // print_vector(current);
        perms.insert(current);
    }
}

void bfs(si points, si &visited, int steps, pii target){
    si next_points;
    // cout << "STEPS: " << steps << endl;
    for (auto point: points){
        // cout << point << endl;
        if (point == target.second){
            // cout << "ANSWER: " << steps << endl;
            pairs[target] = steps;
            return; 
        }else{
            for (auto x: tree[point]){
                if (visited.find(x) == visited.end()){
                    next_points.insert(x);
                }
            }
        }
        visited.insert(point);
    }
    steps++;
    bfs(next_points, visited, steps, target);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vi pho(m);
    REP(m){
        cin >> pho[i];
    }

    REP(n-1){
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }


    FOR(a, 0, m-1){
        FOR(b, a+1, m){
            pairs[MP(pho[a], pho[b])] = 0;
            pairs[MP(pho[b], pho[a])] = 0; // Remove
        }
    }

    // for (auto x: pairs){
    //     cout << x.first.first << " " << x.first.second << endl;
    // }

    for (auto pair: pairs){
        si visited = {};
        si start;
        start.insert(pair.first.first);
        bfs(start, visited, 0, pair.first);
    }

    // for (auto x: pairs){
    //     cout << x.first.first << x.first.second << " " << x.second;
    // }    
    recur(si(pho.begin(), pho.end()), {});

    int mini = INT_MAX;

    for (auto perm: perms){
        int score = 0;
        FOR(i, 0, perm.size() - 1){
            score+=pairs[MP(perm[i], perm[i+1])];
        }
        mini = min(mini, score);
    }

    cout << mini;




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