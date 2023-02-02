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
    int pos = -1;
    for(int i = 0; i < n - 1; ++i) {
        //cout << string(s.begin(), s.begin() + i + 1) << ' ' << string(s.begin() + n - 1 - i, s.end()) << '\n';
        if(string(s.begin(), s.begin() + i + 1) == string(s.begin() + n - 1 - i, s.end())) {
            pos = i;
        }
    }
    
    string suff(s.begin() + pos + 1, s.end());
    cout << s;
    for(int i = 0; i < k - 1; ++i) {
        cout << suff;
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k >> s;
    solve();
}
