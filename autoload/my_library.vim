function! my_library#paste(name) abort
    let l:plug_file = expand(g:plugin_dir_path . "/source/" . a:name . ".txt")
    if filereadable(l:plug_file)
        let l:i = line(".")
        for line in readfile(l:plug_file)
            call append(l:i, line)
            let l:i = l:i + 1
        endfor
        echo "Pasted: " . l:plug_file
    else
        let l:user_file = expand(g:user_library_path . "/" . a:name . ".txt")
        if filereadable(l:user_file) == 1
            let l:i = line(".")
            for line in readfile(l:user_file)
                call append(l:i, line)
                let l:i = l:i + 1
            endfor
            echo "Pasted: " . l:user_file
        else
            echo "Library:". a:name . " could not be found."
        endif
    endif
endfunction
