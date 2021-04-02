#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using ld=long double;


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

inline void Check(bool b, int l){
    if(b) puts("OK");
    else printf("NO - line: %d\n", l);
}
int main(){
    Vector2 s(3, 4);
    Vector2 t = {2, 5};

    // first check
    cout << "first check" << endl;
    Check(t == Vector2(2, 5) && Vector2(2, 5) == t, __LINE__);
    Check(s == Vector2(3, 4) && Vector2(3, 4) == s, __LINE__);
    Check(t != s, __LINE__);


    // calc
    cout << "calc" << endl;
    Check(t + Vector2(1, 1) == Vector2(3, 6), __LINE__);
    Check(Vector2(1, 1) + t == Vector2(3, 6), __LINE__);
    Check(t - Vector2(2, 1) == Vector2(0, 4), __LINE__);
    Check(Vector2(2, 1) - t == Vector2(0, -4), __LINE__);
    Check(2*s == Vector2(6, 8), __LINE__);
    Check(t*3 == Vector2(6, 15), __LINE__);
    Check(t/2 == Vector2(1, (ld)5/2), __LINE__);
    Check(-t == Vector2(-2, -5), __LINE__);

    t *= 2; Check(t == Vector2(4, 10), __LINE__);
    t /= 2; Check(t == Vector2(2, 5), __LINE__);
    s += Vector2(2, 2); Check(s == Vector2(5, 6), __LINE__);
    s -= Vector2(2, 2); Check(s == Vector2(3, 4), __LINE__);

    // methods
    cout << "methods" << endl;
    Check(s.sqrMagnitude() == 9+16, __LINE__);
    Check(s.magnitude() == 5, __LINE__);
    Check(s.Normalize() == Vector2((ld)3/5, (ld)4/5), __LINE__);
    Check(s.ToString() == "(3.000000, 4.000000)", __LINE__);
    Check(t.ToString("%.2Lf") == "(2.00, 5.00)", __LINE__);

    // access
    cout << "access" << endl;
    Check(s[0] == 3 && s[1] == 4, __LINE__);
    Check(t.x == 2 && t.y == 5, __LINE__);

    cout << "check iostream" << endl;
    Vector2 tmp;
    cout << "input 2 numbers: "; cin >> tmp;
    cout << "if output is same values then OK:" << endl;
    cout << "output: " << tmp << endl;
    /*
     if access [3] or [-1], return 'nan'.
    */
    return 0;
}

