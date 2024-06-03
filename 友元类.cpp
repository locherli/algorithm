#include <iostream>
#include <string>
using namespace std;

class ROOM//class declaration(room)
{
	friend class myFriend;
public:
	string m_livingRoom;
	ROOM()//construct function
	{
		m_livingRoom = "public space";
		m_bedRoom = "private space";
	}
private:
	string m_bedRoom;
};


class myFriend//class declaration(friend)
{
public:
	void visit(ROOM* room);
	myFriend();
private:
	ROOM* room;

};


void myFriend::visit(ROOM* room)//visiting function
{
	cout << "my frieng is vising:" << room->m_livingRoom << endl;
	cout << "my frieng is vising:" << room->m_bedRoom << endl;
}
myFriend::myFriend()//construct function
{
	room = new ROOM;
}

int main()
{
	ROOM myroom;
	myFriend mike;
	mike.visit(&myroom);
	return 0;
}