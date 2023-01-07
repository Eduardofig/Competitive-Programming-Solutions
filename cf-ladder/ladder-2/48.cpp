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
ll a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);

    ll curr = 0;
    ll ans = 0;

    for(int i = 1; i < n; ++i) {
        ans += curr * (a[i] - a[i - 1]);
        if(a[i] == a[i - 1]) {
            curr++;
        }

        for(ll j = a[i] + 1; j < (i < n - 1? a[i + 1]: LONG_LONG_MAX) && curr > 0; ++j) {
            curr--;
            ans += j - a[i];
        }
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
        cin >> a[i];
    }
    solve();
}
