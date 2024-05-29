#!/bin/bash

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
BOLD='\033[0;1m'
RESET='\033[0m'

# Functions
singleLetterRead() {
	text="$1"

	read -n1 -s -r -p "$text" key
	echo "$key"
}

test()
{
    echo ""
    echo -e "$BOLD""$1 : $RESET" "./sed $2 $3 $4"
    ./sed "$2" "$3" "$4" > /dev/null
    echo ""
    echo -e "$BLUE""Original file : $RESET"
	/bin/cat "$2"
    echo ""
	echo -e "$GREEN""Modified file : $RESET"
	/bin/cat "$2".replace
    echo ""
    singleLetterRead "Press any key to continue..." > /dev/null
	echo ""
}

# Compiling project
echo -e "$BOLD""Compiling Project :$RESET"
echo ""
make

# Tests
test "Normal test" "./files/normalTest" "the" "999"
test "Special Character" "./files/specialCharacter" "," "$"
test "Longer Replace" "./files/longerReplace" "in" "1234567890"
test "No Replace" "./files/noReplace" "e" "e"
test "One Line" "./files/oneLine.txt" "gg" "99"
test "Shorter Replace" "./files/shorterReplace" "the" "0"
test "File doesn't exit" "./files/love.txt" "the" "ive"
test "Replace with empty string" "./files/test" "" "ive"

# Clean
key=$(singleLetterRead 'Clean up? (y or n)')
echo ""
if [ "$key" = "y" ]; then
	make fclean
	rm ./files/*.replace
fi