#pragma once

#include "ofMain.h"
#include "ofAppEGLWindow.h"
#include "ofxRPiCameraVideoGrabber.h"
#include "OMX_Maps.h"
#include "ofxOsc.h"
#include "ofxOMXPlayer.h"

#define PORT 12345

#define MODE_CAMERA 1
#define MODE_VIDEO 2

class shaderApp : public ofBaseApp, public ofxOMXPlayerListener {

	public:

	void setup();
	void update();
	void draw();
    void exit();
	void playVideo(string videoName, string videoPath);
	void onVideoEnd(ofxOMXPlayerListenerEventData& e);
	void onVideoLoop(ofxOMXPlayerListenerEventData& e){ /*empty*/ };

	ofxRPiCameraVideoGrabber videoGrabber;
	bool doDrawInfo;
	
	ofFbo camFbo;
	ofFbo overlayFbo;
	ofShader shader;

	ofTrueTypeFont font[2];

	ofxOscReceiver receiver;

	string lineOne;
	string lineTwo;

	ofxOMXPlayer omxPlayer;

	int displayMode;

	string currentFilter;
	string currentVideo;
    float videoEndTime;
    float timeMarkerTime;
    //bool stopVideo;
};

