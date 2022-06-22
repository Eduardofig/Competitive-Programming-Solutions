#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t, k;
const int MXN = 2e5 + 3;
char arr[MXN];

void solve()
{
    if(k == 1) {
        for(int i = 0; i < n; ++i) {
            if(arr[i] == 'B') {
                cout << 0 << '\n';
                return;
            }
        }
        cout << 1 << '\n';
        return;
    }

    ll min_white, curr_white{};
    for(int i = 0; i < k; ++i) {
        curr_white += (arr[i] == 'W');
    }
    min_white = curr_white;

    ll i = 0, j = k - 1;
    while(j < n - 1) {
        curr_white -= (arr[i] == 'W');
        i++;
        j++;
        curr_white += (arr[j] == 'W');
        min_white = min(min_white, curr_white);
    }

    cout << min_white << '\n';
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
