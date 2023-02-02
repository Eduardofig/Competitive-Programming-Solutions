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
string s, t, p;
int cnts[26]{}, cntp[26]{}, cntt[26]{};
 
void solve()
{
    memset(cnts, 0, sizeof cnts);
    memset(cntt, 0, sizeof cntt);
    memset(cntp, 0, sizeof cntp);

    int i = 0;

    for(char c: t) {

        if(i == s.size()) {
            break;
        }

        if(c == s[i]) {
            i++;
        }
    }

    if(i < s.size()) {
        cout << "NO\n";
        return;
    }

    for(char c: s) {
        cnts[c - 'a']++;
    }

    for(char c: p) {
        cntp[c - 'a']++;
    }

    for(char c: t) {
        cntt[c - 'a']++;
    }


    for(int i = 0; i < 26; ++i) {
        if(cntt[i] - cnts[i] > cntp[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        cin >> s >> t >> p;
        solve();
    }
}
