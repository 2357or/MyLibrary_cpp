#include <cstdio>
#include <string>
using namespace std;

template<class T>string convertBaseNumber(T n, const int to){
    string res = "";
  	while(n){
        int t = n%to; n /= to;
        res += t + (t<10 ? 48 : 87);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for(long long i = n - 1000000; i < n; i++){
        printf("%s\n", convertBaseNumber(i, m).c_str());
    }
    return 0;
}

