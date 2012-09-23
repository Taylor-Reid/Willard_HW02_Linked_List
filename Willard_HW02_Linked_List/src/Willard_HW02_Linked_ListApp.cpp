
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


	// Initialize linked list
	sentinel = &Node(100,100,100,100,127,127,127,5);
	
	// Fill List
	Node* last = sentinel;
	Node* cur;
	cur = new Node(100+(5),100-(5),100,100,127,127,127,5);

	//for(int i = 0; i<3; i++){
		//cur = &Node(100+(5*i),100-(5*i),100,100,127,127,127,5);
		((Node)*cur).insert(cur, last);
		last = cur;
	//}
	

	cur = sentinel->next;
	//while(cur != sentinel){
		drawRectangle(myPixels_, cur);
		//cur = cur->next;
	//}
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
	Color c = Color(n->r,n->g,n->b);
	
	if(n->width <= 0) return;
	if(n->height <= 0) return;

	for(int ky=n->y-n->height;ky<=n->y+n->height; ky++){
		for(int kx=n->x-n->width;kx<=n->x+n->width;kx++){

			if(ky < 0 || kx < 0 || kx >= kAppWidth || ky >= kAppHeight) continue;

			if((kx == n->x-n->width)||(kx == n->x+n->width)||(ky == n->y-n->height)||(ky == n->y+n->height)) {

				int indeces = 4*(kx + ky*kSurfaceSize);
				pixels[indeces] = c.r;
				pixels[indeces+1] = c.g;
				pixels[indeces+2] = c.b;
				pixels[indeces+3] = n->alpha;
			}
		}
	}
}

void Willard_HW02_Linked_ListApp::mouseDown( MouseEvent event )
{
}

void Willard_HW02_Linked_ListApp::update()
{
}

void Willard_HW02_Linked_ListApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	gl::draw(*mySurface_);

}

CINDER_APP_BASIC( Willard_HW02_Linked_ListApp, RendererGl )
