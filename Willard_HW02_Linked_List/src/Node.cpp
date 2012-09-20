#include "Node.h"


Node::Node(void)
{
}


Node::~Node(void)
{

}

void insert(Node* insert_me, Node* after_me){
	insert_me->next = after_me->next;  // Both insert_me and after_me lead to the next node
	after_me->next = insert_me;  // after_me leads to insert_me
	insert_me->prev = after_me;  // insert_me->prev is assigned
	insert_me->next->prev = insert_me;  //  The next node points back to insert me with its prev
	// If Dr. Seuss wrote C++...
}

int listLength(Node* sentinel){
	Node* cur = sentinel->next;
	int count = 1;  // include sentinel
	while(cur != sentinel) {
		count++;
		cur = cur->next;
	}
	return count;
}

// This method detroys a node and sews the list back up.
void deleteFromList(Node* remove_me){
	remove_me->prev->next = remove_me->next; // Previous leads to next
	remove_me->next->prev = remove_me->prev; // Next points to previous
	//  The remove_me node is free
	remove_me->~Node(); // Let remove_me be reclaimed
}
