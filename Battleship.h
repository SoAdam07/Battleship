//Author: Adam So
//November 2020

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Computer.h"
#include "Player.h"
#include <iostream>
#include <ctime>
using namespace std;

class Battleship{
	public:
		void check_player_guess(int row, int col, int gameType);
		void check_computer_guess(int row, int col, int gameType);
		Battleship();
		bool get_status(int gameType);
		int getGameType();
		string getNamePlayer1();
		string getNamePlayer2();
		void playerDisplay_boards();
		void player2Display_boards();
		void check_player_ships();
		void check_computer_ships();
		void check_player2_ships();
		void check_computer2_ships();
	private:
		int gameMode = 0;
		Player player;
		Player player2;
		Computer computer;
		Computer computer2;
		bool status;  //if true => game on!, else if false => someone won!
};


Battleship::Battleship(){
	string n;
	n = "Computer";
	computer.setName(n);
	n = "Computer2";
	computer2.setName(n);
	char vector, cVectorChar;
	int xPos, yPos, compxPos, compyPos, cVectorInt;
	srand(time(0));
	cout << "Enter 1 for Player VS Computer" << endl;
	cout << "Enter 2 for Player VS Player" << endl << ": ";
	cin >> gameMode;
	while (gameMode != 1 and gameMode != 2 and gameMode != 3) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> gameMode;
	}
	if(gameMode == 1){
	cout << "Player, please enter your name: ";
	cin >> n;
	player.setName(n);
	player.initialize_ships();
	computer.initialize_ships();
	player.initialize_boards();
	computer.initialize_boards();
	cout << "It's time to place your boats!" << endl;
	cout << "You first select if you want to place the boat horizontally (H) or vertically (V)." << endl;
	cout << "Then you select the location. The board is a 10 x 10 grid." << endl;
	cout << "The topleft location of the board is (0, 0), and the bottom right location is (9, 9)." << endl;
	cout << "Depending on how you select your placement, you may not be able to place the boat in that position." << endl;
	cout << "If you place a boat vertically, it will start at the location you specify and go downward from there." << endl;
	cout << "Please choose carefully as you place your boats. Once you place a boat, it cannot be moved." << endl;
	cout << endl;
	cout << "Place your Aircraft Carrier (5).Type a direction vector and a starting location." << endl;
	cout << "For example: V 1 0 or H 4 5" << endl << ":";
	//****************************************Aircraftcarrier
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false) or (vector == 'H' && xPos >= 6) or (vector == 'V' && yPos >= 6)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 5; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'A');
		}
	} else {
		for (int counter = 0; counter < 5; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'A');
		}
	}
	//****************************************Battleship
	cout << "Place your Battleship (4). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
			or (vector == 'H' && (xPos >= 7 or player.check_player_placement(yPos, xPos, 'H', 4) == false))
			or (vector == 'V' && (yPos >= 7 or player.check_player_placement(yPos, xPos, 'V', 4) == false))){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 4; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'B');
		}
	} else {
		for (int counter = 0; counter < 4; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'B');
		}
	}
	//****************************************Submarine
	cout << "Place your Submarine (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'S');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'S');
		}
	}
	//****************************************Destroyer
	cout << "Place your Destroyer (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'D');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'D');
		}
	}
	//****************************************Patrolboat
	cout << "Place your Patrol Boat (2). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
					or (vector == 'H' && (xPos >= 9 or player.check_player_placement(yPos, xPos, 'H', 2) == false))
					or (vector == 'V' && (yPos >= 9 or player.check_player_placement(yPos, xPos, 'V', 2) == false))){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid User Input. Please try again." << endl << ":";
				cin >> vector >> xPos >> yPos;
			}
	if (vector == 'H') {
		for (int counter = 0; counter < 2; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'P');
		}
	} else {
		for (int counter = 0; counter < 2; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'P');
		}
	}
	//****************************************ComputerAircraftcarrier
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%6;
		break;
	case 'H':
		compxPos = rand()%6;
		compyPos = rand()%10;
		break;
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 5; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'A');
		}
	} else {
		for (int counter = 0; counter < 5; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'A');
		}
	}
	//****************************************ComputerBattleship
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%7;
		break;
	case 'H':
		compxPos = rand()%7;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 4) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%6;
			break;
		case 'H':
			compxPos = rand()%6;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 4; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'B');
		}
	} else {
		for (int counter = 0; counter < 4; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'B');
		}
	}
	//****************************************ComputerSubmarine
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%8;
		break;
	case 'H':
		compxPos = rand()%8;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 3; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'S');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'S');
		}
	}
	//****************************************ComputerDestroyer
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%8;
		break;
	case 'H':
		compxPos = rand()%8;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 3; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'D');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'D');
		}
	}
	//****************************************ComputerPatrolboat
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%9;
			break;
		case 'H':
			compxPos = rand()%9;
			compyPos = rand()%10;
			break;
		}
		while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 2) == false) {
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%9;
				break;
			case 'H':
				compxPos = rand()%9;
				compyPos = rand()%10;
				break;
			}
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 2; counter++, compxPos++) {
				computer.set_computer_board(compyPos, compxPos, 'P');
			}
		} else {
			for (int counter = 0; counter < 2; counter++, compyPos++) {
				computer.set_computer_board(compyPos, compxPos, 'P');
			}
		}
		player.display_boards();
		cout << "Boards and Ships initialized!" << endl;
		status = true;
}
if (gameMode == 2){
	cout << "Player1, please enter your name: ";
	cin >> n;
	player.setName(n);
	player.initialize_ships();
	player2.initialize_ships();
	player.initialize_boards();
	player2.initialize_boards();
	cout << "It's time to place your boats!" << endl;
	cout << "You first select if you want to place the boat horizontally (H) or vertically (V)." << endl;
	cout << "Then you select the location. The board is a 10 x 10 grid." << endl;
	cout << "The topleft location of the board is (0, 0), and the bottom right location is (9, 9)." << endl;
	cout << "Depending on how you select your placement, you may not be able to place the boat in that position." << endl;
	cout << "If you place a boat vertically, it will start at the location you specify and go downward from there." << endl;
	cout << "Please choose carefully as you place your boats. Once you place a boat, it cannot be moved." << endl;
	cout << endl;
	cout << "Place your Aircraft Carrier (5).Type a direction vector and a starting location." << endl;
	cout << "For example: V 1 0 or H 4 5" << endl << ":";
	//****************************************Aircraftcarrier
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false) or (vector == 'H' && xPos >= 6) or (vector == 'V' && yPos >= 6)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 5; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'A');
		}
	} else {
		for (int counter = 0; counter < 5; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'A');
		}
	}
	//****************************************Battleship
	cout << "Place your Battleship (4). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
			or (vector == 'H' && (xPos >= 7 or player.check_player_placement(yPos, xPos, 'H', 4) == false))
			or (vector == 'V' && (yPos >= 7 or player.check_player_placement(yPos, xPos, 'V', 4) == false))){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 4; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'B');
		}
	} else {
		for (int counter = 0; counter < 4; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'B');
		}
	}
	//****************************************Submarine
	cout << "Place your Submarine (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'S');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'S');
		}
	}
	//****************************************Destroyer
	cout << "Place your Destroyer (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'D');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'D');
		}
	}
	//****************************************Patrolboat
	cout << "Place your Patrol Boat (2). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player.check_player_input(vector, xPos, yPos) == false)
					or (vector == 'H' && (xPos >= 9 or player.check_player_placement(yPos, xPos, 'H', 2) == false))
					or (vector == 'V' && (yPos >= 9 or player.check_player_placement(yPos, xPos, 'V', 2) == false))){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid User Input. Please try again." << endl << ":";
				cin >> vector >> xPos >> yPos;
			}
	if (vector == 'H') {
		for (int counter = 0; counter < 2; counter++, xPos++) {
			player.set_player_board(yPos, xPos, 'P');
		}
	} else {
		for (int counter = 0; counter < 2; counter++, yPos++) {
			player.set_player_board(yPos, xPos, 'P');
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Player2, please enter your name: ";
	cin >> n;
	player2.setName(n);
	cout << "It's time to place your boats!" << endl;
	cout << "You first select if you want to place the boat horizontally (H) or vertically (V)." << endl;
	cout << "Then you select the location. The board is a 10 x 10 grid." << endl;
	cout << "The topleft location of the board is (0, 0), and the bottom right location is (9, 9)." << endl;
	cout << "Depending on how you select your placement, you may not be able to place the boat in that position." << endl;
	cout << "If you place a boat vertically, it will start at the location you specify and go downward from there." << endl;
	cout << "Please choose carefully as you place your boats. Once you place a boat, it cannot be moved." << endl;
	cout << endl;
	cout << "Place your Aircraft Carrier (5).Type a direction vector and a starting location." << endl;
	cout << "For example: V 1 0 or H 4 5" << endl << ":";
	//****************************************Aircraftcarrier2
	cin >> vector >> xPos >> yPos;
	while ((player2.check_player_input(vector, xPos, yPos) == false) or (vector == 'H' && xPos >= 6) or (vector == 'V' && yPos >= 6)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 5; counter++, xPos++) {
			player2.set_player_board(yPos, xPos, 'A');
		}
	} else {
		for (int counter = 0; counter < 5; counter++, yPos++) {
			player2.set_player_board(yPos, xPos, 'A');
		}
	}
	//****************************************Battleship2
	cout << "Place your Battleship (4). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player2.check_player_input(vector, xPos, yPos) == false)
			or (vector == 'H' && (xPos >= 7 or player2.check_player_placement(yPos, xPos, 'H', 4) == false))
			or (vector == 'V' && (yPos >= 7 or player2.check_player_placement(yPos, xPos, 'V', 4) == false))){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid User Input. Please try again." << endl << ":";
		cin >> vector >> xPos >> yPos;
	}
	if (vector == 'H') {
		for (int counter = 0; counter < 4; counter++, xPos++) {
			player2.set_player_board(yPos, xPos, 'B');
		}
	} else {
		for (int counter = 0; counter < 4; counter++, yPos++) {
			player2.set_player_board(yPos, xPos, 'B');
		}
	}
	//****************************************Submarine2
	cout << "Place your Submarine (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player2.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player2.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player2.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player2.set_player_board(yPos, xPos, 'S');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player2.set_player_board(yPos, xPos, 'S');
		}
	}
	//****************************************Destroyer2
	cout << "Place your Destroyer (3). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player2.check_player_input(vector, xPos, yPos) == false)
				or (vector == 'H' && (xPos >= 8 or player2.check_player_placement(yPos, xPos, 'H', 3) == false))
				or (vector == 'V' && (yPos >= 8 or player2.check_player_placement(yPos, xPos, 'V', 3) == false))){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid User Input. Please try again." << endl << ":";
			cin >> vector >> xPos >> yPos;
		}
	if (vector == 'H') {
		for (int counter = 0; counter < 3; counter++, xPos++) {
			player2.set_player_board(yPos, xPos, 'D');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, yPos++) {
			player2.set_player_board(yPos, xPos, 'D');
		}
	}
	//****************************************Patrolboat2
	cout << "Place your Patrol Boat (2). Type a direction vector and a starting location." << endl;
	cout << "For example: V 0 4 or H 9 3" << endl << ":";
	cin >> vector >> xPos >> yPos;
	while ((player2.check_player_input(vector, xPos, yPos) == false)
					or (vector == 'H' && (xPos >= 9 or player2.check_player_placement(yPos, xPos, 'H', 2) == false))
					or (vector == 'V' && (yPos >= 9 or player2.check_player_placement(yPos, xPos, 'V', 2) == false))){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid User Input. Please try again." << endl << ":";
				cin >> vector >> xPos >> yPos;
			}
	if (vector == 'H') {
		for (int counter = 0; counter < 2; counter++, xPos++) {
			player2.set_player_board(yPos, xPos, 'P');
		}
	} else {
		for (int counter = 0; counter < 2; counter++, yPos++) {
			player2.set_player_board(yPos, xPos, 'P');
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Boards and Ships initialized!" << endl;
	status = true;
}
if (gameMode == 3){
	computer.initialize_ships();
	computer2.initialize_ships();
	computer.initialize_boards();
	computer2.initialize_boards();
	//****************************************ComputerAircraftcarrier
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%6;
		break;
	case 'H':
		compxPos = rand()%6;
		compyPos = rand()%10;
		break;
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 5; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'A');
		}
	} else {
		for (int counter = 0; counter < 5; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'A');
		}
	}
	//****************************************ComputerBattleship
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%7;
		break;
	case 'H':
		compxPos = rand()%7;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 4) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%6;
			break;
		case 'H':
			compxPos = rand()%6;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 4; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'B');
		}
	} else {
		for (int counter = 0; counter < 4; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'B');
		}
	}
	//****************************************ComputerSubmarine
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%8;
		break;
	case 'H':
		compxPos = rand()%8;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 3; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'S');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'S');
		}
	}
	//****************************************ComputerDestroyer
	cVectorInt = rand()%2;
	switch(cVectorInt){
	case 0:
		cVectorChar = 'V';
		break;
	case 1:
		cVectorChar = 'H';
		break;
	}
	switch(cVectorChar){
	case 'V':
		compxPos = rand()%10;
		compyPos = rand()%8;
		break;
	case 'H':
		compxPos = rand()%8;
		compyPos = rand()%10;
		break;
	}
	while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
	}
	if (cVectorChar == 'H') {
		for (int counter = 0; counter < 3; counter++, compxPos++) {
			computer.set_computer_board(compyPos, compxPos, 'D');
		}
	} else {
		for (int counter = 0; counter < 3; counter++, compyPos++) {
			computer.set_computer_board(compyPos, compxPos, 'D');
		}
	}
	//****************************************ComputerPatrolboat
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%9;
			break;
		case 'H':
			compxPos = rand()%9;
			compyPos = rand()%10;
			break;
		}
		while (computer.check_computer_placement(compyPos, compxPos, cVectorChar, 2) == false) {
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%9;
				break;
			case 'H':
				compxPos = rand()%9;
				compyPos = rand()%10;
				break;
			}
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 2; counter++, compxPos++) {
				computer.set_computer_board(compyPos, compxPos, 'P');
			}
		} else {
			for (int counter = 0; counter < 2; counter++, compyPos++) {
				computer.set_computer_board(compyPos, compxPos, 'P');
			}
		}
		//****************************************ComputerAircraftcarrier2
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%6;
			break;
		case 'H':
			compxPos = rand()%6;
			compyPos = rand()%10;
			break;
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 5; counter++, compxPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'A');
			}
		} else {
			for (int counter = 0; counter < 5; counter++, compyPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'A');
			}
		}
		//****************************************ComputerBattleship2
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%7;
			break;
		case 'H':
			compxPos = rand()%7;
			compyPos = rand()%10;
			break;
		}
		while (computer2.check_computer_placement(compyPos, compxPos, cVectorChar, 4) == false) {
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%6;
				break;
			case 'H':
				compxPos = rand()%6;
				compyPos = rand()%10;
				break;
			}
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 4; counter++, compxPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'B');
			}
		} else {
			for (int counter = 0; counter < 4; counter++, compyPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'B');
			}
		}
		//****************************************ComputerSubmarine2
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
		while (computer2.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%8;
				break;
			case 'H':
				compxPos = rand()%8;
				compyPos = rand()%10;
				break;
			}
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 3; counter++, compxPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'S');
			}
		} else {
			for (int counter = 0; counter < 3; counter++, compyPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'S');
			}
		}
		//****************************************ComputerDestroyer2
		cVectorInt = rand()%2;
		switch(cVectorInt){
		case 0:
			cVectorChar = 'V';
			break;
		case 1:
			cVectorChar = 'H';
			break;
		}
		switch(cVectorChar){
		case 'V':
			compxPos = rand()%10;
			compyPos = rand()%8;
			break;
		case 'H':
			compxPos = rand()%8;
			compyPos = rand()%10;
			break;
		}
		while (computer2.check_computer_placement(compyPos, compxPos, cVectorChar, 3) == false) {
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%8;
				break;
			case 'H':
				compxPos = rand()%8;
				compyPos = rand()%10;
				break;
			}
		}
		if (cVectorChar == 'H') {
			for (int counter = 0; counter < 3; counter++, compxPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'D');
			}
		} else {
			for (int counter = 0; counter < 3; counter++, compyPos++) {
				computer2.set_computer_board(compyPos, compxPos, 'D');
			}
		}
		//****************************************ComputerPatrolboat2
			cVectorInt = rand()%2;
			switch(cVectorInt){
			case 0:
				cVectorChar = 'V';
				break;
			case 1:
				cVectorChar = 'H';
				break;
			}
			switch(cVectorChar){
			case 'V':
				compxPos = rand()%10;
				compyPos = rand()%9;
				break;
			case 'H':
				compxPos = rand()%9;
				compyPos = rand()%10;
				break;
			}
			while (computer2.check_computer_placement(compyPos, compxPos, cVectorChar, 2) == false) {
				cVectorInt = rand()%2;
				switch(cVectorInt){
				case 0:
					cVectorChar = 'V';
					break;
				case 1:
					cVectorChar = 'H';
					break;
				}
				switch(cVectorChar){
				case 'V':
					compxPos = rand()%10;
					compyPos = rand()%9;
					break;
				case 'H':
					compxPos = rand()%9;
					compyPos = rand()%10;
					break;
				}
			}
			if (cVectorChar == 'H') {
				for (int counter = 0; counter < 2; counter++, compxPos++) {
					computer2.set_computer_board(compyPos, compxPos, 'P');
				}
			} else {
				for (int counter = 0; counter < 2; counter++, compyPos++) {
					computer2.set_computer_board(compyPos, compxPos, 'P');
				}
			}
			cout << "Boards and Ships initialized!" << endl;
			status = true;
}
}
void Battleship::check_player_guess(int row, int col, int gameType){  //check player's guess on computer's board
	if (gameType == 1) {
		switch (computer.getBoardEntry(row, col)) {
		case 'A':
		case 'B':
		case 'D':
		case 'P':
		case 'S':
		case 'X':
			computer.set_computer_board(row, col, 'X');
			player.setOpponentBoardEntry(row, col, 'H');
			cout << "Hit by " << player.getName() << "!" << endl;
			player.display_boards();
			break;
		case '0':
			player.setOpponentBoardEntry(row, col, 'M');
			cout << "Miss by " << player.getName() << "!" << endl;
			player.display_boards();
			break;
		}
	}
	if (gameType == 2) {
		switch (player2.getBoardEntry(row, col)) {
		case 'A':
		case 'B':
		case 'D':
		case 'P':
		case 'S':
		case 'X':
			player2.set_player_board(row, col, 'X');
			player.setOpponentBoardEntry(row, col, 'H');
			cout << "Hit by " << player.getName() << "!" << endl;
			break;
		case '0':
			player.setOpponentBoardEntry(row, col, 'M');
			cout << "Miss by " << player.getName() << "!" << endl;
			break;
		}
	}
	if (gameType == 3) {
		switch (player.getBoardEntry(row, col)) {
		case 'A':
		case 'B':
		case 'D':
		case 'P':
		case 'S':
		case 'X':
			player.set_player_board(row, col, 'X');
			player2.setOpponentBoardEntry(row, col, 'H');
			cout << "Hit by " << player2.getName() << "!" << endl;
			break;
		case '0':
			player2.setOpponentBoardEntry(row, col, 'M');
			cout << "Miss by " << player2.getName() << "!" << endl;
			break;
		}
	}
}
void Battleship::check_computer_guess(int row, int col, int gameType){
	bool loop = false;
	if (gameType == 1) {
		if (computer.hit_check() == true) {
			row = computer.hit_checkY();
			col = computer.hit_checkX();
			switch (player.getBoardEntry(row, col)) {
			case 'A':
			case 'B':
			case 'D':
			case 'P':
			case 'S':
				player.set_player_board(row, col, 'X');
				computer.setOpponentBoardEntry(row, col, 'H');
				cout << "Hit by Computer! (" << row << ", " << col << ")"
						<< endl;
				break;
			case '0':
				computer.setOpponentBoardEntry(row, col, 'M');
				cout << "Miss by Computer! (" << row << ", " << col << ")"
						<< endl;
				break;
			}
		} else {
			while (loop == false) {
				if (computer.miss_check(row, col) == false) {
					row = rand() % 10;
					col = rand() % 10;
				} else {
					switch (player.getBoardEntry(row, col)) {
					case 'A':
					case 'B':
					case 'D':
					case 'P':
					case 'S':
						player.set_player_board(row, col, 'X');
						computer.setOpponentBoardEntry(row, col, 'H');
						cout << "Hit by Computer! (" << row << ", " << col
								<< ")" << endl;
						loop = true;
						break;
					case '0':
						computer.setOpponentBoardEntry(row, col, 'M');
						cout << "Miss by Computer! (" << row << ", " << col
								<< ")" << endl;
						loop = true;
						break;
					}
				}
			}
		}
	}
	if (gameType == 2) {
		if (computer.hit_check() == true) {
			row = computer.hit_checkY();
			col = computer.hit_checkX();
			switch (computer2.getBoardEntry(row, col)) {
			case 'A':
			case 'B':
			case 'D':
			case 'P':
			case 'S':
				computer2.set_computer_board(row, col, 'X');
				computer.setOpponentBoardEntry(row, col, 'H');
				cout << "Hit by Computer! (" << row << ", " << col << ")"
						<< endl;
				computer.display_boards();
				break;
			case '0':
				computer.setOpponentBoardEntry(row, col, 'M');
				cout << "Miss by Computer! (" << row << ", " << col << ")"
						<< endl;
				computer.display_boards();
				break;
			}
		} else {
			while (loop == false) {
				if (computer.miss_check(row, col) == false) {
					row = rand() % 10;
					col = rand() % 10;
				} else {
					switch (computer2.getBoardEntry(row, col)) {
					case 'A':
					case 'B':
					case 'D':
					case 'P':
					case 'S':
						computer2.set_computer_board(row, col, 'X');
						computer.setOpponentBoardEntry(row, col, 'H');
						cout << "Hit by Computer! (" << row << ", " << col
								<< ")" << endl;
						computer.display_boards();
						loop = true;
						break;
					case '0':
						computer.setOpponentBoardEntry(row, col, 'M');
						cout << "Miss by Computer! (" << row << ", " << col
								<< ")" << endl;
						computer.display_boards();
						loop = true;
						break;
					}
				}
			}
		}
	}
	if (gameType == 3) {
	if (computer2.hit_check() == true) {
			row = computer2.hit_checkY();
			col = computer2.hit_checkX();
			switch (computer.getBoardEntry(row, col)) {
			case 'A':
			case 'B':
			case 'D':
			case 'P':
			case 'S':
				computer.set_computer_board(row, col, 'X');
				computer2.setOpponentBoardEntry(row, col, 'H');
				cout << "Hit by computer2! (" << row << ", " << col << ")" << endl;
				computer2.display_boards();
				break;
			case '0':
				computer2.setOpponentBoardEntry(row, col, 'M');
				cout << "Miss by computer2! (" << row << ", " << col << ")" << endl;
				computer2.display_boards();
				break;
			}
		} else {
			while (loop == false) {
				if (computer2.miss_check(row, col) == false) {
					row = rand() % 10;
					col = rand() % 10;
				} else {
					switch (computer.getBoardEntry(row, col)) {
					case 'A':
					case 'B':
					case 'D':
					case 'P':
					case 'S':
						computer.set_computer_board(row, col, 'X');
						computer2.setOpponentBoardEntry(row, col, 'H');
						cout << "Hit by computer2! (" << row << ", " << col << ")" << endl;
						computer2.display_boards();
						loop = true;
						break;
					case '0':
						computer2.setOpponentBoardEntry(row, col, 'M');
						cout << "Miss by computer2! (" << row << ", " << col << ")" << endl;
						computer2.display_boards();
						loop = true;
						break;
					}
				}
			}
		}
	}
}

