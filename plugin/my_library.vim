if exists('g:loaded_my_library')
  finish
endif
let g:loaded_my_library = 1

if ! exists('g:user_library_path')
    let g:user_library_path = '~'
endif

if ! exists('g:plugin_dir_path')
    let g:plugin_dir_path = '~/.vim/bundles/repos/github.com/2357or/MyLibrary_cpp'
endif

command! -nargs=1 Library :call my_library#paste(<q-args>)
