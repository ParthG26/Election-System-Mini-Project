# Election-System-Mini-Project
AIM : To create a C program representing the election system where one can cast    their vote on their favourite person
ABSTRACT : 
This C program demonstrates the process of election system where one can add the party name ,cast their vote , check the vote count and find who is in leading position .
It is used to elect candidates from the list made by adding the party details.
This program contains basic header file , #include <stdio.h> and many more and uses several functions and data types . ‘do’ loops and ‘switch’ statements have been used so that the user could enter their opinion on the output screen. 
Structures have also been used. Overall the program is not complicated, and is useful in casting one’s vote on their favorite leader. 
A Database has been created where the votes are stored. The code can be executed in ‘DEVC++’ or any C-compilers . 
ALGORITHM :  
First we declare header file and then define the candidates name followed by declaring the return type (void in this case), function name (retPcode, retVC, retName, Enter, Display, Cast Vote, Result) and printf statements, switch cases to print the options which is to be displayed on the output window. 
When coming to the ‘leading candidate’ section , We use if control statement and basic operators of file handling to find out which candidate has got more voting. 
We store the votecount and the party details in a binary file that we can access to perform operations and read it at our leisure. 
We can also update the records during the vote casting through this method by using seek() in file handling. 
So main function is created and below that we use ‘while’ loop to execute the program again in order to the option selected on the output window. 
‘Switch’ statements have been used which tests the value of the given variable and compares it with multiple cases (Here we have got 3 cases). 
This program continues until the choice to continue the program becomes something other than ‘Y’ or ‘y’. 
This program is a simple menu-driven program with many options including the option to exit which helps the user to understand the methodology better.
