#include <iostream>
#include <cmath>
using namespace std;
using ll=long long;
using ld=long double;

// a: 底 (a > 0)
// b: 真数 (b > 1, b != 1)
ld log_n(ld a, ld b){
    if(a<=0 || b<=0 || b==1) return numeric_limits<ld>::quiet_NaN();
    if(a==1) return 0;
    return logl(b)/logl(a);
}

int main(){
    ld a, b; cin >> a >> b;
    cout << log_n(a, b) << endl;
    return 0;
}

