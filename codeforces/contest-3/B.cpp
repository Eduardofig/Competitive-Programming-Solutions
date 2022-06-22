#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MXN = 1e5 + 3;
ll arr[MXN];
ll n;

void solve()
{
    int ans[n];

    for(int i = 0; i < n; ++i) {
        ans[i] = i + 1;
    }

    for(int i = 1; i < n; ++i) {
        if(arr[i] == arr[i - 1]) {
            swap(ans[i], ans[i - 1]);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(ans[i] == i + 1) {
            cout << "-1\n";
            return;
        }
    }

    for(int i: ans) {
        cout << i << " ";
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
