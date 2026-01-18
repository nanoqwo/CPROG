#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
    // Constants
   	constexpr int gScreenWidth     { 780 };
   	constexpr int gScreenHeight    { 970 };
   	// PATH TO YOUR RESOURCE FOLDER 'resources', 'gResPath'
   	const std::string gResPath { "./resources/" };
	// PATH'S TO ALL YOUR EXTERNAL RESOURCES using 'gResPath'
	const std::string bg_str  { gResPath + "images/space_bg.png" };
    const std::string rocketcolor_str { gResPath + "images/RocketColor.png" };
    const std::string rocket_str { gResPath + "images/Rocket.png" };
    const std::string enemyplane_str { gResPath + "images/EnemyPlaneColor.png" };
    const std::string enemyship_str { gResPath + "images/EnemyShipColor.png" };
    const std::string enemyufo_str { gResPath + "images/EnemyUfoColor.png" };
    const std::string projectile_str { gResPath + "images/Projectile.png" };
    const std::string bullet_str { gResPath + "images/Bullet.png" };
    const std::string font_str { gResPath + "fonts/Jersey10.ttf"};
}

#endif