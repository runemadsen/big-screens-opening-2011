#include "testApp.h"

/*  Setup
__________________________________________________________ */

void testApp::setup()
{
	max_start_time = 40;
    num_lanterns_front = 5;
    num_lanterns_middle = 6;
    num_lanterns_back = 7;
    
    ofSetWindowTitle("template project");
	ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofHideCursor();
    
    sequence.loadSequence("A_", "png", 1, 154, 3);
	sequence.preloadAllFrames();
    
    float xPos = 0;
    
    // create middle row
    
    for(int i = 0; i < num_lanterns_middle; i++)
    {
        float yPos = ofRandom(-100, -10);
        float start_time = ofRandom(max_start_time);
        float scale = ofRandom(0.3, 0.6);
        float framerate = ofRandom(30, 60);
        
        lanterns.push_back(new Lantern(&sequence, xPos, yPos, start_time, framerate, scale));
        
        xPos += ((ofGetWidth() - 200) / num_lanterns_middle);
        cout << xPos << "\n";
    }
    
    // Create front row
    
    xPos = 0;
    
    for(int i = 0; i < num_lanterns_front; i++)
    {
        float yPos = ofRandom(-100, -10);
        float start_time = ofRandom(max_start_time);
        float scale = ofRandom(0.7, 0.9);
        float framerate = ofRandom(30, 60);
        
        lanterns.push_back(new Lantern(&sequence, xPos, yPos, start_time, framerate, scale));
        
        xPos += ((ofGetWidth() - 200) / num_lanterns_front);
        cout << xPos << "\n";
    }
    
    
    
    
    
    
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