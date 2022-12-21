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
    for(int i = 0; i < n - 1; ++i) {
        if(s[i] == '4' && s[i + 1] == '4') {
            s[i] = '*';
            s[i + 1] = '*';
            if(i < 1 || s[i - 1]  != '1') {
                cout << "NO\n";
                return;
            }
            s[i - 1] = '*';
        }
    }

    for(int i = 0; i < n; ++i) {
        if(s[i] == '4') {
            s[i] = '*';
            
            if(i < 1 || s[i - 1] != '1') {
                cout << "NO\n";
                return;
            }

            s[i - 1] = '*';
        }
    }

    for(char c: s) {
        if(c != '*' && c != '1') {
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

    cin >> s;
    n = s.size();
    solve();
}
