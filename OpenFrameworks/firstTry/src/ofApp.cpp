#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // load in sounds:
    ow.loadSound("sounds/jdee_beat.mp3");
    dog.loadSound("sounds/dog.mp3");

    
    xPos = 0;
    xVel = 3;
    

    
}


//--------------------------------------------------------------
void ofApp::update(){

    
    
    xPos = xVel + xPos;
    if (xPos < 0) {
        xVel = -xVel;
        dog.play();
    }
    
    else if (xPos > ofGetWidth()) {
         xVel = -xVel;
         ow.play();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofCircle(xPos, ofGetHeight()/2 ,22);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
