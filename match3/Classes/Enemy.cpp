//
//  Enemy.cpp
//  match3
//
//  Created by Anton Kovalchuk on 28.09.14.
//
//

#include "Enemy.h"

bool Enemy::init()
{
    _maxHealth = _health = 100;
    _damage = 20;
    _frequency = 5;
    
    return true;
}