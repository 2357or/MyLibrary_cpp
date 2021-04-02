# Vector2

| - - - - - - - | - - - - - - - - - - - - - - - - - - - - |
| :----:        | :------                                 |
| commad        | `:Library vector2`                      |
| sample        | [Vector2.cpp](/sample/Vector2.cpp)      |
| link          | non                                     |

## 使用

### **[構造体]**
**Vector2(ld x, ld y)**
### 説明
- 幾何学ライブラリの基本構造体
- 組み込み関数
    - magnitude(): ベクトルの長さ
    - sqrMagnitude(): ベクトルの長さの2乗
    - Normalize(): このベクトルと同じ向きの単位ベクトル
### 制約
- `14桁`
### 計算量
- non


<br>


## ソースコード

### 依存
```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using ld=long double;
```

### 実装
```cpp
struct Vector2{
    ld x, y;
    constexpr Vector2(ld X=0, ld Y=0):x(X),y(Y){}
    ld sqrMagnitude(){return pow(x, 2)+pow(y, 2);}
    ld magnitude(){return sqrt(sqrMagnitude());}
    Vector2 Normalize() { return (*this)/magnitude(); }
    string ToString(const char* fmt = "%Lf"){
        char bufferX[std::numeric_limits<ld>::max_exponent10+1 +6 +3];
        sprintf(bufferX, fmt, x); string bX = string(bufferX);
        char bufferY[std::numeric_limits<ld>::max_exponent10+1 +6 +3];
        sprintf(bufferY, fmt, y); string bY = string(bufferY);
        return "(" + bX + ", " + bY + ")";
    }
    /*{{{ operator */
    constexpr Vector2& operator+=(const Vector2& rhs){x+=rhs.x; y+=rhs.y; return *this;}
    constexpr Vector2& operator-=(const Vector2& rhs){x-=rhs.x; y-=rhs.y; return *this;}
    constexpr Vector2& operator*=(const ld& rhs){x*=rhs; y*=rhs; return *this;}
    constexpr Vector2& operator/=(const ld& rhs){x/=rhs; y/=rhs; return *this;}
    constexpr Vector2 operator*(const ld& rhs){return Vector2(*this)*=rhs;}
    constexpr Vector2 operator+(const Vector2& rhs){return Vector2(*this)+=rhs;}
    constexpr Vector2 operator-(const Vector2& rhs){return Vector2(*this)-=rhs;}
    constexpr Vector2 operator-(){return Vector2(-x, -y);}
    friend Vector2 operator*(const ld& lhs,const Vector2& rhs){return Vector2(rhs)*=lhs;}
    friend Vector2 operator/(const Vector2& lhs,const ld& rhs){return Vector2(lhs)/=rhs;}
    constexpr bool operator==(const Vector2 rhs){return (this->x == rhs.x)&&(this->y == rhs.y);}
    constexpr bool operator!=(const Vector2 rhs){return (this->x != rhs.x)&&(this->y != rhs.y);}
    constexpr ld operator[](const int& i){
        switch(i){
            case 0: return x; case 1: return y;
            default: return numeric_limits<ld>::quiet_NaN();
        }
    }
    friend ostream& operator<<(ostream& os,const Vector2& v)noexcept{return os<<v.x<<' '<<v.y;}
    friend constexpr istream& operator>>(istream& is,Vector2& v)noexcept{return is>>v.x>>v.y;}/*}}}*/
};
```

### 解説
```cpp
struct Vector2{
    ld x, y;
    constexpr Vector2(ld X = 0, ld Y = 0) : x(X), y(Y) {}

    // ベクトルの 2 乗の長さ
    ld sqrMagnitude(){ return pow(x, 2)+pow(y, 2); }

    // ベクトルの長さ
    ld magnitude(){ return sqrt(sqrMagnitude()); }

    // このベクトルと同じ向きの単位ベクトル
    Vector2 Normalize() { return (*this)/magnitude(); }

    // ベクトルの値を見やすくフォーマットされた文字列
    // 引数に long double 型のフォーマット指定子を取れる
    string ToString(const char* fmt = "%Lf"){
        char bufferX[std::numeric_limits<ld>::max_exponent10+1 +6 +3];
        sprintf(bufferX, fmt, x); string bX = string(bufferX);
        char bufferY[std::numeric_limits<ld>::max_exponent10+1 +6 +3];
        sprintf(bufferY, fmt, y); string bY = string(bufferY);
        return "(" + bX + ", " + bY + ")";
    }

    // 算術演算
    constexpr Vector2& operator+=(const Vector2& rhs){x+=rhs.x; y+=rhs.y; return *this;}
    constexpr Vector2& operator-=(const Vector2& rhs){x-=rhs.x; y-=rhs.y; return *this;}
    constexpr Vector2& operator*=(const ld& rhs){x*=rhs; y*=rhs; return *this;}
    constexpr Vector2& operator/=(const ld& rhs){x/=rhs; y/=rhs; return *this;}
    constexpr Vector2 operator*(const ld& rhs){return Vector2(*this)*=rhs;}
    constexpr Vector2 operator+(const Vector2& rhs){return Vector2(*this)+=rhs;}
    constexpr Vector2 operator-(const Vector2& rhs){return Vector2(*this)-=rhs;}
    constexpr Vector2 operator-(){return Vector2(-x, -y);}
    friend Vector2 operator*(const ld& lhs,const Vector2& rhs){return Vector2(rhs)*=lhs;}
    friend Vector2 operator/(const Vector2& lhs,const ld& rhs){return Vector2(lhs)/=rhs;}

    // 比較
    constexpr bool operator==(const Vector2& r){return (this->x == r.x) && (this->y == r.y);}
    constexpr bool operator!=(const Vector2& r){return (this->x != r.x) && (this->y != r.y);}

    // [0] 、[1] を使用して x、y 成分にアクセス
    constexpr ld operator[](const int& i)const {
        switch(i){
            case 0: return x;
            case 1: return y;
            default: return numeric_limits<ld>::quiet_NaN();
        }
    }

    // iostreamのオーバーロード
    // ostream は ' 'というリテラルを使うので constexpr にできない
    friend ostream& operator<<(ostream& os,const Vector2& v)noexcept{return os<<v.x<<' '<<v.y;}
    friend constexpr istream& operator>>(istream& is,Vector2& v)noexcept{return is>>v.x>>v.y;}
};
```
