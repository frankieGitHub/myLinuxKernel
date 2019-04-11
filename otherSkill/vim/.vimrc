"s line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'. Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
set nocompatible
set backspace=indent,eol,start

" Vim5 and later versions support syntax highlighting. Uncommenting the
" following enables syntax highlighting by default.
if has("syntax")
syntax on " 语法高亮
endif
colorscheme ron " elflord ron peachpuff default 设置配色方案，vim自带的配色方案保存在/usr/share/vim/vim72/colors目录下

" detect file type
filetype on
filetype plugin on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark
set guifont=Courier_new:h14:b:cDEFAULT
colorscheme solarized

set fencs=utf-8,GB18030,ucs-bom,default,latin1

" Uncomment the following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"have Vim load indentation rules and plugins according to the detected filetype
filetype plugin indent on
endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.

"set ignorecase " 搜索模式里忽略大小写
"set smartcase " 如果搜索模式包含大写字符，不使用 'ignorecase' 选项。只有在输入搜索模式并且打开 'ignorecase' 选项时才会使用。
set autowrite " 自动把内容写回文件: 如果文件被修改过，在每个 :next、:rewind、:last、:first、:previous、:stop、:suspend、:tag、:!、:make、CTRL-] 和 CTRL-^命令时进行；用 :buffer、CTRL-O、CTRL-I、'{A-Z0-9} 或 `{A-Z0-9} 命令转到别的文件时亦然。
set autoindent " 设置自动对齐(缩进)：即每行的缩进值与上一行相等；使用 noautoindent 取消设置
"set smartindent " 智能对齐方式
set tabstop=4 " 设置制表符(tab键)的宽度
set softtabstop=4 " 设置软制表符的宽度
set shiftwidth=4 " (自动) 缩进使用的4个空格
set cindent " 使用 C/C++ 语言的自动缩进方式
set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s "设置C/C++语言的具体缩进方式
"set backspace=2 " 设置退格键可用
set showmatch " 设置匹配模式，显示匹配的括号
set linebreak " 整词换行
set whichwrap=b,s,<,>,[,] " 光标从行首和行末时可以跳到另一行去
"set hidden " Hide buffers when they are abandoned
"set mouse=a " Enable mouse usage (all modes) "使用鼠标
set number " Enable line number "显示行号
"set previewwindow " 标识预览窗口
set history=50 " set command history to 50 "历史记录50条


"--状态行设置--
set laststatus=2 " 总显示最后一个窗口的状态行；设为1则窗口数多于一个的时候显示最后一个窗口的状态行；0不显示最后一个窗口的状态行
set ruler " 标尺，用于显示光标位置的行号和列号，逗号分隔。每个窗口都有自己的标尺。如果窗口有状态行，标尺在那里显示。否则，它显示在屏幕的最后一行上。

"--命令行设置--
set showcmd " 命令行显示输入的命令
set showmode " 命令行显示vim当前模式

"--find setting--
set incsearch " 输入字符串就显示匹配点
set hlsearch

map <F9> :call CompileRunGcc()<CR>

func! CompileRunGcc()
    exec "w"
if &filetype == 'c'
    exec "!g++ % -o %<"
    exec "!time ./%<"
elseif &filetype == 'cpp'
    exec "!g++ % -o %<"
    exec "!time ./%<"
elseif &filetype == 'java'
    exec "!javac %"
    exec "!time java %<"
elseif &filetype == 'sh'
    :!time bash %
elseif &filetype == 'python'
    exec "!time python2.7 %"
endif
endfunc


"--following is python hint
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'davidhalter/jedi-vim'

call vundle#end()            " required
filetype plugin indent on    " required
"--python hint end.


"--ctags setting--
" 按下F5重新生成tag文件，并更新taglist
map <F5> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR><CR> :TlistUpdate<CR>
imap <F5> <ESC>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR><CR> :TlistUpdate<CR>
set tags=tags
set tags+=./tags "add current directory's generated tags file


if has("cscope")
    set csprg=/usr/bin/cscope
    set csto=1
    set cst
    set nocsverb
    " add any database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    " else add database pointed to by environment
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif
    set csverb
endif

set ts=4
set expandtab
:%retab!

nmap <C-_>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-_>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-_>i :cs find i <C-R>=expand("<cfile>")<CR><CR>
nmap <C-_>d :cs find d <C-R>=expand("<cword>")<CR><CR>


set cursorcolumn
set cursorline


filetype plugin on
let g:pydiction_location = '/home/frankie/.vim/bundle/pydiction/complete-dict'
let g:pydiction_menu_height = 3

"--------{-----------  
set sessionoptions=buffers,sesdir,resize,folds,tabpages  
" 注意目录要存在  
au VimLeave * mksession! ./session.vim
au VimLeave * wviminfo!  ./viminfo.vim 
"--------}----------- 
let Tlist_Auto_Open=1
let Tlist_Exit_OnlyWindow =1
:let g:winManagerWindowLayout='FileExplorer|TagList'
:nmap wm :WMToggle<CR>
map <F3> :Explore<CR>
