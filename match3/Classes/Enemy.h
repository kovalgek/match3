//
//  Enemy.h
//  match3
//
//  Created by Anton Kovalchuk on 28.09.14.
//
//

#ifndef __match3__Enemy__
#define __match3__Enemy__

#include "Person.h"

USING_NS_CC;

class Enemy : public Person
{
    CC_SYNTHESIZE(int, _frequency, Frequency);
    
    virtual bool init();
    CREATE_FUNC(Enemy);
};

#endif /* defined(__match3__Enemy__) */
