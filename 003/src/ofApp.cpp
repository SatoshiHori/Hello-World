// 003
// combination of probability and spark.

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(Width, Height);
	ofSetFrameRate(30);
	ofSetBackgroundColor(255,255,255);
	for (i = 0; i < Num; i++) {
		for (j = 0; j < Num; j++) {
			p[i][j] = 1.0 / (float)Num;
		}
		prev[i] = 0;
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
		curr = p[from][to]; // mouseY / (float)Height;
		p[from][to] += 1.0/(1.0/(float)Num+(abs(abs(curr) - abs(prev[to]))));
		sum = 0;
		for (i = 0; i < Num; i++) {
			sum += p[from][i];
		}
		p[from][to] /= sum;
		prev[to] = curr;
		from = to;
		rand = (int)ofRandom(-1, Num + 1);
		for (i = 0;; i++) {
			if (ofRandom(0, 1) < p[from][(i + rand) % Num] && from != (i + rand) % Num) {
				to = (i + rand) % Num;
				break;
			}
		}
		
		buffer[count] = prev[to];
		count++;
		if (count == Width / xZoom) count = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0,0,0);
	//std::printf("thre: %d /// ", thre[to]);
	//std::printf("from %d to %d\n", from, to);
	//std::printf("%d", button_frag);
	
	for (i = 1; i < (Width / xZoom); i++) {
		for (j = 1; j < 10; j++) {
			if (abs(buffer[i] - buffer[i - j]) / j < 0.01) {
				ofDrawLine(i * xZoom, (buffer[i] * (float)Height * zoom + (float)centerPos) + (float)Height / 2.0,
					(i - j) * xZoom, (buffer[i - j] * (float)Height * zoom + (float)centerPos) + (float)Height / 2.0);
				break;
			}
		}
		ofDrawCircle(i * xZoom, (buffer[i] * (float)Height * zoom + (float)centerPos) + (float)Height / 2.0, 1.0);
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