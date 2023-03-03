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

int m;
//int k;
//int a[MXN];
//int b[MXN];
string s;
int op[MXN];
int a[MXN]{};
 
void solve()
{
    int n = s.size();
    for(int i = 0; i < m; i++) {
        a[op[i] - 1]++;
    }

    int pref = 0;

    for(int i = 0; i < n / 2; ++i) {
        pref += a[i];
        pref %= 2;

        if(pref == 1) {
            swap(s[i], s[n - i - 1]);
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
    for(int i = 0; i < m; i++) {
        cin >> op[i];
    }
    solve();
}
