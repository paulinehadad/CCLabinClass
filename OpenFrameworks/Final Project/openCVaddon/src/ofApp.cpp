#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //initiate the video grabber and load the face tracking model file
    vidGrabber.initGrabber(320,240);
    finder.setup("haarcascade_frontalface_default.xml");
    
   //load in sounds
    ellie.loadSound("sounds/ellie.mp3");
    bey.loadSound("sounds/bey.mp3");
    rock.loadSound("sounds/rock.mp3");
    iggy.loadSound("sounds/iggy.mp3");
    
    // controls how round circles are;
    ofSetCircleResolution(50);
    
    //call the setup function for all bubbles
    for (int i = 0; i < NUMBUB; i++) {
        bubbles[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //call an update to get a new frame from the camera
    vidGrabber.update();
    
    //if there is a new frame, look for faces in it.
    if (vidGrabber.isFrameNew()){
        finder.findHaarObjects(vidGrabber.getPixelsRef());
	}
    
    //make all bubbles move
    for (int i = 0; i < NUMBUB; i++) {
        bubbles[i].move();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw the image you got from the camera scaled up a bit
    vidGrabber.draw(0, 0, 640, 480);
    
    //display all bubbles
    for (int i = 0; i < NUMBUB; i++) {
        bubbles[i].display();
    }
	
    //for every face you find, draw a white rectangle around it.
    ofNoFill();
    ofRectangle face;
	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        face = finder.blobs[i].boundingRect;
		ofRect(face.xPos*2, face.y*2, face.width*2, face.height*2);

	}

    //convert the x + y position floats to strings
    string xPosi = ofToString(face.xPos);
    string yPosi = ofToString(face.y);

    
   //debug line showing the x coordinate of the head's position
   cout << "xFace is:" + xPosi << endl;
    
    //if the head is on any side of the window, then play first sound
    if ((face.xPos && face.y) == 0) {
        ellie.play();
    }
    
    //if the head is on, then play the second sound
    if ((face.y < 220) && (face.y > 190)) {
        bey.play();
    }
    
    //if the head is on, then play the third sound
    if ((face.y < 300) && (face.y > 200)) {
        iggy.play();
    }
    
    //if the head is on, then play the fourth sound
    if ((face.xPos < 300) && (face.xPos > 200)) {
        rock.play();
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
