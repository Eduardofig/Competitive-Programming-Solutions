#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, k, m;
//int a[MXN];
//int b[MXN];
string s;
vector<pair<int, char>> changes;

bool deleted[MXN]{};

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

int find(vector<seg_tree> &sts, int occ, char c)
{
    int high = m * k - 1, low = 0;

    while(high > low) {
        int mid = low + (high - low) / 2;

        if(sts[c - 'a'].query(0, mid) >= occ) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return high;
}

void solve()
{
    m = s.size();
    vector<seg_tree> sts(26, seg_tree(m * k));

    for(int i = 0; i < m * k; i++) {
        sts[s[i % m] - 'a'].update(i, 1);
    }

    for(auto &[p, c]: changes) {
        int pos = find(sts, p, c);

        deleted[pos] = true;

        sts[c - 'a'].update(pos, 0);
    }

    for(int i = 0; i < m * k; i++) {
        if(!deleted[i]) {
            cout << s[i % m];
        }
    }

    cout << '\n';
}

void read()
{
    cin >> k >> s >> n;
    changes.resize(n);

    for(auto &[p, c] : changes) {
        cin >> p >> c;
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
