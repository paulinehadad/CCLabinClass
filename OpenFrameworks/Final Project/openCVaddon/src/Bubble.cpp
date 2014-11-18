//
//  Bubble.cpp
//  06_openCVaddon
//
//  Created by Pauline Hadad on 11/10/14.
//
//

#include "Bubble.h"

Bubble::Bubble() {
    positionX = ofGetWindowWidth() * 0.5;
    positionY = ofGetWindowHeight() * 0.5;
}

void Bubble::setup() {
    //set the size of the bubbles to random between 40 and 60
    size = ofRandom(40, 60);
    
    //sets velocity to random
    velX = ofRandom(-5, 5);
    velY = ofRandom(-4, 4);
    
    //sets the colors of the bubbles to random
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
}

void Bubble::move() {
    positionX += velX;
    positionY += velY;
    
    //if a bubble hits a wall, reverse direction
    if (positionX > ofGetWindowWidth() || positionX < 0) {
        velX *= (-1);
    }
    
    if (positionY > ofGetWindowHeight() || positionY < 0) {
        velY *= (-1);
    }
    
}

void Bubble::display() {
    ofSetColor(r, g, b);
    ofCircle(positionX, positionY, size);
    
    //convert the x + y position floats to strings
    string xPo = ofToString(positionX);
    string yPo = ofToString(positionY);
    
    //display instructions on the screen
    string debugString = "Dont mind the bubbles! Move your head around to play different sounds!";

    
    //draw our on screen output
    ofSetColor(178, 102, 255);
    ofDrawBitmapString(debugString, 30, 30);
    
}

void Bubble::reset(float newPosX, float newPosY) {
    positionX = newPosX;
    positionY = newPosY;
    size = ofMap(newPosX, 0, ofGetWindowWidth(), 30, 80);
}