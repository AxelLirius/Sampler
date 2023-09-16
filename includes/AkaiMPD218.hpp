#include "../includes/MidiDevice.hpp"


class AkaiMPD218 : private MidiDevice
{
	public:
		AkaiMPD218();
		void populate();
		void start();
};
