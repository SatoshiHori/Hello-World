// 001
// based on integer.
// 2019/8/8

// i foaund bug in buffer time (2019/8/9 17:10)

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(Width, Height);
	ofSetFrameRate(30);
	ofSetBackgroundColor(255,255,255);
	for (i = 0; i < Num; i++) {
		for (j = 0; j < Num; j++) {
			p[i][j] = 0;// (int)ofRandom(-1, Num + 1);
		}
		prev[i] = 0;
		thre[i] = 0;
	}
	from = 0;
	to = 1;
	zoom = 1;
	count = 0;
	speed = 1;
	centerPos = 0;
	scale = 1;
	mouseX = 0;
	mouseY = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (times = 0; times < speed; times++) {
		curr = p[from][to];
		if (thre[to] > abs(abs(curr) - abs(prev[to]))) {
			p[from][to]++;
			//p[from][to] %= Height;
		}
		else {
			p[from][to]--;
			//p[from][to] %= Height;
			//p[from][to] *= -1;
		}
		thre[to] = abs(abs(curr) - abs(prev[to]));
		prev[to] = curr;
		from = to;
		rand = (int)ofRandom(-1, Num + 1);
		best_p = p[from][rand];
		best = rand;
		for (i = 0; i < Num; i++) {
			if (p[from][(i + rand) % Num] > best_p && from != (i + rand) % Num) {
				best_p = p[from][(i + rand) % Num];
				best = (i + rand) % Num;
			}
		}
		to = best;
		buffer[count] = prev[to];
		count++;
		if (count == Width) count = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0,0,0);
	//std::printf("thre: %d /// ", thre[to]);
	//std::printf("from %d to %d\n", from, to);
	//std::printf("%d", button_frag);
	
	for (i = 1; i < Width; i++) {
		for (j = 1; j < 30; j++) {
			if (abs(buffer[i] - buffer[i - j]) / j < 1) {
				ofDrawLine(i, ((buffer[i]) * zoom + centerPos) + Height / 2,
					(i - j), ((buffer[i-j]) * zoom + centerPos) + Height / 2);
				//break;
			}
		}
		ofDrawCircle(i, ((buffer[i]) * zoom + centerPos) + Height / 2, 1);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	std::printf("%d", key);
	if (key == 57357) speed *= 2;
	if (key == 57359 && speed > 1) speed /= 2;
	if (key == 57356) scale /= 2;
	if (key == 57358) scale *= 2;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	mouseX = x;
	mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	dragSpeedX = x - dragX;
	dragSpeedY = y - dragY;
	zoom += (float)dragSpeedX / 100.0 * (float)scale;
	centerPos += dragSpeedY;
	dragX = x;
	dragY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	dragX = x;
	dragY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//centerPos += y;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}