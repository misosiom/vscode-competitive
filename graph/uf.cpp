class UnionFind {
	public:
		int par[100009];
		int siz[100009];

		// N 頂点の Union-Find を作成
		void init(int N) {
			for (int i = 0; i < N; i++) par[i] = -1; // 最初は親が無い
			for (int i = 0; i < N; i++) siz[i] = 1; // 最初はグループの頂点数が 1
		}
		// 頂点 x の根を返す関数
		int root(int x) {
			while (true) {
				if (par[x] == -1) break; // 1 個先（親）がなければ、ここが根
				x = par[x]; // 1 個先（親）に進む
			}
			return x;
		}
	
		// 要素 u と v を統合する関数
		void unite(int u, int v) {
			int RootU = root(u);
			int RootV = root(v);
			if (RootU == RootV) return; // u と v が同グループのときは処理を行わない
			if (siz[RootU] < siz[RootV]) {
				par[RootU] = RootV;
				siz[RootV] = siz[RootU] + siz[RootV];
			}
			else {
				par[RootV] = RootU;
				siz[RootU] = siz[RootU] + siz[RootV];
			}
		}
	
		// 要素 u と v が同一のグループかどうかを返す関数
		bool same(int u, int v) {
			if (root(u) == root(v)) return true;
			return false;
		}
};
