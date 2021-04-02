# sort_second

| - - - - - - - | - - - - - - - - - - - - - - - - - - - -                        |
| :----:        | :------                                                        |
| commad        | `:Library sort_second`                                                 |
| sample        | [sort_second.cpp](/sample/sort_second.cpp)                            |
| link          | [参考記事](https://perogram.hateblo.jp/entry/2018/12/17/045943) |

## 使用

### **[比較関数]**
**compare_by_second<T, U>**
### 説明
- pair\<T, U\> の second を基準に昇順ソートを行う
### 制約
- non
### 計算量
- non


<br>


## ソースコード

### 依存
```cpp
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
```

### 実装
```cpp
template<class T, class U>
bool compare_by_second(const pair<T,U>& A, const pair<T,U>& B){
    if(A.second != B.second) return A.second < B.second;
    else return A.first < B.first;
}
```

### 解説
```cpp
// secondを基準に昇順ソートする
// 降順にしたい場合は, 関数内の 「<」 を 「>」 に変える
template<class T, class U>
bool compare_by_second(const pair<T,U>& A, const pair<T,U>& B){
    if(A.second != B.second){
        // 目標(ソート済)の時に True になるように返す
        return A.second < B.second;
    }
    else{
        // second の値が同じ時は first を基準にソート
        return A.first < B.first;
    }
}


#define ALL(x) x.begin(),x.end()
int main(){
    //...

    // sort()の最後の引数に渡す
    // templateの型の自動判定は行われないので <T, U> で指定する
    // (pint の時は <int, int> とする)
    sort(ALL(p), compare_by_second<int, string>);

    //...
}
```
