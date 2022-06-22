#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
ll n, t, k;
const int MXN = 2e5 + 3;
ll p[MXN];
ll dist[MXN][MXN];
ll cicle_dist[MXN];
vector<ll> g[MXN];
string s;

void solve()
{
    memset(dist, -1, sizeof dist);

    for(int i = 0; i < n; ++i) {
        g[i].push_back(p[i] - 1);
    }

    for(int i = 0; i < n; ++i) {
        queue<ll> q;
        q.push(i);
        dist[i][i] = 0;

        while(!q.empty()) {
            ll curr = q.front();
            q.pop();
            for(ll neigh: g[curr]) {
                if(dist[i][neigh] == -1) {
                    dist[i][neigh] = dist[i][curr] + 1;
                    q.push(neigh);
                }

                if(neigh == i) {
                    cicle_dist[i] = dist[i][neigh];
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {

    }
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> p[j];
        }
    }
}
