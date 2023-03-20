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
int a[MXN];
int prefxor[MXN]{};
int pref1[MXN]{};
int pref0[MXN]{};
//int b[MXN];
//string s;

void solve()
{
    prefxor[0] = 0;

    for(int i = 0; i < n; i++) {
        prefxor[i + 1] = prefxor[i] ^ a[i];
    }

    for(int i = 0; i < n; i++) {
        pref1[i + 1] = pref1[i] + (prefxor[i] == 1);
        pref0[i + 1] = pref0[i] + (prefxor[i] == 0);
    }

    ll nneg = 0, npos = 0;

    nneg += a[0];
    npos += a[0] ^ 1;

    for(int i = 1; i < n; i++) {
        if(prefxor[i + 1] == 1) {
            nneg += pref0[i];
            npos += pref1[i];
        } else {
            nneg += pref1[i];
            npos += pref0[i];
        }

        nneg += a[i];
        npos += a[i] ^ 1;
    }

    cout << nneg << ' ' << npos << '\n';
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] < 0;
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
