#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int b[MXN];
//string s;
ll p[MXN];
 
void solve()
{
    ll ans = INF;
    for(int mask = 0; mask < (1 << n); ++mask) {
        ll a = 0, b = 0;
        for(int i = 0; i < n; ++i) {
            if(((1 << i) & mask) > 0) {
                a += p[i];
            } else {
                b += p[i];
            }
        }
        ans = min<ll>(ans, abs(a - b));
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    solve();
}
