#include <string>
#include <fstream>      
#include <conio.h>
#include <iostream>
using namespace std;
struct node
{
	char pbcode[8];
	string name;
	float price;
	int qt;
	string mfgdate;
	string expdate;
	int found;
	char ch, nm;
	node* next;
};
node* head;
class admin
{
public:
	string user;
	char p1;
	char p2;
	char p3;
	char p4;
	char p5;
	admin()
	{
		user = "admin";
		p1 = 'a';
		p2 = 'd';
		p3 = 'm';
		p4 = 'i';
		p5 = 'n';
		head = NULL;
	}
	void login()
	{
		cout << "             Please Enter user name      " << endl;
		cin >> user;
		cout << "             Please Enter Password       " << endl;
		p1 = _getch();
		cout << "*";
		p2 = _getch();
		cout << "*";
		p3 = _getch();
		cout << "*";
		p4 = _getch();
		cout << "*";
		p5 = _getch();
		cout << "*";
		if (user == "admin"&& p1 == 'a'&& p2 == 'd'&&p3 == 'm'&&p4 == 'i'&&p5 == 'n')
		{
			admin a;
			system("cls");
			cout << "           *******Logged in**********";
			a.menu();
		}
		else
		{
			cout << "\nYou Entered Wrong Password";

		}
	}
	void menu()
	{
		admin b;
		int c = 0;
		while (c != 5)
		{
			cout << "         \n what you Want to Do        " << endl << endl;
			cout << "        1: Add Item                   " << endl;
			cout << "        2: Delete Item                " << endl;
			cout << "        3: Search Item                " << endl;
			cout << "        4: Total Stock               " << endl;
			cout << "        5: Exit                       " << endl;
			cin >> c;
			switch (c)
			{
			case 1:
			{
				b.add();
				break;
			}
			case 2:
			{
				del();
				break;
			}
			case 3:
			{
				b.search();
				break;

			}
			case 4:
			{
				b.display();
				break;

			}
			case 5:
			{
				break;
			}
			default:
				cout << "You Enter Wrong Choice   ";
			}
		}
	}
	void add()
	{
		node* temp = new node;


		system("cls");
		cout << "         \n  ***********Bakery Management System****************" << endl << endl << endl;
		cout << "Enter Pbcode \n";
		cin.ignore();
		cin.getline(temp->pbcode, 8);
		cout << "Enter name \n";
		cin >> temp->name;
		cout << "Enter Price Of ITEMS \n";
		cin >> temp->price;
		cout << "Enter Quantity \n";
		cin >> temp->qt;
		cout << "Enter MFG DATE dd-mm-yyy \n";
		cin.ignore();
		cin >> temp->mfgdate;
		cout << "Enter Exp date  dd-mm-yyy\n";
		cin.ignore();
		cin >> temp->expdate;
		ofstream file;
		file.open("items.txt", ios::app);
		file << endl << temp->name << "\t" << temp->pbcode << "\t" << temp->price << "\t" << temp->qt << "\t" << temp->mfgdate << "\t" << temp->expdate;


	}
	void display()
	{
		ifstream file;
		file.open("items.txt", ios::in);
		system("cls");
		cout << "         \n  ***********Bakery Management System****************" << endl << endl;
		cout << "\n           *************TOTAL STOCK***********" << endl << endl << endl;
		while (!file.eof())
		{
			node* temp = new node;
			file >> temp->name >> temp->pbcode >> temp->price >> temp->qt >> temp->mfgdate >> temp->expdate;
			cout << "Product Code:            " << temp->pbcode << endl;
			cout << "Product Name:            " << temp->name << endl;
			cout << "Price:                   " << temp->price << endl;
			cout << "Quantity:                " << temp->qt << endl;
			cout << "Manufacture Date:        " << temp->mfgdate << endl;
			cout << "Expiry Date:             " << temp->expdate << endl << endl;
		}
	}
	void search()
	{
		
		head = NULL;
		fstream file;
		file.open("items.txt", ios::in|ios::out|ios::app);
		cout << "\n **********FOLLOWING ARE  THE ITEMS YOU SEARCHED FOR*******************" << endl << endl << endl;
		while (!file.eof())
		{
			
			node* temp = new node;
			file >> temp->name >> temp->pbcode >> temp->price >> temp->qt >> temp->mfgdate >> temp->expdate;
			if (head == NULL)
			{
				cout<<"enter";
				head = temp;
				temp->next = NULL;
			}
			else
			{
				cout<<"enter1";
				node* ptr=NULL;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = temp;
				temp->next = NULL;
			}
		}
		int a = 0;
		system("cls");
		cout << "What You Want you Do          " << endl << endl;
		cout << "1: Search by name:            " << endl;
		cout << "2: Search by Product Code:    " << endl;
		cout << "3: Exit                       " << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			int count = 0;
			node* current;
			current = head;
			string name;
			cout << "Enter Name of Product You want to Search:   " << endl;
			cin >> name;
			while (current != NULL)
			{
				if (current->name == name)
				{
					cout << "************You Searched For************" << endl << endl << endl;
					cout << "Product Code:            " << current->pbcode << endl;
					cout << "Product Name:            " << current->name << endl;
					cout << "Price:                   " << current->price << endl;
					cout << "Quantity:                " << current->qt << endl;
					cout << "Manufacture Date:        " << current->mfgdate << endl;
					cout << "Expiry Date:             " << current->expdate << endl << endl;
					count++;
					break;
				}
				else
				{
					current = current->next;
				}
			}
			if (count == 0)
			{
				cout << " Your Product is not in the List";
			}
			break;
		}
		case 2:
		{
			int count = 0;
			node* current;
			current = head;
			string code;
			cout << "Enter Code of Product You want to Search:   " << endl;
			cin >> code;
			while (current != NULL)
			{
				if (current->pbcode == code)
				{
					cout << "************You Searched For************" << endl << endl << endl;
					cout << "Product Code:            " << current->pbcode << endl;
					cout << "Product Name:            " << current->name << endl;
					cout << "Price:                   " << current->price << endl;
					cout << "Quantity:                " << current->qt << endl;
					cout << "Manufacture Date:        " << current->mfgdate << endl;
					cout << "Expiry Date:             " << current->expdate << endl << endl;
					count++;
					break;
				}
				else
				{
					current = current->next;
				}
			}
			if (count == 0)
			{
				cout << " Your Product is not in the List";
			}
			break;

		}
		case 3:
		{
			break;
		}
		default:
			cout << "You Entered Wrong Choice";
		}


	}
	void del()
	{
		head = NULL;
		ifstream file;
		file.open("items.txt", ios::in);
		while (!file.eof())
		{
			node* temp = new node;
			file >> temp->name >> temp->pbcode >> temp->price >> temp->qt >> temp->mfgdate >> temp->expdate;
			if (head == NULL)
			{
				head = temp;
				temp->next = NULL;
			}
			else
			{
				node* ptr=NULL;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = temp;
				temp->next = NULL;
			}
		}
		string code;
		int count = 0;
		node* current;
		node * prev;
		prev = head;
		current = head;
		cout << "Enter Code of Product You want to Deleted:   " << endl;
		cin >> code;
		while (current != NULL)
		{
			if (current->pbcode == code)
			{
				cout << "************You Following Product is Deleted************" << endl << endl << endl;
				cout << "Product Code:            " << current->pbcode << endl;
				cout << "Product Name:            " << current->name << endl;
				cout << "Price:                   " << current->price << endl;
				cout << "Quantity:                " << current->qt << endl;
				cout << "Manufacture Date:        " << current->mfgdate << endl;
				cout << "Expiry Date:             " << current->expdate << endl << endl;
				count++;
				prev->next = current->next;
				delete current;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (count == 0)
		{
			cout << " Your Product is not in the List";
		}

	}
	void placeorder()
	{
		admin b;
		b.display();
		node* head2;
		head2 = NULL;
		ifstream file;
		file.open("items.txt", ios::in);
		while (!file.eof())
		{
			node* temp = new node;
			file >> temp->name >> temp->pbcode >> temp->price >> temp->qt >> temp->mfgdate >> temp->expdate;
			if (head2 == NULL)
			{
				head2 = temp;
				temp->next = NULL;
			}
			else
			{
				node* ptr;
				ptr = head2;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = temp;
				temp->next = NULL;
			}
		}
		int totalbill = 0;
		string code;
		char a = 'y';
		while (a == 'y' || a == 'Y')
		{
			int count = 0;
			node* current = head2;
			cout << "Enter Product Code of Product you want to Purchase" << endl;
			cin >> code;
			while (current != NULL)
			{
				if (current->pbcode == code)
				{
					int c = 0;
					cout << "Enter Quantity of Product:  " << endl;
					cin >> c;
					totalbill = totalbill + (current->price*c);
					count++;
					break;
				}
				else
				{
					current = current->next;
				}
			}
			if (count == 0)
			{
				cout << "Your Product is Not in the list" << endl;
			}
			cout << "Do You Want other item to purchase? Y/N" << endl;
			cin >> a;
		}
		cout << "Your Total Bill is:         " << totalbill << endl << endl;
		cout << "                 *******Thank YOU************    ";
		_getch();
	}

};
int main()
{
	int a = 0;
	while (a != 3)
	{
		system("cls");
		cout << "         \n  ***********Bakery Management System****************" << endl << endl;
		cout << "        1: Admin Menu     " << endl;
		cout << "        2: Place Order    " << endl;
		cout << "        3: Exit           " << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			admin a;
			a.login();
			break;
		}
		case 2:
		{
			admin a;
			a.placeorder();
			break;
		}
		case 3:
		{
			break;
		}
		default:
			cout << "         You Enter Wrong Choice     ";
		}

	}
	_getch();
}
