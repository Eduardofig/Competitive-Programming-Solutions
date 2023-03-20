#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n;
//int a[MXN];
//int b[MXN];
//string s;
map<string, int> mp;
string pins[10];

void solve()
{
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(mp[pins[i]] > 1) {
            ans++;
            string tmp = pins[i];
            bool found = false;
            for(int k = 0; k < 4 && !found; k++) {
                for(char c = '0'; c <= '9' && !found; c++) {
                    pins[i][k] = c;
                    if(mp.find(pins[i]) == mp.end()) {
                        found = true;
                        mp[pins[i]]++;
                    }
                }
            }

            mp[tmp]--;
        } 
    }

    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        cout << pins[i] << '\n';
    }
}

void read()
{
    mp.clear();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pins[i];
        mp[pins[i]]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
