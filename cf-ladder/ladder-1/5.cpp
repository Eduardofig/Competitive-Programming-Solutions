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

int n, a, b;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    while(n > 0) {
        n -= __gcd(a, n);
        if(n <= 0) {
            cout << 0 << '\n';
            return;
        }
        n -= __gcd(b, n);
        if(n <= 0) {
            cout << 1 << '\n';
            return;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b >> n;
    solve();
}
