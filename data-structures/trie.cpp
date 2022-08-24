#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5;

struct trie
{
    struct trie_node
    {
        int ch[26];
        int n_substr;
        int n_str;
    };

    vector<trie_node> nodes;
    int tt = 0;

    trie(int n = 1e5) {
        nodes.resize(n);
    }

    void insert(string s)
    {
        if(s.size() > nodes.size()) {
            nodes.resize(s.size() * 2);
        }

        int curr = 0;
        for(char c: s) {
            // If there is no next
            if(nodes[curr].ch[c - 'a'] == 0) {
              nodes[++tt].n_str = 0;
              nodes[tt].n_substr = 0;
              memset(nodes[tt].ch, 0, sizeof nodes[tt].ch);
              nodes[curr].ch[c - 'a'] = tt;
            }
            // curr := curr->next
            ++nodes[curr].n_substr;
            curr = nodes[curr].ch[c - 'a'];
        }
        ++nodes[curr].n_str;
    }

    int cnt_str(string s)
    {
        int curr = 0;
        for(char c : s) {
            if(nodes[curr].ch[c - 'a'] == 0) {
                return 0;
            }

            curr = nodes[curr].ch[c - 'a'];
        }

        return nodes[curr].n_str;
    }

    bool has_str(string s)
    {
        return this->cnt_str(s) > 0;
    }

    int cnt_substr(string substr)
    {
        int curr = 0;
        for(char c: substr) {
            if(nodes[curr].ch[c - 'a'] == 0) {
                return 0;
            }
            curr = nodes[curr].ch[c - 'a'];
        }

        return nodes[curr].n_substr;
    }

    bool has_substr(string s)
    {
        return this->cnt_substr(s) > 0;
    }
};

int main()
{
    trie tr(100);

    tr.insert("jose");
    tr.insert("eduardo");
    tr.insert("eduardo");
    tr.insert("eduardo");

    cout << tr.cnt_str("eduardo") << '\n';
    cout << tr.cnt_str("jose") << '\n';
    cout << tr.cnt_substr("edu") << '\n';
    cout << tr.cnt_substr("jos") << '\n';
    tr.insert("josa");
    tr.insert("edua");
    cout << tr.cnt_substr("jos") << '\n';
    cout << (tr.has_substr("edus") ? "yes" : "no") << '\n';
    cout << (tr.has_substr("edua") ? "yes" : "no") << '\n';
    cout << tr.cnt_substr("edu") << '\n';
}
