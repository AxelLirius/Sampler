#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <signal.h>
#include "../includes/Sound.hpp"

class Pad
{
	private:
		sf::Sound * Music;
	    sf::SoundBuffer buffer;
		SoundPath sound;
		int number;
		bool isLoop;
		bool isInit;
	public:
		Pad(string Asound, bool isLoop, int number);
		void play(int volume);
		void stopLoop();
		bool isReading();
		bool Loop();
		void init();
		void setNumber(unsigned char isNumber);
		int getNumber();
		void setSound(string Asound);
		void setVolume(int volume);
		string getSound();		
};
