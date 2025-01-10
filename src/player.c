#include "player.h"
#include "resources.h"
#include <raylib.h>
#include "ecs.h"

void initPlayer(Player *player)
{
    player->lives = 3;
    player->score = 0;
}

