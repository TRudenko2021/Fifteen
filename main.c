#include "game.h"

main()
{
		
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos1={0,0},pos2={45,15};// cell zero reset: two-field structure (x and y coordinates)

	SetConsoleTextAttribute(hout, 10);// set the color of the characters
	cursorOff();	
	frame(pos1,pos2);

	field = (int**)calloc(4, sizeof(int*));
	int i;
	for(i=0; i<4; i++){		
		field[i] = (int*)calloc(4, sizeof(int));	
	}

	do{
		gameInit();
	}while(notEndYet());
	
    pos1.X=1;
    pos1.Y=1;
    SetConsoleCursorPosition(hout,pos1);// setting the cursor to this position
	printf("       FIFTEEN");
	pos1.Y++;
    SetConsoleCursorPosition(hout,pos1);
	printf("To move an empty cell to the top, press W");
	pos1.Y++;
    SetConsoleCursorPosition(hout,pos1);
	printf("Down S");
	pos1.Y++;
    SetConsoleCursorPosition(hout,pos1);
	printf("To the left A");
	pos1.Y++;
    SetConsoleCursorPosition(hout,pos1);
	printf("Right D");
	pos1.Y++;
    SetConsoleCursorPosition(hout,pos1);
	printf("To exit the game press P");
    pos1.Y+=2;
	printField(pos1);

	while(!notEndYet()){
		gameMove();
		system("cls");// clear the screen
		printField(pos1);
	}
	printf("\n    YUO WON!\n");
	getch();	
}

