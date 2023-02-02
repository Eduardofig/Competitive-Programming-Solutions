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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    
    if(m > n / 2) {
        cout << (m - 1 >= 1? m - 1: m + 1);
    } else {
        cout << (m + 1 <= n? m + 1: m - 1);
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    solve();
}
