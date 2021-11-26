#include <bits/stdc++.h>

using namespace std;

const int MXN = 101, INF = 0x3f3f3f3f;
int capacity[MXN][MXN], flow[MXN][MXN], par[MXN];
bool vis[MXN];
int s, t, c, n, ans, network = 1;

void ford_fulkerson()
{
    while(true) {
        queue<int> q;
        int bottleneck = INF, curr;
        bool found = false;
        memset(par, -1, sizeof par);
        memset(vis, false, sizeof vis);
        vis[s] = true;

        q.push(s);

        while(!q.empty()) {
            curr = q.front();
            q.pop();

            if(curr == t) {
                while(curr != s) {
                    bottleneck = min(bottleneck, capacity[par[curr]][curr] - flow[par[curr]][curr]);
                    curr = par[curr];
                }

                curr = t;
                while(curr != s) {
                    flow[par[curr]][curr] += bottleneck;
                    flow[curr][par[curr]] -= bottleneck;
                    curr = par[curr];
                }

                found = true;
                ans += bottleneck;

                break;
            }

            for(int to = 0; to < n; ++to) {
                if(capacity[curr][to] > flow[curr][to] && !vis[to]) {
                    vis[to] = true;
                    par[to] = curr;
                    q.push(to);
                }
            }
        }

        if(!found) {
            cout << "Network " << network++ << endl;
            cout << "The bandwidth is " << ans << "." << endl << endl;
            return;
        }

        found = false;
        bottleneck = INF;
    }
}

int main()
{
    int from, to, cap;
    while(true) {
        cin >> n;
        if(!n) break;

        memset(capacity, 0, sizeof capacity);
        memset(flow, 0, sizeof flow);
        memset(vis, false, sizeof vis);
        ans = 0;

        cin >> s >> t >> c;
        s--, t--;
        for(int i = 0; i < c; ++i) {
            cin >> from >> to >> cap;
            from--, to--;

            capacity[from][to] += cap;
            capacity[to][from] += cap;
        }

        ford_fulkerson();
    }
}
