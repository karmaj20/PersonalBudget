#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() 
{
	PersonalBudget personalBudget("users.xml");

	personalBudget.signupUser();
	personalBudget.loginUser();
}