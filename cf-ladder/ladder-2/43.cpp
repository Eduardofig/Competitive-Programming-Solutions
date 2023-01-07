#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

ll a, b, c, d;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    for(int i = 0; i < MXN; ++i) {

        ll num = b + i * a - d;

        if(num >= 0 && num % c == 0) {
            cout << b + i * a << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> d;
    solve();
}
