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

int n, m;
//int k;
set<int> cant;
//int b[MXN];
//string s;
 
void solve()
{
    set<int> ans;
    int tot = 0;
    int curr = 1;
    while(true) {
        if(cant.find(curr) == cant.end()) {
            if(tot + curr <= m) {
                ans.insert(curr);
                tot += curr;
            } else {
                break;
            }
        }
        curr++;
    }

    cout << ans.size() << '\n';
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

    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int toy;
        cin >> toy;
        cant.insert(toy);
    }
    solve();
}
