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

int n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

vector<pair<ll, ll>> p;

map<ll, ll> xm, ym;
ll dm = 0;

map<pair<ll, ll>, ll> rep;

void solve()
{
    for(auto &[x, y]: p) {

        rep[{x, y}]++;

        xm[x]++;
        ym[y]++;

        if(x == y) {
            dm++;
        }
    }

    ll ans = 0;
    for(auto &[_, cnt]: xm) {
        ans += cnt * (cnt - 1) / 2;
    }

    for(auto &[_, cnt]: ym) {
        ans += cnt * (cnt - 1) / 2;
    }

    for(auto &[_, cnt]: rep) {
        ans -= cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;

    p.resize(n);

    for(auto &[x, y]: p) {
        cin >> x >> y;
    }

    solve();
}
