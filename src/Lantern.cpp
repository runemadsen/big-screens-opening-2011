#include "Lantern.h"

Lantern::Lantern(ofxImageSequence * sequence, float xPos, float yPos, int start_time, float frame_rate)
{
    _sequence = sequence;
    _loc.set(xPos, yPos);
    _start_time = start_time;
    _frame_rate = frame_rate;
}

void Lantern::update()
{
    
}

void Lantern::draw()
{
    //ofEnableAlphaBlending();
    //ofSetColor(255, 255, 255, alpha);
    // draw pic
    //ofDisableAlphaBlending();
    _sequence->setFrameRate(_frame_rate);
    _sequence->getFrameForTime(_start_time + ofGetElapsedTimef())->draw(_loc.x, _loc.y);
}

