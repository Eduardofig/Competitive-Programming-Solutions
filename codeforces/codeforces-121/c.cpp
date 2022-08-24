#include <bits/stdc++.h>
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
vector<string> names;
int dp[26][26] = { 0 };
 
void solve()
{
    for(string name: names) {
        for(int i = 0; i < 26; ++i) {
            if(dp[i][name.front() - 'a'] > 0) {
                dp[i][name.back() - 'a'] = max(dp[i][name.front() - 'a'] + (int)name.size(), dp[i][name.back() - 'a']);
            }
        }
        dp[name.front() - 'a'][name.back() - 'a'] = max(dp[name.front() - 'a'][name.back() - 'a'], (int)name.size());
    }

    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        ans = max(ans, dp[i][i]);
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    names.resize(n);
    for(string &name: names) {
        cin >> name;
    }
    solve();
}
