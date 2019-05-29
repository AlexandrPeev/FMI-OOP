#include "fmibook.h"
#include <cstring>
#include <iostream>
#include <fstream>

fmibook::fmibook(const char* name, const unsigned int &age)
{
	admin = new Admin(name, age, this);
}

User* fmibook::FindUser(const char* name)
{
	if (strcmp(name, admin->GetNickname()) == 0)
	{
		return admin;
	}
	for (unsigned int i = 0; i < User_Data.GetSize(); ++i)
	{
		if (strcmp(name, User_Data[i]->GetNickname()) == 0)
		{
			return User_Data[i];
		}
	}
	return nullptr;
}

void fmibook::AddUser(const char* Requester, const char* Unick, const unsigned int &Uage, const char &usertype)
{
	if (strcmp(Requester, admin->nickname) == 0 && Uage > 0)
	{
		if (usertype == 'u')
		{
			User* tmp = new User(Unick, Uage, 0);
			User_Data.Add_User(tmp);
		}
		else if (usertype == 'm')
		{
			User* tmp = new Moderator(Unick, Uage, 0);
			User_Data.Add_User(tmp);
		}
	}
	else
	{
		std::cout << "Invalid request";
		return;
	}
}

void fmibook::RemoveUser(const char* Requester, const char* name)
{
	if (strcmp(Requester, admin->nickname) == 0)
	{
		if (FindUser(name) == nullptr)
		{
			std::cout << "Requested User does not exist";
		}
		else
		{
			for (unsigned int i = 1; i < Publication_Data.GetSize() + 1; ++i)
			{
				if (strcmp(Publication_Data[i-1]->GetUser()->GetNickname(), name) == 0)
				{
					Publication_Data.Delete_Publication(i);
				}
			}
			for (unsigned int i = 0; i < User_Data.GetSize(); ++i)
			{
				if (strcmp(name, User_Data[i]->GetNickname()) == 0)
				{
					User_Data.Remove_User(name);
				}
			}
		}
	}
	else
	{
		std::cout << "User is not an Admin";
	}
}

void fmibook::MuteUser(const char* Requester, const char* Affected)
{
	if (FindUser(Requester) != nullptr)
	{
		if (FindUser(Requester)->Authorisation() != 'u')
		{
			if (FindUser(Requester) != nullptr)
			{
				FindUser(Affected)->muted = 1;
			}
			else
			{
				std::cout << "Requester does not exist in the database";
			}
		}
		else
		{
			std::cout << "Normal user cannot mute other users";
		}
	}
	else
	{
		std::cout << "Requester does not exist in the database";
	}
}

void fmibook::RenameUser(const char* name, const char* newname)
{
	FindUser(name)->ChangeNickName(newname);
}

void fmibook::UnmuteUser(const char* Requester, const char* Affected)
{
	if (FindUser(Requester) != nullptr)
	{
		if (FindUser(Requester)->Authorisation() != 'u')
		{
			if (FindUser(Requester) != nullptr)
			{
				FindUser(Affected)->muted = 0;
			}
			else
			{
				std::cout << "Requester does not exist in the database";
			}
		}
		else
		{
			std::cout << "Normal user cannot mute other users";
		}
	}
	else
	{
		std::cout << "Requester does not exist in the database";
	}
}

void fmibook::AddPost(const char* Requester, const char* text__url, const char* content, const char &posttype)
{
	User* user = FindUser(Requester);
	if (user != nullptr)
	{
		if (user->muted == 0)
		{
			if (posttype == 'l')
			{
				Link_Publication* tmp = new Link_Publication(Publication_Data.GetSize() + 1, user, text__url, content);
				Publication_Data.Add_Publication(tmp);
			}
			else if (posttype == 'p')
			{
				Pic_Publication* tmp = new Pic_Publication(Publication_Data.GetSize() + 1, user, text__url);
				Publication_Data.Add_Publication(tmp);
			}
			else if (posttype == 't')
			{
				Text_Publication* tmp = new Text_Publication(Publication_Data.GetSize() + 1, user, text__url);
				Publication_Data.Add_Publication(tmp);
			}
		}
		else
		{
			 std::cout << "User is muted";
		}
	}
	else
	{
		std::cout << "User does not exist";
	}
}

