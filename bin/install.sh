#!/bin/bash

# Define color codes for output messages
YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

# Define variables for repository URL, temporary directory, installation directory, and shell configuration file
REPO_URL="https://github.com/timurlog/tree.git"
TEMP_DIR="$HOME/temp_____"
INSTALL_DIR="$HOME/tree"
HOME_DIR="$HOME"
RC_FILE="$HOME/.zshrc"

# Display a welcome message
echo -e "${BLUE}Welcome to the tree installer.${RESET}"

# Navigate to the home directory
cd "$HOME" || { echo -e "${RED}Unable to return to the home directory.${RESET}"; exit 1; }

# Prepare for installation by cleaning up and creating a temporary directory
echo -e "${YELLOW}Preparing the installation...${RESET}"
rm -rf "$TEMP_DIR"
mkdir -p "$TEMP_DIR" || { echo -e "${RED}Failed to create the temporary directory.${RESET}"; exit 1; }

# Ensure the temporary directory is removed on script exit
trap 'rm -rf "$TEMP_DIR"' EXIT

# Clone the repository into the temporary directory
echo -e "${YELLOW}Cloning the repository...${RESET}"
git clone --recursive "$REPO_URL" "$TEMP_DIR/tree" > /dev/null 2>&1 || { echo -e "${RED}Failed to clone the repository.${RESET}"; exit 1; }

# Copy the cloned files to the installation directory
echo -e "${YELLOW}Copying files...${RESET}"
rm -rf "$INSTALL_DIR"
cp -r "$TEMP_DIR/tree" "$HOME_DIR" || { echo -e "${RED}Failed to copy files.${RESET}"; exit 1; }

# Build the project using `make`
echo -e "${YELLOW}Building tree...${RESET}"
cd "$INSTALL_DIR" || { echo -e "${RED}Unable to access the installation directory.${RESET}"; exit 1; }
make > /dev/null 2>&1 || { echo -e "${RED}Build failed.${RESET}"; exit 1; }

# Add an alias to the shell configuration file if it doesn't already exist
echo -e "${YELLOW}Adding alias in ${MAGENTA}$RC_FILE${YELLOW}...${RESET}"
if ! grep -q "alias tree=" "$RC_FILE"; then
    printf "\nalias tree=%s/tree/tree\n" "$HOME_DIR" >> "$RC_FILE"
fi

# Return to the home directory and clean up the temporary directory
cd "$HOME" || { echo -e "${RED}Unable to return to the home directory.${RESET}"; exit 1; }
rm -rf "$TEMP_DIR" || { echo -e "${RED}Failed to delete the temporary directory.${RESET}"; exit 1; }

# Display a success message
echo -e "${GREEN}tree installation completed successfully.${RESET}"

# Restart the shell to apply changes
exec "$SHELL"
