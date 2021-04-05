#pragma once

#include "ofMain.h"
#include "ofxKuNetwork.h"

class ofApp : public ofBaseApp {

	// push a key to
	// create a random string and to send-it.
	// receive the string and log.

public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);

	ofxKuNetworkTcpClient sender;
	ofxKuNetworkTcpServer receiver;

	std::string str;//received string
};
