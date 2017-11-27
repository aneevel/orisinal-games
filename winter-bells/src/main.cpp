#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	// TODO: Replace PLACEHOLDER with whatever title I settle on
	// TODO: Replace 800, 600 with a constant if this is the resolution settled on
	sf::RenderWindow window(sf::VideoMode(800,600), "Orisinal Bells PLACEHOLDER");

	// Limit the framerate to 60 fps to ensure a smooth run
	window.setFramerateLimit(60);

	// Load the background texture
	sf::Texture background;
	if(!background.loadFromFile("assets/background.png"))
		std::cout << "Could not load background asset!" << std::endl;

	// Create a sprite to represent it
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	// Load the player texture
	sf::Texture player;
	if(!player.loadFromFile("assets/squirrel.png"))
		std::cout << "Could not load player asset!" << std::endl;

	// Create a sprite to represent it
	sf::Sprite playerSprite;
	playerSprite.setTexture(player);

	// 60 is a magic number for now - the size of the sprite
	playerSprite.setPosition(window.getSize().x / 2, window.getSize().y - 60);

	while (window.isOpen()) {

		sf::Event event;

		// Immediately grab mouse position
		int previousPosition = event.mouseMove.x;

		while (window.pollEvent(event)) {

			// Process a close request
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Check for mouse movement
		if(sf::Event::MouseMoved && (previousPosition - event.mouseMove.x) > 1) {

			playerSprite.setPosition(sf::Mouse::getPosition(window).x, playerSprite.getPosition().y);
			std::cout << "Mouse left" << std::endl;
		} else if (sf::Event::MouseMoved && (event.mouseMove.x - previousPosition) > 1) {

			playerSprite.setPosition(sf::Mouse::getPosition(window).x , playerSprite.getPosition().y);
			std::cout << "Mouse right" << std::endl;
		}

		// Clear before draw phase
		window.clear();

		// Enter draw phase
		window.draw(backgroundSprite);
		window.draw(playerSprite);

		// Enter display phase
		window.display();
	}
}


