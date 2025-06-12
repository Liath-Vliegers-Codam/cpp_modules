#!/bin/bash

# Path to the executable
EXECUTABLE="./megaphone"

# Define test cases as separate quoted strings
declare -a TEST_CASES=(
    '"shhhhh... I think the students are asleep..."'
    'Damnit " ! " "Sorry students, I thought this thing was off."'
    ''
    '"this is a test"'
    '"123 456 789"'
    '"special characters !@#$%^&*()"'
    '"MixedCaseInput"'
)

# Run the executable with each test case
for TEST in "${TEST_CASES[@]}"; do
    echo "$EXECUTABLE $TEST"
    eval $EXECUTABLE $TEST
    echo "-------------------------"
done
