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
    bool ok = true;
    if(a % b != 0) {
        ok = false;
        for(int i = 0; i <= 9; ++i) {
            if((10 * a + i) % b == 0) { 
                a = 10 * a + i;
                n--;
                ok = true;
            }
        }
    }

    if(!ok) {
        cout << "-1\n";
        return;
    }

    string ans = to_string(a);

    if(a % b == 0) {
        for(int i = 0; i < n; ++i) {
            ans.push_back('0');
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> n;
    solve();
}
