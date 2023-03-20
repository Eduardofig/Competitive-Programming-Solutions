#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
//int a[MXN];
//int b[MXN];
string s;

void solve()
{
    int cnt = count(s.begin(), s.end(), '1');
    for(char c: s) {
        if(c != '1') {
            if(c == '2') {
                for(int i = 0; i < cnt; i++) {
                    cout << '1';
                }
                cnt = 0;
            }
            cout << c;
        }
    }

    for(int i = 0; i < cnt; i++) {
        cout << '1';
    }

    cout << '\n';
}

void read()
{
    cin >> s;
    n = s.size();
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
