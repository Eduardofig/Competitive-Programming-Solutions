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
int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    int ans = 0;
    for(char curr_c = 'a'; curr_c <= 'z'; ++curr_c) {
        int len = 0;
        int curr = 0;
        for(char c: s) {
            if(c == curr_c) {
                len++;
            } 
            if(len == k) {
                len = 0;
                curr++;
            }

            if(c != curr_c) {
                len = 0;
            }
        }
        ans = max(curr, ans);
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k >> s;
    solve();
}
