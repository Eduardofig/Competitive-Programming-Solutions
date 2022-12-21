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

void change(char &c)
{
    if(isupper(c)) {
        c = tolower(c);
    } else {
        c = toupper(c);
    }
}
 
void solve()
{
    int up = count_if(s.begin(), s.end(), [](char c) {
            return isupper(c);
    });

    if(up == s.size() || (up == s.size() -1 && islower(s.front()))) {
        for(char &c: s) {
            change(c);
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
