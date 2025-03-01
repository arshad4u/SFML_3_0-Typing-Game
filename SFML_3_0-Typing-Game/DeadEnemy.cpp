#include "Header.hpp"

DeadEnemy::DeadEnemy(float x, float y, Texture* dead) : sprite(*dead)  {
    this->rectSprite.size.y = 526;
    this->rectSprite.size.x = 629;
    
	this->sprite.setTextureRect(rectSprite);
	this->sprite.setTexture(*dead);
	this->sprite.scale(Vector2f(0.2f, 0.2f));
	this->sprite.setPosition(Vector2f(x, y));
}

void DeadEnemy::renderDead(RenderWindow& target) {
	if (this->clock.getElapsedTime().asSeconds() > 0.1f) {
        if (this->rectSprite.position.x < 6919) {
            this->rectSprite.position.x += 629;
		}
		sprite.setTextureRect(rectSprite);
		this->clock.restart();
	}

	target.draw(this->sprite);
}
