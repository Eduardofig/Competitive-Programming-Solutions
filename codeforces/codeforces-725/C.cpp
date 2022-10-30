#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
//using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, l, r;
int a[MXN];

void solve()
{
    sort(a, a + n);

    ll ans = 0;

    for(int i = 0; i < n; ++i) {
        int lb = lower_bound(a, a + n, l - a[i]) - a;
        int rb = upper_bound(a, a + n, r - a[i]) - a;

        ans += max(rb - lb - (int)(i >= lb && i < rb), 0);
    }

    cout << ans / 2 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> l >> r;
        int num;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}
