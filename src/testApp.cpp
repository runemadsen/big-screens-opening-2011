#include "testApp.h"

/*  Setup
__________________________________________________________ */

void testApp::setup()
{
	max_start_time = 40;
    num_lanterns_front = 5;
    num_lanterns_middle = 7;
    sequence_letters = "BEHKNOPQSXYZ";
    float full_size = (ofGetHeight() * 0.70);
    int survival_min = 30000;
    int survival_max = 60000;
    
    loadXML();
    
    ofSetWindowTitle("template project");
	ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofHideCursor();
    
    // load sequences
    for(int i = 0; i < sequence_letters.length(); i++)
    {
        stringstream ss;
        string let;
        char c = sequence_letters[i];
        ss << c;
        ss >> let;
        let += "_";
        
        if(let != "G_")
        {
            sequences[i].loadSequence(let, "png", 1, 154, 3);
            sequences[i].preloadAllFrames();
            cout << "loaded sequence: " << let << "\n"; 
        }
    }
    
    float xPos = 0;
    float xRandom = ofGetHeight() / 7;
    
    // create middle row
    
    for(int i = 0; i < num_lanterns_middle; i++)
    {
        float yPos = ofRandom(-100, -20);
        float start_time = ofRandom(max_start_time);
        float scale = ofRandom(0.5, 0.8);
        float framerate = ofRandom(20, 40);
        float size = full_size * scale;
        float survival = ofRandom(survival_min, survival_max);
        int index = round(ofRandom(sequence_letters.length()-1));
        cout << index << "\n";
        
        lanterns.push_back(new Lantern(&sequences[index],i > 0 && i < num_lanterns_middle - 1 ? xPos - ofRandom(xRandom) : xPos, yPos, start_time, framerate, size, survival));
        
        xPos += ((ofGetWidth() - 300) / (num_lanterns_middle - 1));
    }
    
    // Create front row
    
    xRandom = ofGetHeight() / 4;
    xPos = 0;
    
    for(int i = 0; i < num_lanterns_front; i++)
    {
        float yPos = ofRandom(-100, -20);
        float start_time = ofRandom(max_start_time);
        float scale = ofRandom(0.75, 1);
        float framerate = ofRandom(20, 50);
        float size = full_size * scale;
        float survival = ofRandom(survival_min, survival_max);
        int index = round(ofRandom(sequence_letters.length()-1));
        
        lanterns.push_back(new Lantern(&sequences[index],i > 0 && i < num_lanterns_front - 1 ? xPos - ofRandom(xRandom) : xPos, yPos, start_time, framerate, size, survival));
        
        xPos += ((ofGetWidth() - 200) / (num_lanterns_front - 1));
    }
    
    
    title = new Title(scale, xTitlePos, yTitlePos);
    title->alpha = 255;
    
    if (ofGetWidth() == 3840) 
    {
        ofToggleFullscreen();
    }
}

void testApp::loadXML()
{
    XML.loadFile("settings.xml");
    
    scale = XML.getValue("root:scale", 1.0);
	xTitlePos = XML.getValue("root:xpos", 0);
	yTitlePos = XML.getValue("root:ypos", 0);
}

/*  Update
__________________________________________________________ */

void testApp::update()
{
    for(int i = 0; i < lanterns.size(); i++)
    {
        lanterns[i]->update();
        
        if(lanterns[i]->is_faded_down())
        {
            int index = round(ofRandom(sequence_letters.length()-1));
            lanterns[i]->reset(&sequences[index]);
        }
    }
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