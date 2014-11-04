//
//  Shape.h
//  animation
//
//  Created by Pauline Hadad on 11/4/14.
//
//


#pragma once
#include "ofMain.h"

class Shape {
public:
    
    //constructor
    Shape();
    
    //variables
    float posX, posY;
    float velX, velY;
    
    float size;
    
    float r, g, b;
    
    //methods
    void setup();
    void move();
    void display();
    
    void reset(float newPosX, float newPosY);
};



