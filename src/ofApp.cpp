#include "ofApp.h"


void ofApp::setup()
{
    
//    currentDrawingColor = ofColor(255);
//    currentDrawingRadius = 20;
    
    ofSetCircleResolution(64);
	ofSetBackgroundAuto(false);
	ofSetBackgroundColor(38, 38, 38);

	

	/*
	minDistance = 10;
	leftMouseButtonPressed = false;
	*/
}


void ofApp::update()
{
	/*
	if (leftMouseButtonPressed) {
		ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
		if (lastPoint.distance(mousePos) >= minDistance) {
			// a.distance(b) calculates the Euclidean distance between point a and b.  It's
			// the length of the straight line distance between the points.
			currentPolyline.curveTo(mousePos);
			lastPoint = mousePos;
		}
	}
	*/
	//ofDrawRectangle(550, 550, 100, 100);
	//ofSetColor(0);
	//ofDrawBitmapString("brush size: " + ofToString(currentDrawingRadius), 600, 600);
}


void ofApp::draw()
{	

    ofFill();
    ofSetColor(ofColor::fromHsb(hue, saturation, brightness, alpha));
	ofSetRectMode(OF_RECTMODE_CORNER);
	//cout << hue << std::endl;
    

	if (hollowbrush == false) {

		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
			ofDrawCircle(ofGetMouseX(), ofGetMouseY(), currentDrawingRadius);
		}
		if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
			ofSetColor(38, 38, 38);
			ofDrawCircle(ofGetMouseX(), ofGetMouseY(), currentDrawingRadius);
		}

	}else{
		
		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {	
			ofNoFill();
			ofDrawCircle(ofGetMouseX(), ofGetMouseY(), currentDrawingRadius);
		}
		if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
			ofNoFill();
			ofSetColor(38, 38, 38);
			ofDrawCircle(ofGetMouseX(), ofGetMouseY(), currentDrawingRadius);
		}

		/*

		ofSetColor(255);  // White color for saved polylines
		for (int i = 0; i < polylines.size(); i++) {
			ofPolyline polyline = polylines[i];
			//polyline.draw();      

        float normalLength = 100;
        for (int p=0; p<500; p+=1) {
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = polyline.getIndexAtPercent(p/500.0);
            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
            ofLine(point-normal/2, point+normal/2);
        }
		}
		ofSetColor(255, 100, 0);  // Orange color for active polyline
		currentPolyline.draw();

		*/
		
		

	}



	std::stringstream ss;
	
	ss << " Hold down left mouse button to draw \n Hold down right mouse button to erase \n\n 1 decreases step size \n 2 increases step size \n\n = decreases brush size \n - increases brush size \n\n Q decreases hue \n W increases hue \n\n A decreases saturation \n S increases saturation \n\n Z decreases brightness \n X increases brightness \n\n O decreases alpha \n P increases alpha \n\n N enables hollow brush \n M enables regular round brush \n\n Delete key clears the canvas" << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

	ss << "step size: " << scale << std::endl << std::endl;
	ss << "brush size: " << currentDrawingRadius << std::endl << std::endl;
	ss << "hue: " << hue << std::endl << std::endl;
	ss << "saturation: " << saturation << std::endl << std::endl;
	ss << "brightness: " << brightness << std::endl << std::endl;
	ss << "alpha: " << alpha << std::endl << std::endl;


	ofDrawBitmapStringHighlight(ss.str(), 50, 100, ofColor(200), ofColor(0));

	if (hollowbrush == true) {
		ofDrawBitmapStringHighlight("hollowbrush", 50, 670, ofColor(200), ofColor(0));

		if (currentDrawingRadius <= 200) {
			ofSetColor(38);
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(150, 800, 200, 200);
			ofSetColor(ofColor::fromHsb(hue, saturation, brightness, alpha));
			ofNoFill();
			ofDrawEllipse(150, 800, currentDrawingRadius, currentDrawingRadius);
		}else{
			ofSetColor(0);
			ofDrawBitmapString(" Brush size \n exceeding preview limit", 50, 800);
		}
	}
	else if (hollowbrush == false) {
		ofDrawBitmapStringHighlight("round brush", 50, 670, ofColor(200), ofColor(0));

		if (currentDrawingRadius <= 200) {
			ofSetColor(38);
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(150, 800, 200, 200);
			ofSetColor(ofColor::fromHsb(hue, saturation, brightness, alpha));
			ofDrawEllipse(150, 800, currentDrawingRadius, currentDrawingRadius);
		}
		else {
			ofSetColor(0);
			ofDrawBitmapString(" Brush size \n exceeding preview limit", 50, 800);
		}
	}


	//ofSetColor(200);
	//ofSetRectMode(OF_RECTMODE_CENTER);
	//ofDrawRectangle(150, 800, 200, 200);
	//ofSetColor(ofColor::fromHsb(hue, saturation, brightness, alpha));
	//ofDrawEllipse(150, 800, currentDrawingRadius, currentDrawingRadius);





    
}


