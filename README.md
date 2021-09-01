# How to use
1. Make a directory build and use `cmake ..`
2. Use `make`
3. Use `./programa [Answers file] [Method] [Quantity] [Correct answers file]`

# Methods parameters
**best** - Best students based on answers

**worst** - Worst students based on answers

**best-questions** - Questions which most students got right

**worst-questions** - Questions which most students got wrong

**blank-questions** - Questions which most students didn't mark `A-E`

**[Quantity]** - Number of students to print

# File format
[Name] X X X X X X

Antero E A C A E C B B B B

Luca D E U B E A A B A E

Jurema D E E C A G E D E D

Daisy D C E C E B E A A D

Carla D C A D C E E D C M

Tayná B A D M W C C H B B

# Correct answers format
A D E E B C B A

# Important
The program can detect the number of questions based on how many questions the students answered.

The program will only recognize **A - E** , any other will be considered blank.

Keep in mind most part of the code uses portuguese variables.
