#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 1e5 + 3;
ll arr[MXN];
ll n;

void solve()
{
    int max = 0, ans = 0, count = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] < max) {
            ans++;
            max = 0;
        } else {
            max = arr[i];
        }
    }

    cout << ans << '\n';
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
