# Dijkstra法(単一始点最短経路)

| - - - - - - - | - - - - - - - - - - - - - - - - - - - - |
| :----:        | :------                                 |
| commad        | `:Library dijkstra`                     |
| sample        | [Dijkstra.cpp](/sample/Dijkstra.cpp)    |
| link          | 参考: 蟻本                              |

## 使用

### **[構造体]**
**Dijkstra<T>(int v, T inf)**
### 説明
- priority_queueを使用したダイクストラ法
### 制約
- グラフ: 重み付き有向グラフ(負の辺なし)
- `0 < v < (1<<31)`
### 計算量
- `calc: O(|E|log|V|)`


<br>


## ソースコード

### 依存
```cpp
#include <vector>
#include <queue>
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
using namespace std;
```

### 実装
```cpp
template<class T> struct Dijkstra{
    using P = pair<T, int>;
    Dijkstra(int v, T inf) : size(v),inf(inf),graph(v,vector<Edge>()),dist(v){}
    void addEdge(int from, int to, T cost){
        graph[from].push_back({to, cost});
    }
    void calc(int start){
        priority_queue<P, vector<P>, greater<P>> que;
        fill(dist.begin(), dist.end(), inf);
        dist[start] = 0;
        que.push({0, start});
        while(que.size()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(auto& e : graph[v]) if(chmin(dist[e.to], dist[v]+e.cost)){
                que.push({dist[e.to], e.to});
            }
        }
    }
    T getDist(int v){ return dist[v]; }
    private:
        struct Edge{ int to; T cost; };
        int size;
        T inf;
        vector<vector<Edge>> graph;
        vector<T> dist;
};
```

### 解説
```cpp
template<class T> struct Dijkstra{
    // firstは最短距離、secondは頂点の番号
    using P = pair<T, int>;
    // コンストラクタ ( Dijkstra<T> dijk(v, inf); )
    // 頂点の数、無限の値
    Dijkstra(int v, T inf) : size(v),inf(inf),graph(v,vector<Edge>()),dist(v){}
    // 有向辺の追加
    void addEdge(int from, int to, T cost){
        graph[from].push_back({to, cost});
    }
    // 最短経路を計算
    void calc(int start){
        // {最短距離, 頂点番号} で 大きい順に取り出せる queue
        priority_queue<P, vector<P>, greater<P>> que;
        // infで初期化、start は 0
        fill(dist.begin(), dist.end(), inf);
        dist[start] = 0;
        // 探索
        que.push({0, start});
        while(que.size()){
            // 距離が最小の頂点を取得
            P p = que.top(); que.pop();
            // その頂点番号をキャッシュ
            int v = p.second;
            // 最短距離でない(すでに最短距離が確定してある)なら無視
            if(dist[v] < p.first) continue;
            // 最小の頂点に隣接する頂点を探索
            // 最短距離を更新する
            //  -> 更新されたならば、キューに次の最短距離候補としてプッシュ
            for(auto& e : graph[v]) if(chmin(dist[e.to], dist[v]+e.cost)){
                que.push({dist[e.to], e.to});
            }
        }
    }
    T getDist(int v){ return dist[v]; }
    private:
        struct Edge{ int to; T cost; };
        int size; // 頂点の数
        T inf; // 無限の値
        vector<vector<Edge>> graph; // 重み付き有向グラフ
        vector<T> dist; // 最短距離
};
```
