#include<stdio.h>
#include "Header.h"


void computeInterest(double value, double interest, double redemption, int period){
	double creditGross = getCreditGross(value);

	double firstRedemption = getRedemption(creditGross, redemption);
	double firstInterest = getInterest(creditGross, interest);
	double monthlyRate = firstInterest + firstRedemption;
	
	printf("\nEs wurde eine monatliche Rate von %lf EURO berechnet.", monthlyRate);

	struct monthlyRate rates[1024];

	for (int i = 0; i < period; i++){

		//getMonthlyRate(rates[i], creditGross, interest, redemption);
		rates[i].month = i + 1;
		rates[i].interest = getInterest(creditGross, interest);
		rates[i].redemption = monthlyRate - rates[i].interest;

		if (i == 0 || (i + 1) % 12 == 0){
			printf("\n---------------------------------------");
			printf("\nBerechnung fuer den %d. Monat:", rates[i].month);
			printf("\nKredit am Monatsanfang: %lf", creditGross);
			printf("\nZinslast fuer diesen Monat: %lf", rates[i].interest);
			printf("\nTilgung in diesem Monat: %lf", rates[i].redemption);
		}
		creditGross = creditGross - rates[i].redemption; //+ tmpInterest;
		rates[i].credit = creditGross;
		
		if (creditGross <= 0)
			break;
	}
	printf("\n---------------------------------------\n");
	printf("\nRestkredit: %lf", creditGross);
}

int main(){
	printf("Zinsberechnung:\n");
	printf("---------------\n");
	int period = 0;
	double value, interest, redemption = 0.0;

	printf("\nKreditrahmen:");
	scanf_s("%lf", &value);
	printf("\nZinswert (p.a.):");
	scanf_s("%lf", &interest);
	printf("\nTilgung (p.a.):");
	scanf_s("%lf", &redemption);
	printf("\nLaufzeit in Monaten:");
	scanf_s("%d", &period);

	printf("\n");

	computeInterest(value, interest, redemption, period);

	getchar();
	printf("\nDruecken Sie Eingabe...");
	scanf_s("%c");
	return 0;
}

