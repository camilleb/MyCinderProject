#pragma once
#include "FlickrImage.h"
#include <list>
#include <string>

using namespace std;

class Controller {
public:
	Controller();
	void update();
	void draw();
	void addFlickrImage( string url );
	
	std::list<FlickrImage>	mFlickrImages;
};