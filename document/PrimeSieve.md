# PrimeSieve(素数篩)

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                                                |
| :----:        | :------                                                                                |
| commad        | `:Library sieve`                                                                       |
| sample        | [PrimeSieve.cpp](/sample/PrimeSieve.cpp)                                               |
| link          | [atcoder解説ライブラリ](https://github.com/atcoder/live_library/blob/master/prime.cpp) |

## 使用

### **[構造体]**
**PrimeSieve(ll n)**
### 説明
- 大きさnの素数篩を作成する
- 関数
    - isPrime(int): 素数判定
    - divisorCount(int): 約数の数
    - divisors(int): 約数を列挙
    - factorize(int): 素因数分解
### 制約
- `1 < n < (1<<31)`
### 計算量
- コンストラクタ: `O(n log n)`


<br>


## ソースコード

### 依存
```cpp
#include <vector>
using namespace std;
using ll=long long;
```

### 実装
```cpp
struct PrimeSieve{
    int size;
    vector<int> sieve, primes;
    PrimeSieve(int n) : size(n), sieve(n+1){
        sieve[0] = sieve[1] = -1;
        primes.push_back(2);
        for(int i = 2; i <= n; i += 2) sieve[i] = 2;
        for(ll i = 3; i <= n; i += 2){
            if(sieve[i]) continue;
            primes.push_back(i); sieve[i] = i;
            for(ll j = i*i; j <= n; j += i) if (!sieve[j]) sieve[j] = i;
      	}
    }
    bool isPrime(int x){ return sieve[x] == x; }
    vector<int> factorize(int x){
    	vector<int> res;
        while(x != 1){
            res.push_back(sieve[x]);
            x /= sieve[x];
        }
        return res;
    }
    int divisorCount(int x){
    	int cnt = 1, res = 1;
    	while(x != 1){
    	    int b = sieve[x]; x /= sieve[x];
    	    int p = sieve[x];
    	    if(b == p) cnt++;
    	    else{ res *= (cnt+1); cnt = 1; }
        } res *= cnt;
    	return res;
    }
    vector<int> divisors(int x){
        auto fac = factorize(x); vector<int> res = {1};
        for(int& f : fac){
            int size = res.size();
            for(int i=0; i<size; i++) res.push_back(res[i]*f);
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};
```

### 解説
```cpp
struct PrimeSieve{
    // 篩のサイズ
    int size;

    // 篩と、素数の配列
    /* 篩は
      | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |..
      |---|---|---|---|---|---|---|---|---|----|----|----|-
      | -1| 2 | 3 | 2 | 5 | 2 | 7 | 2 | 3 | 2  | 11 | 2  |..
     という形となっている
     (i 番目には i の最小の素因数を持っている)
    */
    vector<int> sieve, primes;

    // コンストラクタで篩を生成する
    PrimeSieve(int n) : size(n), sieve(n+1){
        sieve[0] = sieve[1] = -1;

        // 偶数除去で若干の高速化
        primes.push_back(2);
        for(int i = 2; i <= n; i += 2) sieve[i] = 2;

        for(ll i = 3; i <= n; i += 2){
            if(sieve[i]) continue;
            primes.push_back(i); sieve[i] = i;
            for(ll j = i*i; j <= n; j += i) if (!sieve[j]) sieve[j] = i;
      	}
    }

    // 素数かどうか
    // <=> 最小の素因数が自分自身と同じ数
    bool isPrime(int x){ return sieve[x] == x; }

    // 約数の数を数え上げる
    // 約数は求めていない、係数部分のみ数え上げることで高速化している
    int divisorCount(int x){
    	int cnt = 1, res = 1;
    	while(x != 1){
    	    int b = sieve[x]; x /= sieve[x];
    	    int p = sieve[x];
    	    if(b == p) cnt++;
    	    else{ res *= (cnt+1); cnt = 1; }
        } res *= cnt;
    	return res;
    }

    // 約数を列挙する
    vector<int> divisors(int x){
        // 素因数分解を行う
        auto fac = factorize(x); vector<int> res = {1};
        for(int& f : fac){
            int size = res.size();
            for(int i=0; i<size; i++) res.push_back(res[i]*f);
        }
        // 重複を除去
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }

    // 素因数分解を行う
    vector<int> factorize(int x){
    	vector<int> res;
        while(x != 1){
            res.push_back(sieve[x]);
            x /= sieve[x];
        }
        return res;
    }
};
```
