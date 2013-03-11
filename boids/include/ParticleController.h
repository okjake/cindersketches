//
//  ParticleController.h
//  kinectFlocking
//
//  Created by Jake Pyne on 13/08/2011.
//  Copyright 2011 TUI Interactive Media. All rights reserved.
//

#ifndef kinectFlocking_ParticleController_h
#define kinectFlocking_ParticleController_h

#include "Particle.h"
#include <list>

class ParticleController {
public:
    ParticleController();
    void update(const ci::Channel32f &channel);
    void draw();
    void addParticles( int amt );
    void addParticle( int xi, int yi );
    void removeParticles( int amt );
    
    std::list<Particle> mParticles;
};

#endif
