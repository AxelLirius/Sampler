#include "../includes/AkaiMPD218.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
AkaiMPD218 :: AkaiMPD218()
 :MidiDevice()
 {}

void AkaiMPD218::populate()
{
		
		for(int i = 0; i<16; i++)
		{
			Program program(i);
			this->listofProgram.push_back(program);
		}
		vector<char> PadConfiguration;
		char lecture;
		int program = 0;
		Bank bankA('A');
		Bank bankB('B');
		Bank bankC('C');
		ifstream fichier;
		fichier.open("./conf/Configuration.txt");
		if(fichier.is_open() == true )
		{
			while(!fichier.eof())
			{
				fichier.get(lecture);
				//cout << lecture << endl;
				if(lecture != ' ' and lecture != '\n')
				{
					PadConfiguration.push_back(lecture);
					cout << lecture << endl;
				}
				else if(lecture == '\n')
				{
					cout << program << PadConfiguration.size() << PadConfiguration[0] << PadConfiguration[1] << PadConfiguration[2] << PadConfiguration[3] << PadConfiguration[4] << PadConfiguration[5] << endl;
					if((PadConfiguration.size() == 6) and (PadConfiguration.at(2) == 'A' or PadConfiguration.at(2) == 'B' or  PadConfiguration.at(2) == 'C'))
					{	
						
						string strprogram;
						strprogram.push_back(PadConfiguration.at(0));
						strprogram.push_back(PadConfiguration.at(1));
						cout << strprogram << program << endl;
						
						if(stoi(strprogram) != program)
						{
							this->listofProgram.at(program-1).listofBank.clear();
							this->listofProgram.at(program-1).listofBank.push_back(bankA);
							this->listofProgram.at(program-1).listofBank.push_back(bankB);
							this->listofProgram.at(program-1).listofBank.push_back(bankC);
							program = stoi(strprogram);
							bankA.listofPad.clear();
							bankB.listofPad.clear();
							bankC.listofPad.clear();
						}
						if(PadConfiguration.at(2) == 'A')
						{
							cout << "c'est validé" << ((int)(PadConfiguration.at(3) - '0')) - 1 << (int)(PadConfiguration.at(4) - '0') << (int)(PadConfiguration.at(3) - '0') - 1;
							Pad pad("./sounds/Program" + to_string(program) + "/BankA" +"/pad" + to_string(((int)(PadConfiguration.at(3) - '0')) - 1) + ".wav", (int)(PadConfiguration.at(4) - '0'), (int)(PadConfiguration.at(3) - '0') - 1);
							bankA.addPad(pad);
						}
						else if(PadConfiguration.at(2) == 'B')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankB" +"/pad" + to_string(((int)(PadConfiguration.at(3) - '0')) + 15) + ".wav", (int)(PadConfiguration.at(4) - '0'), (int)(PadConfiguration.at(3) - '0') - 1 );
							bankB.addPad(pad);
						}
						else if(PadConfiguration.at(2) == 'C')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankC" +"/pad" + to_string(((int)(PadConfiguration.at(3) - '0')) + 31) + ".wav", (int)(PadConfiguration.at(4) - '0'), (int)(PadConfiguration.at(3) - '0') - 1);
							bankC.addPad(pad);
						}

					}
					else if((PadConfiguration.size() == 6) and  (PadConfiguration.at(2) != 'A' or PadConfiguration.at(2) != 'B' or  PadConfiguration.at(2) != 'C'))
					{
						string strpad;
						strpad.push_back(PadConfiguration.at(2));
						strpad.push_back(PadConfiguration.at(3));
						if(PadConfiguration.at(1) == 'A')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankA" +"/pad" + to_string(stoi(strpad) - 1) + ".wav", (int)(PadConfiguration.at(4) - '0'), stoi(strpad) - 1);
							bankA.addPad(pad);
						}
						else if(PadConfiguration.at(1) == 'B')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankB" +"/pad" + to_string(stoi(strpad) + 15) + ".wav", (int)(PadConfiguration.at(4) - '0'), stoi(strpad) - 1);
							bankB.addPad(pad);
						}
						else if(PadConfiguration.at(1) == 'C')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankC" +"/pad" + to_string(stoi(strpad) + 31) + ".wav", (int)(PadConfiguration.at(4) - '0'), stoi(strpad) - 1);
							bankC.addPad(pad);
						}
					}
					else if(PadConfiguration.size() == 7)
					{
						string strpad;
						strpad.push_back(PadConfiguration.at(3));
						strpad.push_back(PadConfiguration.at(4));
						if(PadConfiguration.at(2) == 'A')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankA" +"/pad" + to_string(stoi(strpad) - 1) + ".wav", (int)(PadConfiguration.at(5) - '0'), stoi(strpad) - 1);
							bankA.addPad(pad);
						}
						else if(PadConfiguration.at(2) == 'B')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankB" +"/pad" + to_string(stoi(strpad) + 15) + ".wav", (int)(PadConfiguration.at(5) - '0'), stoi(strpad) - 1);
							bankB.addPad(pad);
						}
						else if(PadConfiguration.at(2) == 'C')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankC" +"/pad" + to_string(stoi(strpad) + 31) + ".wav", (int)(PadConfiguration.at(5) - '0'), stoi(strpad) - 1);
							bankC.addPad(pad);
						}
					}
					else if(PadConfiguration.size() == 5)
					{
						if((int)(PadConfiguration.at(0) - '0') != program)
						{
							cout << (int)(PadConfiguration.at(0) - '0') << program << endl;
							if(program != 0)
							{
								this->listofProgram.at(program-1).listofBank.clear();
								this->listofProgram.at(program-1).listofBank.push_back(bankA);
								this->listofProgram.at(program-1).listofBank.push_back(bankB);
								this->listofProgram.at(program-1).listofBank.push_back(bankC);
							}
							program = (int)(PadConfiguration.at(0) - '0');		
							bankA.listofPad.clear();
							bankB.listofPad.clear();
							bankC.listofPad.clear();
						}
						if(PadConfiguration.at(1) == 'A')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankA" +"/pad" + to_string(((int)(PadConfiguration.at(2) - '0'))- 1) + ".wav", (int)(PadConfiguration.at(3) - '0'), (int)(PadConfiguration.at(2) - '0') - 1);
							bankA.addPad(pad);
						}
						else if(PadConfiguration.at(1) == 'B')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankB" +"/pad" + to_string(((int)(PadConfiguration.at(2) - '0')) + 15) + ".wav", (int)(PadConfiguration.at(3) - '0'), (int)(PadConfiguration.at(2) - '0') - 1 );
							bankB.addPad(pad);
						}
						else if(PadConfiguration.at(1) == 'C')
						{
							Pad pad("./sounds/Program" + to_string(program) + "/BankC" +"/pad" + to_string(((int)(PadConfiguration.at(2) - '0')) + 32) + ".wav", (int)(PadConfiguration.at(3) - '0'), (int)(PadConfiguration.at(2) - '0') - 1);
							bankC.addPad(pad);
						}
						
					}
					PadConfiguration.clear();
				}
			}
			this->listofProgram.at(program-1).listofBank.clear();
			this->listofProgram.at(program-1).listofBank.push_back(bankA);
			this->listofProgram.at(program-1).listofBank.push_back(bankB);
			this->listofProgram.at(program-1).listofBank.push_back(bankC);
			for(int i = 0; i< 16; i++)
			{
				cout << listofProgram.at(i).listofBank.size() << endl;
				cout << listofProgram.at(i).listofBank.at(0).listofPad.at(0).getSound() << endl;
			}
			fichier.close();
		}
}

