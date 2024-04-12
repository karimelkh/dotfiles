if status is-interactive
    # Commands to run in interactive sessions can go here
end

# aliases

## fish shell
alias unalias="functions -e"

## ls
alias l="/bin/ls"
alias ls="exa -bghHiS --git --icons --color=always --group-directories-first"
alias ll="ls --long"
alias la="ls --long --all"
alias tree="ls --tree"

## cd
alias ..="cd ../"
alias ...="cd ../../"

## grep
alias grep="grep --color=auto"
alias hgrep="history | grep"

## vim
alias vim="nvim"

## git
alias gittl="git ls-files | xargs wc -l | tail -1" # get the total number of lines of a git repo

## nmcli
alias wifi="nmcli device wifi"

## pkg management
alias updatemirrors="sudo rate-mirrors --allow-root --protocol https arch | sudo tee /etc/pacman.d/mirrorlist"

## ffmpeg
# alias ffgif="ffmpeg -f x11grab -s 1366x768 -i :0.0 -t 10 ~/output.mp4"

# disable the anoying fish greeting message
set fish_greeting

# env vars
set -x EDITOR nvim
set -x TERM alacritty
set -x LD_LIBRARY_PATH /usr/local/lib $LD_LIBRARY_PATH
