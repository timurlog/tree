#!/bin/bash

# Couleurs pour les messages
YELLOW="\033[1;33m"
RED="\033[0;91m"
GREEN="\033[1;32m"
BLUE="\033[0;94m"
MAGENTA="\033[0;95m"
RESET="\033[0m"

# Variables
REPO_URL="https://github.com/timurlog/tree.git"
TEMP_DIR="$HOME/temp_____"
INSTALL_DIR="$HOME/tree"
RC_FILE="$HOME/.zshrc"

echo -e "${BLUE}Bienvenue dans l'installateur de Tree.${RESET}"
cd "$HOME" || { echo -e "${RED}Impossible de revenir au répertoire personnel.${RESET}"; exit 1; }

# Nettoyage et création du répertoire temporaire
echo -e "${YELLOW}Préparation de l'installation...${RESET}"
rm -rf "$TEMP_DIR"
mkdir -p "$TEMP_DIR" || { echo -e "${RED}Échec de la création du répertoire temporaire.${RESET}"; exit 1; }

# Assurer le nettoyage en cas d'erreur
trap 'rm -rf "$TEMP_DIR"' EXIT

# Clonage du dépôt Git
echo -e "${YELLOW}Clonage du dépôt...${RESET}"
git clone --recursive "$REPO_URL" "$TEMP_DIR/tree" > /dev/null 2>&1 || { echo -e "${RED}Échec du clonage du dépôt.${RESET}"; exit 1; }

# Copie des fichiers dans le répertoire d'installation
echo -e "${YELLOW}Copie des fichiers...${RESET}"
rm -rf "$INSTALL_DIR"
cp -r "$TEMP_DIR/tree" "$INSTALL_DIR" || { echo -e "${RED}Échec de la copie des fichiers.${RESET}"; exit 1; }

# Construction du projet
echo -e "${YELLOW}Construction de Tree...${RESET}"
cd "$INSTALL_DIR" || { echo -e "${RED}Impossible d'accéder au répertoire d'installation.${RESET}"; exit 1; }
make > /dev/null 2>&1 || { echo -e "${RED}Échec de la construction.${RESET}"; exit 1; }

# Ajout de l'alias dans le fichier de configuration
echo -e "${YELLOW}Ajout de l'alias dans ${MAGENTA}$RC_FILE${RESET}..."
if ! grep -q "alias tree=" "$RC_FILE"; then
    printf "\nalias tree=%s/tree/tree\n" "$INSTALL_DIR" >> "$RC_FILE" || { echo -e "${RED}Échec de la mise à jour de ${RC_FILE}.${RESET}"; exit 1; }
fi

cd "$HOME" || { echo -e "${RED}Impossible de revenir au répertoire personnel.${RESET}"; exit 1; }
rm -rf "$TEMP_DIR" || { echo -e "${RED}Échec de la suppression du répertoire temporaire.${RESET}"; exit 1; }

# Fin de l'installation
echo -e "${GREEN}Installation de Tree terminée avec succès.${RESET}"

# Remplacement automatique du shell actuel
exec "$SHELL"
