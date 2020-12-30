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
typedef set<si> ssi;
typedef set<pii> sii;
typedef vector<string> vs;

template<typename K, typename V>
void print_map(map<K,V> const &m);
template<typename Container>
void print_vector(Container v);
void print_set(si s);

int n, m;

vector<vector<string>> mp;
vii cameras;
map<pii, int> visited;

void fill_cam(){
    for (auto pair: cameras){
        //UP
        int y = pair.first - 1;
        int x = pair.second;
        while(y >= 0 && mp[y][x] != "W"){
            if (mp[y][x] == "." || mp[y][x] == "S"){
                mp[y][x] = "W*";}
                y--;
            
            
        }

        //DOWN
        y = pair.first + 1;
        x = pair.second;
        while(y < n && mp[y][x] != "W"){
                        if (mp[y][x] == "." || mp[y][x] == "S"){

            mp[y][x] = "W*";}
            y++;
        }

        //LEFT
        y = pair.first;
        x = pair.second - 1;
        while(x >=0 && mp[y][x] != "W"){
                        if (mp[y][x] == "." || mp[y][x] == "S"){

            mp[y][x] = "W*";}
            x--;
        }


        //RIGHT
        y = pair.first;
        x = pair.second + 1;
        while(x < m && mp[y][x] != "W"){
                        if (mp[y][x] == "." || mp[y][x] == "S"){

            mp[y][x] = "W*";}
            x++;
        }
    }

    FOR(y, 0, n){
        FOR (x, 0, m){
            if (mp[y][x] == "W*"){
                mp[y][x] = "W";
            }
            if (mp[y][x] == "C"){
                mp[y][x] = "W";
            }
        }
    }
}

pii conveyor(pii point){
    if (visited.find(point) == visited.end()){
        if (mp[point.first][point.second] == "."){
            return point;
        } else if (mp[point.first][point.second] == "W"){
            return MP(-1,-1);
        }else{
            
            visited[point] = -1;
            // UP
            if (mp[point.first][point.second] == "U"){
                return conveyor(MP(point.first-1, point.second));
            }


            // DOWN
            if (mp[point.first][point.second] == "D"){
                return conveyor(MP(point.first+1, point.second));

            }

            // LEFT
            if (mp[point.first][point.second] == "L"){
                return conveyor(MP(point.first, point.second - 1));
            }

            // RIGHT
            if (mp[point.first][point.second] == "R"){
                return conveyor(MP(point.first, point.second + 1));
            }

        }
    } else{
        return MP(-1, -1);
    }
    
}



void recur(sii points, int steps){

    // cout << steps;
    sii next_points;


    for (auto point: points){
        // cout << point.first << point.second << endl;

        if (visited.find(point) != visited.end()){
            visited[point] = min(visited[point], steps);
        } else{
            visited[point] = steps;
        }

        // UP
        if (point.first - 1 >= 0 && mp[point.first - 1][point.second] != "W"){

            pii temp = conveyor(MP(point.first - 1, point.second));
            if (temp.first != -1 && temp.second != -1){
                if (visited.find(temp) == visited.end()){
                    next_points.insert(temp);
                }
            }
            
        }

        // DOWN
        if (point.first + 1 < n && mp[point.first + 1][point.second] != "W"){
            pii temp = conveyor(MP(point.first + 1, point.second));
            if (temp.first != -1 && temp.second != -1){
                if (visited.find(temp) == visited.end()){
                    next_points.insert(temp);
                }
            }
        }

        // LEFT
        if (point.second - 1 >= 0 && mp[point.first][point.second - 1] != "W"){
            pii temp = conveyor(MP(point.first, point.second - 1));
            if (temp.first != -1 && temp.second != -1){
                if (visited.find(temp) == visited.end()){
                    next_points.insert(temp);
                }
            }
        }

        // RIGHT
        if (point.second + 1 < m && mp[point.first][point.second + 1] != "W"){
            pii temp = conveyor(MP(point.first, point.second + 1));
            if (temp.first != -1 && temp.second != -1){
                if (visited.find(temp) == visited.end()){
                    next_points.insert(temp);
                }
            }
        }
    }

    if (next_points.size() > 0){
        // for (auto x: next_points){
        //     cout << "CALCULATION: " << x.first << " " << x.second << endl;
        // }
    recur(next_points, steps+1);
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    vii orders;
    pii start;

    REP(n){
        string temp;
        cin >> temp;
        mp.PB(vector<string>(m));
        FOR(a, 0, temp.size()){
            mp[i][a] = temp[a];
            if (temp[a] == '.'){
                orders.PB(MP(i,a));
            }
            if (temp[a] == 'S'){
                start = MP(i,a);
            }
            if (temp[a] == 'C'){
                cameras.PB(MP(i,a));
            }
        }
    }

    fill_cam();

    // for (auto x: mp){
    //     print_vector(x);
    // }

    // for (auto x: visited){
    //     cout << x.first.first << " " << x.second;
    // }

    sii temp;
    temp.insert(start);

    visited[start] = 0;
    if (mp[start.first][start.second] == "W"){
        for (auto x: orders){
            cout << "-1" << endl;
        }
        return 0;
    }
    recur(temp, 0);
    
    // for (auto x: visited){
    //     cout << x.first.first << " " << x.first.second << ": " << x.second << endl; 
    // }

    for (auto x: orders){
        if (visited.find(x) != visited.end()){
            cout << visited[x] << endl;
        } else{
            cout << "-1" << endl;
        }
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