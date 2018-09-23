#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
}
//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	float radius = 300;
	int tail_length = 60;
	int height = 500;

	this->cam.begin();
	ofRotateX(270);

	for (int z = 0; z <= height; z += 20) {

		int start_deg = ofGetFrameNum() % 360 + z;
		int sphere_deg = start_deg + tail_length;
		ofNoFill();
		ofBeginShape();
		for (int deg = start_deg; deg < sphere_deg; deg++) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);
			ofVertex(x, y, z - height * 0.5);
		}
		ofEndShape();

		ofFill();
		ofDrawSphere(ofPoint(radius * cos(sphere_deg * DEG_TO_RAD), radius * sin(sphere_deg * DEG_TO_RAD), z - height * 0.5), 5);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(720, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}