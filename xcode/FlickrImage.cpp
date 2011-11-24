#include "FlickrImage.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;

FlickrImage::FlickrImage()
{
}

FlickrImage::FlickrImage(string url, Vec2f loc )
{
	mLoc	= loc;
	mDir	= Rand::randVec2f();
	mVel	= Rand::randFloat( 5.0f );
	mUrl	= url;
	mImg	= gl::Texture( loadImage( loadUrl( mUrl ) ) );
}

void FlickrImage::update()
{
	mLoc += mDir * mVel;
	//float x = getWindowWidth()/2;
	//float y = sin( getElapsedSeconds() ) * 75.0f + getWindowHeight() / 2;	
}

void FlickrImage::draw()
{
	if(mImg){
		gl::draw( mImg, mLoc);
		//gl::draw( myFlickrImage, Vec2f( x - myFlickrImage.getWidth() / 2, y - myFlickrImage.getHeight() / 2 ));
	}
}

