#!/bin/bash

YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

echo "Welcome in tree instaler"

cd "$HOME" || exit

rm -rf tree
mkdir temp_____

cd temp_____ || exit
rm -rf tree

# download github
echo "Cloning repository..."
git clone --recursive https://github.com/timurlog/tree.git > /dev/null 2>&1 || { echo "\033[0;91mCloning failed.\033[0m"; exit 1; }

cp -r tree "$HOME"

cd "$HOME" || exit
rm -rf temp_____

cd "$HOME"/tree || exit

echo "Building tree..." 
make > /dev/null 2>&1

RC_FILE="$HOME/.zshrc"

echo "Adding alias tree in file: $RC_FILE"

# set up the alias
if ! grep "tree=" "$RC_FILE" > /dev/null 2>&1; then
	printf "\nalias tree='%s/tree/tree'\n" "$HOME" >> "$RC_FILE"
fi

echo "Tree installation completed successfully."
# automatically replace current shell with new one.
exec "$SHELL"
