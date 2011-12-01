#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxImageSequence.h"
#include "Title.h"
#include "Lantern.h"
#include <sstream>
#include <string>

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void loadXML();
    
    
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // XML Data
        float scale;
        int xPos;
        int yPos;
        string group_line1;
        string group_line2;
        string project_line1;
        string project_line2;
        string video_name;
    
        ofxXmlSettings XML;
    
        Title * title;
        ofxImageSequence sequence;
        vector <Lantern *> lanterns;
    
        ofxImageSequence sequences[26];
    
        int max_start_time;
        int num_lanterns_front;
        int num_lanterns_middle;
        string sequence_letters;
};
