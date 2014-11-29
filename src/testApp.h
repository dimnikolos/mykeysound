#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int WIDTH = 70;

		ofTrueTypeFont myfont;

		ofSoundPlayer soundPlayerArray[31];
		bool soundPlayerArrayLoaded[31];
		ofSoundPlayer aSoundPlayer;
		char keyArray[31] = {'Q','W','E','R','T','Y','U','I','O','P',
                         'A','S','D','F','G','H','J','K','L',
                         'Z','X','C','V','B','N','M',OF_KEY_LEFT,OF_KEY_DOWN,OF_KEY_RIGHT,OF_KEY_UP,' '};

};
