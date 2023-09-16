#include "../includes/Bank.hpp"
#include <vector>

class Program
{
	private:
		char id;
	public:
		vector<Bank> listofBank;
		Program(char id);
		void addBank(Bank bank);
		Bank getBank(char id);
		char getId();
		void sedId(char id);
		
};
