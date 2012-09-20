#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Willard_HW02_Linked_ListApp : public AppBasic {
  public:

	Node* sentinel;

	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Willard_HW02_Linked_ListApp::setup()
{
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
