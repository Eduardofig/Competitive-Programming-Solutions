#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
int arr[MXN];
 
void solve()
{
    if(n == 1) {
        cout << "YES\n";
        return;
    }
    if(n == 2) {
        if(arr[1] >= arr[0]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if(n == 3) {
        cout << "YES\n";
        return;
    }

    pair<int, int> p[n];
    bool vis[n];
    memset(vis, false, sizeof vis);

    for(int i = 0; i < n; ++i) {
        p[i].first = arr[i];
        p[i].second = i;
    }
    sort(p, p + n);

    int swaps = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i] || p[i].second == i) {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        while(!vis[j]) {
            vis[j] = true;

            j = p[j].second;
            cycle_size++;
        }

        if(cycle_size > 0) {
            swaps += cycle_size - 1;
        }
    }

    if(swaps == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
