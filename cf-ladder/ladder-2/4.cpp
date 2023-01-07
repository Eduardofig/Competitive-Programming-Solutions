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
 
void solve()
{
    int a, b, c, d;
    for(int i = 0; i < 4; ++i) {
        cin >> a >> b >> c >> d;
        int p1 = min(a, b);
        int p2 = min(c, d);

        if(p1 + p2 <= n) {
            cout << i + 1 << ' ' << p1 + (n - p1 - p2) << ' ' << p2 << '\n';
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

    cin >> n;
    solve();
}
