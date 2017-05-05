#include "Sound.h"

Sound::Sound()
{
	if (!lazerBuffer.loadFromFile("Blast.wav"))
		throw std::invalid_argument("Lazer sound not loaded!");
	if (!explosionBuffer.loadFromFile("Explosion.wav"))
		throw std::invalid_argument("Explosion sound not loaded!");
	if (!rewardBuffer.loadFromFile("Win.wav"))
		throw std::invalid_argument("Win sound not loaded!");
	if (!failBuffer.loadFromFile("Fail.wav"))
		throw std::invalid_argument("Fail sound not loaded!");
	if (!music.openFromFile("Background.wav"))
		throw std::invalid_argument("Music not loaded!");
}

void Sound::playBackgroundMusic()
{
	music.setVolume(50.0);
	music.setLoop(true);
	music.play();
}

void Sound::pauseBackgroundMusic()
{
	music.pause();
}

void Sound::playLazer()
{
	lazerSound.setBuffer(lazerBuffer);
	lazerSound.play();
}

void Sound::playExplosion()
{
	explosionSound.setBuffer(explosionBuffer);
	explosionSound.play();
}

void Sound::playReward()
{
	rewardSound.setBuffer(rewardBuffer);
	rewardSound.play();
}

void Sound::playFail()
{
	failSound.setBuffer(failBuffer);
	failSound.play();
}