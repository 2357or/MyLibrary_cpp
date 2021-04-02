if exists('g:loaded_my_library')
  finish
endif
let g:loaded_my_library = 1

command! -nargs=1 Library :call my_library#paste(<q-args>)
