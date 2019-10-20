#include"Node.h"
class LinkedList
{
public:
	int length;
	Node* head;

	LinkedList();
	void add(Account*);
	void insertAtTail(Account*);
	void print();
	void printSaving();
	void printChecking();
	void save();
	void transaction();
	void deleteNode();
	void editNode();
};
void LinkedList::editNode()
{
	string name, lname;
	cout << "Enter the first name of the client you want to edit";
	cin >> name;
	cout << "Enter the last name of the client you want to edit";
	cin >> lname;
	bool status = true;

	Node *node = head;

	while(node)
	{

		if (node->data->owner.getName() == name && node->data->owner.getLName() == lname)
		{
			string fN, lN, aT;
			int b;
			cout << "\n\n\nEnter Full Name of Client: ";    //Enter new Data
			cin >> fN >> lN;
			cout << "\n\n\nEnter New Balance: ";
			cin >> b;
			cout << "\n\n\nEnter new Account Type (saving/checking): ";
			cin >> aT;
			node->data->owner.setName(fN);
			node->data->owner.setLName(lN);
			node->data->owner.setAccountType(aT);
			node->data->balance = b;
			status = false;

		}
		node = node->next;

	}

	if (!status)
	{
	cout << "\n\t+-------------MODIFICATION SUCCESSFULL--------------+\n\n";
	}
	if (status)
	{
		cout << "\n\t+-------------NO SUCH CLIENT EXISTS-------------+\n\n";
	}

}
LinkedList::LinkedList() {
	length = 0;
	head = NULL;
}
void LinkedList::deleteNode()
{
	string name, lname;
	cout << "Enter full name of the Client: ";
	cin >> name >> lname;
	bool status = true;

	Node *node = head;

	if (head->data->owner.getName() == name && head->data->owner.getLName() == lname)
	{
		head = head->next;
		status = false;
	}
	else
	{

	   while(node && status)
	   {

		     if (node->next!=NULL && node->next->data->owner.getName()== name && node->next->data->owner.getLName() == lname)
		    {
				 node->next = node->next->next;
				 status = false;
		    }

	   }
	}
	if (!status)
	{
		     //deleting from linked list

	cout << "\n\t+-----------DELETION SUCCESSFULL----------------+\n\n";
	}

	if (status)
	{
	cout << "\n\t+-------------NO SUCH CLIENT EXISTS-------------+\n\n";
	}

}
void LinkedList::save()
{
	Node* node = head;
	while (node) {
		node->data->showDetails();
		node->data->save();
		node = node->next;
	}
}

void LinkedList::add(Account *a) {
	Node* node = new Node();
	node->data = a;
	node->next = head;
	this->head = node;
	this->length++;
}
void  LinkedList::insertAtTail(Account *a)
{
	if (head)
	{
		Node* node =head;

		while (node->next!=NULL)
		{
			node = node->next;
		}
		node->next = new Node();
		node->data = a;
		length++;

	}
	else
	{
		add(a);
	}
}

void LinkedList::print() {
	Node* node = head;
	int i = 1;
	while (node) {
		node->data->showDetails();
		node = node->next;
		i++;
	}
}
void LinkedList::printSaving() {
	Node* node = head;
	int i = 1;
	while (node) {
		if (node->data->owner.getAccountType() == "saving")
		{
			node->data->showDetails();
		}
		node = node->next;
		i++;
	}
}
void LinkedList::printChecking() {
	Node* node = head;
	int i = 1;
	while (node) {
		if (node->data->owner.getAccountType() == "checking")
		{
			node->data->showDetails();
		}
		node= node->next;
		i++;
	}
}
void LinkedList::transaction()
{
	string name, lname;
	cout << "Enter full name of the Client: ";
	cin >> name >> lname;
	bool status = true;

	Node* node = head;
	while(node && status)
	{

		if (node->data->owner.getName() == name && node->data->owner.getLName() == lname)
		{
			cout << "D for deposit || W for withdraw ";
			char t;
			cin >> t;
			cout << "Enter Amount";
			double amount;
			cin >> amount;

			Account *a;
			status = false;
			if (t == 'D' || t == 'd')
			{
				a=node->data;
				a->deposit(amount);
				a->showDetails();
				node->data = a;
			}
			else if (t == 'W' || t == 'w')
			{
				a = node->data;
				a->withdraw(amount);
				node->data = a;
			}
		}
		node = node->next;

	}
	if (!status)
	{
    cout << "\n\t+----------TRANSACTION SUCCESSFULL--------------+\n\n";

	}
	if (status)
	{
		cout << "\n\t+-------------NO SUCH CLIENT EXISTS-------------+\n\n";
	}
}
