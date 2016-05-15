#include "Player.hpp"

Player::Player(sf::Vector2f startPos)
{
	health = 200;
	recovery = 12;
	stamina = 120;
	energy = 20;

	// Board piece
	sf::String fileName = "../Resources/pi_player.png";
	if (!mTexture.loadFromFile(fileName))
	{
		// Handle error
	}
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setPosition(startPos.x + 54, startPos.y + 44);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// COMBAT VIEW - Background
	mBackgroundSprite.setPosition(330, 320);
	// Avatar
	fileName = "../Resources/av_player.png";
	if (!mAvatarTex.loadFromFile(fileName))
	{
		// Handle error
	}
	mAvatarSprite.setTexture(mAvatarTex);
	mAvatarSprite.setPosition(330, 320);
	// Stats
	mStats = new sf::RectangleShape[4];
	mStats[0] = sf::RectangleShape(sf::Vector2f((float)(1 * health), 32));
	mStats[1] = sf::RectangleShape(sf::Vector2f((float)(2 * recovery), 32));	// Super idiotic - TODO
	mStats[2] = sf::RectangleShape(sf::Vector2f((float)(1 * stamina), 32));
	mStats[3] = sf::RectangleShape(sf::Vector2f((float)(2 * energy), 32));		// Super idiotic - TODO
	mStats[0].setFillColor(sf::Color(100, 0, 0));
	mStats[1].setFillColor(sf::Color(200, 90, 90));
	mStats[2].setFillColor(sf::Color(0, 100, 0));
	mStats[3].setFillColor(sf::Color(90, 200, 90));
	for (int i = 0; i < 4; i++)
		mStats[i].setPosition(426, (float)(322 + 34 * i));

	// Initialise animation variables.
	mCurrentKeyFrame = sf::Vector2i(0, 0);
	mKeyFrameSize = sf::Vector2i(32, 32);
	mSpriteSheetWidth = 4;
	mAnimationSpeed = 0.2f;
	mKeyFrameDuration = 0.0f;
	// Initiate walking variables
	goal = mSpriteSheet.getPosition();
	wasWalking = false;
	isWalking = false;
}
Player::~Player()
{
	delete[] mStats;
}

void Player::Update(float dt)
{

}
void Player::Update(float dt, sf::Vector2f* target)
{
	// Check to start walking
	//if (is_S && !wasWalking && !isWalking)
	//{
	//	isWalking = true;
	//	goal = sf::Vector2f(target[1].x + 54, target[1].y + 44);
	//	dir = sf::Vector2f(0.f, 1.f);
	//}
	//else if (is_A && !wasWalking && !isWalking)
	//{
	//	isWalking = true;
	//	goal = sf::Vector2f(target[0].x + 54, target[0].y + 44);
	//	dir = sf::Vector2f(-1.6f, 0.9f);
	//}
	//else if (is_D && !wasWalking && !isWalking)
	//{
	//	isWalking = true;
	//	goal = sf::Vector2f(target[2].x + 54, target[2].y + 44);
	//	dir = sf::Vector2f(+1.6f, 0.9f);
	//}
	if (mSpriteSheet.getPosition().y < target[1].y)
	{
		isWalking = true;
		goal = sf::Vector2f(target[1].x + 54, target[1].y + 44);
		dir = sf::Vector2f(0.f, 1.f);
	}

	// Update walk
	if (isWalking)
	{
		mKeyFrameDuration += dt;
		mCurrentKeyFrame.y = 0;

		// Reset
		if (mSpriteSheet.getPosition().y > goal.y && ((mSpriteSheet.getPosition().x < (goal.x + 0.001f)) || (mSpriteSheet.getPosition().x >(goal.x + 0.001f))))
		{
			isWalking = false;
			dir = sf::Vector2f();
		}
	}

	mSpriteSheet.move(dir * mSpeed * dt);

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
	wasWalking = isWalking;
}

void Player::addLoot(int loot)
{
	this->loot += loot;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

	target.draw(mBackgroundSprite, states);
	target.draw(mAvatarSprite, states);
	for (int i = 0; i < 4; i++)
		target.draw(mStats[i], states);

	target.draw(mSpriteSheet, states);
}