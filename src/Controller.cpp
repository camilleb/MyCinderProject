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

void Controller::addFlickrImage(string url)
{
	float x = Rand::randFloat( app::getWindowWidth() );
	//float y = Rand::randFloat( app::getWindowHeight() );
	float y = getWindowHeight() / 2;
	mFlickrImages.push_back(FlickrImage(url, Vec2f( x, y ) ) );
}