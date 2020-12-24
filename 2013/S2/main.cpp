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

template <typename Container>
void print_vector(Container v);
void print_set(si s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max, n;
    cin >> max >> n;
    vi v(n);

    REP(n)
    {
        cin >> v[i];
    }

    if (n < 4)
    {
        int sum = 0;
        FOR(i, 0, n)
        {
            sum += v[i];
            if (sum > max)
            {
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    else
    {
        int sum = v[0] + v[1] + v[2] + v[3];
        if (sum <= max)
        {
            FOR(i, 1, n - 3)
            {
                sum-=v[i-1];
                sum+=v[i+3];
                // cout << "SUM" << sum << endl;
                if (sum > max){
                    cout << i+3;
                    return 0;
                }
            }
            cout << n;
        }
        else
        {
            int sum = 0;
            FOR(i, 0, n)
            {
                sum += v[i];
                if (sum > max)
                {
                    cout << i;
                    return 0;
                }
            }
        }
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