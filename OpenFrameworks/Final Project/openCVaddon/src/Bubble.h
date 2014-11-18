//
//  Bubble.h
//  06_openCVaddon
//
//  Created by Pauline Hadad on 11/10/14.
//
//

#pragma once
#include "ofMain.h"

class Bubble {
public:
    Bubble();
    
    int positionX, positionY;
    float velX, velY;
    float size;
    float r, g, b;
    
    void setup();
    void move();
    void display();
    
    void reset(float newPosX, float newPosY);
};