void fmibook::RemovePost(const char* Requester, const unsigned int &num)
{
	User* user = FindUser(Requester);
	if (user != nullptr)
	{
		if (user->Authorisation() == 'u')
		{
			if (strcmp(Requester, Publication_Data[num]->GetUser()->GetNickname()) != 0)
			{
				std::cout << "Normal user cannot delete publications of other users";
			}
			else
			{
				Publication_Data.Delete_Publication(num);
			}
		}
		else
		{
			Publication_Data.Delete_Publication(num);
		}
	}
	else
	{
		std::cout << "User does not exist" << std::endl;
	}
}

void fmibook::ViewPost(const char* name, const unsigned int &num)
{
	if (Publication_Data[num - 1] == nullptr)
	{
		std::cout << "Publication has been deleted";
	}
	else
	{
		User* tmp = FindUser(name);
		if (tmp != nullptr)
		{
			char* nu = new char[10];
			itoa(Publication_Data[num - 1]->GetNumber(), nu, 10);
			char* filename = new char[strlen(name) + 1 + 1 + strlen(nu) + 1 + 5];
			int counter = 0;
			for (counter; counter < strlen(name); ++counter)
			{
				filename[counter] = name[counter];
			}
			filename[counter++] = '_';
			for (int i = 0; i < strlen(nu); ++i)
			{
				filename[counter++] = nu[i];
			}
			filename[counter++] = '.';
			filename[counter++] = 'h';
			filename[counter++] = 't';
			filename[counter++] = 'm';
			filename[counter++] = 'l';
			filename[counter++] = '\0';
			std::cout << filename;
			std::ofstream myFile(filename);
			Publication_Data[num - 1]->Visualize(myFile);
			myFile.close();
			delete[] nu;
			delete[] filename;
		}
		else
		{
			std::cout << "User does not exist";
		}
	}
}

void fmibook::ViewAllPosts(const char* name)
{
	User* tmp = FindUser(name);
	if (tmp != nullptr)
	{
		char* nname = new char[strlen(name) + 6];
		int counter = 0;
		for (counter; counter < strlen(name); ++counter)
		{
			nname[counter] = name[counter];
		}
		nname[counter++] = '.';
		nname[counter++] = 'h';
		nname[counter++] = 't';
		nname[counter++] = 'm';
		nname[counter++] = 'l';
		nname[counter++] = '\0';
		std::ofstream myFile(nname);
		for (int i = 0; i < Publication_Data.GetSize(); ++i)
		{
			if (Publication_Data[i] != nullptr && strcmp(Publication_Data[i]->GetUser()->GetNickname(), name) == 0)
			{
				Publication_Data[i]->Visualize(myFile);
				myFile << std::endl;
			}
		}
		delete[] nname;
	}
	else
	{
		std::cout << "User does not exist";
	}
}

void fmibook::Stats()
{
	unsigned int counter_users = 0;
	unsigned int counter_mods = 0;
	unsigned int block_counter = 0;
	for (unsigned int i = 0; i < User_Data.GetSize(); ++i)
	{
		if(User_Data[i]->Authorisation() == 'u')
		{
			counter_users++;
		}
		else if(User_Data[i]->Authorisation() == 'm')
		{
			counter_mods++;
		}
	}
	std::cout << "There are " << counter_users << "users" <<  std::endl;
	std::cout << "There are " << counter_mods << "mods" << std::endl;
	std::cout << "Blocked Users: " << std::endl;
	for (unsigned int i = 0; i < User_Data.GetSize(); ++i)
	{
		if (User_Data[i]->GetMuteState() == 1)
		{
			block_counter++;
		}
	}
	std::cout << block_counter << std::endl;
	for (unsigned int i = 0; i < User_Data.GetSize(); ++i)
	{
		if (User_Data[i]->GetMuteState() == 1)
		{
			std::cout << User_Data[i]->GetNickname() << std::endl;
		}
	}

}

fmibook::~fmibook()
{
	delete admin;
}
