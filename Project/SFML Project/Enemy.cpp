#include "Enemy.hpp"


Enemy::Enemy()
{
	// Background
	mBackgroundSprite.setPosition(20, 320);

}
Enemy::Enemy(int h, int r, int s, int e, int l)
{
	health = h;
	recovery = r;
	stamina = s;
	energy = e;
	loot = l;

	// COMBAT VIEW - Background
	mBackgroundSprite.setPosition(20, 320);
	// Avatar
	sf::String fileName = "../Resources/av_bandit.png";
	if (!mAvatarTex.loadFromFile(fileName))
	{
		// Handle error
	}
	mAvatarSprite.setTexture(mAvatarTex);
	mAvatarSprite.setPosition(20, 320);
	// Stats
	mStats = new sf::RectangleShape[4];
	mStats[0] = sf::RectangleShape(sf::Vector2f((float)(2 * health), 32));
	mStats[1] = sf::RectangleShape(sf::Vector2f((float)(6 * recovery), 32));	// Super idiotic - TODO
	mStats[2] = sf::RectangleShape(sf::Vector2f((float)(2 * stamina), 32));
	mStats[3] = sf::RectangleShape(sf::Vector2f((float)(6 * energy), 32));		// Super idiotic - TODO
	mStats[0].setFillColor(sf::Color(100, 0, 0));
	mStats[1].setFillColor(sf::Color(200, 90, 90));
	mStats[2].setFillColor(sf::Color(0, 100, 0));
	mStats[3].setFillColor(sf::Color(90, 200, 90));
	for (int i = 0; i < 4; i++)
		mStats[i].setPosition(116, (float)(322 + 34 * i));

	// Text

}
Enemy::~Enemy()
{
	delete[] mStats;
}

void Enemy::Update(float dt)
{

}
void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mBackgroundSprite, states);

	if (mStats != nullptr)
	{
		target.draw(mAvatarSprite, states);
		for (int i = 0; i < 4; i++)
			target.draw(mStats[i], states);
	}
}