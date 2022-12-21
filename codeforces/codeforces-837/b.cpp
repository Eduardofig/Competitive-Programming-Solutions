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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

int mn[MXN];
 
void solve()
{
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int sz = mn[i] - 1 - i + 1;

        ans += sz;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            mn[i] = n;
        }

        for(int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;

            if(from > to) {
                swap(from, to);
            }

            from--;
            to--;

            mn[from] = min(mn[from], to);
        }

        for(int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i], mn[i + 1]);
        }
        solve();
    }
}
