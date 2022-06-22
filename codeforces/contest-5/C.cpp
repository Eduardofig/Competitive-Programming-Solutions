#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll MXN = 2e5 + 3;
ll n, t;
ll s[MXN], f[MXN], d[MXN];

void solve()
{
    queue<ll> q;

    d[0] = f[0] - s[0];
    for(int i = 1; i < n; ++i) {
        d[i] = f[i] - max(s[i], f[i - 1]);
    }

    for(int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> s[j];
        }
        for(int j = 0; j < n; ++j) {
            cin >> f[j];
        }
        solve();
    }
}
