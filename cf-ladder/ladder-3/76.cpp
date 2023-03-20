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
    string a(n, 'b'); 
    string b(n, 'b'); 
    int cntab{}, cntar{}, cntsb{}, cntsr{}, cntbb{}, cntbr{};

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            a[i] = 'r';
        } else {
            b[i] = 'r';
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 'b') {
            cntab++;
        } else {
            cntar++;
        }

        if(b[i] == 'b') {
            cntbb++;
        } else {
            cntbr++;
        }

        if(s[i] == 'b') {
            cntsb++;
        } else {
            cntsr++;
        }
    }

    string tmp = s;

    int diffr = cntar - cntsr;
    int diffb = cntab - cntsb;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(diffr > 0 && s[i] == 'b' && a[i] == 'r') {
            s[i] = 'r';
            diffr--;
            ans++;
        }

        if(diffb > 0 && s[i] == 'r' && a[i] == 'b') {
            s[i] = 'b';
            diffb--;
            ans++;
        }
    }


    for(int i = 0; i < n; i++) {
        if(s[i] == 'r' && a[i] == 'b') {
            ans++;
        }
    }

    s = tmp;
    int ansb = 0;
    diffr = cntbr - cntsr;
    diffb = cntbb - cntsb;

    for(int i = 0; i < n; i++) {
        if(diffr > 0 && s[i] == 'b' && b[i] == 'r') {
            s[i] = 'r';
            diffr--;
            ansb++;
        }

        if(diffb > 0 && s[i] == 'r' && b[i] == 'b') {
            s[i] = 'b';
            diffb--;
            ansb++;
        }
    }


    for(int i = 0; i < n; i++) {
        if(s[i] == 'r' && b[i] == 'b') {
            ansb++;
        }
    }

    cout << min(ansb, ans) << '\n';

}

void read()
{
    cin >> n >> s;
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
