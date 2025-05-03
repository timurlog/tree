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
echo -e "${BLUE}Welcome to the tree updater.${RESET}"

# Navigate to the home directory
cd "$INSTALL_DIR" || { echo -e "${RED}Unable to access the installation directory.${RESET}"; exit 1; }

# Pull the latest changes from the repository
if [ -d ".git" ]; then
	echo -e "${YELLOW}Pulling latest changes from the repository...${RESET}"
	git pull origin main > /dev/null 2>&1 || { echo -e "${RED}Failed to pull the repository.${RESET}"; exit 1; }
else
	echo -e "${RED}Error: This is not a git repository.${RESET}"
	exit 1
fi

# Build the project using `make`
echo -e "${YELLOW}ReBuilding tree...${RESET}"
make > /dev/null 2>&1 || { echo -e "${RED}Build failed.${RESET}"; exit 1; }

# Return to the home directory and clean up the temporary directory
cd "$HOME" || { echo -e "${RED}Unable to return to the home directory.${RESET}"; exit 1; }

# Display a success message
echo -e "${GREEN}tree update completed successfully.${RESET}"
