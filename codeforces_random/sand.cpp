#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n, k;
int arr[MXN];
 
void solve()
{
    if(k == 1) {
        cout << (n - 1) / 2 << '\n';
        return;
    }
    int ans = 0;
    for(int i = 1; i < n - 1; ++i) {
        if(arr[i] > arr[i + 1] + arr[i - 1]) {
            ans++;
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
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
