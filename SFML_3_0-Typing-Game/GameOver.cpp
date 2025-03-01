#include "Header.hpp"

void GameOver::initText(Font* font) {
    this->gameOverText.setFont(*font);
    this->gameOverText.setCharacterSize(36);
    this->gameOverText.setFillColor(Color::Black);
    this->gameOverText.setString("GAME OVER");
    this->gameOverText.setPosition(Vector2f(
                                   1920 / 2.f - this->gameOverText.getGlobalBounds().size.x / 2.f,
                                   1080 / 2.f - this->gameOverText.getGlobalBounds().size.y / 2.f)
    );
}

GameOver::GameOver(Font* font) : gameOverText(*font){
    this->initText(font);
}

void GameOver::renderGameOver(GameWindow *game) {

    game->getWindow()->draw(this->gameOverText);

    if (Mouse::isButtonPressed(Mouse::Button::Left)) {
        if (this->gameOverText.getGlobalBounds().contains(game->getMousePos())) {
            game->initVariables();
        }
    }
}
