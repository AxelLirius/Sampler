#include "../includes/MidiDevice.hpp"


MidiDevice::MidiDevice()
{
	this->midiin = new RtMidiIn();
	this->midiout = new RtMidiOut();
	this->midiin->openPort(1);
	this->midiout->openPort(1);
}

void MidiDevice::addProgram(Program program)
{
	this->listofProgram.push_back(program);
}

string MidiDevice::getModel()
{
	return this->Model;
}

void MidiDevice::setModel(string Model)
{
	this->Model = Model;
}

Program MidiDevice::getProgram(char id)
{
	for(int y = 0; y < this->listofProgram.size(); y++)
	{
		if(this->listofProgram.at(y).getId() == id)
		{
			return this->listofProgram.at(y);
		}
	}
	return listofProgram.at(0);
}

