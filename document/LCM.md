# 最大公約数(LCM)

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                        |
| :----:        | :------                                                        |
| commad        | `:Library lcm`                                                 |
| sample        | [GCD-LCM.cpp](/sample/GCD-LCM.cpp)                            |
| link          | [参考記事](https://qiita.com/drken/items/0c88a37eec520f82b788) |

## 使用

### **[関数]**
**lcm(ll a, ll b) -> ll**
### 説明
- 2数の最小公約数(LCM)を求める
### 制約
- `0 < a, b < (1<<31)`
### 計算量
- `O(log n)`


<br>


## ソースコード

<b>*注意　gcd(ll, ll)に依存します*</b>
### 依存
```cpp
#include <iostream>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
```

### 実装
```cpp
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
```

### 解説
```cpp
ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;

    // 以下の順に演算を行うとオーバーフローする可能性がある
    // なので上記のように先に割り算をして値を小さくすることが必要
    // return x * y / gcd(x, y);
}
```
