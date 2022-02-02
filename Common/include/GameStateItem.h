#ifndef R_TYPE_GAMESTATEITEM_H
#define R_TYPE_GAMESTATEITEM_H

#include "BasicBlock.hpp"

struct GameStateItem
{
    std::vector<InteratibleObject*> objects;
    std::vector<GameActor*> players;
    std::vector<GameActor*> enemys;
};

#endif //R_TYPE_GAMESTATEITEM_H
