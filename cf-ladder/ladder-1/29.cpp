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
string s1 = "a";

int min_dist(char a, char b)
{
    if(a > b) {
        swap(a, b);
    }

    return min(b - a, a - 'a' + 'z' - b + 1);
}
 
void solve()
{
    int ans = 0;

    for(char c: s) {
        s1.push_back(c);
    }

    int n = s1.size();

    for(int i = 1; i < n; ++i) {
        ans += min_dist(s1[i], s1[i - 1]);
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
