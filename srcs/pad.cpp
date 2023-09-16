#include "../includes/Pad.hpp"

Pad::Pad(string Asound, bool isLoop, int number)
{
	this->sound.setPath(Asound);
	this->isLoop = isLoop;
	this->isInit = false;
	this->number = number;
	this->buffer.loadFromFile(this->sound.getPath());
}
void Pad::play(int volume)
{
	this->init();
	this->Music->setBuffer(buffer);
	cout << "Je suis jouée" << endl;
	cout << this->sound.getPath() << endl;
	//this->Music->setVolume((float)volume);
	this->Music->play();
}

void Pad::init()
{
	if(this->isInit == false)
	{
		this->Music = new sf::Sound();
		this->isInit = true;
    }
}

void Pad::stopLoop()
{
		cout << "Loop stopé" << endl;
		this->Music->stop();
}

bool Pad::isReading()
{
	if(this->isInit == false)
	{
		return false;
	}
	else
	{
		if(this->Music->getStatus() == 2)
		{
			return true;
		}
	}
	return false;
	//return this->test;
}

void Pad::setNumber(unsigned char isNumber)
{
	this->number = isNumber;
}

int Pad::getNumber()
{
	return this->number;
}

void Pad::setSound(string Asound)
{
	this->sound.setPath(Asound);
}

string Pad::getSound()
{
	return this->sound.getPath(); 
}

bool Pad::Loop()
{
	return this->isLoop;
}

void Pad::setVolume(int volume)
{
	this->Music->setVolume((float)volume);
}
