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
    int i = 0, j = s.size() - 1;

    vector<int> ans;

    while(i < j) {
        while(s[i] != '(') {
            i++;
        }
        if(i >= j) {
            break;
        }
        while(s[j] != ')') {
            j--;
        }

        if(i < j) {
            ans.push_back(i++ + 1);
            ans.push_back(j-- + 1);
        }
    }

    if(ans.empty()) {
        cout << 0 << '\n';
        return;
    }

    cout << 1 << '\n' << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
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
