#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    isFirst = false;
    image.load("tex2.png");
    shader.load("lifegame");
    currenttexture = &mBuffers[1];
    beforetexture = &mBuffers[0];
    ofFbo::Settings s = ofFbo::Settings();
    s.width = ofGetWidth();
    s.height = ofGetHeight();
    s.internalformat=GL_RGBA;
    s.useDepth=false;
    s.depthStencilAsTexture=false;
    for(int i = 0 ; i < 2; i++){
        mBuffers[i].allocate(s);
        mBuffers[i].begin();
        image.draw(ofPoint(0,0), ofGetWidth(), ofGetHeight());
        mBuffers[i].end();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    swap(currenttexture, beforetexture);
    currenttexture->begin();
    shader.begin();
    shader.setUniformTexture("texture", *beforetexture, 0);
    shader.setUniform2f("resolution", beforetexture->getWidth(), beforetexture->getHeight());
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1f("rand", ofRandom(0.5));
    shader.setUniform1f("screenWidth", ofGetWidth());
    shader.setUniform1f("screenHeight", ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    currenttexture->end();
    currenttexture->draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
