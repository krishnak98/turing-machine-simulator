# TURING MACHINE SIMULATOR

Turing machine simulator written in C++

## Introduction

The formal definition of a turing machine is as follows: 

A Turing machine M is a 7-tuple
(Q, sigma, gamma, delta, q0, #, F) where
```text 
Q is a set of states,
sigma is a finite set of symbols, the input alphabet,
gamma is a finite set of symbols, the tape alphabet,
delta is the partial transition function,
# is a member of gamma is a symbol called blank,
q0 is a member of Q is the initial state,
F is a subset of Q is a set of final states.
```

But it can be thought of as an infinite tape of cells, where each cell contains a binary digit (0 or 1).
The machine then positions reads the content of a cell, and depending on the value and the state of the machine (defined by the user), it updates the cell and moves one block to the left or right and the process repeats till the machine reaches a halt/accepting state (again defined by the user)

## Input Format

The input format of the file should be as follows:
```
4 a b c H             --> number of states followed by all the states
2 0 1                 --> number of symbols followed by the symbols
0                     --> blank symbol
1 1                   --> number of input symbols followed by the input symbols
a                     --> initial state of the machine
1 H                   --> number of accepting/halt state of the machine followed by the halt states
6                     --> number of transitions defined
a 0 b 1 1             --> each transition is of the form :
a 1 c 1 -1            --> (current state, current symbol, updated state, updated symbol, direction) 
b 0 a 1 -1            --> direction can be +1/-1 signifying right/left respectively
b 1 b 1 1
c 0 b 1 -1
c 1 H 1 1
```


## Running the program

To compile and run the simulator, execute the following command in the terminal
```bash
$ bash make.sh
```

## Output 
The `^` symbol represents where the head is currently at, on the tape. Alongside the tape, the state of the simulator is mentioned as well

![image](https://user-images.githubusercontent.com/21224026/121770389-a76e1e00-cb86-11eb-953e-8f0b9f038f8f.png)





