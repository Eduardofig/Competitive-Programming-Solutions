#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e6 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
//int a[MXN];
//int b[MXN];
string s;
bool removed[MXN];
 
void solve()
{
    memset(removed, false, sizeof removed);

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '0') {
            for(int j = i; j <= n && s[j] == '0'; j += i) {
                if(!removed[j]) {
                    ans += i;
                    removed[j] = true;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        s.resize(n + 1);

        s[0] = 'a';

        for(int i = 1; i <= n; ++i) {
            cin >> s[i];
        }

        solve();
    }
}
