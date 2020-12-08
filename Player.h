//Author: Adam So
//November 2020

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
using namespace std;

class Player{
	public:
		Player();
		void setName(string n);
		string getName();
		int find_ship(int row, int col);  //find the ship that got hit
		void check_ship();  //see if a ship is sunk
		bool check_status(); //see if all the Players' ships are sunk!
//		string sink_ship(int ship_num); //display a message that says which ship is sunk
		void initialize_ships();  //start the game with fresh ships
		void initialize_boards();  //start up the boards to display
		void display_boards();
		char getBoardEntry(int r, int c);  //check the value at that row, col entry
		void setOpponentBoardEntry(int r, int c, char v);  //check the value at that row, col entry
		void tallyHit(int shipNum, int row, int col);
		void set_player_board(int playerX, int playerY, char shipType);
		bool check_player_placement(int playerX, int playerY, char vector, int length);
		bool check_player_input(char vector, int playerX, int playerY);
//		bool total_status();
	private:
		int ships[5];  //they will all be 0 initially
		char board[10][10];
		char opponent_board[10][10];
		string name;
		const int NUM_SHIPS = 5;

};

Player::Player(){

}

void Player::display_boards(){
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

void Player::setOpponentBoardEntry(int r, int c, char v){
	opponent_board[r][c] = v;
}

char Player::getBoardEntry(int r, int c){
	char boardEntry;
	boardEntry = board[r][c];
	return boardEntry;
}

void Player::tallyHit(int shipNum, int row, int col){

}


void Player::setName(string n){
	name = n;
}

string Player::getName(){
	string getName = name;
	return getName;
}

int Player::find_ship(int row, int col){  //find the ship that got hit

}

void Player::check_ship(){  //see if a ship is sunk
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

bool Player::check_status() { //see if all the Players' ships are sunk!
		if (ships[0] == 0 and ships[1] == 0 and ships[2] == 0 and ships[3] == 0 and ships[4] == 0){
			return false;
		}
		return true;
	}

void Player::initialize_ships(){  //start the game with fresh ships
	for(int i = 0; i < NUM_SHIPS; i++){
		ships[i] = 1;
	}

}

void Player::initialize_boards() { //start up the boards to display
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

void Player::set_player_board(int playerY, int playerX, char shipType) {
	board[playerY][playerX] = shipType;
}


bool Player::check_player_placement(int playerY, int playerX, char vector, int length) {
	int violation = 0;
	int i = playerX;
	int j = playerY;
	if (vector == 'H') {
		for (int counter = 0; counter < length; counter++, i++) {
			if (board[playerY][i] != '0') {
				violation++;
			}
		}
		if (violation == 0) {
			return true;
		}
		return false;
	} else {
		for (int counter = 0; counter < length; counter++, j++) {
			if (board[j][playerX] != '0') {
				violation++;
			}
		}
		if (violation == 0) {
			return true;
		}
		return false;
	}
}

bool Player::check_player_input(char vector, int playerX, int playerY){
	int violation = 0;
	if (vector != 'V' and vector != 'H') {
		violation++;
	}
	if (playerX != 0 and playerX != 1 and playerX != 2 and playerX != 3 and playerX != 4 and playerX != 5 and playerX != 6 and playerX != 7 and playerX != 8 and playerX != 9) {
		violation++;
	}
	if (playerY != 0 and playerY != 1 and playerY != 2 and playerY != 3 and playerY != 4 and playerY != 5 and playerY != 6 and playerY != 7 and playerY != 8 and playerY != 9){
		violation++;
	}
	if(cin.fail() == true){
		violation++;
	}
	if (violation == 0){
		return true;}
		return false;
}

//bool Player::total_status(){
//	if (ships[0] == 0 and ships[1] == 0 and ships[2] == 0 and ships[3] == 0 and ships[4] == 0){
//		return false;
//	}
//	return true;
//}

#endif
//string Player::sink_ship(int ship_num){ //display a message that says which ship is sunk
//	switch(ship_num){
//	case 0:
//		cout << name << " says: You sunk my Patrol Boat!" << endl;
//		break;
//	case 1:
//		cout << name << " says: You sunk my Destroyer!" << endl;
//		break;
//	case 2:
//		cout << name << " says: You sunk my Submarine!" << endl;
//		break;
//	case 3:
//		cout << name << " says: You sunk my Battleship!" << endl;
//		break;
//	case 4:
//		cout << name << " says: You sunk my Aircraft Carrier!" << endl;
//		break;
//	}
//}

//************************** GRAVEYARD
//bool Player::check_player_placement(int playerX, int playerY, char vector, int length) {
//	if (vector == 'H') {
//		for (int counter = 0; counter < length; counter++) {
//			if (board[playerX][playerY] == '0') {
//				playerX++;
//			} else {
//				return false;
//			}
//		}
//	return true;
//}
//}

//			}
//			while (board[playerX][playerY] != 0) {
//				playerX++;
//				return false;
//
//			}
//		}
//	} else {
//		for (int counter = 0; counter < length; counter++) {
//			while (board[playerX][playerY] == 0) {
//				playerY++;
//				return true;
//
//
//			}
//			while (board[playerX][playerY] != 0) {
//				playerY++;
//				return false;
//
//			}
//		}
//	}
//}
//



	//	if (vector == 'H') {
//		for (int counter = 0; counter < length; counter++) {
//			do {
//				while (board[playerX][playerY] == 0) {
//				playerX++;
//				return true;
//			}
//			while (board[playerX][playerY] == 0) {
//				playerX++;
//				return false;
//			}
//			}
//		}
//	}
//}
//		}else {
//		for (int counter = 0; counter < length; counter++) {
//			if (board[playerX][playerY] == 0) {
//				playerY++;
//				return true;
//			} else {
//				return false;
//			}
//		}
//	}
//}

//if (vector == 'H') {
//		for (int counter = 0; counter < length; counter++) {
//			if (board[playerX][playerY] == 0) {
//				playerX++;
//				return true;
//			} else {
//				return false;
//			}
//		}
//		}else {
//		for (int counter = 0; counter < length; counter++) {
//			if (board[playerX][playerY] == 0) {
//				playerX++;
//				return true;
//			} else {
//				return false;
//			}
//		}
//	}

