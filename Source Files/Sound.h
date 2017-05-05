#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>

class Sound
{
public:
	Sound();
	void playBackgroundMusic();
	void pauseBackgroundMusic();
	void playLazer();
	void playExplosion();
	void playReward();
	void playFail();
private:
	sf::SoundBuffer lazerBuffer;
	sf::SoundBuffer explosionBuffer;
	sf::SoundBuffer rewardBuffer;
	sf::SoundBuffer failBuffer;
	sf::Music music;
	sf::Sound lazerSound;
	sf::Sound explosionSound;
	sf::Sound rewardSound;
	sf::Sound failSound;
};
