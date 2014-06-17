#include<stdio.h>


struct monthlyRate{
	int month;
	double credit;
	double interest;
	double redemption;
};

double fixCosts = 1.5;

double getCreditGross(int value){
	return value / (1 - (fixCosts / 100));
}

double getInterest(double credit, double interest){
	return ((interest / 100) / 12) * credit;
}

double getRedemption(double credit, double redemption){
	return ((redemption / 100) / 12) * credit;
}

