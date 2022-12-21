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
    bool ok1 = s.size() >= 5, ok2{}, ok3{}, ok4{};
    
    for(char c: s) {
        ok2 = ok2 || (c >= '0' && c <= '9');
        ok3 = ok3 || (c >= 'a' && c <= 'z');
        ok4 = ok4 || (c >= 'A' && c <= 'Z');
    }

    if(ok1 && ok2 && ok3 && ok4) {
        cout << "Correct\n";
    } else {
        cout << "Too weak\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    solve();
}
