#pragma once
#include "ofMain.h"
#include "Tools.h"
#include "Tweenable2D.h"
#include "ofxImageSequence.h"

class Lantern : public Tweenable2D
{
public:
    
    Lantern(ofxImageSequence * sequence, float xPos, float yPos, int start_time, float frame_rate, float size, int survival);
    
    void update();
    void draw();
    bool is_faded_down();
    bool should_fade_down();
    
    void reset(ofxImageSequence * sequence);
    
    ofxImageSequence * _sequence;
    ofPoint _loc;
    ofPoint _original_loc;
    
    int _start_time;
    float _frame_rate;
    float _size;
    int _survival;
    
    long _start_millis;
    bool animating;
};
