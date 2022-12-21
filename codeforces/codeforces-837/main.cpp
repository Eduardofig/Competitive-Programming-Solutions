#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;
const int MXP = 1e5 + 3;

bool prim[MXP];
int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;
set<int> np;
vector<int> primes;
map<int, int> cnt;

void init()
{
    memset(prim, true, sizeof prim);

    prim[1] = prim[0] = false;
    for(int i = 2; i * i < MXP; ++i) {
        if(prim[i]) {
            primes.push_back(i);
            for(int j = i * i; j < MXP; j += i) {
                prim[j] = false;
            }
        }
    }
}
 
void solve()
{
    for(int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }

    for(auto &[_, num]: cnt) {
        if(num > 1) {
            cout << "YES\n";
            cnt.clear();
            return;
        }
    }

    for(int i = 0; i < n; ++i) {
        bool is_prime = true;

        for(int p: primes) {
            if(a[i] % p == 0) {
                is_prime = false;

                if(np.find(p) != np.end()) {
                    cout << "YES\n";
                    np.clear();
                    return;
                } 

                np.insert(p);
            }
        }

        if(is_prime) {

            if(np.find(a[i]) != np.end()) {
                cout << "YES\n";
                np.clear();
                return;
            }

            np.insert(a[i]);
            primes.push_back(a[i]);
        }
    }


    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}
