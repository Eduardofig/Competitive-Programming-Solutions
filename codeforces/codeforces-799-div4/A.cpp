#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll a, b, c, d;

void solve()
{
    ll ans{};

    if(b > a) ans++;
    if(c > a) ans++;
    if(d > a) ans++;

    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> a >> b >> c >> d;
        solve();
    }
}
