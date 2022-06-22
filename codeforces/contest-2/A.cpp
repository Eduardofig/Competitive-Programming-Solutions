#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 53;
double arr[MXN];
double n;

void solve()
{
    double sum{};
    for(int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    for(int i = 0; i < n; ++i) {
        if((sum - arr[i]) / (n - 1) == arr[i]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
