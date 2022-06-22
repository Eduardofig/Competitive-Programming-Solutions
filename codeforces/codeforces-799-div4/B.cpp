#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 1e4 + 3;

ll arr[MXN];
ll n, biggest;

void solve()
{
    ll ans = n;
    ll pairs{};
    for(ll i = 0; i <= biggest; ++i) {
        if(arr[i] >= 2) {
            if(arr[i] % 2 == 0) {
                ans -= arr[i] - 2;
                pairs++;
            } else {
                ans -= arr[i] - 1;
            }
        }
    }

    ans -= pairs - (pairs % 2);
    if(pairs % 2) {
        ans -= 2;
    }

    cout << ans << '\n';
}

int main()
{
    ll t, num;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        memset(arr, 0, sizeof arr);
        biggest = 0;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            biggest = max(biggest, num);
            arr[num]++;
        }
        solve();
    }
}
