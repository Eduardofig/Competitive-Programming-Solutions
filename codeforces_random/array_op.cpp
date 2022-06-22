#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 3;
ll n, k;
ll arr[MXN];

void solve()
{
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    sort(arr, arr + n);

    cout << abs(arr[0] - arr[n - 1]) << '\n';
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
