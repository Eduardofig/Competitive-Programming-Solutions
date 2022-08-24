#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 4e4 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, num;
vector<int> palindromes;
 
void solve()
{
    int dp[n][num];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; ++i) {
        for(int j = num; j >= 0; --j) {
            if(j - palindromes[i] >= 0) {
                dp[i][j - palindromes[i]]++;
                dp[i][j - palindromes[i]] %= MOD;
            }
            dp[i + 1][j] += dp[i][j] % MOD;
            dp[i + 1][j] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += dp[i][0] % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    auto is_palindrome = [](int i) {
        string s = to_string(i);
        int n = s.size();
        for(int i = 0; i < n - i - 1; ++i) {
            if(s[i] != s[n - i]) {
                return false;
            }
        }

        return true;
    };

    for(int i = 0; i < MXN; ++i) {
        if(is_palindrome(i)) {
            palindromes.push_back(i);
            cout << i << '\n';
        }
    }

    int t;
    cin >> t;
    n = palindromes.size();
    while(t--) {
        cin >> num;
        solve();
    }
}
