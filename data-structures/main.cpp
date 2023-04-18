#include <bits/stdc++.h>

#define For(i, n) for(int i = 0; i < (int)(n); ++i)
#define Foro(i, n) for(int i = 1; i < (int)(n); ++i)
#define Forr(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define Forl(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define Fore(v, ...) for(auto &[__VA_ARGS__]: (v))
#define All(x) (x).begin(), (x).end()
#define Mini(x, y) (x) = min((x), (y))
#define Maxi(x, y) (x) = max((x), (y))
#define pb push_back
#define eb emplace_back
#define ii pair<int, int>
#define iii tuple<int, int, int>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

ll n, m, k, p, u, x, w, z;
// vector<int> a(MXN);
// vector<int> b(MXN);
// vector<int> v(MXN);
// vector<vector<int>> g(MXN, vector<int>());
// string s;

int nxt()
{
    int x;
    cin >> x;
    return x;
}

class seg_tree
{
    private:
        const int ROOT = 1;

        int n;
        vector<int> tree;

        int recurse_query(int node, int query_low, int query_high, int node_low, int node_high)
        {
            // node is completely inside interval [query_low, query_high]
            if(query_low <= node_low && query_high >= node_high) {
                return tree[node];
            }
            // node is completely outside interval [query_low, query_high]
            if(query_high < node_low || query_low > node_high) {
                return 0;
            }

            int left = 2 * node, right = 2 * node + 1;

            int mid = node_low + (node_high - node_low) / 2;

            return recurse_query(left, query_low, query_high, node_low, mid) + 
                recurse_query(right, query_low, query_high, mid + 1, node_high);

        }

    public:
        int query(int low, int high)
        {
            return recurse_query(ROOT, low, high, 0, n - 1);
        }

        void update(int target_node, int value)
        {
            // update the value of a[i] to v
            tree[n + target_node] = value;

            // iterate through all parents of i and recalculate their values
            int par = (n + target_node) / 2;
            for(int node = par; node >= ROOT; node /= 2) {
                int left = 2 * node, right = 2 * node + 1;

                tree[node] = tree[left] + tree[right];
            }
        }

        void build(vector<int> arr)
        {
            n = arr.size();
            // pad a[i] with 0's to make it's size a power of 2
            while(__builtin_popcount(n) != 1) {
                arr.push_back(0);
                n++;
            }

            // tree size is twice the size of the array
            tree.resize(2 * n);

            // fill in leaf nodes
            for(int i = 0; i < n; ++i) {
                tree[n + i] = arr[i];
            }

            // Fill in remaining nodes from bottom up
            for(int node = n - 1; node >= ROOT; --node) {
                int left = 2 * node, right = 2 * node + 1;

                // A node is the sum of two children
                tree[node] = tree[left] + tree[right];
            }
        }

        seg_tree(vector<int> arr)
        {
            build(arr);
        }

        seg_tree(int n)
        {
            while(__builtin_popcount(n) != 1) {
                n++;
            }

            tree.resize(2 * n, 0);
            this->n = n;
        }
};

vector<vector<int>> g(MXN);
vector<vector<ii>> g2(MXN);
vector<int> cost(MXN, 0);

struct lca_blifting
{
    vector<int> depth;
    vector<vector<int>> par;

    int ROOT = 0;
    const int MXLOG = 21;

