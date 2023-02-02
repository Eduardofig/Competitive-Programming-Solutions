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

int n, d;
//int k;
int a[MXN];
//int b[MXN];
//string s;

 
void solve()
{
    sort(a, a + n);

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll has = upper_bound(a + i + 1, a + n, a[i] + d) - a - i - 1;

        ans += max(0LL, has * (has - 1) / 2);
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> d;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
