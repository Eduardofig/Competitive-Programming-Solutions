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
    n = s.size();
    int cnt = 0;
    int curr = '0';
    int curr_cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == curr) {
            curr_cnt++;
        } else {
            curr = s[i];
            curr_cnt = 1;
        }

        cnt = max(curr_cnt, cnt);
    }
    cnt = max(curr_cnt, cnt);

    if(cnt >= 7) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    solve();
}
