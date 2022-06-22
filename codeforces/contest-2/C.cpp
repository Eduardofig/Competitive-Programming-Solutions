#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 1e5 + 3;
ll arr[MXN];
ll n;

void solve()
{
    sort(arr, arr + n);

    ll ans[MXN];

    int i = 0;
    int j = 0, k = n / 2;
    while(i < n) {
        ans[i++] = arr[j++];
        ans[i++] = arr[k++];
    }

    for(int i = 0; i < n; ++i) {
        if(!((ans[i] > ans[(i - 1 + n) % n] && ans[i] > ans[(i + 1) % n]) || ((ans[i] < ans[(i - 1 + n) % n] && ans[i] < ans[(i + 1) % n])))) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
