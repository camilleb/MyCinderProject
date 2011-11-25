#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Xml.h"
#include "cinder/params/Params.h"
#include "Controller.h"
#include "FlickrXML.h"
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class MyCinderProjectApp : public AppBasic {
  public:
	void prepareSettings(Settings *settings );
	void setup();
	void update();
	void draw();
    void loadPhotos(string currentTag);
	
	Controller mController;
	FlickrXML mFlickrXML;
    params::InterfaceGl mParams;
    string mTag;
    string mCurrentTag;
};


void MyCinderProjectApp::prepareSettings(Settings *settings )
{
	settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}


void MyCinderProjectApp::setup()
{
	mTag = mCurrentTag = "kitten";    loadPhotos(mCurrentTag);
    
    mParams = params::InterfaceGl( "Parameters", Vec2i( 225, 10) );
    mParams.addParam( "Your word", &mTag );
}

void MyCinderProjectApp::update()
{
    
    if(mTag != mCurrentTag){
        mCurrentTag = mTag;
        mController.cleanFlickrImages();
        loadPhotos(mCurrentTag);
    }
	mController.update();
}

void MyCinderProjectApp::draw()
{
	gl::clear( Color( 0, 0, 0 ));
	mController.draw();
    
	// Draw the interface
	params::InterfaceGl::draw();
}

void MyCinderProjectApp::loadPhotos(string currentTag){
    mFlickrXML = FlickrXML(currentTag);
	XmlTree photos = mFlickrXML.getXMLPhotos();
	for( XmlTree::Iter photo = photos.begin("photo"); photo != photos.end(); ++photo ){
		string photoFarm = photo->getAttributeValue<string>( "farm" );
		string photoId = photo->getAttributeValue<string>( "id" );
		string photoServer = photo->getAttributeValue<string>( "server" );		
		string photoSecret = photo->getAttributeValue<string>( "secret" );
		string url = "http://farm"+photoFarm+".static.flickr.com/"+photoServer+"/"+photoId+"_"+photoSecret+"_m.jpg";
		mController.addFlickrImage(url);
	}
}


CINDER_APP_BASIC( MyCinderProjectApp, RendererGl )
