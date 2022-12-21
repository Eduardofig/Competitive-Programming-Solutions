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
    int a = 0, b = 0;
    for(char c: s) {
        if(c >= 'a' && c <= 'z') {
            a++;
        } else {
            b++;
        }
    }

    for(char &c: s) {
        if(a >= b) {
            c =  tolower(c);
        } else {
            c = toupper(c);
        }
    }
    cout << s << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    solve();
}
