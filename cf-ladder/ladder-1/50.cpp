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

ll n;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    ll ans = 0;
    while(n % 5 == 0) {
        n /= 5;
        ans += 3;
    }

    while(n % 3 == 0) {
        n /= 3;
        ans += 2;
    }

    if(__builtin_popcountll(n) != 1) {
        cout << -1 << '\n';
    } else {
        while(n % 2 == 0) {
            n /= 2;
            ans++;
        }

        cout << ans << '\n';
    }

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        solve();
    }
}
