# PersonalBudget

An object-oriented program that allows you to control you home budget wrote in C++. Program wrote entirely in English with clean code, rules SOLID and DRY principles.

At the entrance, the user can login and register. I used an XML files for registration using the CMarkup library and that`s where the user data are stored and pulled ou at login.

![main menu](/IMGreadme/mainMenuPersonalBudget.png)

After logging in, the user can add an income or expense. Income or expense can be added with current data or chosen by user. 

![main menu](/IMGreadme/userMenuPersonalBudget.png)

The next options allows user to check his current month balance, previous month balance or balance from chosen period. Program allows to change password of account nad logout. 
User can choose current date taken from method or user can enter own date. If the date is not in yyyy-mm-dd format, the user is informed about the error and gets an oppotrunity to enter the date again.
The user can of course change his password and logout.

Sample user balance

![main menu](/IMGreadme/balancePersonalBudget.png)

Tools used :
- C++ language
- STL library ---> vectors, maps, iterators
- XML files   ---> CMarkup library
- Inheritance
- Clean Code  ---> i.e self-describing variables

I prefer to design the program and next to write it.

![main menu](/IMGreadme/UMLPersonalBudget.png)
