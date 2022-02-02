/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Enemy
*/

#include "GameBlock.hpp"

void gotoThen(BasicEntities *b)
{
    Enemy *e = (Enemy *) b;
    bool xSame = false;
    bool ySame = false;
    int buffx;
    int buffy;

    if (e->getposition().x == e->getRefPos().x)
        xSame = true;
    else {
        buffx = e->getRefPos().x - e->getposition().x;
        buffx = (buffx > 3) ? 3 : ((buffx < -3) ? -3 : ((buffx > 0) ? 1 : -1)); 
        e->getposition().x += buffx;
    }
    if (e->getposition().y == e->getRefPos().y)
        ySame = true;
    else {
        buffy = e->getRefPos().y - e->getposition().y;
        buffy = (buffy > 3) ? 3 : ((buffy < -3) ? -3 : ((buffy > 0) ? 1 : -1)); 
        e->getposition().y += buffy;
    }
    if (xSame && ySame) {
        if (b->getTag() == "Enemy0")
            b->mouve = Circular;
        else if (b->getTag() == "Enemy1")
            b->mouve = CircularBackAnForth;
    }
}

void Enemy::touchedBy(std::string _tag)
{
    if (_tag.substr(0,8) == "PMissile") {
        life--;
        if (_tag[8] == '2')
        life--;
    }
    if (life <= 0) {
        deteleteDelay = Tempo(1000);
        mbox.play("destroyed");
        setDelete(true);
    }
    else
        mbox.play("touch");
}

Enemy::Enemy(Vector2 _refPosition, Vector2 oPosition ,  int id, Tempo delay) : activeClock(delay)
{
    refPosition = _refPosition;
    if (id == 0)
        setDisplay("asset/enem.png", Vector2(2,1), Vector2(64,32), 6);
    if (id == 1){
        setDisplay("asset/enem1.png", Vector2(2,1), Vector2(96,48), 6);
        life  = 2;
    }
    position  = oPosition;
    mouve  = gotoThen;
    Tag = "Enemy" +  std::to_string(id);
    mbox.addSoud("asset/sound/smallBoom.ogg", "touch");
    mbox.addSoud("asset/sound/bigBoom.ogg", "destroyed");
}

void Enemy::tik()
{
    if (!set) {
        if (activeClock.tik())
            set = true;
        else return;
    }  
    if (act)
        act(this);
    if (mouve)
        mouve(this);
    if (anim.tik())
        changeSpriteIndex();
    getSprites().setPosition(position.x , position.y);
}