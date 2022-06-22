#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;
ll p[MXN];
ll n, q;

void solve()
{
    sort(p, p + n);
    reverse(p, p + n);

    ll pref[n];
    pref[0] = p[0];
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + p[i];
    }

    ll x, y;

    for(int i = 0; i < q; ++i) {
        cin >> x >> y;
        ll ans = pref[x - 1];
        if(x > y) {
            ans -= pref[x - y - 1];
        }

        cout << ans << '\n';
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    solve();
}
