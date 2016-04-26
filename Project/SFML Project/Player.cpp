#include "Player.hpp"

Player::Player(sf::Vector2f startPos)
{
	sf::String fileName = "../Resources/player2.png";
	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (!mTexture.loadFromFile(fileName))
	{
		// Handle error
	}
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setPosition(startPos.x + 54, startPos.y + 44);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// Initialise animation variables.
	mCurrentKeyFrame = sf::Vector2i(0, 0);
	mKeyFrameSize = sf::Vector2i(32, 32);
	mSpriteSheetWidth = 4;
	mAnimationSpeed = 0.2f;
	mKeyFrameDuration = 0.0f;
	// Initiate walking variables
	wasWalking = false;
	isWalking = false;
}
Player::~Player()
{

}

void Player::Update(float dt, sf::Vector2f target)
{
	sf::Vector2f direction(0.0f, 0.0f);

	// Handle input from arrow keys and update direction and animation
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	direction.x = -1.f;
	//	mKeyFrameDuration += dt;
	//	mCurrentKeyFrame.y = 1;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	direction.x = 1.0f;
	//	mKeyFrameDuration += dt;
	//	mCurrentKeyFrame.y = 2;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	direction.y = 1.0f;
	//	mKeyFrameDuration += dt;
	//	mCurrentKeyFrame.y = 0;
	//}

	//if ((mSpriteSheet.getPosition().x + 54) - target.x < 0.001f &&
	//	target.x - (mSpriteSheet.getPosition().x + 54) > 0.001f)

	// Check to start jumping
	bool is_S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool is_A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	if (is_S && !mWasSpacePressed && !mIsJumping)
	{
		mIsJumping = true;
		mStartY = mSpriteSheet.getPosition().y;
		dir = sf::Vector2f(0.f, 1.f);
	}
	else if (is_A && !mWasSpacePressed && !mIsJumping)
	{
		mIsJumping = true;
		mStartY = mSpriteSheet.getPosition().y;
		dir = sf::Vector2f(-1.1f, 0.9f);
	}

	// Update jump
	if (mIsJumping)
	{
		direction = dir;
		mKeyFrameDuration += dt;
		mCurrentKeyFrame.y = 0;

		// Check players walking, clean up
		if (mSpriteSheet.getPosition().y > (mStartY + 120.f))
		{
			mIsJumping = false;
			dir = sf::Vector2f(0.f, 0.f);
		}
	}

	mSpriteSheet.move(direction * mSpeed * dt);

	// Update animation
	if (mKeyFrameDuration >= mAnimationSpeed)
	{
		mCurrentKeyFrame.x++;

		if (mCurrentKeyFrame.x >= mSpriteSheetWidth)
			mCurrentKeyFrame.x = 0;

		mSpriteSheet.setTextureRect(sf::IntRect(mCurrentKeyFrame.x * mKeyFrameSize.x,
			mCurrentKeyFrame.y * mKeyFrameSize.y, mKeyFrameSize.x, mKeyFrameSize.y));
		mKeyFrameDuration = 0.0f;
	}

}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
}