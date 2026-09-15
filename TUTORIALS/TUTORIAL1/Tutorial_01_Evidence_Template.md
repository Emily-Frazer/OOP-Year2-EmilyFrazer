# Guided Tutorial 1: evidence

Name or student identifier: Emily frazer c003222789
Project/repository: OOP-Year2-EmilyFrazer
Configuration and compiler: Visual studio, C++
Final commit identifier: 

## 01 · Create a program you can build

Prediction before running: The program would run and display the message along with a new line

Observed result: The program displayed the message, the new line then the program stopped runnung

Explanation in my own words: the program saw the cout and knew to display a message, the \n made the program create a new line after the string. Return 0 ended the function of main and the program stopped running

Modification/test performed: removing a semicolon from the cout line. This led to a syntax error and the program would not open.

What I repaired or still need to understand: I added the semicolon back to the code, allowing the program to run properly

## 02 · Separate a declaration from a definition

Prediction before running: That the program would run as normal, but show the message twice

Observed result: the message was only shown one time

Explanation in my own words: the header and the cpp file for report are linked together, the cpp can read what is in the header due to the #include at the top of the cpp. it knows what the report function is due to it being defined in the header file. This means that the function is called as normal

Modification/test performed: commenting out where the function is called in the cpp file to see what happened
2: Changing the name of the included header file to see what would happen to the cpp file

What was observed: When the function call was commented out of the cpp. THe program didnt run, the error message mentioned missing a function header and had "old style?" in brackets afterwards. The program has no idea what function it is calling becaue the calling line has been commented out

2:Changing the name of the header file led to the cpp file having no idea what it was looking for in the files. there is only one .h file and it didnt match the name it was looking for, this led to all the function declarations being missing so the cpp file had no idea what it could do 

What I repaired or still need to understand: changing the name back to the correct header file allowed the cpp file to see the function declarations again. this shows how important it is to spell the names of your files correctly and to #include them properly into the needed files

## 03 · Read a name without losing its spaces

Prediction before running: not sure what will happen but i think the space will just be included in the string as a space. I am not sure what the importance of getLine() is.

Observed result: The program ran as intended, no error messages were outputted to the screen

Explanation in my own words: the code initialised a variable of  string for the players name, then asked for the player to input it. I am not entirely sure what getline() does but from observation its checking to see if the player actually inputted anything. if the player didnt, an error message shows with the error that no name was found or read. If the player inputted a name, the program ended with the message intended for the player

Modification/test performed: change the program to ask for a different inputted string

What I repaired or still need to understand: thwe names of your variables are important. you cant ask the player for the name of their location and save it in the code as "player name". it gets confusing for the programmer

## 04 · Recover from an invalid bonus

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 05 · Give the program a predictable data location

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 06 · Read a complete, validated mission record

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 07 · Change a value through its address

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 08 · Use the debugger to test your explanation

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 09 · Make one supported change

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## 10 · Test, explain and save the completed work

Prediction before running: 

Observed result: 

Explanation in my own words: 

Modification/test performed: 

What I repaired or still need to understand: 

## Test record

| Case | Expected result | Actual result | Pass/fail | Explanation |
|---|---|---|---|---|
| | | | | |

## Final reflection

One concept I can explain: 

One remaining question: 

