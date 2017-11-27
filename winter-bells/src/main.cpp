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

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			// Process a close request
			if (event.type == sf::Event::Closed)
				window.close();
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


