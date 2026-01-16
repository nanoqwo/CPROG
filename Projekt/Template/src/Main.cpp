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
        for(int j = 0; j<5; ++j){
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
    eng.setBackground(eng.loadTexture(cnts::gResPath + "images/space_bg.png"));

    eng.startScreen("SPACE GAME", "Press ENTER to Start");
    initGame();
    eng.run();
    
    return 0;
}
