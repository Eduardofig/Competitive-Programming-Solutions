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
    char curr = -1;
    int rep = 0;
    int mx_rep = 0;
    for(char c: s) {
        if(c == curr) {
            rep++;
        } else {
            mx_rep = max(mx_rep, rep);
            rep = 1;
            curr = c;
        }
    }
    mx_rep = max(mx_rep, rep);

    cout << mx_rep << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    solve();
}
