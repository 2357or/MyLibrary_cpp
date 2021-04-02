# 素因数分解

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                                                                        |
| :----:        | :------                                                                                                        |
| commad        | `:Library prime_fact`                                                                                          |
| sample        | [PrimeFactorization.cpp](/sample/PrimeFactorization.cpp)                                                       |
| link          | [参考記事](https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3) |

## 使用

### **[関数]**
**prime_factorization(ll n) -> vector<pair<ll, ll>>**
### 説明
- nを素因数分解し、RanLength圧縮した形にする(first: 素数, second: 指数)
### 制約
- `1 < n < (1<<31)`
### 計算量
- `O(√n)`


<br>


## ソースコード

### 依存
```cpp
#include <utility>
#include <vector>
using namespace std;
using ll=long long;
```

### 実装
```cpp
vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> res;
    ll ex = 0;
    while (n%2 == 0) {
        ex++; n /= 2;
    }
    if(ex != 0) res.push_back({2, ex});
    for(ll i = 3; i*i <= n; i += 2 ){
        ex = 0;
        while(n%i == 0){
            ex++; n /= i;
        }
        if(ex != 0) res.push_back({i, ex});
    }
    if(n != 1) res.push_back({n, 1});
    return res;
}
```

### 解説
引数: 素因数分解したい数値

戻り値: pairの配列 (first: 素数, second: 数指)

ex) 60 -> [{2, 2}, {3, 1}, {5, 1}]

```cpp
vector<pair<ll, ll>> prime_factorization(ll n){
    // レスポンス
    vector<pair<ll, ll>> res;


    // 指数
    // その素数がいくつ含まれているかカウントする変数
    ll ex = 0;

    // 偶数除去
    // 割れる限り割り続ける
    while (n % 2 == 0) {
        ex++;
        n /= 2;
    }

    // 一回でも割れていればresに追加
    if(ex != 0) res.push_back({2, ex});


    // 奇数のみを対象に割り続ける
    // 範囲は√n 以下
    for(ll i = 3; i*i <= n; i += 2 ){
        // 指数を初期化
        ex = 0;

        // 破れる限り割り続ける
        while(n % i == 0){
            ex++;
            n /= i;
        }

        // 一回でも割れていればresに追加
        // これはwhile分の直前に if (N % a != 0) continue; するのと同じ
        if(ex != 0) res.push_back({i, ex});
    }


    // √n 以下まで割り終えた時、nは
    // n = 1 (...A)
    // n > 1 (...B)
    // であり、Aの場合、素因数分解は完全に完了したので、それまでに得られた解を出力すればよい。
    // Bの場合は、残った整数は素数であるのでresに追加する
    if(n != 1) res.push_back({n, 1});

    return res;
}

int main(){
    // 入力
    ll N; cin >> N;

    // 参照を受け取ることでメモリを節約
    const auto &res = prime_factorization(N);

    // N: a a b c c  となるようにフォーマット
    cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;

    return 0;
}
```
