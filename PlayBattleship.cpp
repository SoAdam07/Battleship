//This is the game of Battleship.
//Author: Adam So
//November 2020
// Ship name - hits required to sink
//1) Aircraft carrier - 5
//2) Battleship - 4
//3) Submarine - 3
//4) Destroyer - 3
//5) Patrol boat - 2
//This game will allow for a game between a Player and the Computer.
//Each Player has 5 ships to be placed, a map of their own ships and a map of the Computer's ships (with
//hits or misses).
//The game alternates between players until one of them sinks all of the other players' ships.

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Battleship.h"
using namespace std;

bool check_player_input(int row, int col){
		int violation = 0;
		if (row != 0 and row != 1 and row != 2 and row != 3 and row != 4 and row != 5 and row != 6 and row != 7 and row != 8 and row != 9) {
			violation++;
		}
		if (col != 0 and col != 1 and col != 2 and col != 3 and col != 4 and col != 5 and col != 6 and col != 7 and col != 8 and col != 9){
			violation++;
		}
		if(cin.fail() == true){
			violation++;
		}
		if (violation == 0){
			return true;}
			return false;
	}

int main(){
	bool winner = false;
	int row, col, holder;

	cout << "Welcome to the game of BATTLESHIP!\n"
			<< "The objective of this game is to sink all of your opponent's boats.\n"
			<< "Each player has five (5) boats. Each boat has a name and a size.\n"
			<< "Here are the boat names and sizes:\n"
			<< "Aircraft Carrier 5\n"
			<< "BATTLESHIP 4\n"
			<< "Submarine 3\n"
			<< "Destroyer 3\n"
			<< "Patrol Boat 2\n" << endl;
	srand(time(NULL));
	Battleship game;
	if(game.getGameType() == 1){
	int turn = rand() % 2;  //1 is player turn, and 2 is comp turn
	while(!winner){
		if(turn == 1){   //Player goes first.
			cout << "Please enter your guess (Row Column): ";
			cin >> row >> col;
			while (check_player_input(row, col) == false) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid User Input. Please try again." << endl << ":";
				cin >> row >> col;
			}
			game.check_player_guess(row, col, game.getGameType());
			game.check_computer_ships();
			if(game.get_status(game.getGameType()) == false){
				cout << game.getNamePlayer1() <<  " wins!\n"; //Player wins.
				break;
			}
			row = rand()%10;
			col = rand()%10;
			game.check_computer_guess(row, col, game.getGameType());
			game.check_player_ships();
			if(game.get_status(game.getGameType()) == false){
				cout << "Computer wins!\n";
				break;
			}
		}
		else{    //Computer goes first.
			row = rand()%10;
			col = rand()%10;
			game.check_computer_guess(row, col, game.getGameType());
			game.check_player_ships();
			if(game.get_status(game.getGameType()) == false){
				cout << "Computer wins!\n";
				break;
			}
			cout << "Please enter your guess (Row Column): ";
			cin >> row >> col;
			while (check_player_input(row, col) == false) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid User Input. Please try again." << endl << ":";
				cin >> row >> col;
			}
			game.check_player_guess(row, col, game.getGameType());
			game.check_computer_ships();
			if(game.get_status(game.getGameType()) == false){
				cout << game.getNamePlayer1() <<  " wins!\n"; //Player wins!
				break;
			}
		}
	}
	return 0;
}
	if (game.getGameType() == 2){
		int turn = rand() % 2;  //1 is player turn, and 2 is player2 turn
		int intro = 1;
		while(!winner){
			if(turn == 1){   //Player goes first.
				if (intro > 0){
				cout << game.getNamePlayer1() << " will be going first." << endl;
				intro--;
				}
				cout << "Enter any key when you are ready." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');

				game.playerDisplay_boards();
				cout << game.getNamePlayer1() << " please enter your guess (Row Column): ";
				cin >> row >> col;
				while (check_player_input(row, col) == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid User Input. Please try again." << endl << ":";
					cin >> row >> col;
				}
				game.check_player_guess(row, col, game.getGameType());
				game.check_player2_ships();
				if(!game.get_status(game.getGameType())){
					cout << game.getNamePlayer1() <<  " wins!\n"; //Player wins.
					break;
				}
						cout << "Enter any key when you are ready to clear screen." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
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
				cout << game.getNamePlayer2() << " it is your turn."
						<< "Enter any key when you are ready." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
				game.player2Display_boards();
				cout << game.getNamePlayer2() << " please enter your guess (Row Column): ";
				cin >> row >> col;
				while (check_player_input(row, col) == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid User Input. Please try again." << endl << ":";
					cin >> row >> col;
				}
				game.check_player_guess(row, col, game.getGameType() + 1);
				game.check_player_ships();
				if(!game.get_status(game.getGameType())){
					cout << game.getNamePlayer2() <<  " wins!\n"; //Player2 wins.
					break;
				}
				cout << "Enter any key when you are ready to clear screen." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
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
			}
			else{
				if(intro > 0){
				cout << game.getNamePlayer2() << " will be going first." << endl;
						intro--;
				}
				cout << "Enter any key when you are ready." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
				game.player2Display_boards();
				cout << game.getNamePlayer2() << " please enter your guess (Row Column): ";
				cin >> row >> col;
				while (check_player_input(row, col) == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid User Input. Please try again." << endl << ":";
					cin >> row >> col;
				}
				game.check_player_guess(row, col, game.getGameType() + 1);
				game.check_player_ships();
				if(!game.get_status(game.getGameType())){
					cout << game.getNamePlayer2() <<  " wins!\n"; //Computer2 wins.
					break;
				}
				cout << "Enter any key when you are ready to clear screen." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
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
				cout << game.getNamePlayer1() << " it is your turn."
						<< " Enter any key when you are ready." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
				game.playerDisplay_boards();
				cout << game.getNamePlayer1() << " please enter your guess (Row Column): "; //Player2 goes first.
				cin >> row >> col;
				while (check_player_input(row, col) == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid User Input. Please try again." << endl << ":";
					cin >> row >> col;
				}
				game.check_player_guess(row, col, game.getGameType());
				game.check_player2_ships();
				if(!game.get_status(game.getGameType())){
					cout << game.getNamePlayer1() <<  " wins!\n"; //Player wins.
					break;
				}
				cout << "Enter any key when you are ready to clear screen." << endl;
				cin >> holder;
				cin.clear();
				cin.ignore(1000, '\n');
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
			}
		}
		return 0;
	}
	if (game.getGameType() == 3){
		int turn = rand() % 2;  //1 is Computer turn, and 2 is computer2 turn
		while(!winner){
			if (turn == 1) {   //Computer goes first.
				row = rand() % 10;
				col = rand() % 10;
				game.check_computer_guess(row, col, game.getGameType() - 1);
				game.check_computer2_ships();
				if (!game.get_status(game.getGameType())) {
					cout << "Computer wins!\n";
					break;
				}
				row = rand() % 10;
				col = rand() % 10;
				game.check_computer_guess(row, col, game.getGameType());
				game.check_computer_ships();
				if (!game.get_status(game.getGameType())) {
					cout << "Computer2 wins!\n";
					break;
				}
			}
			else{    //Computer2 goes first.
				row = rand()%10;
				col = rand()%10;
				game.check_computer_guess(row, col, game.getGameType());
				game.check_computer_ships();
				if(!game.get_status(game.getGameType())){
					cout << "Computer2 wins!\n";
					break;
				}
				row = rand()%10;
				col = rand()%10;
				game.check_computer_guess(row, col, game.getGameType() - 1);
				game.check_computer2_ships();
				if(!game.get_status(game.getGameType())){
					cout << "Computer wins!\n";
					break;
				}
			}
		}
		return 0;
	}
}

/*Two player game.
   if(!game.get_status()){
		//Player wins.
		break;
   }
   else{
		cout << "Are you done with your move?";
		//Get yes or no here and then go to a blank screen and prompt for the next player
		//to begin their turn. This way, neither player sees the other players' board.
   }
*/
