#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "Controller.h"

using namespace ci;
using std::list;

Controller::Controller()
{
}

void Controller::update()
{
	for( list<FlickrImage>::iterator fi = mFlickrImages.begin(); fi != mFlickrImages.end(); ++fi ){
		fi->update();
	}
}

void Controller::draw()
{
	for( list<FlickrImage>::iterator fi = mFlickrImages.begin(); fi != mFlickrImages.end(); ++fi ){
		fi->draw();
	}
}

void Controller::addFlickrImage(string url, float delta, int i)
{
	//float x = Rand::randFloat( app::getWindowWidth() );
	//float y = Rand::randFloat( app::getWindowHeight() );
	float x = delta * i;
    float y = getWindowHeight() / 2;
	mFlickrImages.push_back(FlickrImage(url, Vec2f( x, y ), delta ) );
}

void Controller::positionPhotos(float delta){
    int i = 0;
    for( list<FlickrImage>::iterator fi = mFlickrImages.begin(); fi != mFlickrImages.end(); ++fi ){
		fi->setX(delta * i, delta);
        i++;
	}
}

void Controller::cleanFlickrImages(){
    mFlickrImages.clear();
}