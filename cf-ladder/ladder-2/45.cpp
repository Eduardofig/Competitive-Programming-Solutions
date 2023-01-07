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

ll n, x;
//int k;
ll c[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(c, c + n);
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += c[i] * x;
        x = max(1LL, x - 1);
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> x;
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    solve();
}
