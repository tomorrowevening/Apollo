#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Font.h"
#include "cinder/Text.h"
#include "cinder/params/Params.h"

#include "AppSettings.h"
#include "Background.h"
#include "Effectors.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderCocoaViewApp : public AppNative {
  public:
	
	AppSettings settings;
	Background bg;
	params::InterfaceGlRef	mParams;
	
	void prepareSettings( Settings *settings );
	void setup();
	void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	void setupGUI();
};

void CinderCocoaViewApp::prepareSettings( Settings *settings ) {
	settings->setWindowSize( 1000, 600 );
	settings->setFrameRate( 60.0f );
}

void CinderCocoaViewApp::setup() {
	setupGUI();
	bg.setup();
}

void CinderCocoaViewApp::mouseDown( MouseEvent event ) {
}

void CinderCocoaViewApp::update() {
	settings.update();
	bg.update();
}

void CinderCocoaViewApp::draw() {
	const float grey = 32.f / 255.f;
	gl::clear( Color( grey, grey, grey ), true );
	
	bg.bindShader();
	bg.render();
	bg.unbindShader();
	
	Vec2f pos;
	int i, n;
	float px, py, rad;
	
//	gl::enableAlphaBlending();
	gl::enableAdditiveBlending();
	gl::color(1, 1, 1, settings.dotAlpha);
	
	for(i = 0; i < settings.countX; ++i) {
		px = (float)i / (float)settings.countX;
		pos.x = i * settings.spaceX + settings.paddingX;
		for(n = 0; n < settings.countY; ++n) {
			py = (float)n / (float)settings.countY;
			pos.y = n * settings.spaceY + settings.paddingY;
			rad = settings.getRadius(px, py);
			gl::drawSolidCircle(pos, rad);
		}
	}
	
	gl::enableAlphaBlending();
	mParams->draw();
}

void CinderCocoaViewApp::keyDown( KeyEvent event ) {
	const char keyChar = event.getChar();
	if(keyChar == 'f') {
		setFullScreen(!isFullScreen());
	} else if(keyChar == 'r') {
		settings.reset();
	}
}

void CinderCocoaViewApp::setupGUI() {
	mParams = params::InterfaceGl::create( "Pattern", Vec2i( 200, 400 ) );
	
	// Total
	mParams->addParam("Count X", &settings.countX, "min=0 max=500 step=1");
	mParams->addParam("Count Y", &settings.countY, "min=0 max=500 step=1");
	
	// Spacing
	mParams->addParam("Space X", &settings.spaceX, "min=1 max=100 step=1");
	mParams->addParam("Space Y", &settings.spaceY, "min=1 max=100 step=1");
	
	// Padding
	mParams->addParam("Padding X", &settings.paddingX, "min=0 max=200 step=1");
	mParams->addParam("Padding Y", &settings.paddingY, "min=0 max=200 step=1");
	
	// Radius
	mParams->addParam("Alpha", &settings.dotAlpha, "min=-0 max=1 step=0.05");
	mParams->addParam("Radius X Effector", &settings.effectX);
	mParams->addParam("Radius Y Effector", &settings.effectY);
	mParams->addParam("Reverse X Effector", &settings.reverseX);
	mParams->addParam("Reverse Y Effector", &settings.reverseY);
	mParams->addParam("X Multiplier", &settings.multiplierX, "min=-20 max=20 step=0.25");
	mParams->addParam("Y Multiplier", &settings.multiplierY, "min=-20 max=20 step=0.25");
	
	// Effectors
	mParams->addParam("X Effector", settings.effectorNames(), &settings.xEffector);
	mParams->addParam("Y Effector", settings.effectorNames(), &settings.yEffector);
	
	mParams->addParam("Radius Multiplier", &settings.multiplierRadius, "min=0 max=25 step=0.1");
}

CINDER_APP_NATIVE( CinderCocoaViewApp, RendererGl )
