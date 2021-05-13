#include "game.h"

#define uppLeftCor 188
#define lowRightCor 201
#define horizLine 205
#define uppRightCor 187
#define verticLine 186
#define lowLeftCor 200

void frame(COORD left,COORD right)
{
	
	COORD pos;
	SetConsoleCursorPosition(hout, right);
	printf("%c",uppLeftCor);
	SetConsoleCursorPosition(hout, left);
	printf("%c",lowRightCor);
	int i;
	for(i=1;i<(right.X-left.X);i++){
		printf("%c",horizLine);
	}
	printf ("%c",uppRightCor);
	pos=left;
	for(pos.Y++;pos.Y<right.Y ;pos.Y++){
		pos.X=left.X;
		SetConsoleCursorPosition(hout, pos);
		printf("%c",verticLine);
		pos.X=right.X;
		SetConsoleCursorPosition(hout, pos);
		printf("%c",verticLine);
	}
	pos.X=left.X;
	SetConsoleCursorPosition(hout, pos);
	printf("%c",lowLeftCor);
    for(i=1;i<(right.X-left.X);i++){
		printf("%c",horizLine);
	}
	SetConsoleCursorPosition(hout, left);
}
  
void cursorOff()
{
	CONSOLE_CURSOR_INFO structCursorInfo;	
	GetConsoleCursorInfo(hout,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hout, &structCursorInfo );
}

void gameInit()
{
	int x,y,i,j;
	srand(time(NULL));
	for(i=1; i<=15;){
		x=rand()%4;
		y=rand()%4;
		if(field[x][y] == 0){
		field[x][y] = i++;
		}
	}
	for(i=0; i<4; i++){	
		for(j=0; j<4; j++){
		
			if(field[j][i] == 0){
				emptyCell_x=j; emptyCell_y = i;
				return;
			}
		}
	}
}

void printField(COORD pos)
{
	int i,j;
    SetConsoleCursorPosition(hout,pos);
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(field[j][i]){
			printf("%3d", field[j][i]);
			}		
			else{
			printf(" _");
			}
		}
		pos.Y+=2; 
		SetConsoleCursorPosition(hout,pos);
	}
}

int notEndYet()
{
	int i,j,k=0,last[3];
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){		
			if(field[j][i] != 4*i+j+1){
			return 0;
			}
		}
	}
	for(j=0; j<4; j++){
	    if(field[j][i]!=0){
			last[k]=field[j][i];
			k++;
		}
		if(last[0]==13 && last[1]==14 && last[2]==15){
		return 1;
		}
	}
	return 0;
}

int gameMove()
{
	char c;
	while(1){
			c = getch();
			switch(c){
					case 'a':// move the empty cell left
							if(emptyCell_x==0){
								printf("This move is not possible.\n\n");
								break;
							}
							else{
								field[emptyCell_x][emptyCell_y] = field[emptyCell_x-1][emptyCell_y];
								field[emptyCell_x-1][emptyCell_y] = 0;
								emptyCell_x--;
								return 1;
							}
					case 'w':// move the empty cell up
							if(emptyCell_y==0){
								printf("This move is not possible.\n\n");
								break;
							}
							else{
								field[emptyCell_x][emptyCell_y] = field[emptyCell_x][emptyCell_y-1];
								field[emptyCell_x][emptyCell_y-1] = 0;
								emptyCell_y--;
								return 2;				
							}
					case 'd':// move the empty cell right
							if(emptyCell_x==3){
								printf("This move is not possible.\n\n");
								break;
							}
							else{
								field[emptyCell_x][emptyCell_y] = field[emptyCell_x+1][emptyCell_y];
								field[emptyCell_x+1][emptyCell_y] = 0;
								emptyCell_x++;
								return 3;
							}
					case 's':// move the empty cell down
							if(emptyCell_y==3){
								printf("This move is not possible.\n\n");
								break;
							}
							else{
								field[emptyCell_x][emptyCell_y] = field[emptyCell_x][emptyCell_y+1];
								field[emptyCell_x][emptyCell_y+1] = 0;
								emptyCell_y++;
								return 4;
							}
					case 'p': exit(1);
			
			}
	}
}

 
