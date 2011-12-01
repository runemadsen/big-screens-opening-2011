#pragma once
#include "ofMain.h"
#include "Tools.h"
#include "Tweenable2D.h"
#include "ofxImageSequence.h"

class Lantern : public Tweenable2D
{
public:
    
    Lantern(ofxImageSequence * sequence, float xPos, float yPos, int start_time, float frame_rate, float scale);
    
    void update();
    void draw();
    
    ofxImageSequence * _sequence;
    ofPoint _loc;
    
    int _start_time;
    float _frame_rate;
    float _scale;
};
