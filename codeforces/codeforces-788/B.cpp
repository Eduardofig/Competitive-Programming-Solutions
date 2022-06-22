#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e4 + 3;
const int INF = 0x3f3f3f3f;

int n, m;
string s;
bool spc[26];
 
void solve()
{
    int prev = -1;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        if(spc[s[i] - 'a']) {
            v.push_back(i - prev - 1);
            prev = i;
        }
    }

    if(v.empty()) {
        cout << 0 << '\n';
        return;
    }

    int mx = 0, count = 0;
    for(int i: v) {
        if(i == mx) {
            count++;
        } else if(i > mx){
            mx = i;
            count = 1;
        }
    }

    int ans = mx;

    if(v.size() > 1 && (v.front() != mx || count > 1)) {
        ans++;
    }

    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        memset(spc, false, sizeof spc);

        cin >> n >> s >> m;
        while(m--) {
            char c;
            cin >> c;
            spc[c - 'a'] = true;
        }
        solve();
    }
}
