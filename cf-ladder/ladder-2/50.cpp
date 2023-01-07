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
vector<string> v;
//int b[MXN];
//string s;
 
void solve()
{
    reverse(v.begin(), v.end());

    set<string> se;
    for(string s: v) {
        if(se.find(s) == se.end()) {
            se.insert(s);
            cout << s << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    v.resize(n);

    for(string &s: v) {
        cin >> s;
    }

    solve();
}
