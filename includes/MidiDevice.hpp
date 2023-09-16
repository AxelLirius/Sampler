#include "../rtmidi/RtMidi.h"
#include "../includes/Program.hpp"
#include <iostream>
#include <vector>

using namespace std;

class MidiDevice
{
	protected:
		RtMidiIn *midiin;
		RtMidiOut *midiout;
		string Model;
		vector<Program> listofProgram;
	public:
		MidiDevice();
		void addProgram(Program program);
		string getModel();
		void setModel(string Model);
		Program getProgram(char id);
		virtual void populate() = 0;
		virtual void start() = 0;	
};











