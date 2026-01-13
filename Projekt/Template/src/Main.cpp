#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

int main(){

    SpritePtr sprites[]{SpritePtr(new Enemy("football.png", 0, 0))};


    eng.add(SpritePtr(new Enemy("football.png", 0,0)));
    eng.add(SpritePtr(new Player("Rocket.png")));
    eng.run();
    
    return 0;
}
