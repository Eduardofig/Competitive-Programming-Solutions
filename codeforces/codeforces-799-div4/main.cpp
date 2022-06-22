#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3, INF = 0x3f3f3f3f;

ll arr[MXN];
ll pref[MXN], n, s;

void solve()
{
    ll ans = INF;
    pref[0] = arr[0] - '0';

    for (ll i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + arr[i] - '0';
    }

    for(ll i = 0; i < n; ++i) {
        ll high = n - 1, low = i;
        ll mid = (high - low + 1) / 2, sum;

        while(true) {
            sum = pref[mid] - i > 0? pref[i - 1]: 0;

            if(sum == s) {
                ans = min(ans, i + (n - mid));
                break;
            } else if(sum < s) {
                high = mid;
            } else {
                low = mid;
            }

            if(high <= low) {
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
