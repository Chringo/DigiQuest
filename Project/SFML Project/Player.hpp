#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player(sf::Vector2f startPos);
	virtual ~Player();

	void Update(float dt, sf::Vector2f target);

private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	float mSpeed = 120.f;

	// Animation variables
	sf::Vector2i mCurrentKeyFrame;
	sf::Vector2i mKeyFrameSize;
	int mSpriteSheetWidth;
	float mAnimationSpeed;
	float mKeyFrameDuration;
	// Walking variables
	bool wasWalking;
	bool isWalking;

	// Jump variables
	bool mWasSpacePressed = false;
	bool mIsJumping = false;
	float mStartY = 0.0f;
	sf::Vector2f dir;
	float mGravity = 9.82f;
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif