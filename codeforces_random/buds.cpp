#include <bits/stdc++.h>

using namespace std;

const bool DEBUG = false;
const int MXN = 100;
int n, root = 0, leaves, buds;
vector<int> g[MXN];
bool vis[MXN]{};

bool dfs(int curr)
{
    vis[curr] = true;

    if(g[curr].size() == 0) {
        leaves++;
        return false;
    }

    int child_buds = 0;
    for(int next: g[curr]) {
        if(!vis[next]) {
            child_buds += (int)dfs(next);
        }
    }

    if(child_buds == g[curr].size()) {
        if(curr != root) {
            leaves++;
        }
        return false;
    } else {
        if(curr != root) {
            buds++;
        }
        return true;
    }
}

void solve()
{
    leaves = 0;
    buds = 0;
    dfs(root);

    bool root_has_leaf = false;
    for(int neigh: g[root]) {
        if(g[neigh].size() == 0) {
            root_has_leaf = true;
        }
    }

    if(!root_has_leaf) {
        buds--;
    }

    if(DEBUG) {
        cout << "leave " << leaves << " buds " << buds << endl; 
    }

    cout << max(leaves - buds, 0) << '\n';
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        if(DEBUG) {
            cout << "test case " << i << endl;
        }
        cin >> n;
        for(int j = 0; j < MXN; ++j) {
            g[j].clear();
            vis[j] = false;
        }
        for(int j = 0; j < n - 1; ++j) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            int from = min(u, v), to = max(u, v);
            if(DEBUG) {
                cout << "edge from " << u << " to " << v << endl;
            }
            g[from].push_back(to);
        }

        solve();
    }
}
