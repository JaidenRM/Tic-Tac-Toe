/*declred library*/
#include <stdio.h>
#include <stdlib.h>

/*defined constants*/
#define TRUE 1
#define COLS 7
#define DIV "==================="

/*declared functions*/
void xPlace(char array[][COLS]);
void boardMoveX(int *rows, int *columns, int *coordX, int *coordY, char array[]
[*columns]);
void oPlace(char array[][COLS]);
void boardMoveO(int *rows, int *columns, int *coordX, int *coordY, char array[]
[*columns]);
void makeBoard(char board[][COLS]);
char takeTurns(char array[][COLS]);
void stateDraw(char array[][COLS]);
void xWins(char array[][COLS]);
void oWins(char array[][COLS]);

/*putting everything together
*/
int main(int argc, char *argv[]) {
	char board[3][7];
	makeBoard(board);
	takeTurns(board);
	return 0;
}

/*keeps asking for input until game is over
*/
char takeTurns(char board[][COLS]){ 
	int i= TRUE; 
	while(i == TRUE) {
		xPlace(board);
		xWins(board);
		stateDraw(board);
		oPlace(board);
		oWins(board);
	}
}

/* checks to see if X has won
*/
void xWins(char board[][COLS]) {
	int rows, columns;
	int count = 0;
	for(rows=0;rows<3;rows++) {
		for(columns=1;columns<7;columns+=2) {
			if(board[rows][columns]=='X') {	
				count+=1;
			}
		}
		if(count==3) {
			printf("Game over, X wins!");
			exit(EXIT_FAILURE);
		}
		else if(board[0][1]=='X' && board[1][3]=='X' && board[2][5]=='X' || 
		board[0][5]=='X' && board[1][3]=='X' && board[2][1]=='X') {
			printf("Game over, X wins!");
			exit(EXIT_FAILURE);
		}
		else {
			count=0;
		}
	}
	for(columns=1;columns<7;columns+=2) {
		for(rows=0;rows<3;rows++) {
			if(board[rows][columns]=='X') {	
				count+=1;
			}
		}
		if(count==3) {
			printf("Game over, X wins!");
			exit(EXIT_FAILURE);
		}
		else if(board[0][1]=='X' && board[1][3]=='X' && board[2][5]=='X' || 
		board[0][5]=='X' && board[1][3]=='X' && board[2][1]=='X') {
			printf("Game over, X wins!");
			exit(EXIT_FAILURE);
		}
		else {
			count=0;
		}
	}
}

/* checks to see if O has won
*/
void oWins(char board[][COLS]) {
	int rows, columns;
	int count = 0;
	for(rows=0;rows<3;rows++) {
		for(columns=1;columns<7;columns+=2) {
			if(board[rows][columns]=='O') {	
				count+=1;
			}
		}
		if(count==3) {
			printf("Game over, O wins!");
			exit(EXIT_FAILURE);
		}
		else if(board[0][1]=='O' && board[1][3]=='O' && board[2][5]=='O' || 
		board[0][5]=='O' && board[1][3]=='O' && board[2][1]=='O') {
			printf("Game over, O wins!");
			exit(EXIT_FAILURE);
		}
		else {
			count=0;
		}
	}
	for(columns=1;columns<7;columns+=2) {
		for(rows=0;rows<3;rows++) {
			if(board[rows][columns]=='O') {	
				count+=1;
			}
		}
		if(count==3) {
			printf("Game over, O wins!");
			exit(EXIT_FAILURE);
		}
		else if(board[0][1]=='O' && board[1][3]=='O' && board[2][5]=='O' || 
		board[0][5]=='O' && board[1][3]=='O' && board[2][1]=='O') {
			printf("Game over, O wins!");
			exit(EXIT_FAILURE);
		}
		else {
			count=0;
		}
	}
}


