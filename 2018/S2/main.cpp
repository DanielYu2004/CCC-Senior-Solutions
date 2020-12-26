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

int n;

vvi rotate(vvi v)
{
    vvi r(n);

    FOR(i, 0, n)
    {
        FOR(a, 0, n)
        {
            r[i].PB(v[n - a - 1][i]);
        }
    }
    return r;
}

void p(vvi v)
{
    REP(n)
    {
        for (auto x : v[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

bool check(vvi v)
{
    bool y = true;
    for (auto x : v)
    {
        FOR(i, 0, n - 1)
        {
            if (!(x[i] < x[i + 1]))
            {
                y = false;
                break;
            }
        }
    }

    REP(n - 1)
    {
        if (!(v[i][0] < v[i + 1][0]))
        {
            y = false;
        }
    }

    if (y == true)
    {
        p(v);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vvi v(n);

    FOR(i, 0, n)
    {
        FOR(j, 0, n)
        {
            int temp;
            cin >> temp;
            v[i].PB(temp);
        }
    }

    while (!check(v))
    {
        v = rotate(v);
    }

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