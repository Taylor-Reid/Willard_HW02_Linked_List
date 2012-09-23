//#include "Shape.h"

class Node
{
public:
	
	Node* next;
	Node* prev;
	int x;
	int y;
	int width;
	int height;
	int r;
	int g;
	int b;
	int alpha;

	Node(int x_coord, int y_coord, int rect_width, int rect_height, int red, int green, int blue, int alpha_opacity);
	~Node(void);

	void insert(Node* insert_me, Node* after_me);
	int listLength(Node* sentinel);
	void deleteFromList(Node* remove_me);
	void reverseList(Node* sentinel);
};