#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

// all current agents as of April 10th, 2022
string AGENTS[19] = { "Brimstone", "Viper", "Omen", "Killjoy", "Cypher", "Sova", "Sage", "Phoenix", "Jett", "Reyna", "Raze", "Breach", "Skye", "Yoru", "Astra", "KAY/O", "Chamber", "Neon", "Fade" };

// function to pick random agent
string generator();

int main() {
	int pickednum;
	bool haspicked = false;

	// needed for rng
	srand(time(0));

	// checks if the user input is a proper value
	while (haspicked == false) {
		cout << "How many players need to pick a character?" << endl;

		cin >> pickednum;
		if (cin.fail()) {
			cout << "That's not a number! Try again!" << endl;
			system("pause");
			pickednum = NULL;
		}
		else if (pickednum < 1 || pickednum > 5) {
			cout << "That's not within the range! Try again!" << endl;
			system("pause");
			pickednum = NULL;
		}
		else {
			haspicked = true;
		}

		cin.clear();
		cin.ignore(100000, '\n');
		system("cls");
	}

	int playernum = 1;

	//string vector to keep track of which agents have been picked
	vector<string> pickedagents;

	while (playernum <= pickednum) {
		bool unique = false;

		string selectedagent = generator();

		vector<string>::iterator it;

		while (unique == false) {
			// used for the first agent pick, it will always be unique
			if (pickedagents.size() == 0) {
				unique = true;
				pickedagents.push_back(selectedagent);
				//selectedagent = generator();
			}
			// is the selected agent already picked?
			else {
				if (find(pickedagents.begin(), pickedagents.end(), selectedagent) != pickedagents.end()) {
					selectedagent = generator();
				}
				else {
					unique = true;
					pickedagents.push_back(selectedagent);
				}
			}
		}

		cout << "Player " << playernum << ": " << selectedagent << endl;

		playernum++;
	}
	
	cout << "All players are picked! Good luck (You might need it...)" << endl;
	system("pause");

}

// simple rng that picks a number between 0 and the total agent count - 1, then returns the string value of the index value in the array at the top of the program
string generator() {
	int length = (sizeof(AGENTS) / sizeof(string)) - 1;
	int selected = rand() % length;

	return AGENTS[selected];
}