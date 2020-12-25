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
typedef unordered_set<int> si;
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

    int j, a, sol;
    sol = 0;
    cin >> j >> a;
    map<char, si> mp;

    REP(j)
    {
        char size;
        cin >> size;
        if (mp.find(size) != mp.end())
        {
            mp[size].insert(i + 1);
        }
        else
        {
            mp[size] = {i + 1};
        }
    }

    // print_map(mp);
    REP(a)
    {
        char size;
        int num;
        cin >> size >> num;

        if (size == 'S')
        {
            if (mp['L'].find(num) != mp['L'].end())
            {
                sol++;
                mp['L'].erase(num);
            }
            else if (mp['M'].find(num) != mp['M'].end())
            {
                sol++;
                mp['M'].erase(num);
            }
            else if (mp['S'].find(num) != mp['S'].end())
            {
                sol++;
                mp['S'].erase(num);
            }
        }

        else if (size == 'M')
        {
            if (mp['M'].find(num) != mp['M'].end())
            {
                sol++;
                mp['M'].erase(num);
            }
            else if (mp['L'].find(num) != mp['L'].end())
            {
                sol++;
                mp['L'].erase(num);
            }
        }
        else
        {
            if (mp['L'].find(num) != mp['L'].end())
            {
                sol++;
                mp['L'].erase(num);
            }
        }

        // if (size == 'S'){
        //     if (find(mp['L'].begin(), mp['L'].end(), num) != mp['L'].end()){
        //         sol++;
        //         remove(mp['L'].begin(), mp['L'].end(), num);

        //     }
        //     else if (find(mp['M'].begin(), mp['M'].end(), num) != mp['M'].end()){
        //         sol++;
        //         remove(mp['M'].begin(), mp['M'].end(), num);

        //     }
        //     else if (find(mp['S'].begin(), mp['S'].end(), num) != mp['S'].end()){
        //         sol++;
        //         remove(mp['S'].begin(), mp['S'].end(), num);

        //     }
        // } else if(size == 'M'){
        //     if (find(mp['S'].begin(), mp['S'].end(), num) != mp['S'].end()){
        //         sol++;
        //         remove(mp['S'].begin(), mp['S'].end(), num);

        //     }
        //     else if (find(mp['M'].begin(), mp['M'].end(), num) != mp['M'].end()){
        //         sol++;
        //         remove(mp['M'].begin(), mp['M'].end(), num);

        //     }
        // } else{
        //     if (find(mp['L'].begin(), mp['L'].end(), num) != mp['L'].end()){
        //         sol++;
        //         remove(mp['L'].begin(), mp['L'].end(), num);

        //     }
        // }
    }

    std::cout << sol;

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
        std::cout << "{" << pair.first << ": ";
        print_vector(pair.second);
    }
}