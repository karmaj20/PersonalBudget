#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
	CMarkup xml;
	string login, password, name, surname;
	int userId;

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

	xml.Save("users.xml");
	
}
