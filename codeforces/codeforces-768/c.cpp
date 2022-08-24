#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = (1 << 16) + 3;
const int INF = 0x3f3f3f3f;

int n, k;
bool used[MXN];
 
void solve()
{
    memset(used, false, sizeof used);

    if(k == n - 1) {
        if(n <= 4) {
            cout << -1 << '\n';
        } else {
            cout << k << ' ' << k - 1 << '\n';
            cout << 1 << ' ' << 3 << '\n';
            cout << 0 << ' ' << (3 ^ k) << '\n';

            used[k] = used[k - 1] = true;
            used[1] = used[3] = true;
            used[0] = used[(3 ^ k)] = true;

            for(int i = 0; i < n; ++i) {
                if(!used[i]) {
                    used[i] = used[i ^ (n - 1)] = true;

                    cout << i << ' ' << (i ^ (n - 1)) << '\n';
                }
            }
        }
        return;
    }

    cout << k << ' ' << n - 1 << '\n';
    used[k] = true;
    used[n - 1] = true;

    if(k != 0) {
        cout << (k ^ (n - 1)) << ' ' << 0 << '\n';
        used[0] = true;
        used[k ^ (n - 1)] = true;
    }

    for(int i = 0; i < n; ++i) {
        if(i != k && !used[i]) {
            used[i] = true;
            used[i ^ (n - 1)] = true;

            cout << i << ' ' << (i ^ (n - 1)) << '\n';
        }
    }

    //cout << "test end\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        solve();
    }
}
