Name : Mallikarjun Kalyanshetti


USN : 1PI12IS051


Quest. No. : 3


Quest. Title : LOGIN program for a user.


Description of source code :This is written using C language.
It is a login program in which the user is given 3 chances to enter his login crediantals,it welcomes the user if he/she enters the correct username and password .
The program terminates after three unsuccessful login trails.This program also creates / appends to a logFile in which the important events of the program are recorded.



Way to execute : Open terminal in Ubuntu , go to the directry where this source code is stored.
copy->paste your file in which usernames and passwords are saved in the same directry and execute the program in terminal using the command 
"./a.out -f searchFileName -l LogFileName" after compiling it using the command "gcc asn2_3.c
Bugs:
1. Since scanf() function is used, white spaces included in input makes the program to run in the way which it is not supposed to.
