#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(n) FOR(i, 0, n)
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
typedef vector<string> vs;

template <typename K, typename V>
void print_map(map<K, V> const &m);
template <typename Container>
void print_vector(Container v);
void print_set(si s);

int wins;
int t;

void recur(ssi games, map<int, int> scores)
{
    if (games.size() == 0)
    {
        // cout << "COUNT" << endl;
        //   for (auto x: scores){
        //     cout << x.first << " " << x.second << endl;
        // }
        int win = scores[t];
        int maxi = 0;
        for (auto x : scores)
        {
            if (x.first != t)
            {
                maxi = max(maxi, x.second);
            }
        }
        if (win > maxi)
        {
            wins++;
        }
    }
    else
    {

        for (auto game : games)
        {
            vector<int> teams;
            for (auto team : game)
            {
                teams.PB(team);
            }

            ssi temp = games;
            temp.erase(game);

            // win
            scores[teams[0]] += 3;
            recur(temp, scores);
            scores[teams[0]] -= 3;
            // lose
            scores[teams[1]] += 3;
            recur(temp, scores);
            scores[teams[1]] -= 3;
            //draw
            scores[teams[0]] += 1;
            scores[teams[1]] += 1;
            recur(temp, scores);
            
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int g;
    cin >> t >> g;

    ssi games;
    map<int, int> scores = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};

    FOR(i, 1, 4)
    {
        FOR(x, i + 1, 5)
        {
            si temp;
            temp.insert(i);
            temp.insert(x);
            games.insert(temp);
        }
    }

    REP(g)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        si temp;
        temp.insert(a);
        temp.insert(b);
        games.erase(temp);
        if (c > d)
        {
            scores[a] += 3;
        }
        else if (d > c)
        {
            scores[b] += 3;
        }
        else
        {
            scores[a] += 1;
            scores[b] += 1;
        }
    }

    recur(games, scores);

    // for (auto x: games){
    //     for (auto y: x){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    // for (auto x: scores){
    //     cout << x.first << " " << x.second << endl;
    // }

    cout << wins;

    return 0;
}

template <typename Container>
void print_vector(Container v)
{
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]"
         << "\n";
}

void print_set(si s)
{
    vi v(s.begin(), s.end());
    print_vector(v);
}

template <typename K, typename V>
void print_map(map<K, V> const &m)
{
    for (auto const &pair : m)
    {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}