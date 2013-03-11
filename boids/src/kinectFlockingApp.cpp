#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Particle.h"
#include "ParticleController.h"
#include "cinder/Channel.h"
#include "cinder/ImageIO.h"
#include "cinder/Capture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class kinectFlockingApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    ParticleController  mParticleController;
    Channel32f          mChannel;
    Capture             mCapture;
};

void kinectFlockingApp::setup()
{
    try {
        mCapture = Capture(800, 600);
        mCapture.start();
    }
    catch ( ... ) {
        console() << "Couldn't initialize capture.";
    }
    
}

void kinectFlockingApp::mouseDown( MouseEvent event )
{
}

void kinectFlockingApp::update()
{
    if ( mCapture && mCapture.checkNewFrame() ) {
        Channel32f channel(mCapture.getSurface());
        mParticleController.update(channel);
    }
}

void kinectFlockingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0,0,0 ) );
    mParticleController.draw();
}

void kinectFlockingApp::prepareSettings( Settings *settings) {
    settings->setWindowSize(800, 600);
    settings->setFrameRate(60);
    
}
CINDER_APP_BASIC( kinectFlockingApp, RendererGl )
