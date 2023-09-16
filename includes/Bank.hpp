#include "../includes/Pad.hpp"
#include <vector>

class Bank
{
	private:
		char id;
	public:
		vector<Pad> listofPad;
		Bank(char id);
		Bank();
		void addPad(Pad pad);
		Pad getPad(int number);
		char getId();
		void sedId(char id);
		int getSize();
		
};
