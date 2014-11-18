#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofMain.h"
#include "Bubble.h"

//the number of bubbles on the screen
#define NUMBUB 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    //x position of the head
    int xPos;
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //bubbles is an array of Bubbles
    Bubble bubbles[NUMBUB];
    
    //the four different sounds
    ofSoundPlayer		ellie;
    ofSoundPlayer		bey;
    ofSoundPlayer		rock;
    ofSoundPlayer		iggy;
    
      //start by declaring a video grabber, to use the image from your camera
    ofVideoGrabber vidGrabber;
    
    //declare a haar finder, the method we'll use for face tracking
    ofxCvHaarFinder finder;
		
};
