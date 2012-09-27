
/*
Cary Willard
9/24/2012

This app fulfills requirements A, B, and E of Homework 2,
Royal Society.

My instructional message code was adapted from Matt Dwyers message code,
which can be found in his Royal Society app here:

https://github.com/CaryWillard/RoyalSociety/blob/master/src/RoyalSocietyApp.cpp

The strobe function found in the draw method came from my CatPicture app.
The drawRectangle method came from my HomeWork01 app.

*/

/*
	This looks pretty good, the only issues I have seen are isues of de-cluttering the code,
	using simpler methods/functions.
	It would also be helpful if you added slightly more detailed comments to your functions describing
	what they do and what inputs they require.

*/


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

	void setup();
	void drawRectangle(Node* n);
	void clear();
	void toTop();
	void mouseDown( MouseEvent event );
	void keyDown(KeyEvent event);
	void update();
	void drawList(Node* sentinel);
	void draw();
	void prepareSettings(Settings* settings);
	void reverseList(Node* sentinel);

private:
	Node* sentinel;
	Node* cur;
	Node* temp;
	Surface* mySurface_;
	uint8_t* myPixels_;

	Font* font;
	bool showMenu;
	float brightness;
	float red;
	float green;
	float blue;
	float strobeInterval;
	float brightnessRatio;
	int color;
	bool strobeUp;
	bool rev;
	bool shimmy;

	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int kSurfaceSize=1024;

	int frameNumber;
	int mouse_x;
	int mouse_y;
	bool shiftIsDown;

};

// Standard prepare settings
void Willard_HW02_Linked_ListApp::prepareSettings(Settings* settings){
(*settings).setWindowSize(kAppWidth, kAppHeight);
}


void Willard_HW02_Linked_ListApp::setup()
{
	// Initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,true);
	myPixels_ = (*mySurface_).getData();
	clear();

	// Initializations for the strobing menu
	font = new Font("Times New Roman",30);
	brightness = 0.0f;
	red = 0.0f;
	green = 0.5f;
	blue = 1.0f;
	strobeInterval = 0.01f;
	strobeUp = true;
	brightnessRatio = 0.8;
	color = 1;
	shimmy = true;

	// Initialize automation variables
	frameNumber = 0;
	mouse_x = 0;
	mouse_y = 0;

	// Initialize linked list
	sentinel = new Node(100,100,100,100,127,127,127,5);//fixed per your instruction
	
	// Fill List
	temp = sentinel;

	for(int i = 0; i<25; i++){
		cur = (new Node((kAppWidth/4)+(i*6),(kAppHeight/4)+(i*6),200-(12*i),200
			-(12*i),80,(16*i),70+(5*i),255-(10*i)));
		((Node)*cur).insert_after(cur, temp);// I believe this can be written simply as cur->insert_after(cur,temp);
		temp = cur;
	}
	if(rev){
	reverseList(sentinel);
	}
	cur = sentinel->next;
	while(cur != sentinel){
		drawRectangle(cur);
		cur = cur->next;
	}
}


/*
Makes all the pixels in the surface black
*/
void Willard_HW02_Linked_ListApp::clear(){
	//you can make all the surface black using gl::clear(0,0,0) in the draw method
	Color c = Color(0,0,0);
	for(int y = 0; y < kSurfaceSize; y++){
		for(int x = 0; x < kSurfaceSize; x++){
			int index = 4*(x + y*kAppWidth);
			myPixels_[index] = c.r;
			myPixels_[index+1] = c.g;
			myPixels_[index+2] = c.b;
		}
	}
}

void Willard_HW02_Linked_ListApp::toTop()
{
Node* current = sentinel->next;
sentinel->next = current->next;
sentinel->next->prev = sentinel;
sentinel->insert_after(current, sentinel);

}

void drawList(Node* sentinel){

}

void Willard_HW02_Linked_ListApp::drawRectangle(Node* n){
	// It might be simpler do draw your shapes using the built in cinder::gl::drawRect()
	// that way you don't have to worry about modifying the surface directly, since that is not our assigment this time. 
	// cinder::gl::drawRect() can execute in the draw method. 
	uint8_t a = n->alpha;
	
	if(n->width <= 0) return;
	if(n->height <= 0) return;

	for(int ky=(n->y);ky<=(n->y)+(n->height); ky++){
		for(int kx=(n->x);kx<=(n->x)+(n->width);kx++){

			if(ky < 0 || kx < 0 || kx >= kAppWidth || ky >= kAppHeight) continue;

			if((kx >= (n->x))&&(kx <= (n->x)+(n->width))&&(ky >= (n->y))&&(ky 
				<= (n->y)+(n->height))) {

				int indeces = 4*(kx + ky*kSurfaceSize);
				myPixels_[indeces] = ((int)n->r);
				myPixels_[indeces+1] = ((int)n->g);
				myPixels_[indeces+2] = ((int)n->b);
				myPixels_[indeces+3] = ((int)n->alpha);
			}
		}
	}
}

// The linked list is correct for the first two nodes or so, and then the nodes 
// don't have any data.
void Willard_HW02_Linked_ListApp::reverseList(Node* sentinel) {
	// The list will rearrange itself around the sentinel
	Node* t;
	Node* c = sentinel;

	do{
		t = c->next;
		c->next = c->prev;
		c->prev = t;
		c = c->prev;
	}while(c != sentinel);
}

void Willard_HW02_Linked_ListApp::mouseDown( MouseEvent event )
{
	rev = !rev;
	setup();
}

void Willard_HW02_Linked_ListApp::keyDown(KeyEvent event)
{

	if(event.getCode() == KeyEvent::KEY_r){
		reverseList(sentinel);
	}

	char yup = event.getChar();
	if(yup == '/' || yup == '?')
	{
	if(showMenu){
		showMenu = false;
	} else{
		showMenu = true;
		}
	}

	// I can't figure out what these next two events do in your code. Are they functioning?
	if(event.getCode() == KeyEvent::KEY_SPACE){
		reverseList(sentinel);
	}

	if(event.getCode() == KeyEvent::KEY_UP){
		toTop();
	}
}

void Willard_HW02_Linked_ListApp::update()
{
	// Using the update method causes destroys my list
	//reverseList(sentinel);
}

void Willard_HW02_Linked_ListApp::draw()
{
	//gl::draw(*mySurface_);
	//all of these if statements can go into your update method, so that your draw method is not as cluttered.
	if(color == 1) {
		red = red + strobeInterval;
		green = green - (strobeInterval/2);
		blue = blue - (strobeInterval/2);
	}
	if(color == 2) {
		green = green + strobeInterval;
		red = red - (strobeInterval/2);
		blue = blue - (strobeInterval/2);
	}
	if(color == 3) {
		blue = blue + strobeInterval;
		red = red - (strobeInterval/2);
		green = green - (strobeInterval/2);
	}

	if((red > 1.0f)&&(color == 1)) {
		color = 2;
	}
	if((green > 1.0f)&&(color == 2)) {
		color = 3;
	}
	if((blue > 1.0f)&&(color == 3)) {
		color = 1;
	}

	if(showMenu){
		// ahh, this is a nice simple way to draw strings to the screen. I like this.
		gl::clear(Color(0,0,0));
		gl::drawString("Press \"?\", then click to reorder the pyramid stack", 
			Vec2f(150.0f,150.0f),Color(red,green,blue), *font);
	} else {

		gl::clear(Color(0,0,0));
		gl::draw(*mySurface_);
	}
	
}

CINDER_APP_BASIC( Willard_HW02_Linked_ListApp, RendererGl )
