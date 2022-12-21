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
string s;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    vector<char> v;

    v.push_back(s.front() - '0');
    for(char c: s) {
        if(c - '0' != v.back()) {
            v.push_back(c - '0');
        }
    }

    int n = v.size() - (int)(v.front() == 0);

    cout << max(n - 1, 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
    }
}
