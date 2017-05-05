#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <list>
#include <stdexcept>
#include <vector>
#include "Spaceship.h"
#include "Aliens.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Winner.h"
#include "Loser.h"
#include "Entity.h"
#include "Sound.h"
#include "Explosion.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
	sf::Vector2f shipPos;
	sf::Vector2f shipspeed(400.f, 0.f);
	sf::Vector2f alienPos;
	sf::Vector2f alienSpeed(500.f, 500.f);
	sf::Vector2f bulletPos;
	sf::Vector2f bulletSpeed(500.f, 0);
	bool gameOver = false;
	bool winner = false;
	int moveCount = 0;
	int bossMoveCount = 0;
	int playerLife = 3;
	int bossLife = 7;
	bool once = false;
	int m = 0, n = 0;

	srand(time(NULL));

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders Clone");
	window.setVerticalSyncEnabled(true);

	//start background music
	Sound music;
	music.playBackgroundMusic();

	//create background
	sf::Sprite back;
	sf::Texture star;

	//create explosion
	Explosion expl;
	expl.kill();

	if (!star.loadFromFile("stars.png"))
		throw std::invalid_argument("Background not loaded!");
	back.setTexture(star);

	//create life board
	sf::Text shipLife;
	sf::Text bssLife;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	shipLife.setFont(font);
	bssLife.setFont(font);
	shipLife.setCharacterSize(25);
	bssLife.setCharacterSize(25);
	shipLife.setPosition(0, 0);
	bssLife.setPosition(0, 25);
	shipLife.setFillColor(sf::Color::White);
	bssLife.setFillColor(sf::Color::White);


	//Load win and Lose screen
	Winner win;
	Loser lose;
	//create Boss bullet
	Bullet bossBullL(sf::Vector2f(0, 0), bulletSpeed, "bullet.png");
	Bullet bossBullR(sf::Vector2f(0, 0), bulletSpeed, "bullet.png");
	bossBullL.kill();
	bossBullR.kill();

	//create enemy bullet
	Bullet alienBullet(sf::Vector2f(0, 0), bulletSpeed, "bullet.png");
	alienBullet.kill();

	//create friendly bullet
	Bullet bullet(sf::Vector2f(0, 0), bulletSpeed, "bullet.png");
	bullet.kill();

	//create Alien BOSS
	Aliens Boss(sf::Vector2f(0, 0), alienSpeed, "Boss.png");
	Boss.getSprite().setScale(0.15, 0.15);
	Boss.setLocation(sf::Vector2f(WIDTH/2 - Boss.getSprite().getGlobalBounds().width/2,HEIGHT/4 - Boss.getSprite().getGlobalBounds().height/2));
	Boss.kill();

	//create The spaceship ***Eagle One***
	Spaceship eagleOne(sf::Vector2f(0.0, 0.0), shipspeed, "Player.png");
	shipPos.x = WIDTH / 2;
	shipPos.y = (HEIGHT - eagleOne.getSprite().getGlobalBounds().height);
	eagleOne.setLocation(shipPos);
	eagleOne.setLives(playerLife);

	//create the Asteroid Arrays 
	Asteroid AsteroidArray[9][4];
	//Set the location of the Asteroids 
	for (int i = 0; i < 9; i++)
	{
		if (i < 3)
		{
			for (int j = 0; j < 3; j++)
			{
				Asteroid ass1(sf::Vector2f(j * 27 + 3 * (WIDTH / 15) - 27, 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass2(sf::Vector2f(j * 27 + 6 * (WIDTH / 15) - 27, 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass3(sf::Vector2f(j * 27 + 9 * (WIDTH / 15) - 27, 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass4(sf::Vector2f(j * 27 + 12 * (WIDTH / 15) - 27, 6 * (HEIGHT / 9)), "Astroide.png");
				AsteroidArray[0 + j][0] = ass1;
				AsteroidArray[0 + j][1] = ass2;
				AsteroidArray[0 + j][2] = ass3;
				AsteroidArray[0 + j][3] = ass4;
			}
		}
		if (i >= 3 && i < 6)
		{
			for (int j = 0; j < 3; j++)
			{
				Asteroid ass1(sf::Vector2f(j * 27 + 3 * (WIDTH / 15) - 27, 27 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass2(sf::Vector2f(j * 27 + 6 * (WIDTH / 15) - 27, 27 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass3(sf::Vector2f(j * 27 + 9 * (WIDTH / 15) - 27, 27 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass4(sf::Vector2f(j * 27 + 12 * (WIDTH / 15) - 27, 27 + 6 * (HEIGHT / 9)), "Astroide.png");
				AsteroidArray[3 + j][0] = ass1;
				AsteroidArray[3 + j][1] = ass2;
				AsteroidArray[3 + j][2] = ass3;
				AsteroidArray[3 + j][3] = ass4;
			}
		}
		if (i >= 6 && i < 9)
		{
			for (int j = 0; j < 3; j++)
			{
				Asteroid ass1(sf::Vector2f(j * 27 + 3 * (WIDTH / 15) - 27, 54 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass2(sf::Vector2f(j * 27 + 6 * (WIDTH / 15) - 27, 54 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass3(sf::Vector2f(j * 27 + 9 * (WIDTH / 15) - 27, 54 + 6 * (HEIGHT / 9)), "Astroide.png");
				Asteroid ass4(sf::Vector2f(j * 27 + 12 * (WIDTH / 15) - 27, 54 + 6 * (HEIGHT / 9)), "Astroide.png");
				AsteroidArray[6 + j][0] = ass1;
				AsteroidArray[6 + j][1] = ass2;
				AsteroidArray[6 + j][2] = ass3;
				AsteroidArray[6 + j][3] = ass4;
			}
		}
	}

	//Creating the main alien cluster and setting their locations
	Aliens aliens[3][10];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0)
			{
				Aliens alien(sf::Vector2f(0, 0), alienSpeed, "Enemy.png");
				alienPos.x = j * 70 + 50;
				alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
				alien.setLocation(alienPos);
				aliens[i][j] = alien;
			}
			if (i == 1)
			{
				Aliens alien(sf::Vector2f(0, 0), alienSpeed, "enemy2.png");
				alienPos.x = j * 70 + 50;
				alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
				alien.setLocation(alienPos);
				aliens[i][j] = alien;
			}
			if (i == 2)
			{
				Aliens alien(sf::Vector2f(0, 0), alienSpeed, "Enemy.png");
				alienPos.x = j * 70 + 50;
				alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
				alien.setLocation(alienPos);
				aliens[i][j] = alien;
			}
		}
	}

	//creating main clock for FPS
	sf::Clock clock;

	//creating clock for Alien movement 
	sf::Clock alienClock;
	alienClock.restart().asSeconds();

	//creating clock for boss movement
	sf::Clock bossClock;
	bossClock.restart().asSeconds();
	//creating clock for boss bullet
	sf::Clock bossBullClk;
	bossBullClk.restart().asSeconds();

	//creating clocks for both bullets
	sf::Clock bulletClock;
	bulletClock.restart().asSeconds();

	sf::Clock alienBulletClock;
	alienBulletClock.restart().asSeconds();

	//Opening game loop
	while (window.isOpen())
	{
		//restarts the main clock
		float deltaTime = clock.restart().asSeconds();

		//Polling for event in the game
		sf::Event event;
		while (window.pollEvent(event))
		{
			// close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			//Restart The game
			if ((event.type == sf::Event::MouseButtonPressed && gameOver))
			{
				if (gameOver)
				{
					gameOver = false;
					winner = false;
					clock.restart();
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (i == 0)
							{
								Aliens alien(sf::Vector2f(0, 0), alienSpeed, "Enemy.png");
								alienPos.x = j * 70 + 50;
								alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
								alien.setLocation(alienPos);
								aliens[i][j] = alien;
							}
							if (i == 1)
							{
								Aliens alien(sf::Vector2f(0, 0), alienSpeed, "enemy2.png");
								alienPos.x = j * 70 + 50;
								alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
								alien.setLocation(alienPos);
								aliens[i][j] = alien;
							}
							if (i == 2)
							{
								Aliens alien(sf::Vector2f(0, 0), alienSpeed, "Enemy.png");
								alienPos.x = j * 70 + 50;
								alienPos.y = (alien.getSprite().getGlobalBounds().height / 2) + i * 70;
								alien.setLocation(alienPos);
								aliens[i][j] = alien;
							}
							moveCount = 0;
						}
					}
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							AsteroidArray[i][j].respawn();
						}
					}
					Boss.setLocation(sf::Vector2f(WIDTH / 2 - Boss.getSprite().getGlobalBounds().width / 2, HEIGHT / 4 - Boss.getSprite().getGlobalBounds().height / 2));
					Boss.setLives(bossLife);
					once = false;
					Boss.kill();
					expl.kill();

					eagleOne.setLocation(shipPos);
					eagleOne.setLives(playerLife);
					eagleOne.respawn();

					music.playBackgroundMusic();
				}
			}
			//Shooting Bullets
			/*
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if (!bullet.getIsAlive() && !gameOver)
				{
					bullet.respawn();
					bullet.setLocation(sf::Vector2f(eagleOne.getSprite().getPosition().x + 40, eagleOne.getSprite().getPosition().y - 15));
					music.playLazer();
				}
			}
			*/
			//Close game
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		//clear window and draw background
		window.clear(sf::Color(0, 0, 0, 255));
		window.draw(back);

		//check for ship movement with keyboard entries
		/*
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			if (eagleOne.getSprite().getPosition().x + eagleOne.getSprite().getGlobalBounds().width < WIDTH)
			{
				eagleOne.getSprite().move(shipspeed.x*deltaTime, 0.f);
			}
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
		{
			if (eagleOne.getSprite().getPosition().x > 0.f)
			{
				eagleOne.getSprite().move(-shipspeed.x*deltaTime, 0.f);
			}
		}
		*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (eagleOne.getSprite().getPosition().x + eagleOne.getSprite().getGlobalBounds().width < WIDTH)
			{
				eagleOne.getSprite().move(shipspeed.x*deltaTime, 0.f);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (eagleOne.getSprite().getPosition().x > 0.f)
			{
				eagleOne.getSprite().move(-shipspeed.x*deltaTime, 0.f);
			}
		}
		//Shooting Bullets
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!bullet.getIsAlive() && !gameOver)
			{
				bullet.respawn();
				bullet.setLocation(sf::Vector2f(eagleOne.getSprite().getPosition().x + 40, eagleOne.getSprite().getPosition().y - 15));
				music.playLazer();
			}
		}
		//Boss Movement
		sf::Time b = bossClock.getElapsedTime();
		if (b.asSeconds() > 0.5)
		{
			Boss.getSprite().move(0, 0);
		}
		//Alien Movement
		float movex = 5.f;
		sf::Time t = alienClock.getElapsedTime();
		if (t.asSeconds() > 0.5)
		{
			if (moveCount < 5)
			{
				//std::cout << "move under 5" << std::endl;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						aliens[i][j].getSprite().move(movex, 0.f);
					}
				}
			}
			else if (moveCount >= 5 && moveCount < 10)
			{
				//std::cout << "Move over 5 and under 10" << std::endl;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						aliens[i][j].getSprite().move(0.f, movex);
					}
				}
			}
			else if (moveCount >= 10 && moveCount < 15)
			{
				//std::cout << "Move over 10 and under 15" << std::endl;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						aliens[i][j].getSprite().move(-movex, 0.f);
					}
				}
			}
			else if (moveCount >= 15 && moveCount < 20)
			{
				//std::cout << "Move over 15 and under 20" << std::endl;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						aliens[i][j].getSprite().move(0.f, movex);
					}
				}
			}
			if (moveCount >= 20)
			{
				moveCount = 0;
			}
			moveCount++;
			alienClock.restart();
		}
		//BOSS movement
		sf::Time a = bossClock.getElapsedTime();
		if (a.asSeconds() > 0.5 && Boss.getIsAlive())
		{
			if (bossMoveCount <60)
			{
				Boss.getSprite().move(movex, 0);
				//std::cout << "Boss moves right" << std::endl;
			}
			else if (bossMoveCount >= 60 && bossMoveCount < 180)
			{
				//std::cout << "Boss moves left" << std::endl;
				Boss.getSprite().move(-movex, 0);
			}
			else if(bossMoveCount >= 180 && bossMoveCount < 240)
			{
				//std::cout << "Boss moves right" << std::endl;
				Boss.getSprite().move(movex, 0);
			}
			if (bossMoveCount > 240)
			{
				bossMoveCount = 0;
			}
			bossMoveCount++;
			bossClock.restart();
		}
		//enemy bullet placement and spawn
		sf::Time abc = alienBulletClock.getElapsedTime();
		if (abc.asSeconds() > 1)
		{
			int shooter = rand() % 3;
			int row = rand() % 10;
			if (!alienBullet.getIsAlive() && !gameOver && aliens[shooter][row].getIsAlive())
			{
				alienBullet.respawn();
				alienBullet.setLocation(sf::Vector2f(aliens[shooter][row].getSprite().getPosition().x + 30, aliens[shooter][row].getSprite().getPosition().y + 10));
				music.playLazer();
				alienBulletClock.restart();
			}
		}
		//boss Bullet placement and spawn
		sf::Time bbc = bossBullClk.getElapsedTime();
		if (bbc.asSeconds() > 0.5)
		{
			if (!bossBullL.getIsAlive() && !gameOver && Boss.getIsAlive())
			{
				bossBullL.respawn();
				float x = Boss.getSprite().getPosition().x + (Boss.getSprite().getGlobalBounds().width/4) - 7;
				float y = Boss.getSprite().getPosition().y + (Boss.getSprite().getGlobalBounds().height/2) + 17;
				bossBullL.setLocation(sf::Vector2f(x,y));
				music.playLazer();
			}
			if (!bossBullR.getIsAlive() && !gameOver && Boss.getIsAlive())
			{
				bossBullR.respawn();
				float x = Boss.getSprite().getPosition().x + (3*Boss.getSprite().getGlobalBounds().width / 4) + 4 ;
				float y = Boss.getSprite().getPosition().y + (Boss.getSprite().getGlobalBounds().height / 2) + 17;
				bossBullR.setLocation(sf::Vector2f(x,y));
				music.playLazer();
				bossBullClk.restart();
			}
		}
		//Bullet movement
		sf::Time bc = bulletClock.getElapsedTime();
		if (bc.asSeconds() > 1.0)
		{
			if (bossBullL.getIsAlive())
			{
				bossBullL.draw(window);
				bossBullL.getSprite().move(0.f, 5);
			}
			if (bossBullR.getIsAlive())
			{
				bossBullR.draw(window);
				bossBullR.getSprite().move(0.f, 5);
			}
			if (alienBullet.getIsAlive() && !gameOver)
			{
				alienBullet.draw(window);
				alienBullet.getSprite().move(0.f, 10);
			}
			if (bullet.getIsAlive() && !gameOver)
			{
				bullet.draw(window);
				bullet.getSprite().move(0.f, -20);
			}
		}
		//check collision between friendly bullet and aliens
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (aliens[i][j].doesCollide(&bullet) && aliens[i][j].getIsAlive() && bullet.getIsAlive())
				{
					if (!gameOver)
					{ 
						music.playExplosion();
					}
					aliens[i][j].collide(&bullet);
					expl.setPosition(sf::Vector2f(aliens[i][j].getSprite().getPosition().x, aliens[i][j].getSprite().getPosition().y));
					expl.spawn();
				}
			}
		}
		//check collision between bullet and boss
		if (Boss.doesCollide(&bullet) && bullet.getIsAlive() && Boss.getIsAlive())
		{
			Boss.collide(&bullet);
			expl.setPosition(sf::Vector2f(Boss.getSprite().getPosition().x + Boss.getSprite().getGlobalBounds().width / 2, Boss.getSprite().getPosition().y + Boss.getSprite().getGlobalBounds().height/2));
			expl.spawn();
			music.playExplosion();
		}
		//check collision between aliens and asteroids
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 10; l++)
					{
						if (AsteroidArray[i][j].doesCollide(&aliens[k][l]) && AsteroidArray[i][j].getIsAlive() && aliens[k][l].getIsAlive())
						{
							AsteroidArray[i][j].kill();
							if (!gameOver)
							{
								music.playExplosion();
							}
						}
					}
				}
			}
		}
		//Check collision between bullets and asteroids
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (AsteroidArray[i][j].doesCollide(&bullet) && AsteroidArray[i][j].getIsAlive() && bullet.getIsAlive())
				{
					music.playExplosion();
					bullet.kill();
				}
				if (AsteroidArray[i][j].doesCollide(&alienBullet) && AsteroidArray[i][j].getIsAlive() && alienBullet.getIsAlive())
				{
					music.playExplosion();
					AsteroidArray[i][j].collide(&alienBullet);
				}
				if (AsteroidArray[i][j].doesCollide(&bossBullL) && AsteroidArray[i][j].getIsAlive() && bossBullL.getIsAlive())
				{
					music.playExplosion();
					AsteroidArray[i][j].collide(&bossBullL);
				}
				if (AsteroidArray[i][j].doesCollide(&bossBullR) && AsteroidArray[i][j].getIsAlive() && bossBullR.getIsAlive())
				{
					music.playExplosion();
					AsteroidArray[i][j].collide(&bossBullR);
				}
			}
		}
		//check for collision between alienbullets and spaceship
		if (eagleOne.doesCollide(&alienBullet) && alienBullet.getIsAlive())
		{
			eagleOne.collide(&alienBullet);
			expl.setPosition(sf::Vector2f(eagleOne.getSprite().getPosition().x, eagleOne.getSprite().getPosition().y - eagleOne.getSprite().getGlobalBounds().height/2));
			expl.spawn();
			music.playExplosion();
		}
		if (eagleOne.doesCollide(&bossBullL) && bossBullL.getIsAlive())
		{
			eagleOne.collide(&bossBullL);
			expl.setPosition(sf::Vector2f(eagleOne.getSprite().getPosition().x, eagleOne.getSprite().getPosition().y - eagleOne.getSprite().getGlobalBounds().height / 2));
			expl.spawn();
			music.playExplosion();
		}
		if (eagleOne.doesCollide(&bossBullR) && bossBullR.getIsAlive())
		{
			eagleOne.collide(&bossBullR);
			expl.setPosition(sf::Vector2f(eagleOne.getSprite().getPosition().x, eagleOne.getSprite().getPosition().y - eagleOne.getSprite().getGlobalBounds().height / 2));
			expl.spawn();
			music.playExplosion();
		}
		//check for loss
		if (!eagleOne.getIsAlive())
		{
			if (!gameOver)
			{
				music.playFail();
			}
			bossBullL.kill();
			bossBullR.kill();
			alienBullet.kill();
			winner = false;
			gameOver = true;
		}
		//check for victory
		int deadAliens = 0; ///sett null for vanlig
	    for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (!aliens[i][j].getIsAlive())
				{
					deadAliens++;
				}
			}
		}
		if (deadAliens == 30 && once == false)
		{
			Boss.respawn();
			Boss.setLives(bossLife);
			once = true;
		}
		if (!Boss.getIsAlive() && deadAliens == 30)
		{
			if (!gameOver)
			{
				music.playReward();
			}
			alienBullet.kill();
			winner = true;
			gameOver = true;
		}
		//check for collision between alien and border/ship
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (aliens[i][j].getIsAlive() && (aliens[i][j].getSprite().getPosition().y + 60 > HEIGHT))
				{
					eagleOne.kill();
					if (!gameOver)
					{
						music.playExplosion();
					}
				}
				if (aliens[i][j].getIsAlive() && eagleOne.doesCollide(&aliens[i][j]))
				{
					eagleOne.kill();
					if (!gameOver)
					{
						music.playExplosion();
					}
				}
			}
		}
		//check collision between boss and player
		if (eagleOne.doesCollide(&Boss))
		{
			eagleOne.kill();
			if (!gameOver)
			{
				music.playExplosion();
			}
		}
		//kill bullets if they are out of bounds
		if (bullet.getSprite().getPosition().y < 0)
		{
			bullet.kill();
		}
		if (alienBullet.getSprite().getPosition().y > HEIGHT)
		{
			alienBullet.kill();
		}
		if (bossBullL.getSprite().getPosition().y > HEIGHT)
		{
			bossBullL.kill();
		}
		if (bossBullR.getSprite().getPosition().y > HEIGHT)
		{
			bossBullR.kill();
		}
		std::stringstream ss;
		std::stringstream st;
		ss << eagleOne.getLives();
		shipLife.setString("Player Life:" + ss.str());
		st << Boss.getLives();
		bssLife.setString("Boss Life:" + st.str());
		//Draw player, aliens and asteroids on the window while game isnt over.
		//if the game is over the win/lose screen is displayed.
		if (!gameOver)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (aliens[j][i].getIsAlive())
					{
						aliens[j][i].draw(window);
					}
				}
			}
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (AsteroidArray[i][j].getIsAlive())
					{
						AsteroidArray[i][j].draw(window);
					}
				}
			}
			if (Boss.getIsAlive())
			{
				Boss.draw(window);
				window.draw(bssLife);
			}
			if (eagleOne.getIsAlive())
			{
				eagleOne.draw(window);
			}
			if (expl.getIsAlive())
			{

				expl.animate(window, m, n);
				n++;
				if (n == 4)
				{
					m++;
					n = 0;
				}
				if (m == 4)
				{
					m = 0;
					n = 0;
					expl.kill();
				}
			}
			window.draw(shipLife);
			window.display();
		}
		else
		{
			music.pauseBackgroundMusic();
			if (alienBullet.getIsAlive())
				alienBullet.kill();
			if (bullet.getIsAlive())
				bullet.kill();
			if (bossBullL.getIsAlive())
				bossBullL.kill();
			if (bossBullR.getIsAlive())
				bossBullR.kill();
			if (winner)
			{
				win.draw(window);
			}
			else
			{
				lose.draw(window);
			}
			window.display();
		}
	}
	return EXIT_SUCCESS;
}