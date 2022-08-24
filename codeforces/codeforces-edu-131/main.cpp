#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
int arr[MXN];
bool used[MXN];
bool end_rec = false;

void solve_rec(int i, vector<int> perm)
{
    if(end_rec) {
        return;
    }

    if(i > n) {
        for(int num: perm) {
            cout << num << " ";
        }
        cout << '\n';
        end_rec = true;
        return;
    }

    int low, high;
    if(arr[i - 1] == 0) {
        low = i + 1;
        high = n + 1;
    } else {
        low = i / (arr[i - 1] - 1) + 1;
        high = min(i / arr[i - 1], n);
    }
    for(int j = low; j <= high; ++j) {
        if(!used[j]) {
            used[j] = true;
            perm.push_back(j);
            solve_rec(i + 1, perm);
            used[j] = false;
            perm.pop_back();
        }
    }
}

void solve()
{
    memset(used, false, sizeof used);
    solve_rec(1, vector<int>());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        end_rec = false;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
