#include "Lantern.h"

Lantern::Lantern(ofxImageSequence * sequence, float xPos, float yPos, int start_time, float frame_rate, float size, int survival)
{
    _sequence = sequence;
    _loc.set(xPos, yPos);
    _original_loc.set(xPos, yPos);
    _start_time = start_time;
    _frame_rate = frame_rate;
    _size = size;
    _survival = survival;    
    _start_millis = ofGetElapsedTimeMillis();
    
    alpha = 255;
    animating = false;
}

void Lantern::update()
{
    if(should_fade_down())
    {
        animating = true;
        tweenAlphaTo(0, 3, EasingEquations::EASE_INOUT_CUBIC);
    }
}

void Lantern::draw()
{
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha);
    _sequence->setFrameRate(_frame_rate);
    
    ofTexture * tex = _sequence->getFrameForTime(_start_time + ofGetElapsedTimef());
    tex->draw(_loc.x, _loc.y, _size, _size);
    ofDisableAlphaBlending();
}

bool Lantern::is_faded_down()
{
    return animating && alpha == 0;
}

bool Lantern::should_fade_down()
{
    return ofGetElapsedTimeMillis() - _start_millis > _survival && !animating;
}

void Lantern::reset(ofxImageSequence * sequence)
{
    _loc.x = _original_loc.x + ofRandom(100);
    
    if(_loc.x < 0)  _loc.x = 0;
    if(_loc.x > ofGetWidth() - 200) _loc.x = ofGetWidth() - 200;
    
    _sequence = sequence;
    _start_millis = ofGetElapsedTimeMillis();
    animating = false;
    tweenAlphaTo(255, 3, EasingEquations::EASE_INOUT_CUBIC);
}

