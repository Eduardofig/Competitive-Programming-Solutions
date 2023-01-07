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
    for(char &c : s) {
        int num = c - '0';

        num = min(num, 9 - num);

        c = '0' + num;
    }

    if(s.front() == '0') {
        s.front() = '9';
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
