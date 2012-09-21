#include "Shape.h"

class Node
{
public:
	
	Node* next;
	Node* prev;

	Node();
	~Node(void);

	void insert(Node* insert_me, Node* after_me);
	int listLength(Node* sentinel);
	void deleteFromList(Node* remove_me);
	void reverseList(Node* sentinel);
};