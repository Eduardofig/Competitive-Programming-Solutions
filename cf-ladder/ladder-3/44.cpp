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

int dp[MXN][30];
 
void solve()
{
    string ans;

    for(char c: s) {
        if(c != ans.back() || ans.size() % 2 == 0) {
            ans.push_back(c);
        }
    }

    if(ans.size() % 2 == 1) {
        ans.pop_back();
    }

    cout << n - ans.size() << '\n' << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> s;
    solve();
}
