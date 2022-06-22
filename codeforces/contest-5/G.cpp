#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t, k, m;
const int MXN = 2e5 + 3;
ll a[MXN];
pair<ll, ll> msg[MXN];

void solve()
{
    ll min = 0x3f3f3f3f;
    ll trains{};
    for(int i = 0; i < n; ++i) {
        if(a[i] < min) {
            min = a[i];
            trains++;
        } else {
            a[i] = min;
        }
    }

    for(auto [train, speed]: msg) {
        min = speed;
        for(int i = train; i < n; ++i) {
            if(a[i] < min) {

            }
        }
    }

    cout << trains << endl;
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> m;
        for(int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for(int j = 0; j < m; ++j) {
            ll a, b;
            msg[j] = {a, b};
        }
    }
}