/*asks for x legal coords
*/
void xPlace(char board[][COLS]) {
	int x, y, x1, y1, comma;
	printf("Enter x,y coordinates (1-3) on the grid to place an 'X': ");
	scanf("%d%c%d", &x, &comma, &y);
	x1 = x;
	y1 = y;
	if(x==1 || x==2 || x ==3 && y==1 || y==2 || y==3) {
		x = x - 1;
		if(y==2) {
			y+=1;
		}
		else if(y==3) {
			y+=2;
		}
		if(board[x][y] == ' ') {
			boardMoveX(&x, &y, &x1, &y1, board);
		}
		else {
			printf("Sorry, that spot is already taken. Please choose one that");
			printf("isn't already taken. \n\n");
			xPlace(board);
		}
	}
	else {
		printf("Sorry, that's not a valid input. Please try again Player 1.");
		printf("\n\n");
		xPlace(board);
	}
}

/*places x on board
*/
void boardMoveX(int *x, int *y, int *x1, int *y1, char board[][COLS]) {
	int rows, columns;
	board[*x][*y] = 'X';
	printf("%s%s%s\n", DIV, DIV, DIV);
	printf("      y\n");
	printf("    1 2 3\n");
	for(rows=0;rows<3;rows++) {
		if(rows==1) {
			printf("%c", 'x');
			printf(" %d", rows+1);
		}
		else {
			printf("  %d", rows+1);
		}
		for(columns=0;columns<7;columns++) {
			printf("%c", board[rows][columns]);
		}
		printf("\n");
	}
	printf("\nThe coordinates you entered were %d, %d.\n", *x1, *y1);
}

/*asks for legal o coords
*/
void oPlace(char board[][COLS]) {
	int x, y, x1, y1, comma;
	printf("Enter x,y coordinates (1-3) on the grid to place an 'O': ");
	scanf("%d%c%d", &x, &comma, &y);
	x1 = x;
	y1 = y;
	if(x==1 || x==2 || x ==3 && y==1 || y==2 || y==3) {
		x = x - 1;
		if(y==2) {
			y+=1;
		}
		else if(y==3) {
			y+=2;
		}
		if(board[x][y] == ' ') {
			boardMoveO(&x, &y, &x1, &y1, board);
		}
		else {
			printf("Sorry, that spot is already taken. Please choose one that");
			printf("isn't already taken. \n\n");
			oPlace(board);
		}
	}
	else {
		printf("Sorry, that's not a valid input. Please try again Player 2.");
		printf("\n\n");
		oPlace(board);
	}
}

/*places o on the board
*/
void boardMoveO(int *x, int *y, int *x1, int *y1, char board[][COLS]) {
	int rows, columns;
	board[*x][*y] = 'O';
	printf("%s%s%s\n", DIV, DIV, DIV);
	printf("      y\n");
	printf("    1 2 3\n");
	for(rows=0;rows<3;rows++) {
		if(rows==1) {
			printf("%c", 'x');
			printf(" %d", rows+1);
		}
		else {
			printf("  %d", rows+1);
		}
		for(columns=0;columns<7;columns++) {
			printf("%c", board[rows][columns]);
		}
		printf("\n");
	}
	printf("\nThe coordinates you entered were %d, %d.\n", *x1, *y1);
}

/*draws the board
*/
void makeBoard(char board[][COLS]) {
	int rows, columns;
	printf("      y\n");
	printf("    1 2 3\n");
	for(rows=0;rows<3;rows++) {
		for(columns=0;columns<7;columns=columns+2) {
			board[rows][columns] = '|';
		}
	}
	for(rows=0;rows<3;rows++) {
		for(columns=1;columns<7;columns=columns+2) {
			board[rows][columns] = ' ';
		}
	}
	for(rows=0;rows<3;rows++) {
		if(rows==1) {
			printf("%c", 'x');
			printf(" %d", rows+1);
		}
		else {
			printf("  %d", rows+1);
		}
		for(columns=0;columns<7;columns++) {
			printf("%c", board[rows][columns]);
		}
		printf("\n");
	}
}

/*checks for a draw
*/
void stateDraw(char board[][COLS]) {
	int rows, columns;
	int count = 0;
	for(rows=0;rows<3;rows++) {
		for(columns=1;columns<7;columns+=2) {
			if(board[rows][columns]==' ') {	
				count+=1;
			}
		}
	}
	if(count == 0) {
		printf("Boring. It's a draw.\n");
		exit(EXIT_FAILURE);
	}
}

/* =============================
2p tic tac toe written by 
Jaiden Muscat on April 2017
   ============================= */