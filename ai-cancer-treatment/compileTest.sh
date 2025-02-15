#!/bin/bash

# if error: -bash: ./compile.sh: /bin/bash^M: bad interpreter: No such file or directory
#     then use ":set fileformat=unix" within VIM editor and save using ":wq!"
#      this converts the line endings so the interpreter can understand.

# Compiler
CXX=g++

# Source files
SRC_FILES="test.cpp \
    ./clauseList/clauseList.cpp \
    ./conclusionList/conclusionList.cpp \
    ./knowledgeBase/knowledgeBase.cpp \
    ./ruleBase/ruleBase.cpp \
    ./variableList/variableList.cpp \
	./ruleBase/ruleBase.cpp"

# Output executable
OUTPUT="test.exe"

# Compile the program
echo "Compiling..."
$CXX $SRC_FILES -o $OUTPUT

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed."
fi
