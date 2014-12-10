//
//  Hero.h
//  match3
//
//  Created by Anton Kovalchuk on 28.09.14.
//
//

#ifndef __match3__Hero__
#define __match3__Hero__

#include "Person.h"

USING_NS_CC;

class Hero : public Person
{
    CC_SYNTHESIZE(int, _rage, Rage);
    CC_SYNTHESIZE(int, _maxRage, MaxRage);
    
    virtual bool init();
    CREATE_FUNC(Hero);
};

#endif /* defined(__match3__Hero__) */
