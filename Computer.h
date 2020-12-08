//Author: Adam So
//November 2020

#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Computer{
	public:
		Computer();
		int find_ship(int row, int col);  //find the ship that got hit
		void check_ship();  //see if a ship is sunk
		bool check_status(); //see if all the Players' ships are sunk!
		string sink_ship(int ship_num); //display a message that says which ship is sunk
		void initialize_ships();  //start the game with fresh ships
		void initialize_boards();  //start up the boards to display 
		void display_boards();
		char getBoardEntry(int r, int c); //check the value at that row, col entry
		char getOpponentBoardEntry(int r, int c);  //check the value at that row, col entry
		void setOpponentBoardEntry(int r, int c, char v);  //check the value at that row, col entry
		void tallyHit(int shipNum, int row, int col);   //increment the number of hits on the ship
		void set_computer_board(int computerY, int computerX, char shipType);
		bool check_computer_placement(int computerY, int computerX, char vector, int length);
		bool miss_check(int computerY, int computerX);
		bool hit_check();
		int hit_checkY();
		int hit_checkX();
		void setName(string n);
		string getName();
	private:
		string name;
		int ships[5];  //they will all be 0 initially
		char board[10][10];
		char opponent_board[10][10];
		const int NUM_SHIPS = 5;
		int hitcomputerY, hitcomputerX;
};

Computer::Computer(){

}

void Computer::display_boards(){
	cout << getName() << "'s Board\n" << "*************" << endl;
	printf("%-3s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s\n", "  ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
	printf("%-3s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s\n", "  ", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_");
	for(int i = 0; i < 10; i++){
		cout << to_string(i) << " |";
		for(int j = 0; j < 10; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << getName() << "'s Opponent Board\n" << "*************" << endl;
	printf("%-3s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s\n", "  ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
	printf("%-3s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s%-2s\n", "  ", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_");
	for(int i = 0; i < 10; i++){
		cout << to_string(i) << " |";
		for(int j = 0; j < 10; j++){
			cout << opponent_board[i][j] << " ";
		}
		cout << endl;
	}
}

void Computer::setOpponentBoardEntry(int r, int c, char v){
	opponent_board[r][c] = v;
}

char Computer::getOpponentBoardEntry(int r, int c){
	char boardEntry1;
	boardEntry1 = opponent_board[r][c];
	return boardEntry1;
}

char Computer::getBoardEntry(int r, int c){
	char boardEntry;
	boardEntry = board[r][c];
	return boardEntry;
}

void Computer::tallyHit(int shipNum, int row, int col){

}

int Computer::find_ship(int row, int col){  //find the ship that got hit

}

void Computer::check_ship(){  //see if a ship is sunk
	for (int counter = 0; counter < 5; counter++){
	switch (counter) {
	case 0:
	{
		int life = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'P') {
					life++;
				}
			}
		}
		if (life < 1) {
			if (ships[0] == 1) {
				cout << name << " says: You sunk my Patrol Boat!" << endl;
				ships[0] = 0;
				break;
			}
			break;
		}
	}
		break;
	case 1:
	{
		int life = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'D') {
					life++;
				}
			}
		}
		if (life < 1) {
			if (ships[1] == 1) {
				cout << name << " says: You sunk my Destroyer!" << endl;
				ships[1] = 0;
				break;
			}
			break;
		}
	}
		break;
	case 2:
	{
		int life = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'S') {
					life++;
				}
			}
		}
		if (life < 1) {
			if (ships[2] == 1) {
				cout << name << " says: You sunk my Submarine!" << endl;
				ships[2] = 0;
				break;
			}
			break;
		}
	}
		break;
	case 3:
	{
		int life = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'B') {
					life++;
				}
			}
		}
		if (life < 1) {
			if (ships[3] == 1) {
				cout << name << " says: You sunk my Battleship!" << endl;
				ships[3] = 0;
				break;
			}
			break;
		}
	}
		break;
	case 4:
	{
		int life = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'A') {
					life++;
				}
			}
		}
		if (life < 1) {
			if (ships[4] == 1) {
				cout << name << " says: You sunk my Aircraft Carrier!" << endl;
				ships[4] = 0;
				break;
			}
			break;
		}
	}
		break;
	}

}
}

bool Computer::check_status(){ //see if all the Computer's ships are sunk!
	if (ships[0] == 0 and ships[1] == 0 and ships[2] == 0 and ships[3] == 0 and ships[4] == 0){
		return false;
	}
	return true;
}

void Computer::initialize_ships(){  //start the game with fresh ships
	for(int i = 0; i < NUM_SHIPS; i++){
		ships[i] = 1;
	}
	hitcomputerX = 0;
	hitcomputerX = 0;
}

