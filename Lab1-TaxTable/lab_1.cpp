#include<iostream>
#include<cstdio>
#include<iomanip>


using namespace std;

int main(){
	float first_price;
	float last_price;
	float stride;
	float tax_p;
	float tax;

	cout << "\nINPUT PART" << endl;
	cout << "===========" << endl;
	cout << setw(19) << left << "Enter first price " << ": ";
	do
	{
		cin >> first_price;
		if (first_price < 0)
			{
				cerr << "ERROR: First price must be at least 0 (zero) SEK\n";
				cout << setw(19) << left << "Enter first price " << ": ";
			}
	}while(first_price < 0);

	cout << setw(19) << left << "Enter last price  " << ": ";
	do
	{
		cin >> last_price;
		if ((last_price < 0) || (last_price < first_price))
			{
				cerr << "ERROR: Last price must be at least 0 (zero)";
				cerr << " SEK and higher or equal to the first price" << endl;
				cout << setw(19) << left << "Enter last price " << ": ";
			}
	}while((last_price < 0) || (last_price < first_price));

	cout << setw(19) << left << "Enter stride " << ": ";
	do
	{
		cin >> stride;
		if (stride <0.01)
			{
				cerr << "ERROR: Stride must be at least 0.01" << endl;
				cout << setw(19) << left << "Enter stride " << ": ";
			}
	}while(stride < 0.01);

	cout << setw(19) << left << "Enter tax percent " << ": ";
	do
	{
		cin >> tax_p;
		if ((tax_p < 0) || (tax_p > 100))
			{
				cerr << "ERROR: tax percent must be between 0 and 100" << endl;
				cout << setw(19) << left << "Enter tax percent " << ": ";
			}
	}while((tax_p < 0) || (tax_p > 100));
	cout << endl;

	cout << "TAX TABLE" << endl;
	cout << "===========" << endl;

	cout << "\tPrice \t\tTax \t\tPrice with tax" << endl;

	cout << "------------------------------------------------------" << endl;

	while(first_price <= last_price)
	{
		cout << "\t" << setprecision(2) << fixed << first_price;
		tax = (first_price * tax_p) / 100;
		cout << "\t\t" << setprecision(2) << fixed << tax;
		cout << "\t\t" << setprecision(2) << fixed << first_price + tax << endl;

		first_price = first_price + stride;

	}
}
