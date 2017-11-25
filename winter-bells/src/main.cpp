#include <SFML/Graphics.hpp>

int main() {

	// TODO: Replace PLACEHOLDER with whatever title I settle on
	// TODO: Replace 800, 600 with a constant if this is the resolution settled on
	sf::RenderWindow window(sf::VideoMode(800,600), "Orisinal Bells PLACEHOLDER");

	// Limit the framerate to 60 fps to ensure a smooth run
	window.setFramerateLimit(60);

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
		// TODO: Add draw phase

		// Enter display phase
		window.display();
	}
}


