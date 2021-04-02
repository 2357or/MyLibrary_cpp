# mod_int

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                                                   |
| :----:        | :------                                                                                   |
| commad        | `:Library mint`                                                                           |
| sample        | [mod_int.cpp](/sample/mod_int.cpp)                                                        |
| link          | [AtCoder公式放送ライブラリ](https://github.com/atcoder/live_library/blob/master/mint.cpp) |

## 使用

### **[構造体]**
**mint(ll x)**
### 説明
- 四則演算で自動でmodをとる整数型
### 制約
- `-(1<<62) < x < (1<<62)`
### 計算量
- コンストラクタ: `O(1)`


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
const int MOD = 1000000007;
#include <cassert>
struct mod_int {
    using mint = mod_int;
    ll val;
    constexpr mod_int(ll x=0):val((x%MOD+MOD)%MOD){}
    constexpr mint& operator+=(const mint r){if((val+=r.val)>=MOD)val-=MOD; return *this;}
    constexpr mint& operator-=(const mint r){if((val-=r.val)<0)val+=MOD; return *this;}
    constexpr mint& operator*=(const mint r){(val*=r.val)%=MOD; return *this;}
    constexpr mint& operator/=(const mint r){return *this *= r.inv();}
    mint inv()const{return pow(MOD-2);}
    mint pow(ll n) const{ assert(0 <= n);
        if(!n)return 1;
        mint t = pow(n>>1);
        t *= t; if(n&1)t*=(*this);
        return t;
    }
    friend mint operator+(const mint& lhs,const mint& rhs){return mint(lhs)+=rhs;}
    friend mint operator-(const mint& lhs,const mint& rhs){return mint(lhs)-=rhs;}
    friend mint operator*(const mint& lhs,const mint& rhs){return mint(lhs)*=rhs;}
    friend mint operator/(const mint& lhs,const mint& rhs){return mint(lhs)/=rhs;}
    friend bool operator==(const mint& lhs,const mint& rhs){return lhs.val==rhs.val;}
    friend bool operator!=(const mint& lhs,const mint& rhs){return lhs.val!=rhs.val;}
    friend constexpr ostream& operator<<(ostream& os,const mint& x)noexcept{
        return os<<x.val;
    }
    friend constexpr istream& operator>>(istream& is,mint& x)noexcept{
        return is>>x.val;
    }
};
using mint = mod_int;
```

### 解説
```cpp
// MOD の値をセットする
const int MOD = 1000000007;

// pow でエラー終了するためinclude
#include <cassert>

struct mod_int {
    using mint = mod_int;

    ll val;
    constexpr mod_int(ll x=0):val((x%MOD+MOD)%MOD){}

    // MOD を取りながら演算
    constexpr mint& operator+=(const mint r){if((val+=r.val)>=MOD)val-=MOD; return *this;}
    constexpr mint& operator-=(const mint r){if((val-=r.val)<0)val+=MOD; return *this;}
    constexpr mint& operator*=(const mint r){(val*=r.val)%=MOD; return *this;}

    // 除算は逆元をかけることとと等しい
    /*
     フェルマーの小定理
        a^(p-1)　 　≡1
        a * a^(p-2) ≡1 (mod p)
     より、
     mod p における a の逆元は a^(p-2) であることがわかる
    */
    constexpr mint& operator/=(const mint r){return *this *= r.inv();}
    mint inv()const{return pow(MOD-2);}

    // 二分累乗法
    mint pow(ll n) const{ assert(0 <= n);
        if(!n)return 1;
        mint t = pow(n>>1);
        t *= t; if(n&1)t*=(*this);
        return t;
    }

    // friend として以下のオペレーターを定義することで、リテラルとの演算を可能に
    friend mint operator+(const mint& lhs,const mint& rhs){return mint(lhs)+=rhs;}
    friend mint operator-(const mint& lhs,const mint& rhs){return mint(lhs)-=rhs;}
    friend mint operator*(const mint& lhs,const mint& rhs){return mint(lhs)*=rhs;}
    friend mint operator/(const mint& lhs,const mint& rhs){return mint(lhs)/=rhs;}
    friend bool operator==(const mint& lhs,const mint& rhs){return lhs.val==rhs.val;}
    friend bool operator!=(const mint& lhs,const mint& rhs){return lhs.val!=rhs.val;}

    // iostream のオペレーターをオーバーロード
    friend constexpr ostream& operator<<(ostream& os,const mint& x)noexcept{
        return os<<x.val;
    }
    friend constexpr istream& operator>>(istream& is,mint& x)noexcept{
        return is>>x.val;
    }
};

// mint として using
using mint = mod_int;
```