    void dfs(int u, int prev)
    {
        par[u][0] = prev;
        for(int pow = 1; pow < MXLOG; ++pow) {
            par[u][pow] = par[par[u][pow - 1]][pow - 1];
        }

        for(int v: g[u]) {
            // Unvisited
            if(depth[v] == -1) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

    lca_blifting(int n, int root = 0): depth(n, -1), par(n, vector<int>(32, -1)), ROOT{ root }
    {
        fill(par[ROOT].begin(), par[ROOT].end(), ROOT);
        depth[ROOT] = 0;

        dfs(ROOT, ROOT);
    }

    int get_lca(int u, int v)
    {
        if(depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v] - depth[u];

        for(int mask = 0; mask < MXLOG; ++mask) {
            if((diff & (1 << mask)) != 0) {
                v = par[v][mask];
            }
        }

        assert(depth[v] == depth[v]);

        for(int mask = MXLOG - 1; mask >= 0 && par[u][0] != par[v][0]; --mask) {
            int nextu = par[u][mask];
            int nextv = par[v][mask];

            if(nextu != nextv) {
                u = nextu;
                v = nextv;
            }
        }

        if(u == v) {
            return u;
        } else {
            return par[u][0];
        }
    }
};

vector<int> who(MXN, -1);
vector<int> subtree_size(MXN, 1);
vector<int> par(MXN);

map<int, vector<int>> mp;
map<int, int> idx;
map<int, unique_ptr<seg_tree>> mpseg;
map<int, int> edge_node;

vector<bool> vis_heavy(MXN);
vector<bool> vis(MXN);
vector<bool> vis_final(MXN);

void dfs_heavy(int u)
{
    vis_heavy[u] = true;

    Fore(g2[u], v, w) {
        if(!vis_heavy[v]) {
            cost[v] = w;
            dfs_heavy(v);
            subtree_size[u] += subtree_size[v];
        }
    }
}

void dfs(int u, int prev)
{
    who[u] = prev;
    vis[u] = true;

    int biggest = g[u].front();

    for(int v: g[u]) {
        if(vis[biggest] || !vis[v] && subtree_size[v] > subtree_size[biggest]) {
            biggest = v;
        }
    }

    for(int v: g[u]) {
        if(!vis[v]) {
            if(v == biggest) {
                dfs(v, who[u]);
            } else {
                dfs(v, v);
            }
        }
    }
}

void dfs_final(int u, int prev)
{
    par[u] = prev;
    vis_final[u] = true;

    mp[who[u]].pb(u);

    for(int v: g[u]) {
        if(!vis_final[v]) {
            dfs_final(v, u);
        }
    }
}

int chain_query(int u, int end, int tot)
{
    tot += mpseg[who[u]]->query(idx[who[u]], idx[u]);

    if(who[u] == end) {
        return tot;
    }

    return chain_query(par[who[u]], end, tot);
}

int query(int u, int v, lca_blifting &lcab)
{
    int lca = lcab.get_lca(u, v);

    return chain_query(u, lca, 0) + chain_query(v, lca, 0) - cost[lca];
}

void update(int u, int new_u)
{
    mpseg[who[u]]->update(idx[u], new_u);
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        fill(All(g), vector<int>());
        fill(All(g2), vector<ii>());
        iota(All(par), 0);
        fill(All(who), -1);
        fill(All(subtree_size), 1);
        fill(All(cost), 0);
        fill(All(vis_heavy), false);
        fill(All(vis), false);
        fill(All(vis_final), false);

        mp.clear();
        idx.clear();
        mpseg.clear();
        edge_node.clear();

        int n;
        cin >> n;

        Foro(i, n) {
            int u, v, w;

            cin >> u >> v >> w;

            g[u].pb(v);
            g[v].pb(u);

            g2[v].eb(u, w);
            g2[u].eb(v, w);

            edge_node[i] = v;
        }

        dfs_heavy(1);
        dfs(1, 1);
        dfs_final(1, 1);

        Fore(mp, num, vec) {
            // cout << endl;
            // cout << who[num] << ": [";
            // for(int i: vec) {
            //     cout << "{" << i << ", " << cost[i]  << "}, ";
            // }
            // cout << "]\n";

            For(u, vec.size()) {
                idx[vec[u]] = u;
                vec[u] = cost[vec[u]];
            }


            mpseg[num] = make_unique<seg_tree>(vec);
        }

        lca_blifting lcab(MXN, 1);

        string op;

        while(true) {
            cin >> op;

            if(op == "DONE") {
                break;
            }

            if(op == "CHANGE") {
                int edge, change;

                cin >> edge >> change;

                update(edge_node[edge], change);
            } else {
                int a, b;

                cin >> a >> b;

                cout << query(a, b, lcab) << '\n';
            }
        }
    }
}
