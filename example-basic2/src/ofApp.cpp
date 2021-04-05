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

	std::string s = "myString" + ofToString(ofGetFrameNum());
	ofLogNotice(__FUNCTION__) << s;

	sender.clearBuffer();
	sender.putString(s);
	sender.send();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
