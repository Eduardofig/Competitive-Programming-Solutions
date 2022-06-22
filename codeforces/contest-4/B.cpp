#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;    
ll n;
ll arr[MXN];

ll factorize_two(ll n)
{
    int ans{};
    while(n % 2 == 0) {
        n /= 2;
        ans++;
    }

    return ans;
}

void solve()
{
    ll n_odd{};
    for(int i = 0; i < n; ++i) {
        if(arr[i] % 2 > 0) {
            n_odd++;
        }
    }

    if(n_odd == n) {
        cout << 0 << '\n';
        return;
    }

    ll min_pow_two = 0x3f3f3f3f;
    if(n_odd == 0) {
        for(int i = 0; i < n; ++i) {
            min_pow_two = min(min_pow_two, factorize_two(arr[i]));
        }
        n_odd++;
    } else {
        min_pow_two = 0;
    }

    cout << min_pow_two + (n - n_odd) << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        solve();
    }
}
