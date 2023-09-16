#include <iostream>
#include <cstdlib>
#include <signal.h>
#include "../rtmidi/RtMidi.h"
#include <SFML/Audio.hpp>
#include "../srcs/AkaiMPD218.cpp"

bool done;

int main()
{
    AkaiMPD218* akaiMPD218 = new AkaiMPD218();
    akaiMPD218->populate();
    akaiMPD218->start();
}
