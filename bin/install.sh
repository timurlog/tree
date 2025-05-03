#!/bin/bash

YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

cd "$HOME" || exit

mkdir temp_____

cd temp_____ || exit
rm -rf tree

# download github
git clone --recursive https://github.com/timurlog/tree.git > /dev/null 2>&1 || { echo "${RED}Cloning failed.${RESET}"; exit 1; }

cp -r tree "$HOME"

cd "$HOME" || exit
rm -rf temp_____

cd "$HOME"/tree || exit

make

RC_FILE="$HOME/.zshrc"

if [ "$(uname)" != "Darwin" ]; then
	RC_FILE="$HOME/.bashrc"
	if [[ -f "$HOME/.zshrc" ]]; then
		RC_FILE="$HOME/.zshrc"
	fi
fi

printf "${YELLOW}Adding alias tree in file: $RC_FILE${RESET}"

# set up the alias
if ! grep "tree=" "$RC_FILE" &> /dev/null; then
	printf "\nalias tree='%s/tree/tree'\n" "$HOME" >> "$RC_FILE"
fi

# automatically replace current shell with new one.
exec "$SHELL"

printf "${GREEN}tree Installation Completed Successfully.${RESET}"
