
#include "Resources.h"

#include "cinder/app/AppBasic.h"
#include "cinder/CinderResources.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Willard_HW02_Linked_ListApp : public AppBasic {
  public:

	Node* sentinel;
	static const int kAppWidth = 900;
	static const int kAppHeight = 900;
	static const int kSurfaceSize=1024;
	int frameNumber;
	int mouse_x;
	int mouse_y;
	Surface* mySurface_;
	uint8_t* myPixels_;

	void setup();
	void drawRectangle(uint8_t* pixels, Node* n);
	static void clear(uint8_t* pix);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Willard_HW02_Linked_ListApp::setup()
{
	// Initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,true);
	myPixels_ = (*mySurface_).getData();
	clear(myPixels_);

	// Initialize automation variables
	frameNumber = 0;
	mouse_x = 0;
	mouse_y = 0;

	// Initialize linked list
	sentinel = &Node(100,100,100,100,127,127,127,5);
	
	// Fill List
	Node* last = sentinel;
	Node* cur;
	//cur = new Node(100+(5),100-(5),100,100,127,127,127,5);

	for(int i = 0; i<4; i++){
		cur = (new Node(100+(20*i),100+(20*i),100,100,80,80+(40*i),80+(5*i),64*i));
		((Node)*cur).insert(cur, last);
		last = cur;
	}
	
	sentinel->reverseList(sentinel);

	cur = sentinel->next;
	while(cur != sentinel){
		drawRectangle(myPixels_, cur);
		cur = cur->next;
	}
}

void Willard_HW02_Linked_ListApp::clear(uint8_t* pix){
	Color c = Color(0,0,0);
	for(int y = 0; y < kSurfaceSize; y++){
		for(int x = 0; x < kSurfaceSize; x++){
			int index = 4*(x + y*kAppWidth);
			pix[index] = c.r;
			pix[index+1] = c.g;
			pix[index+2] = c.b;
		}
	}
}

void Willard_HW02_Linked_ListApp::drawRectangle(uint8_t* pixels, Node* n){

	uint8_t a = n->alpha;
	//Color c = Color(n->r,n->g,n->b);
	
	if(n->width <= 0) return;
	if(n->height <= 0) return;

	for(int ky=(n->y);ky<=(n->y)+(n->height); ky++){
		for(int kx=(n->x);kx<=(n->x)+(n->width);kx++){

			if(ky < 0 || kx < 0 || kx >= kAppWidth || ky >= kAppHeight) continue;

			if((kx >= (n->x))&&(kx <= (n->x)+(n->width))&&(ky >= (n->y))&&(ky <= (n->y)+(n->height))) {

				int indeces = 4*(kx + ky*kSurfaceSize);
				pixels[indeces] = n->r;
				pixels[indeces+1] = n->g;
				pixels[indeces+2] = n->b;
				pixels[indeces+3] = n->alpha;
			}
		}
	}
}

void Willard_HW02_Linked_ListApp::mouseDown( MouseEvent event )
{
	//mouse_x = event.getX();
	//mouse_y = event.getY();
}

void Willard_HW02_Linked_ListApp::update()
{
	/*
	frameNumber++;
	clear(myPixels_);
	Node* current = new Node();
	//sentinel->next = current;
	current = sentinel->next;
	
	while(current != sentinel){
		drawRectangle(myPixels_, current);
		current = current->next;
	}
	*/
}

void Willard_HW02_Linked_ListApp::draw()
{
	gl::draw(*mySurface_);

}

CINDER_APP_BASIC( Willard_HW02_Linked_ListApp, RendererGl )
