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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    // This solution always places a firehydrant as far away from the first house in the positive direction
    // so it does not consider the cases of negative looparound, which my be why it only gets 14/15

    int h, k;

    cin >> h;

    vi houses(h);

    REP(h){
        cin >> houses[i];
    }

    cin >> k;
    sort(houses.begin(), houses.end());

    // print_vector(houses);
    deque<int> dequee;
    FOR(i, 0, houses.size()){
        dequee.PB(houses[i]);
    }

    int length = 1000000;

    FOR(radius, 1, 1000000){
        deque<int> local_deque = dequee;
        int local_k = k;

        while(local_k > 0){
            if (local_deque.empty()){
                break;
            }
            int first = local_deque.front();
            while(first + radius + radius >= local_deque.front() && !local_deque.empty()){
                // cout << local_deque.front() << " ";
                local_deque.pop_front();
            }
            // while(first - radius + 1000000 <= local_deque.back()){
            //     local_deque.pop_back();
            // }
            local_k--;
        }

        // cout << local_deque.size();

        if (local_deque.empty()){
            length = radius;
            break;
        }
        // cout << endl;
        // cout << local_deque.size() << endl;
        // cout << local_deque.size() << endl;

    }


    cout << length;


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