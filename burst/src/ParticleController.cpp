#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ParticleController.h"

using namespace ci;
using std::list;

ParticleController::ParticleController()
{
    for( int y=0; y<80; y++ ){
        for( int x=0; x<100; x++ ){
            addParticle( x, y );
        }
    }
}

void ParticleController::update( const Channel32f &channel)
{
	for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update( channel );
	}
}

void ParticleController::draw()
{
	for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->draw();
	}
}

void ParticleController::addParticles( int amt )
{
	for( int i=0; i<amt; i++ )
	{
		float x = Rand::randFloat( app::getWindowWidth() );
		float y = Rand::randFloat( app::getWindowHeight() );
		mParticles.push_back( Particle( Vec2f( x, y ) ) );
	}
}

void ParticleController::removeParticles( int amt )
{
	for( int i=0; i<amt; i++ )
	{
		mParticles.pop_back();
	}
}


void ParticleController::addParticle(int xi, int yi) {
    float x = ( xi + 0.5f ) * 8.0f;
    float y = ( yi + 0.5f ) * 8.0f;
    mParticles.push_back( Particle( Vec2f( x, y ) ) );
}
