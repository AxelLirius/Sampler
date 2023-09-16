#include "../includes/Sound.hpp"

SoundPath::SoundPath()
{
};


void SoundPath::setPath(string aPath)
{
	this->path = aPath;
}

string SoundPath::getPath()
{
	return this->path;
}
