#include "FlickrXML.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Xml.h"
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

FlickrXML::FlickrXML()
{
}

FlickrXML::FlickrXML(string word)
{
	mWord = word;
}

XmlTree FlickrXML::getXMLPhotos() {
	mApiKey = "d8b4e87121f8791d80a5ae75e34eeca6";
	mRequestUrl = "http://api.flickr.com/services/rest/?method=flickr.photos.search";
	mRequestUrl += "&api_key="+mApiKey;
	mRequestUrl += "&tags="+mWord;
	mRequestUrl += "&per_page=5"; 
	
	cout << mRequestUrl << endl;
	XmlTree xml ( loadUrl( Url( mRequestUrl ) ) );
	return xml.getChild("rsp/photos");
}