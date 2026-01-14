#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

int main(){

    /*the game should be controlled by the player being alive or not, if the player dies the screen gets cleared and the game starts again
    should I have a method here? something like "void setUp()" that puts all enemies and player in the engine..?
    or should the engine be able to take in an array or vector of sprites?
    */
    eng.setBackground(eng.loadTexture(cnts::gResPath + "images/space_bg.png"));

    eng.add(SpritePtr(new Enemy("EnemyUfo.png", 20, 20)));
    eng.add(SpritePtr(new Enemy("EnemyPlane.png", cnts::gScreenWidth/2, 0)));

    eng.add(SpritePtr(new Player("RocketColor.png")));

    eng.run();
    
    return 0;
}
