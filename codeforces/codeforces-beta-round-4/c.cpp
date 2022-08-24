#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
string s;
map<string, int> mp;
//int arr[MXN];
 
void solve()
{
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(mp.find(s) == mp.end()) {
            cout << "OK\n";
            mp.insert({s, 1});
        } else {
            cout << s << mp[s]++ << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    solve();
}
