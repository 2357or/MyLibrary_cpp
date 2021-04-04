# MyLibrary_cpp 導入方法

## ダウンロード&インストール
1. GitHubまたはvim-plugやdein.vimなどでダウンロード
1. 以下の項目を`.vimrc`に設定
    ```vim
    let g:plugin_dir_path='このプラグインまでのパス' "規定値: ~/.vim/bundles/repos/github.com/2357or/MyLibrary_cpp
    ```

## 設定
グーローバル変数が2つあります。

### g:g:user_library_path
既定値: = "~"  
追加したいライブラリファイルがあるディレクトリまでのパス(最後の'/'は無し)を設定してください。  

### g:plugin_dir_path
既定値: = "~/.vim/bundles/repos/github.com/2357or/MyLibrary_cpp"  
基本的に**必須**です。  
このプラグインが保存されているディレクトリまでのパスを設定してください。  

## ライブラリの追加

例えば関数`is_even(int)`を作成したとしましょう。  

1. この関数を`~/CppLibrary/is_even.txt`に保存します。
1. `.vimrc`に以下を追加します。
    ```vim
    let g:user_library_path = '~/CppLibrary'
    ```
1. vimを再起動または.vimrcの再読み込みを行います。
1. `:Library is_even`と入力すると`~/CppLibrary/is_even.txt`の内容がカーソル下にペーストされます。

**注意**  
既にプラグイン内に存在するライブラリ名でライブラリを追加した場合、プラグインないにあるものが優先されます。  
例) `gcd.txt`を作成しても`:Library gcd`では使われることはありません。