string Computer::sink_ship(int ship_num){ //display a message that says which ship is sunk
	switch(ship_num){
	case 0:
		cout << "Computer says: You sunk my Patrol Boat!" << endl;
		break;
	case 1:
		cout << "Computer says: You sunk my Destroyer!" << endl;
		break;
	case 2:
		cout << "Computer says: You sunk my Submarine!" << endl;
		break;
	case 3:
		cout << "Computer says: You sunk my Battleship!" << endl;
		break;
	case 4:
		cout << "Computer says: You sunk my Aircraft Carrier!" << endl;
		break;
	}
}

void Computer::initialize_boards(){  //start up the boards to display
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = '0';
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			opponent_board[i][j] = '0';
		}
	}
}

void Computer::set_computer_board(int computerY, int computerX, char shipType) {
	board[computerY][computerX] = shipType;
}

bool Computer::check_computer_placement(int computerY, int computerX, char vector, int length) {
	int violation = 0;
	int i = computerX;
	int j = computerY;
	if (vector == 'H') {
		for (int counter = 0; counter < length; counter++, i++) {
			if (board[computerY][i] != '0') {
				violation++;
			}
		}
		if (violation == 0) {
			return true;
		}
		return false;
	} else {
		for (int counter = 0; counter < length; counter++, j++) {
			if (board[j][computerX] != '0') {
				violation++;
			}
		}
		if (violation == 0) {
			return true;
		}
		return false;
	}
}

bool Computer::miss_check(int computerY, int computerX) {
	int miss = 0;
	switch (getOpponentBoardEntry(computerY, computerX)) {
	case '0':
		if (computerY > 0 and computerY < 10 and computerX > 0
				and computerX < 10) {
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (miss > 3) {
				return false;
			}
			return true;
		}
		if (computerY == 0 and computerX != 0 and computerX != 9) {
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (miss > 2) {
				return false;
			}
			return true;
		}
		if (computerY == 9 and computerX != 9 and computerX != 0) {
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (miss > 2) {
				return false;
			}
			return true;
		}
		if (computerX == 0 and computerY != 0 and computerY != 9) {
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (miss > 2) {
				return false;
			}
			return true;
		}
		if (computerX == 9 and computerY != 9 and computerY != 0) {
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (miss > 2) {
				return false;
			}
			return true;
		}
		if (computerY == 0 and computerX == 0) {
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (miss > 1) {
				return false;
			}
			return true;
		}
		if (computerY == 9 and computerX == 0) {
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX + 1) == 'M') {
				miss++;
			}
			if (miss > 1) {
				return false;
			}
			return true;
		}
		if (computerY == 0 and computerX == 9) {
			if (getOpponentBoardEntry(computerY + 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (miss > 1) {
				return false;
			}
			return true;
		}
		if (computerY == 9 and computerX == 9) {
			if (getOpponentBoardEntry(computerY - 1, computerX) == 'M') {
				miss++;
			}
			if (getOpponentBoardEntry(computerY, computerX - 1) == 'M') {
				miss++;
			}
			if (miss > 1) {
				return false;
			}
			return true;
		}
	case 'H':
		return false;
	case 'M':
		return false;
	}
}

bool Computer::hit_check() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (opponent_board[i][j] == 'H') {
				if (i > 0 and i < 10 and j > 0 and j < 10) {
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
				}
				if (i == 0 and j != 0 and j != 9) {
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
				}
				if (i == 9 and j != 9 and j != 0) {
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
				}
				if (j == 0 and i != 0 and i != 9) {
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
				}
				if (j == 9 and i != 9 and i != 0) {
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
				}
				if (i == 0 and j == 0) {
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
				}
				if (i == 9 and j == 0) {
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j + 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j + 1;
						return true;
					}
				}
				if (i == 0 and j == 9) {
					if (getOpponentBoardEntry(i + 1, j) == '0') {
						hitcomputerY = i + 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
				}
				if (i == 9 and j == 9) {
					if (getOpponentBoardEntry(i - 1, j) == '0') {
						hitcomputerY = i - 1;
						hitcomputerX = j;
						return true;
					}
					if (getOpponentBoardEntry(i, j - 1) == '0') {
						hitcomputerY = i;
						hitcomputerX = j - 1;
						return true;
					}
				}
			}
		}
	}
	return false;
}

int Computer::hit_checkY() {
	return hitcomputerY;
}

int Computer::hit_checkX() {
	return hitcomputerX;
}

void Computer::setName(string n){
	name = n;
}

string Computer::getName(){
	string getName = name;
	return getName;
}

#endif

//Somehow this code below crashes the Player.h Player Class and causes problems in PlayBattleship.cpp. Error: function definition inside of main
//The function is missing the } at the end making it include #endif
//bool Computer::computer_guess(int computerY, int computerX) {
//	char boardentry = getOpponentBoardEntry(computerY, computerX);
//	switch (boardentry){
//	case '0':
//	case 'H':
//		return false;
//	case 'M':
//		return false;
//}
