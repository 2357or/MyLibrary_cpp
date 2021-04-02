# 素数判定

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                          |
| :----:        | :------                                                          |
| commad        | `:Library is_prime`                                              |
| sample        | [is_prime.cpp](/sample/is_prime.cpp)                               |
| link          | [参考記事](https://qiita.com/EqualL2/items/b3c2530c458f8450d390) |

## 使用

### **[関数]**
**is_prime(ll n) -> bool**
### 説明
- nが素数であるか判定する
### 制約
- `-(1<<31) < n < (1<<31)`
### 計算量
- `O(√n)`


<br>


## ソースコード

### 依存
```cpp
using namespace std;
using ll=long long;
```

### 実装
```cpp
bool is_prime(const ll n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i*i <= n; i += 6){
        if((n % i == 0) || (n % (i+2) == 0)) return false;
    }
    return true;
}
```

### 解説
ex) 73 -> true, 93 -> false

```cpp
bool is_prime(const ll n){
    // 0, 1, 負の数は素数ではない
    if(n < 2) return false;

    // 2と3は素数
    if(n == 2 || n == 3) return true;

    // 2の倍数、3の倍数を除去
    if(n % 2 == 0 || n % 3 == 0) return false;

    // n は n > 3 であり、2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である

    // 6の倍数前後の数を使って試し割りをする
    for(ll i = 5; i * i <= n; i += 6){
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }

    // 全て通り抜けたら素数
    return true;
}

ll n;
int main() {
    cin >> n;
    cout << (is_prime(n) ? "Yes" : "No" ) << endl;
}
```
