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
 
void solve()
{
    for(int i = 0; i + 26 <= n; ++i) {
        set<char> se;
        int nq = 0;
        for(int j = i; j < i + 26; ++j) {
            if(s[j] == '?') {
                nq++;
            } else {
                se.insert(s[j]);
            }
        }
        if(se.size() + nq == 26) {
            for(int j = i; j < i + 26; ++j) {
                if(s[j] == '?') {
                    for(char c = 'A'; c <= 'Z'; ++c) {
                        if(se.find(c) == se.end()) {
                            s[j] = c;
                            se.insert(c);
                            break;
                        }
                    }
                }
            }

            for(char c: s) {
                if(c == '?') {
                    cout << 'Z';
                } else {
                    cout << c;
                }
            }

            cout << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    n = s.size();
    solve();
}
