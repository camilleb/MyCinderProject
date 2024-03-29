#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class FlickrImage {
public:
	FlickrImage();
	FlickrImage( string url, ci::Vec2f, float delta );
	void update();
	void draw();
    void setX(float x, float delta);
	
	ci::Vec2f	mLoc;
	string		mUrl;
	gl::Texture mImg;
    int mDir;
    int mSpeed;
};