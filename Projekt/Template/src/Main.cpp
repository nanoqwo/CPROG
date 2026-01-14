#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

int main(){

    eng.setBackground(eng.loadTexture(cnts::gResPath + "images/space_bg.png"));

    eng.add(SpritePtr(new Enemy("football.png", cnts::gScreenWidth/2, 0)));
    eng.add(SpritePtr(new Player("RocketColor.png")));
    eng.run();
    
    return 0;
}
