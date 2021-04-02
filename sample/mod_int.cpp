#include <iostream>
#include <cstdio>
using namespace std;
using ll=long long;

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


inline void Check(bool b, int l){
    if(b) puts("OK");
    else printf("NO - line: %d\n", l);
}
int main() {
    mint a = 10;
    mint b(3);

    // first check
    cout << "first check" << endl;
    Check(a == 10 && 10 == a, __LINE__);
    Check(b == 3 && 3 == b, __LINE__);

    // literal
    cout << "literal" << endl;
    Check(a != 7, __LINE__);
    a += 7; Check(a == 17, __LINE__);
    a -= 7; Check(a == 10, __LINE__);
    a *= 5; Check(a == 50, __LINE__);
    a /= 5; Check(a == 10, __LINE__);
    Check(a + 4 == 14, __LINE__);
    Check(a - 4 == 6, __LINE__);
    Check(a * 3 == 30, __LINE__);
    Check(a / 5 == 2, __LINE__);

    // same type
    cout << "same type" << endl;
    Check(a != b, __LINE__);
    a += b; Check(a == 13, __LINE__);
    a -= b; Check(a == 10, __LINE__);
    a *= b; Check(a == 30, __LINE__);
    a /= b; Check(a == 10, __LINE__);
    Check(a + b == 13, __LINE__);
    Check(a - b == 7, __LINE__);
    Check(a * b == 30, __LINE__);
    Check(a / b == 333333339, __LINE__);

    // func
    Check(a.inv() == 700000005, __LINE__);
    Check(a.pow(3) == 1000, __LINE__);

    // compare
    /*
     you should use `val` parameter
     ex)
       if(a.val > 12) ...
    */
}
