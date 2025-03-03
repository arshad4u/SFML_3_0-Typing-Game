#include "Header.hpp"
int main() {
    srand(static_cast<unsigned>(time(NULL)));

    GameWindow game;
    Menu menu(&game.font);
    GameOver gameover(&game.font);
    
    while (game.isRunning()) {
        game.getWindow()->clear(sf::Color::White);
        game.getWindow()->draw(game.background);
        game.updateWindowEvents();
        if (game.getDead()) {
            gameover.renderGameOver(&game);
        } else {
            if (game.getStarted()) {
                game.renderGame(*game.getWindow());
            } else {
                menu.renderMenu(&game);
            }
        }
        game.getWindow()->display();
    }
}
