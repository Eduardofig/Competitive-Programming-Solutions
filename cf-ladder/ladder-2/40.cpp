#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 4e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

ll n;
//ll k;
ll a[MXN];
//ll b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);

    ll pref[n + 1];

    pref[0] = 0;

    for(ll i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll tot = pref[n] - pref[i];

        if(i > 0) {
            tot += a[i - 1];
        }
        ans += tot;
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
