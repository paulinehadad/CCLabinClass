#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255); //set background to pink
    //call setup function just for heart
    heart.setup();
    
    for (int i = 0; i < NUMHEARTS; i++) {
        hearts[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    heart.move();
    for(int i = 0; i < NUMHEARTS; i++) {
        hearts[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    heart.display();
    for(int i = 0; i < NUMHEARTS; i++) {
        hearts[i].display();
    }

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
    for(int i = 0; i < NUMHEARTS; i++) {
        hearts[i].reset(mouseX, mouseY);
    }

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
