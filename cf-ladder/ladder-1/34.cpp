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
string s;
 
void solve()
{
    int n = s.size();

    int prefq[n + 1];

    prefq[0] = 0;
    for(int i = 0; i < n; ++i) {
        prefq[i + 1] = prefq[i] + (s[i] == 'Q');
    }

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == 'Q') {
            for(int j = i + 1; j < n; ++j) {
                if(s[j] == 'A') {
                    ans += prefq[n] - prefq[j];
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

    cin >> s;
    solve();
}
