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

ll x, y;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll layer = max(x, y);

    ll begin = (layer - 1) * (layer - 1) + 1;

    ll ans = begin;
    if(layer % 2 == 0) {
        ans += y - 1;
        ans += layer - x;
    } else {
        ans += x - 1;
        ans += layer - y;
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
        cin >> y >> x;
        solve();
    }
}
