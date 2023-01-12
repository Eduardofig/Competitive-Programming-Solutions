#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n, m, k;
//int k;
int h[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    for(int i = 0; i < n - 1; ++i) {
        int need = max(h[i + 1] - k, 0);

        if(h[i] >= need) {
            m += h[i] - need;
        } else {

            if(m < need - h[i]) {
                cout << "NO\n";
                return;
            }

            m -= need - h[i];
        }
    }
    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        solve();
    }
        
}
