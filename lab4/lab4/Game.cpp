// author Alphonsus

#include "Game.h"
#include <iostream>


/// <summary>
/// default construcor
/// pass parameters fpr sfml window, setup m_exitGame
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "missile" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	setupArea(); // load base
	setupSprite(); // load texture
}

/// <summary>
/// default destructor for game, nothing to release
/// </summary>
Game::~Game()
{
}


/// <summary>
/// game loop running at 60fps
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	/*m_window.draw(m_welcomeMessage);
	m_window.draw(m_logoSprite);*/
	m_window.draw(ground);
	m_window.draw(cannon);
	m_window.draw(power);
	m_window.draw(m_powerLevelText);
	m_window.draw(m_laser);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_powerLevelText.setFont(m_ArialBlackfont); // sets the font
	m_powerLevelText.setString("Altitude"); // sets the string 
	m_powerLevelText.setPosition(15.0f, 550.0f); // sets position
	m_powerLevelText.setCharacterSize(20); // sets the size
	m_powerLevelText.setFillColor(sf::Color::White); // sets the colour
	



}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

void Game::setupArea()
{
	ground.setSize(sf::Vector2f (800, 100)); // set the size
	ground.setPosition(sf::Vector2f(0, 500)); // set position
	ground.setFillColor(sf::Color::Green); // set colour
	cannon.setSize(sf::Vector2f(60, 70)); // set the size
	cannon.setPosition(sf::Vector2f(400, 430)); // set the position
	cannon.setFillColor(sf::Color::Cyan); // set the colour
	power.setSize(sf::Vector2f(300, 20)); // set the size
	power.setPosition(sf::Vector2f(105, 550)); // set position
	power.setFillColor(sf::Color::Red); // set colour

}

void Game::setupClick()
{
}

void Game::processMouseEvents(sf::Event t_mouseEvent)
{
	sf::Vertex startOfLine{}; // start of the line
	sf::Vertex endOfLine{}; // end of the line
	sf::Vector2f Click{}; // location of the first mouse click

	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)
	{

		
			Click = (sf::Vector2f{ 400, 430 });
			startOfLine = sf::Vertex{ Click, sf::Color::Red };
			m_laser.append(startOfLine);

		
	}
}



