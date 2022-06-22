#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t, k;
const int MXN = 2e5 + 3;
ll arr[MXN];

void solve()
{
    ll ans{};
    ll remainder[k];

    for(int i = 0; i < k; ++i) {
        remainder[i] = 0;
    }

    for(int i = 0; i < n; ++i) {
        ans += arr[i] / k;
        remainder[arr[i] % k]++;
    }

    for(int i = 1; i < k; ++i) {
        if(remainder[i] > 0) {
            for(int j = k - i; j < k; ++j) {
                if(remainder[j] > 0 && remainder[i] > 0) {
                    if(j != i) {
                        ll tmp = min(remainder[i], remainder[j]);
                        ans += tmp;
                        remainder[i] -= tmp;
                        remainder[j] -= tmp;
                    } else {
                        ans += remainder[i] / 2;
                        remainder[i] = remainder[i] % 2;
                    }
                } 
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> k;
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        solve();
    }
}
