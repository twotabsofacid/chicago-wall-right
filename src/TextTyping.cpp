//
//  TextTyping.cpp
//  TextTypings
//
//
//

#include "TextTyping.hpp"

TextTyping::TextTyping()
{
	text = "Hello World!";
	pos = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	color = ofColor(40);
	fontSize = 24;
	incMax = 250;
    setup();
}

TextTyping::TextTyping(string _text, glm::vec2 _pos, ofColor _color, int _fontSize, int _incMax) {
	text = _text;
	pos = _pos;
	color = _color;
	fontSize = _fontSize;
	incMax = _incMax;
    setup();
}

void TextTyping::setup() {
	myfont.load("fonts/helveticaneue-std.ttf", fontSize);
	ofSetCircleResolution(100);
	inc = 0;
}

void TextTyping::update(int _inc) {
	inc = _inc;
}

void TextTyping::draw() {
	// say our incMax is 250, and we gone 100,
	// we would want to draw 100/250 = 0.4 of the string
	int charsToDraw = ofMap((float)inc/(float)incMax, 0.0, 1.0, 0, text.length(), true);
	ofPushStyle();
	ofSetColor(color);
	ofRectangle textRect = myfont.getStringBoundingBox(text, pos.x,pos.y);
	ofPushStyle();
	float easedAlpha = ofMap((float)inc/(float)incMax, 0.0, 1.0, 0.0, 220.0, true);
	ofSetColor(0, 0, 0, easedAlpha);
	ofFill();
	ofRectangle myRect;
	myRect.x = pos.x - textRect.width/2.0 - 10.0;
	myRect.y = pos.y - textRect.height/2.0 - (10.0 + fontSize);
	myRect.width = textRect.width + 20.0;
	myRect.height = textRect.height + 20.0;
	ofDrawRectangle(myRect);
	ofPopStyle();
	myfont.drawString(text.substr(0, charsToDraw), pos.x - textRect.width/2.0, pos.y - textRect.height/2.0);
	ofPopStyle();
}