void ofApp::keyPressed(int key)
{
	//new canvas

	if (key == OF_KEY_DEL) {
		ofSetRectMode(OF_RECTMODE_CORNER);
		ofSetColor(38, 38, 38);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}


	//scale picker

	if (key == '1') {

		scale--;
		scale = ofClamp(scale, 1, 100);



	}else if (key == '2') {

		scale++;
		scale = ofClamp(scale, 1, 100);


	}

	std::cout << "scale - " << scale << std::endl;

	//brush radius

    if (key == '-'){

        currentDrawingRadius -= scale;
        currentDrawingRadius = ofClamp(currentDrawingRadius, 1, 500);

        
    }else if (key == '='){

        currentDrawingRadius += scale;
		currentDrawingRadius = ofClamp(currentDrawingRadius, 1, 500);


    }

	std::cout << "radius - " << currentDrawingRadius << std::endl;


	//hue

	if (key == 'q') {
		
		hue -= scale;
		hue = ofClamp(hue, 1, 255);


	}
	else if (key == 'w') {
		
		hue += scale;
		hue = ofClamp(hue, 1, 255);


	}

	std::cout << "hue - " << hue << std::endl;

	//saturation

	if (key == 'a') {

		saturation -= scale;
		saturation = ofClamp(saturation, 1, 255);

	}
	else if (key == 's') {

		saturation += scale;
		saturation = ofClamp(saturation, 1, 255);


	}

	std::cout << "saturation - " << saturation << std::endl;

	//brightness

	if (key == 'z') {

		brightness -= scale;
		brightness = ofClamp(brightness, 1, 255);


	}
	else if (key == 'x') {

		brightness += scale;
		brightness = ofClamp(brightness, 1, 255);


	}

	std::cout << "brightness - " << brightness << std::endl;

	//alpha

	if (key == 'o') {

		alpha -= scale;
		alpha = ofClamp(alpha, 1, 255);


	}
	else if (key == 'p') {

		alpha += scale;
		alpha = ofClamp(alpha, 1, 255);


	}

	std::cout << "alpha - " << alpha << std::endl;

	if (key == 'n') {
		hollowbrush = true;

	}
	else if (key == 'm') {
		hollowbrush = false;

	}

	std::cout << "hollowbrush - " << hollowbrush << std::endl;


}


void ofApp::keyReleased(int key)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
	/*
	if (hollowbrush == true) {
		if (button == OF_MOUSE_BUTTON_LEFT) {
			leftMouseButtonPressed = true;
			currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
			currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
			lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
		}
	}
	*/
}


void ofApp::mouseReleased(int x, int y, int button)
{
	/*
	if (hollowbrush == true) {
		if (button == OF_MOUSE_BUTTON_LEFT) {
			leftMouseButtonPressed = false;
			currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
			currentPolyline.simplify(0.75);
			polylines.push_back(currentPolyline);
			currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
		}
	}
	*/
}