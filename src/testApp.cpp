#include "testApp.h"

/*  Setup
__________________________________________________________ */

void testApp::setup()
{
	max_start_time = 40;
    
    ofSetWindowTitle("template project");
	ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofHideCursor();
    
    sequence.loadSequence("frame", "png", 1, 11, 2);
	sequence.preloadAllFrames();
    
    lanterns.push_back(new Lantern(&sequence, 0, 0, ofRandom(max_start_time), ofRandom(1, 30)));
    lanterns.push_back(new Lantern(&sequence, 400, 0, ofRandom(max_start_time), ofRandom(1, 30)));
    lanterns.push_back(new Lantern(&sequence, 600, 0, ofRandom(max_start_time), ofRandom(1, 30)));
    
    title = new Title(scale, xPos, yPos, group_line1, group_line2, project_line1, project_line2);
    title->alpha = 0;
    //title->tweenAlphaTo(255, 3, EasingEquations::EASE_INOUT_CUBIC, 2);
    
    if (ofGetWidth() == 3840) 
    {
        ofToggleFullscreen();
    }
}

/*  Update
__________________________________________________________ */

void testApp::update()
{
}

/*  Draw
__________________________________________________________ */

void testApp::draw()
{
	ofBackground(0, 0, 0);	
    
    for(int i = 0; i < lanterns.size(); i++)
    {
        lanterns[i]->draw();
    }
    
    title->draw();
}

/*  Events
__________________________________________________________ */

void testApp::keyPressed  (int key){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}