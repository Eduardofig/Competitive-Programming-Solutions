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
    string a, b;

    bool found1 = false;
    for(char c: s) {
        int num = c - '0';

        if(num == 1) {
            if(!found1) {
                a.push_back('1');
                b.push_back('0');
                found1 = true;
            } else {
                b.push_back('1');
                a.push_back('0');
            }
        }

        if(num == 0) {
            a.push_back('0');
            b.push_back('0');
        }

        if(num == 2) {
            if(found1) {
                b.push_back('2');
                a.push_back('0');
            } else {
                b.push_back('1');
                a.push_back('1');
            }
        }

    }

    cout << a << '\n' << b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
    }
}
