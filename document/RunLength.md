# RunLength圧縮

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                                                        |
| :----:        | :------                                                                                        |
| commad        | `:Library runlength`(encode only: `:Library runlength-e`, decode only: `:Library runlength-d`) |
| sample        | [RunLength.cpp](/sample/RunLength.cpp)                                                                  |
| link          | [参考記事](https://algo-logic.info/run-length/)                                                |

## 使用

### **[関数]**
**RunLength_encode(string s) -> vector<char, int>**
### 説明
- RunLength圧縮を行う
- 文字列を引数にとり、vector\<文字, 回数\> の形に変化する
### 制約
- `|s| < (1<<63)`
### 計算量
- `O(n)`

<br>

**RunLength_decode(vector<pair<char, int>> p) -> string**
### 説明
- RunLength圧縮されたのもを文字列に復元する
- vector\<文字, 回数\>を引数にとり、文字列を返す
### 制約
- non
### 計算量
- `O(n)`

<br>


## ソースコード

### 依存
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
```

### 実装
```cpp
vector<pair<char, int>> RunLength_encode(const string& s) {
    vector<pair<char, int>> res;
    ll len = s.size();
    ll l = 0;
    while(l < len){
        int r = l + 1;
        while(r < len && s[l] == s[r]) r++;
        res.push_back({s[l], r-l});
        l = r;
    }
    return res;
}
string RunLength_decode(const vector<pair<char, int>>& p){
    string res = "";
    for(auto x : p){
        int c = x.first, len = x.second;
        rep(_, 0, len) res += c;
    }
    return res;
}
```

### 解説
encode: 文字列を引数にとり、vector\<文字, 回数\> の形に変化する  
decode: vector\<文字, 回数\>を引数にとり、文字列を返す

```cpp
// 圧縮
vector<pair<char, int>> RunLength_encode(const string& s) {
    // 変換先
    vector<pair<char, int>> res;

    // 文字列の長さをキャッシュして高速化
    ll len = s.size();

    // 二分探索のように
    // l, r で現在の位置を取りながら最後までループを回す
    ll l = 0;
    while(l < len){
        int r = l + 1;
        while(r < len && s[l] == s[r]) r++;

        // r-lが文字の出現回数になる
        res.push_back({s[l], r-l});
        l = r;
    }

    return res;
}

// 復元
string RunLength_decode(const vector<pair<char, int>>& p){
    // 復元先
    string res = "";

    // first の文字を seconde 回だけ結合する
    for(auto x : p){
        int c = x.first, len = x.second;
        rep(_, 0, len) res += c;
    }

    return res;
}
```
