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
ll a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    ll ans = 0;
    while(a > 0 && b > 0) {
        if(b > a) {
            swap(a, b);
        }
        ans += a / b;
        a %= b;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    solve();
}
