# Mini-C
### CS F363 Compiler Construction Assignment-2
#### Problem Statement Specifications:
Consider a programming language, (Mini-C) with the following features:
1. **Type** : int, float, char
2. **Basic statements**: expression statement, assignment statements, and compound statements, declaration statement.
3. **Control and looping statements**: if statement, for statement, while statement, and
switch statement. (note that nesting of these statements is also possible.)
4. **System functions**: printf and scanf statements.
5. **Other**: Variables, arrays (1-D and 2-D only), and function </br>
The syntax for the above is same as in C language. </br>The structure of the input program is also
same as a C program ignoring headers and macros.


### Tasks:
1. Lexical Analysis: Tokenizes the input program into tokens (identifiers, operators, numbers, etc). Further reports if invalid scanf or printf statements are present in the program. </br>
A valid printf statement has one of the following structure: </br>
  *  printf(“text”) where text is a non-empty string of symbols in the language alphabet. </br>
  *  printf(“text”, list_of_variables) where text is a non-empty string of symbols in
the language alphabet and list_of_variables is a nonempty sequence of variables
separated by a comma (,). </br>
Further, the number of variables in list_of_variables is must be the same as the
number of %d, %c, and %f terms in text.
2. Syntax Analysis: Checking whether the input program is syntactically correct or not.
3. Semantic Analysis: 
* Printing an Abstract Syntax Tree for the program.
* Verifying Semantic errors like type checking, undeclared variables, multiple declarations of variables, functional arguments, etc.
4. Code Generation: Intermediate Code generation ( Three Address Code )
5. Simulation: Simulate the program


### How to run:
1. Compile files for all stages by running ```./compile.sh``` in main directory.
2. Run the corresponding executables for each phase with the input file </br>
for example: ```./semantic_analyzer.out < input.txt``` or ```./intermediate.out < input.txt```
