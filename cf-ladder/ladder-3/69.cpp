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
//
//int a[MXN];
//int b[MXN];
string s;

void solve()
{
     int i = max_element(s.begin(), s.end()) - s.begin();
     int m = s[i] - '0';

     vector<string> ans(m, string(n, '0'));
     for(int i = 0; i < n; ++i) {
         for(int j = 0; j < s[i] - '0'; ++j) {
             ans[j][i]++;
         }
     }

     cout << ans.size() << '\n';
     for(string &s: ans) {

         reverse(s.begin(), s.end());
         while(s.back() == '0') {
             s.pop_back();
         }
         reverse(s.begin(), s.end());

         cout << s << ' ';
     }
     cout << '\n';
}
 
int main()

{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    n = s.size();
    solve();
}
