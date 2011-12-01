#include "Title.h"

Title::Title(float scale, int xPos, int yPos)
{
    if (ofGetWidth() != 3840) 
    {
        cout << "Setting vars for smaller screen \n";
        float percent = ofGetWidth() / 3840.0;
        scale = scale * percent;
        xPos = xPos * percent;
        yPos = yPos * percent;
    }
    
    cout << "xPos: " << xPos << "\n";
    
    _scale = scale;
    pos.set(xPos,yPos,0);
    
    _padding = 10 * _scale;
    _font_size = 80 * _scale;
    _light_font_size = 30 * _scale;
    
    _font.loadFont("Gotham-Medium.ttf", _font_size, true, true);
    _light_font.loadFont("Gotham-Light.ttf", _light_font_size);
    _font.setLetterSpacing(0.92);
}

void Title::update()
{
    
}

void Title::draw()
{
    ofEnableAlphaBlending();
    
    int y = pos.y;
    
    ofSetColor(255, 255, 255, alpha);
    _light_font.drawString("ITP Presents", pos.x, y);
    y += _light_font_size;
    
    draw_line(pos.x, y, "BIG SCREENS");
    
    ofDisableAlphaBlending();
}

void Title::draw_line(float x, float y, string line)
{
    // draw box
    ofSetColor(255, 255, 255, alpha);
    
    ofRect(x - _padding, y - _padding, _font.stringWidth(line) + (2 * _padding) + (_font_size / 8), _font_size + (2 * _padding));
    
    // draw line 1
    ofSetColor(0, 0, 0);
    _font.drawString(line, x, y + (_font_size - (_font_size / 40)));
}