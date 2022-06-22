#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 7;

vector<int> tmp_g[MXN];
vector<int> g[MXN];
int par[MXN];
int nchild[MXN];
int n;

void dfs(int curr)
{
    for(int next: tmp_g[curr]) {
        if(par[next] == -1) {
            par[next] = curr;
            dfs(next);
        }
    }
}

int calc_child(int curr)
{
    for(int child: g[curr]) {
        nchild[curr] += calc_child(child);
    }

    return nchild[curr] + 1;

}

int rec_solve(int curr)
{
    int ans = 0;

    if(g[curr].size() > 0) {
        switch(g[curr].size()) {
            case 1:
                ans += nchild[g[curr][0]];
                break;
            case 2:
                if(nchild[g[curr][0]] > nchild[g[curr][1]]) {
                    ans += nchild[g[curr][0]];
                    ans += rec_solve(g[curr][1]);
                } else {
                    ans += nchild[g[curr][1]];
                    ans += rec_solve(g[curr][0]);
                }
                break;
            default:
                break;
        }
    }

    return ans;
}

void solve()
{
    memset(par, -1, sizeof par);
    par[0] = 0;
    dfs(0);

    for(int i = 1; i < n; ++i) {
        g[par[i]].push_back(i);
    }
    memset(nchild, 0, sizeof nchild);

    calc_child(0);

    cout << rec_solve(0) << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < MXN; ++j) {
            g[j].clear();
            tmp_g[j].clear();
        }
        for(int j = 0; j < n - 1; ++j) {
            int from, to;
            cin >> from >> to;
            tmp_g[from - 1].push_back(to - 1);
            tmp_g[to - 1].push_back(from - 1);
        }
        solve();
    }
}
