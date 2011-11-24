#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Xml.h"
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class FlickrXML {
public:
	FlickrXML();
	FlickrXML(string word);
	XmlTree getXMLPhotos();
	
	string mApiKey;
	string mWord;
	string mRequestUrl;
};