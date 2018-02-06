#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // ---------------------- ofShader Setup ------------------
    // loading shader
    // shader.load("Shaders/c");
    
    // -------- loading shader with AutoReloadedShader---------
    ambientShader.load("Shaders/c");
    
    //FBO setup
    
    //mainFBO
    mainFbo.allocate(ofGetWidth(), ofGetHeight());
    mainFbo.begin();
        ofClear(0, 0, 0, 0);
    mainFbo.end();
    
    //interactionFbo
    interactionFbo.allocate(ofGetWidth(),ofGetHeight());
    interactionFbo.begin();
        ofClear(0, 0, 0, 0);
    interactionFbo.end();

    // ----------------------- Syphon -------------------------
    //SYPHON: using Syphon app Simple Server
    mClient.set("","Simple Server");
    
    // Naming the Syphon output
    mainOutputSyphonServer.setName("oF output");
    
    mClient.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Showing framerate in window title
    std::stringstream strm;
    strm << "FPS: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    // Syphon Stuff
    // Publishing live capture to syphon server- available in Madmapper
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // --------------------ofShader test------------------------
    // shader.begin();
    // matches time in shader with time within openFrameworks
    // shader.setUniform1f("u_time", ofGetElapsedTimef());
    // matching window of shader with window in openFrameworks
    // shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    // ofRect(0,0,ofGetWidth(),ofGetHeight());
    // shader.end();
    
//    interactionShader.begin();
//    {
//
//    }
//    interactionShader.end();
//
//
//
//
//
//
//
//
//
    
    //-----ofxAutoReloadedShader ambient shader inside mainFbo------
    mainFbo.begin();
    {
        ofClear(0, 0, 0, 0);
        
        ambientShader.begin();
        {
            ambientShader.setUniform2f("u_resolution", ofGetWidth(),ofGetHeight());
            ambientShader.setUniform1f("u_time", ofGetElapsedTimef());
            ofSetColor(255,255,255);
            ofFill();
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            
            // Draw other fbo's inside here
            //
            // interactionShader.draw();
            //
            //
            //
        }
        ambientShader.end();
    }
    mainFbo.end();
    
    // ------------------------Drawing fbo----------------------
    ofBackground(0);
    
    mainFbo.draw(0 ,0);
    
    // Publishing to Syphon
    mainOutputSyphonServer.publishTexture(& mainFbo.getTexture());
    
    // ---------------------circle for test---------------------
    ofSetColor(255,255,255);
    ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 100);
    
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
