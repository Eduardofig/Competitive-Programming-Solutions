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
//int a[MXN];
//int b[MXN];
//string s;
int f[MXN][3]{};
 
void solve()
{
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < 3; ++j) {
            cnt += f[i][j];
        }
        if(cnt >= 2) {
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

    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> f[i][j];
        }
    }
    solve();
}
