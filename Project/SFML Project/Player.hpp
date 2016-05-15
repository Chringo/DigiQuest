#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit
{
public:
	Player(sf::Vector2f startPos);
	virtual ~Player();

	void Update(float dt);
	void Update(float dt, sf::Vector2f* target);

	void addLoot(int loot);
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	float mSpeed = 120.f;
	sf::Texture mAvatarTex;
	sf::Sprite mAvatarSprite;

	// Animation variables
	sf::Vector2i mCurrentKeyFrame;
	sf::Vector2i mKeyFrameSize;
	int mSpriteSheetWidth;
	float mAnimationSpeed;
	float mKeyFrameDuration;
	// Walking variables
	bool wasWalking;
	bool isWalking;
	sf::Vector2f goal;
	sf::Vector2f dir;
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif