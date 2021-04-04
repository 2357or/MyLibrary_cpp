# MyLibrary_cpp
- 競プロ用自作ライブラリ(for C++)
- 使用テンプレート: [dotfiles/vim/Templates/source/cpp.txt](https://github.com/2357or/dotfiles/blob/master/vim/Templates/souce/cpp.txt)
- [導入方法](Introduction.md)
- ヘルプ(日本語) `:help my_library`

## 数学
| 名前            | コマンド              | ドキュメント                                             | サンプル                                                 |
| :-----          | :---------            | :-------------                                           | :---------                                               |
| 最大公約数(GCD) | `:Library gcd`        | [GCD.md](/document/GCD.md)                               | [GCD-LCM.cpp](/sample/GCD-LCM.cpp)                       |
| 最小公倍数(LCM) | `:Library lcm`        | [LCM.md](/document/LCM.md)                               | [GCD-LCM.cpp](/sample/GCD-LCM.cpp)                       |
| 素数判定        | `:Library is_prime`   | [is_prime.md](/document/is_prime.md)                     | [is_prime.cpp](/sample/is_prime.cpp)                     |
| 素因数分解      | `:Library prime_fact` | [PrimeFactorization.md](/document/PrimeFactorization.md) | [PrimeFactorization.cpp](/sample/PrimeFactorization.cpp) |
| 対数関数        | `:Library log`        | [Log.md](/document/Log.md)                               | [Log.cpp](/sample/Log.cpp)                               |
| 基数変換        | `:Library conv_base`  | [convertBaseNumber.md](/document/convertBaseNumber.md)   | [convertBaseNumber.cpp](sample/convertBaseNumber.cpp)    |


## データ構造
| 名前                         | コマンド            | ドキュメント                             | サンプル                                 |
| :-----                       | :---------          | :-------------                           | :---------                               |
| UnionFind木                  | `:Library uf`       | [UnionFind.md](/document/UnionFind.md)   | [UnionFind.cpp](/sample/UnionFind.cpp)   |
| 素数篩                       | `:Library sieve`    | [PrimeSieve.md](/document/PrimeSieve.md) | [PrimeSieve.cpp](/sample/PrimeSieve.cpp) |
| Dijkstra法(単一始点最短経路) | `:Library dijkstra` | [Dijkstra.md](/document/Dijkstra.md)     | [Dijkstra.cpp](/sample/Dijkstra.cpp)     |


## ユーティリティ
| 名前     | コマンド            | ドキュメント                         | サンプル                             |
| :-----   | :---------          | :-------------                       | :---------                           |
| mod_int  | `:Library mint`     | [mod_int.md](/document/mod_int.md)   | [mod_int.cpp](/sample/mod_int.cpp)   |
| Vector2  | `:Library vector2`  | [Vector2.md](/document/Vector2.md)   | [Vector2.cpp](/sample/Vector2.cpp)   |
| Geometry | `:Library geom/all` | [Geometry.md](/document/Geometry.md) | [Geometry.cpp](/sample/Geometry.cpp) |


## 比較関数
| 名前           | コマンド               | ドキュメント                               | サンプル                                   |
| :-----         | :---------             | :-------------                             | :---------                                 |
| secondでソート | `:Library sort_second` | [sort_second.md](/document/sort_second.md) | [sort_second.cpp](/sample/sort_second.cpp) |


## データ圧縮
| 名前          | コマンド             | ドキュメント                          | サンプル                               |
| :-----        | :---------           | :-------------                        | :---------                             |
| RunLength圧縮 | `:Library runlength` | [RunLength.md](/document/RunLength.md) | [RunLength.cpp](/sample/RunLength.cpp) |

## 外部ライブラリ
| 名前               | コマンド                   | ドキュメント                                                                                      |
| :-----             | :---------                 | :-------------                                                                                    |
| 多倍長整数         | `:Library boost/cpp_int`   | [Boost逆引きリファレンス/多倍長整数](https://boostjp.github.io/tips/multiprec-int.html)           |
| 多倍長浮動小数点数 | `:Library boost/cpp_float` | [Boost逆引きリファレンス/多倍長浮動小数点数](https://boostjp.github.io/tips/multiprec-float.html) |


<!--

|  | `:Library ` | [.md](/document/.md) | [.cpp](/sample/.cpp) |

-->

