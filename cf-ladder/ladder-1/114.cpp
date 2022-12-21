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

int n, t;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    string ans(n, '0');

    if(t < 10) {
        ans.front() = '0' + t;
    } else {
        if(n == 1) {
            cout << "-1\n";
            return;
        }
        ans.front() = '1';
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> t;
    solve();
}
