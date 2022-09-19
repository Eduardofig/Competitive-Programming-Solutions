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
int a[MXN], b[MXN];
 
void solve()
{
    int mn = *min_element(b, b + n);

    for(int i = 0; i < n; ++i) {
        if(a[i] > b[i]) {
            cout << "NO\n";
            return;
        }

        if(a[i] < b[i] && b[i] > b[(i + 1) % n] + 1) {
            cout << "NO\n";
            return;
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
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        solve();
    }
}
