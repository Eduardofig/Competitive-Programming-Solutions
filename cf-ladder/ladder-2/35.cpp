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

int n;
//int k;
ll a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    sort(a, a + n);

    for(int i = 0; i < n - 2; ++i) {
        if(a[i] + a[n - 2] > a[n - 1]) {
            cout << "YES\n";
            cout << a[i] << ' ';
            for(int j = 0; j < i; ++j) {
                cout << a[j] << ' ';
            }
            for(int j = i + 1; j < n; ++j) {
                cout << a[j] << ' ';
            }
            cout << '\n';
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

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
