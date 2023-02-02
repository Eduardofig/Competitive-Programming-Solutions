#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
map<char, char> mp;
//int b[MXN];
string s;
 
void solve()
{
    int i = 0;
    
    while(mp[s[i]] <= s[i] && i < n) {
        i++;
    }

    while(mp[s[i]] >= s[i] && i < n) {
        s[i] = mp[s[i]];
        i++;
    }

    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for(int i = 1; i <= 9; ++i) {
        cin >> mp[i + '0'];
    }
    solve();
}
