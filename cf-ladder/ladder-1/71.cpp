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
//string s;
map<char, char> rmp;
map<char, char> lmp;
char op;
string s;

void init()
{
    string key = "qwertyuiopasdfghjkl;zxcvbnm,./";
    n = key.size();

    for(int i = 1; i < n; ++i) {
        rmp[key[i]] = key[i - 1];
    }
    for(int i = 0; i < n - 1; ++i) {
        lmp[key[i]] = key[i + 1];
    }
}
 
void solve()
{
    for(char c: s) {
        if(op == 'R') {
            cout << rmp[c];
        } else {
            cout << lmp[c];
        }
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> op >> s;
    init();
    solve();
}
