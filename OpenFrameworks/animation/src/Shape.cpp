//
//  Shape.cpp
//  animation
//
//  Created by Pauline Hadad on 11/4/14.
//
//

#include "Shape.h"

Shape::Shape() {
    posX = ofGetWindowWidth() * 0.5;
    posY = ofGetWindowHeight() * 0.5;
}

void Shape::setup() {
  
    
    size = ofRandom(40, 60);
  
    velX = ofRandom(-5, 5);
    velY = ofRandom(-4, 4);
    
    r = ofRandom(255);
    g = ofRandom(255);
    b = ofRandom(255);
}

void Shape::move() {

    
    posX = posX + velX;
    posY += velY; //shorter syntax, but means the same as in posX above
    
    
   
    if (posX > ofGetWindowWidth() || posX < 0) {
        velX = velX * (-1);
    }
    
    if (posY > ofGetWindowHeight() || posY < 0) {
        velY *= (-1);
    }
}

void Shape::display() {
    float x0 = 50;
    float y0 = 300;
    float x1 = 550+50*cos(ofGetElapsedTimef()*1.0f);
    float y1 = 300+100*sin(ofGetElapsedTimef()/3.5f);
    float x2 = 600+30*cos(ofGetElapsedTimef()*2.0f);
    float y2 = 300+100*sin(ofGetElapsedTimef());
    float x3 = 650;
    float y3 = 300;
    
    
    
    ofFill();
    ofSetHexColor(0xFF99FF);
    ofBeginShape();
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0,0,0,40);
    ofCircle(x0,y0,4);
    ofCircle(x1,y1,4);
    ofCircle(x2,y2,4);
    ofCircle(x3,y3,4);
    ofDisableAlphaBlending();

}

void Shape::reset(float newPosX, float newPosY) {
    posX = newPosX;
    posY = newPosY;
    
    
    
  
    size = ofMap(newPosX, 0, ofGetWindowWidth(), 30, 80);
    
}







