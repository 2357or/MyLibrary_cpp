# 最小公倍数(GCD)

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                        |
| :----:        | :------                                                        |
| commad        | `:Library gcd`                                                 |
| sample        | [GCD-LCM.cpp](/sample/GCD-LCM.cpp)                             |
| link          | [参考記事](https://qiita.com/drken/items/0c88a37eec520f82b788) |

## 使用

### **[関数]**
**gcd(ll a, ll b) -> ll**
### 説明
- 2数の最小公倍数(GCD)を求める
### 制約
- `0 < a, b < (1<<61)`
### 計算量
- `O(log n)`


<br>


## ソースコード

### 依存
```cpp
#include <iostream>
using namespace std;
using ll=long long;
```

### 実装
```cpp
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
```

### 解説
ex) 12, 8 -> 4
```cpp
ll gcd(ll a, ll b) {
    // return b?gcd(b,a%b):a;
    // 展開すると以下のようになる

    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}
```
