/*
 AtCoder Beginner Contest 035 D - トレジャーハント
  https://atcoder.jp/contests/abc035/tasks/abc035_d
*/
#include <iostream>
#include <vector>
#include <queue>
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define INFL 2305843009213693952ll // 2e61

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

int main(){
    int n, m, t; cin >> n >> m >> t;
    vector<int> a(n); rep(i, 0, n) cin >> a[i];
    Dijkstra<ll> to(n, INFL), ba(n, INFL);
    rep(_, 0, m){
        int a, b, c; cin >> a >> b >> c;
        a--;b--;
        to.addEdge(a, b, c);
        ba.addEdge(b, a, c);
    }
    to.calc(0); ba.calc(0);
    ll ans = 0;
    rep(i, 0, n){
        ll d = t - to.getDist(i) - ba.getDist(i);
        if(d <= 0) continue;
        chmax(ans, d*a[i]);
    }
    cout << ans << '\n';
    return 0;
}

