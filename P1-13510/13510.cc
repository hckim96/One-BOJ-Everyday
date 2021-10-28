#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Seg{
    int tree[1 << 18];
    int sz = 1 << 17;

    void update(int x, int v){
        x |= sz; tree[x] = v;
        while(x >>= 1){
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    int query(int l, int r){
        l |= sz, r |= sz;
        int ret = 0;
        while(l <= r){
            if(l & 1) ret = max(ret, tree[l++]);
            if(~r & 1) ret = max(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}seg;

int sz[101010], dep[101010], par[101010], top[101010], in[101010], out[101010];
vector<int> g[101010];
vector<int> inp[101010]; 
tuple<int, int, int> edge[100001];
int edgeToNode[100001];

int chk[101010];
void dfs(int v = 1){
	chk[v] = 1;
	for(auto i : inp[v]){
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
    int ret = 0;
    while(top[a] ^ top[b]){
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, seg.query(in[st], in[a]));
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a, b);
    ret = max(ret, seg.query(in[a] + 1, in[b]));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N;
    cin >> N;
    for (int i = 1; i <= N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        inp[u].push_back(v);
        inp[v].push_back(u);
        edge[i] = {u, v, w};
    }

    dfs();
    dfs1();
    dfs2();
    for (int i = 1; i <= N - 1; ++i) {
        auto [u, v, w] = edge[i];
        if (u == par[v]) {
            edgeToNode[i] = v;
            update(v, w);
        } else {
            edgeToNode[i] = u;
            update(u, w);
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) update(edgeToNode[a], b);
        else cout << query(a, b) << "\n";
    }
}