void AkaiMPD218::start()
{
	bool Loop = false;
	std::vector<unsigned char> bankloop;
	std::vector<unsigned char> messageout;
	std::vector<int> padTouchLoop;
	std::vector<int> poiLoop;
	Program program(2);
	Program programLoop(2);
	int nBytes, i;
	int bitze = 0;
	double stamp = 0;
	unsigned char pad;
	unsigned char velocite;
	int Loopretrro = 0;
	int volume = 100;
	int savevolume;
	unsigned char canal;
	Pad padLoop("", false, 6 );
	system("amixer -D pulse sset Master 100%");
	while (1) {
		if(Loop == true)
		{
			if(messageout.size() >0 and Loopretrro < 150)
			{
				midiout->sendMessage(&messageout);
				Loopretrro++;
			}
			if(this->listofProgram.at(poiLoop.at(0)).listofBank.at(bankloop.at(0) - 65).listofPad.at(padTouchLoop.at(0)).isReading() == false)
			{
				if(bankloop.size() > 1)
				{
					poiLoop.erase(poiLoop.begin());
					bankloop.erase(bankloop.begin());
					padTouchLoop.erase(padTouchLoop.begin());
					Loopretrro =0;
					messageout[0] = poiLoop.at(0) + 128;
					midiout->sendMessage(&messageout);
					if(bankloop.at(0) - 65 == 0)
					{
						messageout[0] = poiLoop.at(0) + 144;
						messageout[1] = padTouchLoop.at(0);
					}
					else if(bankloop.at(0) - 65 == 1)
					{
						messageout[0] = poiLoop.at(0) + 144;
						messageout[1] = padTouchLoop.at(0) + 16;
					}
					else if(bankloop.at(0) - 65 == 2)
					{
						messageout[0] = poiLoop.at(0) + 144;
						messageout[1] = padTouchLoop.at(0) + 31;
					}						
				}
				this->listofProgram.at(poiLoop.at(0)).listofBank.at(bankloop.at(0) - 65).listofPad.at(padTouchLoop.at(0)).play(volume);	 	
			}
		}
		std::vector<unsigned char> message;
		unsigned int nPorts = midiin->getPortCount();
		if(nPorts == 2)
		{
			system("pkill -f ./Sampler");
		}
		stamp = midiin->getMessage( &message );	
		if(message.size() > 0)
		{
			for ( i=0; i<message.size(); i++)
			{
				std::cout << "Byte " << i << " = " << (int)message[i] << ", ";
				if(i == 2)
				{
					cout << endl;
				}
			}
			canal = message[0];
			pad = message[1];
			velocite = message[2];
			for(int i = 142; i<= 160; i++)
			{
				if((int)canal == i and canal != 160 or canal == 176)
				{
					int poi = i - 144;
					if((int)pad <= 15)
					{
						if(this->listofProgram.at(poi).listofBank.at(0).listofPad.at(pad).Loop() == true and bankloop.size() != 0)
						{
								if(bankloop.at(0) == 'A' and pad == padTouchLoop.at(0))
								{
									Loop = false;
									this->listofProgram.at(poi).listofBank.at(0).listofPad.at(pad).stopLoop();
									messageout[0] = 128;
									midiout->sendMessage(&messageout);
									bankloop.clear();
									padTouchLoop.clear();
									poiLoop.clear();
									
								}
								else
								{
									if(bankloop.size() > 1)
									{
										bankloop.erase(bankloop.begin()+1);
										padTouchLoop.erase(padTouchLoop.begin()+1);
										poiLoop.erase(poiLoop.begin()+1);
									}
									bankloop.push_back('A');
									padTouchLoop.push_back((int)pad);
									poiLoop.push_back(poi);
									cout << "Boucle 2 remplacé" <<endl;
								}
						}
						else
						{
							if(this->listofProgram.at(poi).listofBank.at(0).listofPad.at(pad).Loop() == true)
							{
								
								Loop = true;
								bankloop.push_back('A');
								padTouchLoop.push_back((int)pad);
								poiLoop.push_back(poi);
								messageout = message;
								Loopretrro =0;
							}
							else
							{
								cout << "son normal joué" <<endl;
								this->listofProgram.at(poi).listofBank.at(0).listofPad.at(pad).play(volume);
							}
						}
					  }
					  else if((int)pad <= 31)
					  {
						if(this->listofProgram.at(poi).listofBank.at(1).listofPad.at(pad - 16).Loop() == true and bankloop.size() != 0)
						{
							cout << padTouchLoop.at(0) <<endl;
							if(bankloop.at(0) == 'B' and pad - 16 == padTouchLoop.at(0))
							{
								Loop = false;
								this->listofProgram.at(poi).listofBank.at(1).listofPad.at(pad - 16).stopLoop();
								messageout[0] = 128;
								midiout->sendMessage(&messageout);
								bankloop.clear();
								padTouchLoop.clear();
								poiLoop.clear();
								
							}
							else
							{
								if(bankloop.size() > 1)
								{
									bankloop.erase(bankloop.begin()+1);
									padTouchLoop.erase(padTouchLoop.begin()+1);
									poiLoop.erase(poiLoop.begin()+1);
								}
								bankloop.push_back('B');
								padTouchLoop.push_back((int)pad - 16);
								poiLoop.push_back(poi);
								cout << "Boucle 2 remplacé" <<endl;
							}
						}
						else
						{
							if(this->listofProgram.at(poi).listofBank.at(1).listofPad.at(pad - 16).Loop() == true)
							{
								cout << "Boucle normal joué" <<endl;
								Loop = true;
								bankloop.push_back('B');
								padTouchLoop.push_back((int)pad - 16);
								poiLoop.push_back(poi);
								messageout = message;
								Loopretrro =0;
							}
							else
							{
								cout << "son normal joué" <<endl;
								this->listofProgram.at(poi).listofBank.at(1).listofPad.at(pad - 16).play(volume);
							}
						}
					  }
					  else if((int)pad <= 47)
					  {
						if(this->listofProgram.at(poi).listofBank.at(2).listofPad.at(pad - 32).Loop() == true and bankloop.size() != 0)
						{
								if(bankloop.at(0) == 'C' and pad - 32 == padTouchLoop.at(0))
								{
									Loop = false;
									this->listofProgram.at(poi).listofBank.at(2).listofPad.at(pad - 32).stopLoop();
									messageout[0] = 128;
									midiout->sendMessage(&messageout);
									bankloop.clear();
									padTouchLoop.clear();
									poiLoop.clear();
									
								}
								else
								{
									if(bankloop.size() > 1)
									{
										bankloop.erase(bankloop.begin()+1);
										padTouchLoop.erase(padTouchLoop.begin()+1);
										poiLoop.erase(poiLoop.begin()+1);
									}
									bankloop.push_back('C');
									padTouchLoop.push_back((int)pad - 32);
									poiLoop.push_back(poi);
									cout << "Boucle 2 remplacé" <<endl;
								}
						}
						else
						{
							if(this->listofProgram.at(poi).listofBank.at(2).listofPad.at(pad - 32).Loop() == true)
							{
								
								Loop = true;
								bankloop.push_back('C');
								padTouchLoop.push_back((int)pad - 32);
								poiLoop.push_back(poi);
								messageout = message;
								Loopretrro =0;
							}
							else
							{
								cout << "son normal joué" <<endl;
								this->listofProgram.at(poi).listofBank.at(2).listofPad.at(pad - 32).play(volume);
							}
						}
					}
					  else if((int)pad == 51)
					  {
					    savevolume = volume;
						volume = velocite;
						if(volume%10 == 0 and savevolume > volume)
						{
							system("amixer -D pulse sset Master 15%-");
						}
						else if(volume%10 == 0 and savevolume < volume)
						{
							system("amixer -D pulse sset Master 15%+");
						}
					  } 
				}
			}
		}
	
	}
}






