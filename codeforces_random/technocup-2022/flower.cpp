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
    int o = 0, z = 0;
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == 0) {
            z++;
            o = 0;
        } else {
            o++;
            z = 0;
        }
        if(z == 2) {
            cout << -1 << '\n';
            return;
        }
        if(o == 1) {
            ans += 1;
        } 
        if(o >= 2) {
            ans += 5;
        }
    }

    cout << ans << '\n';
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
