#include <stdio.h> //evening niggaz, I'm gonna fill the code up with comments to help you understand what's going on
char matrix[3][3] = {{ ' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}}; //so here I defined the matrix that's gonna hold the values, I defined it here so its preceding the function below for the function to work
int winCheck () { //I just need it to return a number to signal that the game is over
if (
        ((matrix[0][0] == 'X' || matrix[0][0] == 'O') && (matrix[0][0]==matrix[0][1]) && (matrix[0][2]==matrix[0][1])) || //first I had to make sure it's verifying for X's and O's then it would check if all elements of the same row are equal
        ((matrix[1][0] == 'X' || matrix[1][0] == 'O') && (matrix[1][0]==matrix[1][1]) && (matrix[1][2]==matrix[1][1])) || //here it checks by rows
        ((matrix[2][0] == 'X' || matrix[2][0] == 'O') && (matrix[2][0]==matrix[2][1]) && (matrix[2][2]==matrix[2][1])) ||

        ((matrix[0][0] == 'X' || matrix[0][0] == 'O') && (matrix[0][0]==matrix[1][0]) && (matrix[2][0]==matrix[1][0])) ||
        ((matrix[0][1] == 'X' || matrix[0][1] == 'O') && (matrix[0][1]==matrix[1][1]) && (matrix[2][1]==matrix[1][1])) ||//here it checks by columns
        ((matrix[0][2] == 'X' || matrix[0][2] == 'O') && (matrix[0][2]==matrix[1][2]) && (matrix[2][2]==matrix[1][2])) ||

        ((matrix[0][0] == 'X' || matrix[0][0] == 'O') && (matrix[0][0]==matrix[1][1]) && (matrix[2][2]==matrix[1][1])) || //here diagonally
        ((matrix[0][2] == 'X' || matrix[0][2] == 'O') && (matrix[0][2]==matrix[1][1]) && (matrix[2][0]==matrix[1][1])) ||

        (matrix[0][0] != ' ' && matrix[0][1] != ' ' && matrix[0][2] != ' ' && matrix[1][0] != ' ' && matrix[1][1] != ' ' && //here it checks whether the board is full or not
        matrix[1][2] != ' ' && matrix[2][0] != ' ' && matrix[2][1] != ' ' && matrix[2][2] != ' ')

    ) {return 1;} //I chose 1 randomly, just needed it to return a value so I can break;
}
int main () {
while (2) { //the while (2) gonna help me for the replay
int i=0,j,k;
for (j=0;j<3;j++) {
    for (k=0;k<3;k++) {
        matrix[j][k] = ' ';  //basically resets the board
    }
}
system("cls");

while (1) { //here the game starts
printf("\n\t\t\t\t\t\t %c | %c | %c",matrix[0][0],matrix[0][1],matrix[0][2]);
printf("\n\t\t\t\t\t\t ---------");
printf("\n\t\t\t\t\t\t %c | %c | %c",matrix[1][0],matrix[1][1],matrix[1][2]);  //just the UI, pretty straight forward
printf("\n\t\t\t\t\t\t ---------");
printf("\n\t\t\t\t\t\t %c | %c | %c",matrix[2][0],matrix[2][1],matrix[2][2]);
printf("\n\n");
printf("\n                      7    8    9\nChoose yo move :      4    5    6"); if (i%2==0) {printf("\tPlayer X");} else printf("\tPlayer O"); //used the modulo with an incrementing digit i to track the turns of the players
printf("\n                      1    2    3");
printf("\n\n");
if (winCheck()==1) { //I made it check for a win right after updating the board
    printf("\n\n\nGame over");
    printf("\n\n\n\t\tWould you like to restart?");
    getch();
    break; //takes to while (2) where it resets the board
};
wrongMove:; //incase the case is full, the program will get back here
int trans;
scanf("%d",&trans); ://trans as in translation, just a number to help track the move on the board
if (i%2==0) { //since i starts with 0, X always starts, too lazy to make a function where the winner starts lol
switch (trans) {
case 1: if(matrix[2][0]!=' ')goto wrongMove;matrix[2][0] = 'X'; break;
case 2: if(matrix[2][1]!=' ')goto wrongMove;matrix[2][1] = 'X'; break; //pretty straight forward, links the trans (1-9) with the matrix and checks if the board is empty beforehand
case 3: if(matrix[2][2]!=' ')goto wrongMove;matrix[2][2] = 'X'; break;
case 4: if(matrix[1][0]!=' ')goto wrongMove;matrix[1][0] = 'X'; break;
case 5: if(matrix[1][1]!=' ')goto wrongMove;matrix[1][1] = 'X'; break;
case 6: if(matrix[1][2]!=' ')goto wrongMove;matrix[1][2] = 'X'; break;
case 7: if(matrix[0][0]!=' ')goto wrongMove;matrix[0][0] = 'X'; break;
case 8: if(matrix[0][1]!=' ')goto wrongMove;matrix[0][1] = 'X'; break;
case 9: if(matrix[0][2]!=' ')goto wrongMove;matrix[0][2] = 'X'; break;
default: goto wrongMove;;
}} else {
switch (trans) { //here it works with the O's
case 1: if(matrix[2][0]!=' ')goto wrongMove;matrix[2][0] = 'O'; break;
case 2: if(matrix[2][1]!=' ')goto wrongMove;matrix[2][1] = 'O'; break;
case 3: if(matrix[2][2]!=' ')goto wrongMove;matrix[2][2] = 'O'; break;
case 4: if(matrix[1][0]!=' ')goto wrongMove;matrix[1][0] = 'O'; break;
case 5: if(matrix[1][1]!=' ')goto wrongMove;matrix[1][1] = 'O'; break;
case 6: if(matrix[1][2]!=' ')goto wrongMove;matrix[1][2] = 'O'; break;
case 7: if(matrix[0][0]!=' ')goto wrongMove;matrix[0][0] = 'O'; break;
case 8: if(matrix[0][1]!=' ')goto wrongMove;matrix[0][1] = 'O'; break;
case 9: if(matrix[0][2]!=' ')goto wrongMove;matrix[0][2] = 'O'; break;
default: goto wrongMove;
}}
i++; //this incrementation is the one that gets the player moves going
system("cls"); //decided to update the screen at the end cuz it's better this way ig
}
} //takes to while (2) after leaving while (1) in the case where the game ends
}
