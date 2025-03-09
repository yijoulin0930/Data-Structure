#include"LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Clear();
}


void LinkedList::Push_back(int x)
{
	//TODO: add a new node to the back of the list with value x
	if (head == NULL)
		head = new Node(x);
	else 
	{
		Node* add = new Node(x);
		for (Node* temp = head; temp != NULL; temp = temp->next) {
			if (temp->next == NULL) {
				temp->next = add;
				break;
			}
		}
	}
}

void LinkedList::Push_front(int x)
{
	//TODO: add a new node to the front of the list with value x
	if (head == NULL)
		head = new Node(x);
	else 
	{
		Node* temp = new Node(x);
		temp->next = head;
		head = temp;
	}
}

void LinkedList::Insert(int index, int x)
{
	//TODO: add a new node at position "index" of the list with value x
	if (index == 0)
	{
		Node* temp = new Node(x);
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* add = new Node(x);
		int i = 0;
		for (Node* temp = head; temp != NULL; temp = temp->next) {
			if (index == i + 1) {
				Node* tempNext = temp->next;
				add->next = tempNext;
				temp->next = add;
			}
			i++;
		}
		if (index == i )
			Push_back(x);
	}
}

void LinkedList::Delete(int index)
{
	//TODO: delete the node at position "index"
	if (index == 0)
		head = head->next;
	else 
	{
		Node* temp;
		int i = 0;
		for (temp = head; temp != NULL; temp = temp->next) {
			if (i + 1 == index) {
				Node* tempNext = temp->next;
				temp->next = tempNext->next;
				break;
			}
			i++;
		}
	}
}

void LinkedList::Reverse()
{
	//TODO: reverse all elements in the list
	LinkedList reverseLink;
	for (Node* temp = head; temp != NULL; temp = temp->next)
		reverseLink.Push_front(temp->value);
	head = reverseLink.head;
}

void LinkedList::Print()
{
	//TODO: print out all elements in the list
	if (head == NULL) {
		cout << "The List is empty\n";
		return;
	}

	cout << "List: ";
	for (Node* temp = head; temp != NULL; temp = temp -> next)
		cout << temp->value << " ";
	cout << endl;
}

void LinkedList::Clear() 
{
	//TODO: delete all elements in the list
	head = NULL;
}