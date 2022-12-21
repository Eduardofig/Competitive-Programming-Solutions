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

ll a, b, s;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    a = abs(a);
    b = abs(b);
    if(s < a + b) {
        cout << "NO\n";
        return;
    }

    cout << ((s - (a + b)) % 2 == 0? "YES\n": "NO\n");
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> a >> b >> s;
    solve();
}
