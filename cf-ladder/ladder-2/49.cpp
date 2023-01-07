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

string s, s2;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int pos = s.find(s2);

    int ans = 0;
    while(pos != string::npos) {
        ans++;
        pos = s.find(s2, pos + s2.size());
    }
    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s >> s2;
    solve();
}
