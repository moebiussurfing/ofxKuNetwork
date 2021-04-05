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

		// strings
		str = receiver.getString();
		ofLogNotice(__FUNCTION__) << ofToString(str);

		//-

		// chars
		//unsigned char *v;
		//auto b = receiver.getU8Array(v, sizeof(v));

		//std::string sc(reinterpret_cast<const char *> (v), sizeof(v) / sizeof(v[0]));
		//ofLogNotice(__FUNCTION__) << "-> " << sc << std::endl;

		////std::string sc(v, sizeof(v));

		//ofLogNotice(__FUNCTION__) << ofToString(sc);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(64);
	ofDrawBitmapStringHighlight(str, 20, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	std::string s;

	// fill with chars

	const int amnt = 300;
	//const int amnt = 300;//works
	//const int amnt = 325;//fails. too long


	// fill 1
	//s = "myString_{\n" + ofToString(ofGetFrameNum());
	//for (int i = 0; i < amnt; i++)
	//{
	//	s += "h";
	//	//s += ofToString((unsigned char)(i % 255));//? fails bc has delimiter char?
	//	//s += ofToString((unsigned char)ofRandom(0, 256));
	//	if (i % 10 == 0) s += "\n";
	//}
	//s += "\n}\nsize:";
	//s += ofToString(sizeof(s));


	// fill 2
	for (int i = 0; i < amnt; i++)
	{
		s += "h";
	}
	

	ofLogNotice(__FUNCTION__) << s;

	//-

	// string

	//if (key == 's')
	{
		sender.clearBuffer();
		sender.putString(s);
		sender.send();

		//https://stackoverflow.com/questions/62624475/size-of-string-vs-size-of-char-array-in-c
		//The sizeof(std::string) you are seeing may be specific to your implementation 
		//An array of chars is just an array of characters, so sizeof(arr) will always be the the number of characters.
	}

	//--

	// chars

	////if (key == 'c')
	//{
	//	//https://stackoverflow.com/questions/35322150/how-to-copy-a-stdstring-to-unsigned-char-array

	//	unsigned char uCharArr[amnt];
	//	std::copy(s.begin(), s.end(), uCharArr);
	//	uCharArr[s.length()] = 0;

	//	//auto uCharArr = reinterpret_cast<unsigned char*>(s.c_str());

	//	//ofLogNotice(__FUNCTION__) << uCharArr << std::endl;

	//	sender.clearBuffer();
	//	sender.putU8Array((unsigned char*)&uCharArr, sizeof(uCharArr));
	//	//sender.putU8Array(uCharArr, sizeof(uCharArr));
	//	sender.send();
	//}
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
