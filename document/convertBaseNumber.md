# Convert Base Number

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                |
| :----:        | :------                                                |
| commad        | `:Library conv_base`                                   |
| sample        | [convertBaseNumber.cpp](/sample/convertBaseNumber.cpp) |
| link          | non                                                    |

## 使用

### **[関数]**
**convertBaseNumber(T n, const int to)**
### 説明
- 10進数の n を to進数に変換する
### 制約
- `0 < n < (1<<63)`
- `1 < to < (36)
### 計算量
- `O(log(n))`


<br>


## ソースコード

### 依存
```cpp
#include <string>
using namespace std;
```

### 実装
```cpp
template<class T>string convertBaseNumber(T n, const int to){
    string res = "";
  	while(n){
        int t = n%to; n /= to;
        res += t + (t<10 ? 48 : 87);
    }
    reverse(res.begin(), res.end());
    return res;
}
```

### 解説
```cpp
template<class T>string convertBaseNumber(T n, const int to){
    string res = "";  // リザルト

  	while(n){
        int t = n%to; n /= to;

        res += char(t + (t<10 ? 48 : 87));
        /* ↑を展開
         if(t < 10) res += t + '0'  // 普通にchar変換
         else res += 'a' + t-10;  // abc...に変換
        */
    }
    reverse(res.begin(), res.end());

    return res;
}
```
