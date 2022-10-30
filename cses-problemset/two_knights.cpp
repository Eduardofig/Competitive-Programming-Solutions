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
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    for(int k = 1; k <= n; ++k) {
        ll k2 = k * k;
        
        ll tot = max<ll>(0LL, k2 * (k2 - 1) / 2);

        tot -= max<ll>(0LL, 4 * (k - 2) * (k - 1));

        cout << max<ll>(0LL, tot) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    solve();
}
