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
}

void FlickrImage::update()
{
	//mLoc += mDir * mVel;
	//float x = getWindowWidth()/2;
	//float y = sin( getElapsedSeconds() ) * 75.0f + getWindowHeight() / 2;	
    mLoc.y =  sin( getElapsedSeconds()*2 ) * 10.0f + (getWindowHeight() - mImg.getHeight() ) / 2;
}

void FlickrImage::draw()
{
	if(mImg){
		gl::draw( mImg, mLoc);
	}
}

