
#include "../includes/Bank.hpp"

Bank::Bank(char id)
{
	this->id = id;;
}

Bank::Bank()
{
}

void Bank::addPad(Pad pad)
{
	this->listofPad.push_back(pad);
}

char Bank::getId()
{
	return this->id;
}

Pad Bank::getPad(int number)
{
	Pad pad("ERROR",false,0);
	for(int i = 0; i < listofPad.size(); i++)
	{
		if(this->listofPad.at(i).getNumber() == number)
		{
			return this->listofPad.at(i);
		}
	}
	return pad;
}

int Bank::getSize()
{
	return this->listofPad.size();
}


void Bank::sedId(char id)
{
	this->id = id;
}

