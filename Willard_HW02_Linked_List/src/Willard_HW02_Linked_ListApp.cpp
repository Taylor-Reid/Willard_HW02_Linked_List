
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
	static void drawShape(uint8_t* pixels, int x, int y, int height, int width, Color c, uint8_t alpha);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Willard_HW02_Linked_ListApp::setup()
{
	// Initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,false);
	myPixels_ = (*mySurface_).getData();
}

void Willard_HW02_Linked_ListApp::drawShape(uint8_t* pixels, int x, int y, int height, int width, Color c, uint8_t alpha){

	
		if(width <= 0) return;
		if(height <= 0) return;

		for(int ky=y-height;ky<=y+height; ky++){
			for(int kx=x-width;kx<=x+width;kx++){

				if(ky < 0 || kx < 0 || kx >= kAppWidth || ky >= kAppHeight) continue;

				if((kx == x-width)||(kx == x+width)||(ky == y-height)||(ky == y+height)) {

					int indeces = 4*(kx + ky*kSurfaceSize);
					pixels[indeces] = c.r;
					pixels[indeces+1] = c.g;
					pixels[indeces+2] = c.b;
					pixels[indeces+3] = alpha;
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
	gl::clear( Color( 0, 0, 0 ) );

}

CINDER_APP_BASIC( Willard_HW02_Linked_ListApp, RendererGl )
