# Union-Find木

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                        |
| :----:        | :------                                                        |
| commad        | `:Library uf`                                                 |
| sample        | [UnionFind.cpp](/sample/UnionFind.cpp)                            |
| link          | [参考ソースコード(AtCoder)](https://github.com/atcoder/live_library/blob/master/uf.cpp) |

## 使用

### **[構造体]**
**UnionFind(int n)**
### 説明
- 頂点数 n の通常のUnionFind木
### 制約
- `0 <  n < (1<<31)`
### 計算量
- `α(n) `


<br>


## ソースコード

### 依存
```cpp
#include <vector>
using namespace std;
```

### 実装
```cpp
struct UnionFind {
    vector<int> data;
    UnionFind(int n) : data(n, -1) {}
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
```

### 解説
コンストラクタ: 要素数(頂点数)を指定
```cpp
struct UnionFind {
    // 自身が根: その集合の要素数に-1を掛けたもの
    // 自身が葉: 根のID
    // -> 根であれは負の数、葉であれば正の数
    vector<int> data;

    // 全てを根として初期化
    UnionFind(int n = 0) : data(n, -1) {}

    // 根の検索
    int root(int x) {
        if(data[x] < 0) return x;
        return data[x] = root(data[x]); // 経路圧縮
    }

    // 集合の結合
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;

        // 要素数が小さい方を大きい方に結合する
        if(data[x] > data[y]) swap(x, y); // -data[x] > -data[y] となるようにしたい
        data[x] += data[y]; // 要素数の加算
        data[y] = x; // 集合の結合
        return true;
    }

    // 要素xと要素yが同じ集合に属しているか
    bool same(int x, int y) { return root(x) == root(y); }

    // 要素xが属している集合の大きさ(サイズ)
    int size(int x) { return -data[root(x)]; }
};
```
