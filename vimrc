filetype plugin indent on
set mouse-=a
set backspace=2
syntax on
syntax enable
colorscheme molokai
set cindent
set tabstop=4

"for cscope
if has("cscope")                                                                                                                           
        set csprg=/usr/bin/cscope                                                                                                          
        set csto=1                                                                                                                         
        set cst                                                                                                                            
        set nocsverb                                                                                                                       
        if filereadable("cscope.out")                                                                                                      
           cs add cscope.out                                                                                                               
        endif                                                                                                                              
        set csverb                                                                                                                         
endif                                                                                                                                      
                                                                                                                                           
nmap <C-@>s :cs find s <C-R>=expand("<cword>")<CR><CR>                                                                                     
nmap <C-@>g :cs find g <C-R>=expand("<cword>")<CR><CR>                                                                                     
nmap <C-@>c :cs find c <C-R>=expand("<cword>")<CR><CR>                                                                                     
nmap <C-@>t :cs find t <C-R>=expand("<cword>")<CR><CR>                                                                                     
nmap <C-@>e :cs find e <C-R>=expand("<cword>")<CR><CR>                                                                                     
nmap <C-@>f :cs find f <C-R>=expand("<cfile>")<CR><CR>                                                                                     
nmap <C-@>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>                                                                                   
nmap <C-@>d :cs find d <C-R>=expand("<cword>")<CR><CR> 

"vim-plug 

call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'preservim/tagbar', {'on': 'TagbarToggle'}
call plug#end()

"for tagbar
nmap <F4> :TagbarToggle<CR>



"for nerdtree
" auto exit if nothing left                                                                                                                
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif

map <F3> :NERDTreeMirror<CR>
map <F3> :NERDTreeToggle<CR>
