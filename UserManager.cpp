#include "UserManager.h"

User UserManager::getNewUserData()
{
	User user;

	user.setUserId(loadNewUserId());

	string login = "", password = "", name = "", surname = "";
	do {
		cout << "What is your login ?";
		cin >> login;
		user.setLogin(login);
	} while (isLoginExist(user.getLogin()) == true);

	cout << "What is your password ?";
	cin >> password;
	user.setPassword(password);

	cout << "What is your name ? ";
	cin >> name;
	user.setName(name);

	cout << "What is your surname ?";
	cin >> surname;
	user.setSurname(surname);

	return user;
}

int UserManager::loadNewUserId() {
	if (users.empty() == true)
		return 1;
	else
		return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getLogin() == login) {
			cout << "Login is taken." << endl;
			return true;
		}
	}
	return false;
}

void UserManager::signupUser()
{
	User user = getNewUserData();
	users.push_back(user);

	cout << endl << "Account creation was succesful" << endl << endl;
	system("pause");
}
