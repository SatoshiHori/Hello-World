#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		// static constants
		static const int Num = 33;
		static const int Width  = 800;
		static const int Height = 600;
		static const int xZoom = 1;

		// core
		float p[Num][Num];
		float buffer[Width];
		float curr;
		float prev[Num];
		float sum;
		int from, to;
		int i, j;
		int rand;
		
		// for draw
		float zoom;
		int speed;
		int times;
		int count;
		int dragSpeedY;
		int dragSpeedX;
		int dragX;
		int dragY;
		int centerPos;
		float scale;
		float mouseX;
		float mouseY;

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
