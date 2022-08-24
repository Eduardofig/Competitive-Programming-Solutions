#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        ll arr[n + 1];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        arr[n] = 0;
        sort(arr, arr + n + 1);
        int o = lower_bound(arr, arr + n + 1, 0) - arr;

        ll ans = 0;
        for(int i = 0; i <= o; i += k) {
            ans += 2 * abs(arr[i]);
        }

        for(int i = n; i >= o; i -= k) {
            ans += 2 * abs(arr[i]);
        }

        ans -= max(abs(arr[0]), abs(arr[n]));

        cout << ans << '\n';
    }
}
