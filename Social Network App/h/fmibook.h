#pragma once
#include "User.h"
#include "Moderator.h"
#include "Pic_Publication.h"
#include "Link_Publication.h"
#include "Text_Publication.h"
#include "Publication.h"
#include "Publication_Vector.h"
#include "Admin.h"
#include "User_Vector.h"

class fmibook
{
	friend class Admin;
private:
	Publication_Vector Publication_Data;
	User_Vector User_Data;
	Admin* admin;
	fmibook();
public:
	fmibook(const char*, const unsigned int &);
	void AddUser(const char* Requester, const char* Unick, const unsigned int &Uage, const char &usertype);
	void RemoveUser(const char* Requester, const char* name);
	
	User* FindUser(const char* name);
	
	void UnmuteUser(const char* Requester, const char* Affected);
	void MuteUser(const char* Requester, const char* Affected);
	void RenameUser(const char* name, const char* newname);
	
	void fmibook::AddPost(const char* Requester, const char* text__url, const char* content, const char &posttype);
	//Basically, if the post is Link type we pass the content char array, otherwise just nullptr
	void RemovePost(const char* Requester, const unsigned int &num);
	
	void fmibook::ViewPost(const char* name, const unsigned int &num);
	void ViewAllPosts(const char* name);
	void Stats();
	~fmibook();
};

