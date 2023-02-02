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
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{

    if(n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    if(m == 0) {
        cout << n << ' ' << n << '\n';
        return;
    }

    ll newm = min(n, m);

    ll need = n / 2 + n % 2;

    ll diff = max(need - m, 0LL);

    ll mn = n, mx;

    while(newm > 0 && mn > 0) {
        mn = max(mn - 2, 0LL);
        newm--;
    }

    need = (n * (n - 1)) / 2;

    diff = max(need - m, 0LL);
    mx = 0;

    for(ll i = 1; diff >= n - i; ++i) {
        mx++;
        diff -= n - i;
    }

    cout << mn << ' ' << mx << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    solve();
}
