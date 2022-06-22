#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6;

int n_nodes = 0, n_roads;
vector<int> edges[MXN];
bool vis[MXN];
int ans = 0;

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    int par[MXN], ans = 1;
    memset(par, -1, sizeof par);

    while(!q.empty()) {
        int curr = q.front(), prev = -1;
        q.pop();

        if(vis[curr]) {
            continue;
        }

        vis[curr] = true;


        for(int neigh: edges[curr]) {
            if(!vis[neigh]) {
                q.push(neigh);
                par[neigh] = curr;
            } else {
                if(par[neigh] != curr && neigh != par[curr]) {
                    ans = 0;
                }
            }
        }

        prev = curr;
    }

    return ans;
}

int main()
{
    cin >> n_nodes >> n_roads;

    int from, to;
    memset(vis, false, sizeof vis);

    for(int i = 0; i < n_roads; ++i) {
        cin >> from >> to;
        from--; to--;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int ans = 0;
    for(int node = 0; node < n_nodes; ++node) {
        if(!vis[node]) {
            ans += bfs(node);
        }
    }

    cout << ans << endl;
}
