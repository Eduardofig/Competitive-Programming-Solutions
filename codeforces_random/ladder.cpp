#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int n, m;
int arr[MXN], pref[MXN];

void solve()
{
    pref[0] = pref[1] = 0;
    int i;

    for(i = 2; i < n - 1; ++i) {
        int j = i - 1;
        if(arr[j - 1] < arr[j] && arr[j + 1] <= arr[j]) {
            pref[i]++;
        }

        while(arr[i] == arr[i - 1]) {
            pref[i] = pref[i - 1];
            i++;
        }
    }

    int l, r;
    for(int q = 0; q < m; ++q) {
        cin >> l >> r;
        if(pref[r] - l > 0? pref[l]: 0 == 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
