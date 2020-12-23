#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair

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

void print_vector(vi v);
void print_set(si s);


template<typename K, typename V>
void print_map(std::map<K,V> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<char, int> mpa, mpb;

    string a, b;

    cin >> a >> b;

    if (a.size() != b.size()){
        cout << "N";
        return 0;
    } 

    for (int i = 0; i < a.size(); i++){
        if (mpa.find(a[i]) != mpa.end()){
            mpa[a[i]]++;
        } else{
            mpa[a[i]] = 1;
        }

        if (mpb.find(b[i]) != mpb.end()){
            mpb[b[i]]++;
        } else{
            mpb[b[i]] = 1;
        }
    }

    // print_map(mpa);
    // print_map(mpb);
    if (mpa == mpb){
        cout << "A";
        return 0;
    }


    int aa, ba = 0;

    if (mpa['*'] >= mpb['*']){
        mpa['*'] -= mpb['*'];
        mpb['*'] == 0;


        int dif = 0;
        for (auto x: mpb){
            if (x.second < mpa[x.first] && x.first != '*'){
                // cout << x.first << " " << x.second;
                cout << "N";
                return 0;
            } else{
                if (x.first != '*'){
                    // cout << "DIFF: " << x.second - mpa[x.first];
                    dif += x.second - mpa[x.first];
                }
                
            }
        }

        // cout << dif << "\n";
        // cout << mpa['*'];

        if (dif == mpa['*']){
            cout << "A";
            return 0;
        } else{
            cout << "N";
        }
    }

    if (mpb['*'] >= mpa['*']){
        mpb['*'] -= mpa['*'];
        mpa['*'] == 0;


        int dif = 0;
        for (auto x: mpa){
            if (x.second < mpb[x.first] && x.first != '*'){
                // cout << x.first << " " << x.second;
                cout << "N";
                return 0;
            } else{
                if (x.first != '*'){
                    // cout << "DIFF: " << x.second - mpb[x.first];
                    dif += x.second - mpb[x.first];
                }
                
            }
        }

        // cout << dif << "\n";
        // cout << mpb['*'];

        if (dif == mpb['*']){
            cout << "A";
            return 0;
        } else{
            cout << "N";
        }
    }

    return 0;
}

void print_vector(vi v){
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