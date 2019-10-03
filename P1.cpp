#include <iostream>

using namespace std;

int main() {
	int i;	//counter
	int choice;
	void determineSymptoms();
	void analizeSymptoms();
	

	char condVar[10][10];
	char varList[10][10];
	char clauseVList[50][3];

do{
	cout << " Hi, welcome to our automibile diagnosis program! \n";
	cout << " How may we help you today? \n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "My car needs to be diagnosed";
			determineSymptoms();
			break;
		case 2:
			cout << "Summary of previous diagnostics";
				analizeSymptoms();
			break;
		case 3:
			cout << "3) EXIT \n";
			break;
	}
	}while(choice !=NULL);
	return 0;
}

//Backward chaining
void determineSymptoms() {
	int noStart, stalls, heats, noMove, squeal, choice;
do{
	cout << "From the menu, please enter the number that highlights your problem: \n ";
	cin >> choice;
	switch(choice)
	{
		case 1:
			cout << "1) Car wont start\n";
			analizeSymptoms(noStart);
			break;
		case 2:
			cout << "2) Car Stalls\n";
			analizeSymptoms(stalls);
			break;
		case 3:
			cout << "3) Car is heating up\n";
			analizeSymptoms(heats);
			break;
		case 4:
			cout << "4) Car wont move\n";
			analizeSymptoms(noMove);
			break;
		case 5:
			cout << "5) Breaks Squeal \n";
			analizeSymptoms(squeal);
			break;
	}
}while (choice!=NULL);

}
//Forward chaining function
void analizeSymptoms(int ) {
	//do stuff
}