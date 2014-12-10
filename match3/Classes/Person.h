//
//  Person.h
//  match3
//
//  Created by Anton Kovalchuk on 28.09.14.
//
//

#ifndef __match3__Person__
#define __match3__Person__

#include "cocos2d.h"

USING_NS_CC;

class Person : public Ref
{
    CC_SYNTHESIZE(int, _health, Health);
    CC_SYNTHESIZE(int, _maxHealth, MaxHealth);
    CC_SYNTHESIZE(int, _damage, Damage);
};

#endif /* defined(__match3__Person__) */
