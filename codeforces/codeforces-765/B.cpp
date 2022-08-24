#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;

int n;
int arr[MXN];
 
void solve()
{
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = mp.find(arr[i]);
        if (it != mp.end()) {
            ans = max(ans, n - i + it->second);
        }
        mp[arr[i]] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
