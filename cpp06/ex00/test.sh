#!/bin/bash

# COLORS
CYAN="\033[38;5;45m"
RED="\033[38;5;196m"
PINK="\033[38;5;213m"
GREEN="\033[32m"
YELLOW="\033[38;5;220m"
RESET="\033[0m"
BOLD="\033[1m"

# TESTS
echo -e "${GREEN}========= Wrong input ==========${RESET}"

./convert

./convert a 42

./convert afjehgui

./convert bonjour

./convert 42..0

echo -e "${GREEN}========= Single char test ==========${RESET}"

./convert a

echo -e "${GREEN}========= Int test ==========${RESET}"

./convert 0

./convert 42

./convert -42

echo -e "${GREEN}========= Float test ==========${RESET}"

./convert 0.0f

./convert 42.0f

./convert -42.0f

echo -e "${GREEN}========= Double test ==========${RESET}"

./convert 0.0

./convert 42.0

./convert -42.0

./convert 3.14

echo -e "${GREEN}========= Pseudo literal test ==========${RESET}"

./convert inf

./convert +inf

./convert -inf

./convert nan

echo -e "${GREEN}========= Pseudo literal float test ==========${RESET}"

./convert inff

./convert +inff

./convert -inff

./convert nanf