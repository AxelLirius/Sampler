
#include "../includes/Program.hpp"

Program::Program(char id)
{
	this->id = id;
	this->listofBank.resize(3);
}

void Program::addBank(Bank bank)
{
	this->listofBank.push_back(bank);
}

char Program::getId()
{
	return this->id;
}

Bank Program::getBank(char id)
{
	Bank bank('J');
	for(int i = 0; i < this->listofBank.size(); i++)
	{
		if(this->listofBank.at(i).getId() == id)
		{
			return this->listofBank.at(i);
		}
	}
	return bank;
}

void Program::sedId(char id)
{
	this->id = id;
}
