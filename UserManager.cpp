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

int UserManager::loginUser()
{
	User user;
	string login = "", password = "";

	cout << "What is your login ? ";
	cin >> login;

	vector <User>::iterator itr = users.begin();
	while (itr != users.end()) {
		if (itr->getLogin() == login) {
			for (int attempts = 3; attempts > 0; attempts--) {
				cout << "What is your password ? Attempts left: " << attempts << ": ";
				cin >> password;
				user.setPassword(password);

				if (itr->getPassword() == password) {
					cout << endl << "Login was succesful." << endl << endl;
					system("pause");
					idLoggedUser = itr->getId();
					return idLoggedUser;
				}
			}
			cout << "3 times entered password was wrong." << endl;
			system("pause");
			return 0;
		}
		itr++;
	}
	cout << "There is no user with that login." << endl << endl;
	system("pause");
	return 0;
}

void UserManager::logoutUser()
{
	idLoggedUser = 0;
}

