let g:user_library_path = ""
let g:plugin_dir_path = "~/.vim/bundles/repos/github.com/2357or/MyLibrary_cpp"

function! my_library#paste(name) abort
    let l:file = expand(g:plugin_dir_path . "/source/" . a:name . ".txt")
    let l:exists = filereadable(l:file)
    if l:exists == 1
        let l:i = line(".")
        echo l:file
        for line in readfile(l:file)
            call append(l:i, line)
            let l:i = l:i + 1
        endfor
    else
        let l:ufilename = expand(g:user_library_path . a:name . ".txt")
        if filereadable(l:ufilename) == 1
            let l:i = line(".")
            echo l:file
            for line in readfile(l:file)
                call append(l:i, line)
                let l:i = l:i + 1
            endfor
        endif
        echo "Library:".a:name." could not be found."
    endif
endfunction