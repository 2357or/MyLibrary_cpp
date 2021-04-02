#include <iostream>
typedef long long ll;
using namespace std;

// 素数かどうか判定する
// 参考[https://qiita.com/EqualL2/items/b3c2530c458f8450d390]

//引数: 素数判定したい数値
//戻り値: 真偽値 (true: 素数 false: 合成数)
//ex) 73 -> true, 93 -> false

bool is_prime(const ll n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i*i <= n; i += 6){
        if((n % i == 0) || (n % (i+2) == 0)) return false;
    }
    return true;
}

ll n;
int main() {
    cin >> n;
    cout << (is_prime(n) ? "Yes" : "No" ) << endl;
}
