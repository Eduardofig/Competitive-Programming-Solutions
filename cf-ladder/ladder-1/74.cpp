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

int x;
//int k;
//int a[MXN];
//int b[MXN];
string a, s;
 
void solve()
{
    if(s == "week") {
        x += 2;
        x %= 7;
        cout << 365 / 7 + (int)(365 % 7 >= x) << '\n';
    } else {
        if(x == 31) {
            cout << 7 << '\n';
        } else if(x == 30) {
            cout << 11 << '\n';
        } else {
            cout << 12 << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> x >> a >> s;
    solve();
}
