#include <bits/stdc++.h>

using namespace std;

const int NODE_MAX = 200000; // check

struct Seg{
    int tree[1 << 19]; // check
    int sz = 1 << 18; // check bigger than node max number (cnt)

    void update(int x, int v){
        x |= sz; tree[x] = v;
        while(x >>= 1){
            tree[x] = min(tree[x << 1], tree[x << 1 | 1]); // check
        }
    }

    //[l, r]
    int query(int l, int r){
        l |= sz, r |= sz;
        int ret = 1; // check
        while(l <= r){
            if(l & 1) ret = min(ret, tree[l++]); // check
            if(~r & 1) ret = min(ret, tree[r--]); // check
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}seg;

int sz[NODE_MAX + 1], dep[NODE_MAX + 1], par[NODE_MAX + 1], top[NODE_MAX + 1], in[NODE_MAX + 1], out[NODE_MAX + 1];
vector<int> g[NODE_MAX + 1];
vector<int> adj[NODE_MAX + 1]; 

int chk[NODE_MAX + 1];
void dfs(int v = 1){
	chk[v] = 1;
	for(auto i : adj[v]){
		if(chk[i]) continue;
		chk[i] = 1;
		g[v].push_back(i);
		dfs(i);
	}
}

void dfs1(int v = 1){
	sz[v] = 1;
	for(auto &i : g[v]){
		dep[i] = dep[v] + 1; par[i] = v;
		dfs1(i); sz[v] += sz[i];
		if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
}

int pv;
void dfs2(int v = 1){
	in[v] = ++pv;
	for(auto i : g[v]){
		top[i] = i == g[v][0] ? top[v] : i;
		dfs2(i);
	}
	out[v] = pv;
}

void update(int v, int w){
    seg.update(in[v], w);
}

int query(int a, int b){
    int ret = 1; // check
    while(top[a] ^ top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = min(ret, seg.query(in[st], in[a])); // check
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret = min(ret, seg.query(in[a] + 1, in[b])); // check
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, Q;

    cin >> N >> Q;

    fill(seg.tree, seg.tree + size(seg.tree), 1);

    for (int i = 2; i <= N; ++i) {
        int num;
        cin >> num;
        adj[i].push_back(num);
        adj[num].push_back(i);
    }

    dfs(); dfs1(); dfs2();
    
    while (Q--) {
        int b, c, d;
        cin >> b >> c >> d;

        if (query(b, c)) {
            cout << "YES\n";
            if (d) update(b, 0);
        } else {
            cout << "NO\n";
            if (d) update(c, 0);
        }
    }
}