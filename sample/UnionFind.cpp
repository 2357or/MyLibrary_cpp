/*
 Library-Checker (https://judge.yosupo.jp/problem/unionfind)

 問題文
 N 頂点 0 辺の無向グラフに Q 個のクエリが飛んできます。処理してください。
  - t = 0 :辺(u, v)を追加する。
  - t = 1 :u,v が連結ならば 1、そうでないなら 0 を出力する。

 入力
 N Q
 t1 u1 v1
 t2 u2 v2
 ...
 tQ uQ vQ


 # Result
 Date: 2020/10/18/SUN/00:10
 Status: AC
 Time: 154ms
 Memory: 1.42MiB
*/

#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)


struct UnionFind {
    vector<int> data;
    UnionFind(int n = 0) : data(n, -1) {}
    int root(int x) {
        if(data[x] < 0) return x;
        return data[x] = root(data[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -data[root(x)]; }
};

int main(){
    int n, q; cin >> n >> q;
    UnionFind UF(n);
    rep(_, 0, q) {
        int t, a, b; cin >> t >> a >> b;
        if(t){
            if(UF.same(a, b)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else UF.unite(a, b);
    }
    return 0;
}

