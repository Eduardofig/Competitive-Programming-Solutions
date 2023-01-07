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

ll n, m;
//ll k;
ll a[MXN];
//ll b[MXN];
//string s;
vector<array<ll, 3>> q;
 
void solve()
{
    ll pref[2][n + 1];

    pref[0][0] = pref[1][0] = 0;
    for(ll i = 0; i < n; ++i) {
        pref[0][i + 1] = pref[0][i] + a[i];
    }

    sort(a, a + n);

    for(ll i = 0; i < n; ++i) {
        pref[1][i + 1] = pref[1][i] + a[i];
    }

    for(auto [type, l, r]: q) {
        cout << pref[type][r] - pref[type][l] << '\n';
    }
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

    cin >> m;
    q.resize(m);
    for(ll i = 0; i < m; ++i) {
        auto &[type, l, r] = q[i];
        cin >> type >> l >> r;
        type--;
        l--;
    }

    solve();
}
