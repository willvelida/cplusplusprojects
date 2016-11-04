// Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);

private:
	// Data member to hold name of player
	string m_Name;
	Player* m_pNext; //Pointer to next player in list
};

Player::Player(const string& name):m_Name(name),m_pNext(0)
{
}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
};

Lobby::Lobby():m_pHead(0)
{
}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	// create a new player
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);

	// if list is empty, make this player the head of the list
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)
	{
		cout << "The game lobby is empty. No one is here!\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;
	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{
			os << pIter->GetName() << endl;
			pIter = pIter->GetNext();
		}
	}

	return os;
}

int main()
{
	Lobby myLobby;
	int choice;

	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add player to lobby.\n";
		cout << "2 - Remove player from lobby.\n";
		cout << "3 - Clear lobby.\n";
		cout << endl << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "See ya!.\n";
			break;
		case 1:
			myLobby.AddPlayer();
			break;
		case 2:
			myLobby.RemovePlayer();
			break;
		case 3:
			myLobby.Clear();
			break;
		default:
			cout << "Not a valid choice!\n";
		}
	} while (choice != 0);

	return 0;
}