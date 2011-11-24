#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Controller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MyCinderProjectApp : public AppBasic {
  public:
	void prepareSettings(Settings *settings );
	void setup();
	void update();
	void draw();
	
	//gl::Texture myFlickrImages [];
//	gl::Texture myFlickrImage;
	
	Controller mController;
	
};


void MyCinderProjectApp::prepareSettings(Settings *settings )
{
	settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


void MyCinderProjectApp::setup()
{
	mController.addFlickrImage("http://farm8.static.flickr.com/7032/6393973263_20f9ca225c_m.jpg");
	mController.addFlickrImage("http://farm8.static.flickr.com/7032/6393973263_20f9ca225c_m.jpg");
	mController.addFlickrImage("http://farm8.static.flickr.com/7032/6393973263_20f9ca225c_m.jpg");
	mController.addFlickrImage("http://farm8.static.flickr.com/7032/6393973263_20f9ca225c_m.jpg");
	mController.addFlickrImage("http://farm8.static.flickr.com/7032/6393973263_20f9ca225c_m.jpg");
	
}

void MyCinderProjectApp::update()
{
	mController.update();
}

void MyCinderProjectApp::draw()
{
	gl::clear( Color( 0, 0, 0 ));
	mController.draw();
}


CINDER_APP_BASIC( MyCinderProjectApp, RendererGl )
