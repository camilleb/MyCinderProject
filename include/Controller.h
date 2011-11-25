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
	void addFlickrImage( string url, float delta, int i );
    void cleanFlickrImages();
    void positionPhotos(float delta);
	
	std::list<FlickrImage>	mFlickrImages;	
};