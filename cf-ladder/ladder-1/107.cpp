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

set<int> okw = {'A', 'H', 'M', 'I', 'O', 'U',
    'V', 'W', 'X', 'Y', 'T'};
 
void solve()
{
    for(char c: s) {
        if(okw.find(c) == okw.end()) {
            cout << "NO\n";
            return;
        }
    }

    string s2 = s;

    reverse(s.begin(), s.end());

    if(s == s2) {
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
