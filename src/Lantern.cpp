#include "Lantern.h"

Lantern::Lantern(ofxImageSequence * sequence, float xPos, float yPos, int start_time, float frame_rate, float scale)
{
    _sequence = sequence;
    _loc.set(xPos, yPos);
    _start_time = start_time;
    _frame_rate = frame_rate;
    _scale = scale;
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
    ofSetColor(255, 255, 255);
    ofEnableAlphaBlending();
    _sequence->setFrameRate(_frame_rate);
    
    ofTexture * tex = _sequence->getFrameForTime(_start_time + ofGetElapsedTimef());
    tex->draw(_loc.x, _loc.y, tex->getWidth() * _scale, tex->getHeight() * _scale);
    ofDisableAlphaBlending();
}

