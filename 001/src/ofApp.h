#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		static const int Num = 3;
		static const int Width  = 800;
		static const int Height = 600;
		int p[Num][Num];
		int buffer[Width];
		int curr;
		int thre[Num];
		int prev[Num];
		int from, to;
		int best, best_p;
		int i, j;
		int rand;
		float zoom;
		float speed;
		int count;
		int dragSpeedY;
		int dragSpeedX;
		int dragX;
		int dragY;
		int centerPos;
		float scale;
		int mouseX;
		int mouseY;
		int times;

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
