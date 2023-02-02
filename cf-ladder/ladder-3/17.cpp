#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
//using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int m;
int n;
int l[MXN], r[MXN], k[MXN];
//int k;
//int a[MXN];
//int b[MXN];
string s;
 
void solve()
{
    for(int i = 0; i < m; ++i) {
        n = r[i] - l[i] + 1;

        k[i] %= n;

        string copy = string(s.begin() + l[i], s.end() + l[i] + n);

        for(int j = 0; j < n; ++j) {
            int offset = (j + k[i]) % n;
            s[l[i] + offset] = copy[j];
        }

    }
    cout << s << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s >> m;
    for(int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--;
        r[i]--;
    }
    solve();
}
