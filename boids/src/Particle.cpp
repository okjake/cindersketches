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
	mLoc	= loc;
	mDir	= Rand::randVec2f();
	mVel	= Rand::randFloat( 5.0f );
	mRadius	= Rand::randFloat( 1.0f, 4.0f );
}

void Particle::update(const Channel32f &channel)
{
	//mLoc += mDir * mVel;
    float gray = channel.getValue(mLoc);
 
    mColor = Color(gray,gray,gray);
}

void Particle::draw()
{
    gl::color(mColor);
	gl::drawSolidCircle( mLoc, mRadius );
}
