#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include <vector>

void initGame(){
    std::vector<Sprite*> gameObjects;

    gameObjects.push_back(new EnemyManager());
    gameObjects.push_back(new Player());

    for(int i = 0; i < 3; ++i){
        int y = 20 + i * 120;
        for(int j = 0; j<4; ++j){
            int x = 20 + j*120;
            if(i == 0) gameObjects.push_back(new Enemy("EnemyPlaneColor.png",x, y));
            else if(i == 1) gameObjects.push_back(new Enemy("EnemyShipColor.png",x, y));
            else if(i == 2) gameObjects.push_back(new Enemy("EnemyUfoColor.png",x, y));
        }
    }
    for(auto sprite: gameObjects){
        eng.add(SpritePtr(sprite));
    }

}

int main(){

    /*the game should be controlled by the player being alive or not, if the player dies the screen gets cleared and the game starts again
    should I have a method here? something like "void setUp()" that puts all enemies and player in the engine..?
    or should the engine be able to take in an array or vector of sprites?
    */
    eng.setBackground(eng.loadTexture(cnts::gResPath + "images/space_bg.png"));

    // eng.add(SpritePtr(new Enemy("EnemyUfo.png", 20, 20)));
    // eng.add(SpritePtr(new Enemy("EnemyPlane.png", cnts::gScreenWidth/2, 0)));

    // eng.add(SpritePtr(new Player()));

    eng.startScreen();
    initGame();
    eng.run();
    
    return 0;
}
