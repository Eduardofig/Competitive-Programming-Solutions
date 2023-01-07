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
string s, t;
 
void solve()
{
    n = s.size();

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            cnt++;
        }
    }

    if(cnt % 2 == 1) {
        cout << "impossible\n";
        return;
    }

    int cntb = 0;
    string ans(n, ' ');
    for(int i = 0; i < n; ++i) {
        if(s[i] == t[i]) {
            ans[i] = s[i];
        } else {
            if(cntb < cnt / 2) {
                ans[i] = s[i];
                cntb++;
            } else {
                ans[i] = t[i];
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

    cin >> s >> t;
    solve();
}
