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
typedef set<si> sii;
typedef vector<string> vs;

template <typename K, typename V>
void print_map(map<K, V> const &m);
template <typename Container>
void print_vector(Container v);
void print_set(si s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int g, p;
    cin >> g >> p;

    vector<int> gates;
    vector<int> planes(p);
    REP(p)
    {
        cin >> planes[i];
    }

    // gates
    FOR(i, 0, g + 1)
    {
        gates.PB(i);
    }

    int count = 0;

    unordered_set<int> banned;

    for (auto plane : planes)
    {
        if (plane == gates[plane])
        {
            count++;
            gates[plane] = gates[plane - 1];
        }
        else if (gates[plane] == 0)
        {
            break;
        }
        else
        {
            if (banned.find(plane) == banned.end() && banned.find(gates[gates[plane]]) == banned.end()) // idk about this one
            {
                count++;
                gates[plane] = gates[gates[plane] - 1];
                if (gates[gates[plane] - 1] == 0)
                {
                    banned.insert(plane);
                }
            }
            else
            {
                break;
            }
        }
    }

    cout << count;

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