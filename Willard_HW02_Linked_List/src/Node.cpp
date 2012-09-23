
#include "Node.h"


Node::Node(int x_coord, int y_coord, int rect_width, int rect_height, int red, int green, int blue, int alpha_opacity)
{
	// Initialize all the variables
	next = this;
	prev = this;
	x = x_coord;
	y = y_coord;
	width = rect_width;
	height = rect_height;
	r = red;
	g = green;
	b = blue;
	alpha = alpha_opacity;

	// Make the rgb and alpha values reasonable
	if(r>255) { r = 255;}
	if(r<0) { r = 0; }
	if(g>255) { g = 255;}
	if(g<0) { g = 0; }
	if(b>255) { b = 255;}
	if(b<0) { b = 0; }
	if(alpha>255) { alpha = 255; }
	if(alpha<0) { alpha = 0; }

}


Node::~Node(void)
{
}

void Node::insert(Node* insert_me, Node* after_me){
	insert_me->next = after_me->next;  // Both insert_me and after_me lead to the next node
	after_me->next = insert_me;  // after_me leads to insert_me
	insert_me->prev = after_me;  // insert_me->prev is assigned
	insert_me->next->prev = insert_me;  //  The next node points back to insert me with its prev
	// If Dr. Seuss wrote C++...
}

int Node::listLength(Node* sentinel){
	Node* cur = sentinel->next;
	int count = 1;  // include sentinel
	while(cur != sentinel) {
		count++;
		cur = cur->next;
	}
	return count;
}

// This method detroys a node and sews the list back up.
void Node::deleteFromList(Node* remove_me){
	remove_me->prev->next = remove_me->next; // Previous leads to next
	remove_me->next->prev = remove_me->prev; // Next points to previous
	//  The remove_me node is free
	remove_me->~Node(); // Let remove_me be reclaimed
}

void Node::reverseList(Node* sentinel) {
	// The list will rearrange itself around the sentinel
	Node* cur = sentinel->next;
	while(cur != sentinel){
		Node* temp = cur->next; // Swap next and prev
		cur->next = cur->prev;
		cur->prev = temp;
		cur = cur->prev; // Remember, we're done, so prev is the new next
	}

}