bool Battleship::get_status(int gameType) {
	if (gameType == 1) {
	if(player.check_status() == false or computer.check_status() == false){
	status = false;
	}
	return status;
}
if (gameType == 2){
	if(player.check_status() == false or player2.check_status() == false){
	status = false;
	}
	return status;
}
if (gameType == 3){
	if(computer.check_status() == false or computer2.check_status() == false){
	status = false;
	}
	return status;
}
}

void Battleship::check_player_ships(){
	player.check_ship();
}

void Battleship::check_computer_ships(){
	computer.check_ship();
}

void Battleship::check_player2_ships(){
	player2.check_ship();
}

void Battleship::check_computer2_ships(){
	computer2.check_ship();
}

string Battleship::getNamePlayer1() {
	return player.getName();
}
string Battleship::getNamePlayer2() {
	return player2.getName();
}

int Battleship::getGameType() {
	return gameMode;
}

void Battleship::playerDisplay_boards() {
	player.display_boards();
}
void Battleship::player2Display_boards() {
	player2.display_boards();
}

#endif
//******************** Graveyard
//	while(vector == 'H' && xPos >= 6){
//		cout << "Invalid Placement. Please try again." << endl << ":";
//		cin >> vector >> xPos >> yPos;
//	}
//	while(vector == 'V' && yPos >= 6){
//			cout << "Invalid Placement. Please try again." << endl << ":";
//			cin >> vector >> xPos >> yPos;
//		}
//while(vector == 'H' && xPos >= 7 or player.check_player_placement(yPos, xPos, 'H', 4) == false){
//	cout << "Invalid Placement. Please try again." << endl << ":";
//	cin >> vector >> xPos >> yPos;
//}
//while(vector == 'V' && yPos >= 7 or player.check_player_placement(yPos, xPos, 'V', 4) == false){
//		cout << "Invalid Placement. Please try again." << endl << ":";
//		cin >> vector >> xPos >> yPos;
//	}
//while(vector == 'H' && xPos >= 8 or player.check_player_placement(yPos, xPos, 'H', 3) == false){
//	cout << "Invalid Placement. Please try again." << endl << ":";
//	cin >> vector >> xPos >> yPos;
//}
//while(vector == 'V' && yPos >= 8 or player.check_player_placement(yPos, xPos, 'V', 3) == false){
//		cout << "Invalid Placement. Please try again." << endl << ":";
//		cin >> vector >> xPos >> yPos;
//	}
//while(vector == 'H' && xPos >= 9 or player.check_player_placement(yPos, xPos, 'H', 2) == false){
//	cout << "Invalid Placement. Please try again." << endl << ":";
//	cin >> vector >> xPos >> yPos;
//}
//while(vector == 'V' && yPos >= 9 or player.check_player_placement(yPos, xPos, 'V', 2) == false){
//		cout << "Invalid Placement. Please try again." << endl << ":";
//		cin >> vector >> xPos >> yPos;
//	}
