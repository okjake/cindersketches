//
//  Particle.cpp
//  kinectFlocking
//
//  Created by Jake Pyne on 13/08/2011.
//  Copyright 2011 TUI Interactive Media. All rights reserved.
//

#include "Particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Particle::Particle()
{
}

Particle::Particle( Vec2f loc )
{
    mLoc        = Vec2f(0,0);
	mDesiredLoc	= loc;
	mDir        = Rand::randVec2f();
	mVel        = Rand::randFloat( 5.0f );
	mRadius     = Rand::randFloat( 1.0f, 4.0f );
    mColor      = Color(255,255,255);
}

void Particle::update(const Channel32f &channel)
{
	//mLoc += mDir * mVel;
    //float gray = channel.getValue(mLoc);
    mDesiredRadius = channel.getValue( mLoc ) * 7.0f;
    
    if (mDesiredRadius > mRadius) {
        mRadius += 0.1;
    } else if (mDesiredRadius < mRadius) {
        mRadius -= 0.1;
    }
    
    if (mDesiredLoc.x > mLoc.x ) {
        mLoc.x += (mDesiredLoc.x - mLoc.x) / 20.0 ;
    }
    
    if (mDesiredLoc.x < mLoc.x) {
        mLoc.x -= (mLoc.x - mDesiredLoc.x) / 20.0;
    }
    
    if (mDesiredLoc.y > mLoc.y ) {
        mLoc.y += (mDesiredLoc.y - mLoc.y) / 20.0;
    }
    
    if (mDesiredLoc.y < mLoc.y) {
        mLoc.y -= (mLoc.y - mDesiredLoc.y) / 20.0;
    }
    
    
}

void Particle::draw()
{
    gl::color(mColor);
	gl::drawSolidCircle( mLoc, mRadius );
}
