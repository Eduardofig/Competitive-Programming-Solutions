#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
//using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, l, r, x;
//int k;
int c[MXN];
//int b[MXN];
//string s;

bool check(int mask)
{
    int mn = INF, mx = 0, tot = 0;
    int cnt = 0;
    for(int m = 0; m < n; ++m) {
        if(((1 << m) & mask) > 0) {
            cnt++;
            tot += c[m];
            mn = min(c[m], mn);
            mx = max(c[m], mx);
        }
    }

    return (mx - mn >= x) && (tot >= l) && (tot <= r) && (cnt >= 2);
}
 
void solve()
{
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        if(check(mask)) {
            ans++;
        }
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> l >> r >> x;

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    solve();

}
