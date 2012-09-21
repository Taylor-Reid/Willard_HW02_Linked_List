
#include "Node.h"

#include "cinder/CinderResources.h"
#include "cinder/app/AppBasic.h"
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
	static void drawShape(uint8_t* pixels, Shape myShape, int height, int width, Color c, uint8_t alpha);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};


//#define RES_MY_RES			CINDER_RESOURCE( ../resources/, image_name.png, 128, IMAGE )
