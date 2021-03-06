// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();
	void setupArea(); // sets up the area
	void setupClick();
	void processMouseEvents(sf::Event t_mouseEvent);

	sf::Vector2i m_mouseClick{ 0, 0 }; //location of the first mouse click

	bool m_Click = true;

	int m_leftClickX = 0;
	int m_leftClickY = 0;

	sf::VertexArray m_laser{ sf::Lines };



	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Text m_powerLevelText; // text used for the altitude
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game


	sf::RectangleShape ground; // the ground
	sf::RectangleShape cannon; // the cannon
	sf::RectangleShape power; // the power bar

};

#endif // !GAME

