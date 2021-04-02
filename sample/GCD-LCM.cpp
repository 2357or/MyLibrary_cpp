#include <iostream>
using namespace std;
using ll=long long;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int x, y;
int main(){
    cin >> x >> y;
    cout << "GCD: " << gcd(x, y) << endl;
    cout << "LCM: " << lcm(x, y) << endl;
    return 0;
}

