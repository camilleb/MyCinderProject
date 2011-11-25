#include "FlickrImage.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;

FlickrImage::FlickrImage()
{
}

FlickrImage::FlickrImage(string url, Vec2f loc, float delta )
{
	mUrl	= url;
	mImg	= gl::Texture( loadImage( loadUrl( mUrl ) ) );
	mLoc	= loc;
    mLoc.x += (delta - mImg.getWidth())/2;
    mDir    = 1 - 2 * (rand() % 2);
    mSpeed    = rand() % 2 + 1;
}

void FlickrImage::update()
{
    mLoc.y =  sin( getElapsedSeconds() * mSpeed * mDir) * 10.0f + (getWindowHeight() - mImg.getHeight() ) / 2;
}

void FlickrImage::draw()
{
	if(mImg){
		gl::draw( mImg, mLoc);
	}
}

void FlickrImage::setX(float x, float delta){
     mLoc.x = x + (delta - mImg.getWidth())/2;
}
