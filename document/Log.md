# Log

| - - - - - - - | - - - - - - - - - - - - - - - - - - - - |
| :----:        | :------                                 |
| commad        | `:Library log`                          |
| sample        | [Log.cpp](/sample/Log.cpp)              |
| link          | non                                     |

## 使用

### **[関数]**
**log(ll a, ll b)**
### 説明
- aを底, bを真数 とした対数を解く
### 制約
- `-(1<<63) < a, b < (1<<63)` (未定義の値: nan)
### 計算量
- `O(1)`


<br>


## ソースコード

### 依存
```cpp
#include <cmath>
using namespace std;
using ld=long double;
```

### 実装
```cpp
ld log_n(ld a, ld b){
    if(a<=0 || b<=0 || b==1) return numeric_limits<ld>::quiet_NaN();
    if(a==1) return 0;
    return logl(b)/logl(a);
}
```

### 解説
ex) 10, 2 -> 0.30103
```cpp
/* 条件
 a: 底 (a > 0)
 b: 真数 (b > 1, b != 1)
*/
ld log_n(ld a, ld b){
    // 底と真数の条件に不一致のものはnan
    if(a<=0 || b<=0 || b==1) return numeric_limits<ld>::quiet_NaN();

    // a = 1　=> log(a) = 0
    // 以下で0除算が発生するので0を返す
    if(a==1) return 0;

    // 底の変換公式より、e(自然対数)を底としたものに変換
    return logl(b)/logl(a);
}
```
