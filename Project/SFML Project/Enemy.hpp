#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Unit.hpp"
class Enemy : public Unit
{
public:
	Enemy();
	Enemy(int health, int stamina, int recovery, int energy, int loot);
	virtual ~Enemy();

	void Update(float dt);
private:

	sf::Texture mAvatarTex;
	sf::Sprite mAvatarSprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif