#!/bin/bash

cd "$HOME" || exit

mkdir temp_____

cd temp_____ || exit
rm -rf tree

# download github
git clone --recursive https://github.com/timurlog/tree.git || { echo "Git clone failed"; exit 1; }

cp -r tree "$HOME" || { echo "Failed to copy tree directory"; exit 1; }

cd "$HOME" || exit
rm -rf temp_____

cd "$HOME"/tree || exit

make

RC_FILE="$HOME/.bashrc"
[[ -f "$HOME/.zshrc" ]] && RC_FILE="$HOME/.zshrc"

echo "Try to add alias tree in file: $RC_FILE"

# set up the alias
if ! grep "tree=" "$RC_FILE" &> /dev/null; then
	echo "tree alias not present"
	printf "\nalias tree='%s/tree/tree'\n" "$HOME" >> "$RC_FILE"
fi

# automatically replace current shell with new one.
source "$RC_FILE"

printf "\033[33m... and don't forget, \033[1;37mpaco\033[0;33m is not a replacement for your own tests! \033[0m\n"
