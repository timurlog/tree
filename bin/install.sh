#!/bin/bash

YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

printf "%bWelcome to the tree instaler%b\n" "$BLUE" "$RESET"

cd "$HOME" || exit

mkdir temp_____

cd temp_____ || exit
rm -rf tree

# download github
git clone --recursive https://github.com/timurlog/tree.git > /dev/null 2>&1 || { echo "\033[0;91mCloning failed.\033[0m"; exit 1; }

cp -r tree "$HOME"

cd "$HOME" || exit
rm -rf temp_____

cd "$HOME"/tree || exit

make > /dev/null 2>&1

RC_FILE="$HOME/.zshrc"

if [ "$(uname)" != "Darwin" ]; then
	RC_FILE="$HOME/.bashrc"
	if [[ -f "$HOME/.zshrc" ]]; then
		RC_FILE="$HOME/.zshrc"
	fi
fi

printf "%bTry to adding alias tree in file: %s%b\n" "$YELLOW" "$RC_FILE" "$RESET"

# set up the alias
if ! grep "tree=" "$RC_FILE" &> /dev/null; then
	echo -e "\033[1;33mAdding it...\033[0m"
	printf "\nalias tree='%s/tree/tree'\n" "$HOME" >> "$RC_FILE"
else
	echo -e "\033[1;32mAlias already exists in %s.\033[0m" "$RC_FILE"
fi

# automatically replace current shell with new one.
exec "$SHELL"

printf "\033[1;32mTree installation completed successfully.\033[0m\n"
