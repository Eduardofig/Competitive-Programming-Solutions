#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;    
ll n, k;
ll arr[MXN];

void solve()
{
    if(k == 0) {
        cout << 0 << '\n';
    }

    ll pref[n];
    ll sum{};

    pref[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + arr[i];
    }

    ll w = min(n - 1, k);

    if(k >= 2 * (n - 1)) {
        sum = pref[n - 1];
    } else {
        ll tmp{};
        for(ll i = 0; i + w - 1 < n; ++i) {
            tmp = pref[i + w - 1];
            if(i > 0) {
                tmp -= pref[i - 1];
            }
            sum = max(sum, tmp);
        }
    }

    sum += (k - 1) * k / 2;

    k -= n - 1;

    if(k > n - 2) {
        sum += max(0LL, (k / n - 2) * (2 + 2 + (n - 3) * 2) * (n - 2) / 2);
    }

    if(k > 0) {
        sum += max(0LL, (2 + 2 + (n - 3) * 2) * ((k % n - 2)) / 2);
    }

    cout << sum << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n >> k;
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        solve();
    }
}
