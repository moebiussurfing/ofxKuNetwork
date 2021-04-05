#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	receiver.setup(12345, 1024, true, 10000000);
	sender.setup("localhost", 12345, 1024);
}

//--------------------------------------------------------------
void ofApp::exit() {
	sender.close();
	receiver.close();
}

//--------------------------------------------------------------
void ofApp::update() {

	if (receiver.isDataNew()) {

		str = receiver.getString();
		ofLogNotice(__FUNCTION__) << ofToString(str);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(64);
	ofDrawBitmapStringHighlight(str, 20, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	// testing string 
	std::string s;

	// fill 
	const int amnt = 800;
	s = "myString_{\n\n" + ofToString(ofGetFrameNum());
	for (int i = 0; i < amnt; i++)
	{
		if (i < 128) s += ofToString((unsigned char)(i % 255));
		else if (i >= 128 && i < 256) s += "h";
		else s += ofToString((unsigned char)ofRandom(0, 256));
		if (i % 32 == 0) s += "\n";
	}
	s += "\n\n}\nsizeof:";// '\n's and size number not added..
	s += ofToString(sizeof(s));

	// log
	ofLogNotice(__FUNCTION__) << s;

	// send
	sender.clearBuffer();
	sender.putString(s);
	sender.send();
}
