//
//  Particle.h
//  kinectFlocking
//
//  Created by Jake Pyne on 13/08/2011.
//  Copyright 2011 TUI Interactive Media. All rights reserved.
//

#ifndef kinectFlocking_Particle_h
#define kinectFlocking_Particle_h

#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <vector>

class Particle {
public:
	Particle();
	Particle( ci::Vec2f );
	void update(const ci::Channel32f &channel);
	void draw();
	
	ci::Vec2f	mLoc;
	ci::Vec2f	mDir;
	float		mVel;
	float		mRadius;
    
    ci::Color   mColor;
};

#endif
