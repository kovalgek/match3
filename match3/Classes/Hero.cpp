//
//  Hero.cpp
//  match3
//
//  Created by Anton Kovalchuk on 28.09.14.
//
//

#include "Hero.h"

bool Hero::init()
{
    _maxHealth = _health = 100;
    _damage = 20;
    
    _maxRage = 100;
    _rage = 0;
    
    return true;
}