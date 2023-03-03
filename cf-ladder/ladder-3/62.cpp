#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 5e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;

map<int, ll> tot;

void solve()
{
    for(int i = 0; i < n; ++i) {
        tot[a[i] - i] += a[i];
    }

    ll ans = 0;
    for(auto &[_, b]: tot) {
        ans = max(ans, b);
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
