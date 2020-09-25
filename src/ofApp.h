#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;

	float hue = 0;
	float saturation = 0;
	float brightness = 255;
	float alpha = 255;

	float scale = 1;
	//float x = ofGetMouseX();
	//float y = ofGetMouseY();

    //ofColor currentDrawingColor = ofColor::fromHsb(hue, saturation, brightness, alpha);
    float currentDrawingRadius = 50;

	int a = 30;

	bool startDrawing;
	bool hollowbrush;

	/*
	ofPolyline currentPolyline;
	ofVec2f lastPoint;
	vector <ofPolyline> polylines;
	bool leftMouseButtonPressed;
	float minDistance;
    */    
};
