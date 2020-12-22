#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
	CMarkup xml;
	bool fileExists = xml.Load(filenameWithUsers);

	if (!fileExists) {
		xml.AddElem("Users");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("User");
	xml.IntoElem();
	xml.AddElem("id", user.getId());
	xml.AddElem("login", user.getLogin());
	xml.AddElem("password", user.getPassword());
	xml.AddElem("name", user.getName());
	xml.AddElem("surname", user.getSurname());

	xml.Save(filenameWithUsers);
}

vector <User> UsersFile::readUsersFromFile()
{
	CMarkup xml;
	User user;
	vector <User> users;
	xml.Load(filenameWithUsers);

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("User")) {
		xml.IntoElem();

		xml.FindElem("id");
		MCD_STR strSN = xml.GetData();
		user.setUserId(AuxiliaryMethods::stringToIntConverter(strSN));
		xml.FindElem("login");
		strSN = xml.GetData();
		user.setLogin(strSN);

		xml.FindElem("password");
		strSN = xml.GetData();
		user.setPassword(strSN);

		xml.FindElem("name");
		strSN = xml.GetData();
		user.setName(strSN);

		xml.FindElem("surname");
		strSN = xml.GetData();
		user.setSurname(strSN);
		xml.OutOfElem();

		users.push_back(user);
	}


	return users;
}

void UsersFile::saveUsersToFile(vector<User>& users)
{
	CMarkup xml;
	User user;

	bool fileExists = xml.Load(filenameWithUsers);

	xml.ResetMainPos();
	while (xml.FindElem())
		xml.RemoveElem();

	
	xml.AddElem("Users");
	for (int i = 0; i < users.size(); i++) {
		xml.FindElem();
		xml.IntoElem();
		xml.AddElem("User");
		xml.IntoElem();
		xml.AddElem("id", users[i].getId());
		xml.AddElem("login", users[i].getLogin());
		xml.AddElem("password", users[i].getPassword());
		xml.AddElem("name", users[i].getName());
		xml.AddElem("surname", users[i].getSurname());
		xml.OutOfElem();
		xml.AddNode(CMarkup::MNT_COMMENT, "/User");
		xml.Save(filenameWithUsers);
	}
}
