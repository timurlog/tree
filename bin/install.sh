#!/bin/bash

YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

REPO_URL="https://github.com/timurlog/tree.git"
TEMP_DIR="$HOME/temp_____"
INSTALL_DIR="$HOME/tree"
HOME_DIR="$HOME"
RC_FILE="$HOME/.zshrc"

echo -e "${BLUE}Welcome to the tree installer.${RESET}"
cd "$HOME" || { echo -e "${RED}Unable to return to the home directory.${RESET}"; exit 1; }

echo -e "${YELLOW}Preparing the installation...${RESET}"
rm -rf "$TEMP_DIR"
mkdir -p "$TEMP_DIR" || { echo -e "${RED}Failed to create the temporary directory.${RESET}"; exit 1; }

trap 'rm -rf "$TEMP_DIR"' EXIT

echo -e "${YELLOW}Cloning the repository...${RESET}"
git clone --recursive "$REPO_URL" "$TEMP_DIR/tree" > /dev/null 2>&1 || { echo -e "${RED}Failed to clone the repository.${RESET}"; exit 1; }

echo -e "${YELLOW}Copying files...${RESET}"
rm -rf "$INSTALL_DIR"
cp -r "$TEMP_DIR/tree" "$HOME_DIR" || { echo -e "${RED}Failed to copy files.${RESET}"; exit 1; }

echo -e "${YELLOW}Building tree...${RESET}"
cd "$INSTALL_DIR" || { echo -e "${RED}Unable to access the installation directory.${RESET}"; exit 1; }
make > /dev/null 2>&1 || { echo -e "${RED}Build failed.${RESET}"; exit 1; }

echo -e "${YELLOW}Adding alias in ${MAGENTA}$RC_FILE${YELLOW}...${RESET}"
if ! grep -q "alias tree=" "$RC_FILE"; then
    printf "\nalias tree=%s/tree/tree\n" "$HOME_DIR" >> "$RC_FILE"
fi

cd "$HOME" || { echo -e "${RED}Unable to return to the home directory.${RESET}"; exit 1; }
rm -rf "$TEMP_DIR" || { echo -e "${RED}Failed to delete the temporary directory.${RESET}"; exit 1; }

echo -e "${GREEN}Tree installation completed successfully.${RESET}"

exec "$SHELL"
