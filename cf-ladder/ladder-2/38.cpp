#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
//using l = long;
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
    deque<int> ans;

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'l') {
            ans.push_back(i + 1);
        } else {
            ans.push_front(i + 1);
        }
    }

    for(int i: ans) {
        cout << i << '\n';
    }
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
