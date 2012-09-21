#include "Resources.h"


void Willard_HW02_Linked_ListApp::setup()
{
	// Initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,false);
	myPixels_ = (*mySurface_).getData();
}

void Willard_HW02_Linked_ListApp::drawShape(uint8_t* pixels, Shape myShape, int height, int width, Color c, uint8_t alpha){

	
		if(width <= 0) return;
		if(height <= 0) return;

		for(int ky=myShape.y-height;ky<=myShape.y+height; ky++){
			for(int kx=myShape.x-width;kx<=myShape.x+width;kx++){

				if(ky < 0 || kx < 0 || kx >= kAppWidth || ky >= kAppHeight) continue;

				if((kx == myShape.x-width)||(kx == myShape.x+width)||(ky == myShape.y-height)||(ky == myShape.y+height)) {

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
