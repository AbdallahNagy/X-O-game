#include <iostream>
#include <conio.h>
using namespace std;

char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
string winner = " WINNER WINNER CHICKEN DINNER :)";
bool gameOver = false;
bool check;

void switchPlayer()
{
    if(player == 'X') player ='O';
    else player ='X';
}

void draw()
{
    system("cls");
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(i==5 || i==10 || j==5 || j==10) cout << "*";
            else{
                if(i==2 && j==2) cout << arr[0];
                else if(i==2 && j==8) cout << arr[1];
                else if(i==2 && j==13) cout << arr[2];
                else if(i==8 && j==2) cout << arr[3];
                else if(i==8 && j==8) cout << arr[4];
                else if(i==8 && j==13) cout << arr[5];
                else if(i==13 && j==2) cout << arr[6];
                else if(i==13 && j==8) cout << arr[7];
                else if(i==13 && j==13) cout << arr[8];
                else  cout << " ";
            }
        }
        cout <<endl;
    }

    cout << "ENTER PLAYER INPUT:";
}

void input()
{
    check = 0;
    if(_kbhit()){
        switch(_getch())
        {
            case '1': arr[0]=player;cout <<arr[0]; break;
            case '2': arr[1]=player;cout <<arr[1]; break;
            case '3': arr[2]=player;cout <<arr[2]; break;
            case '4': arr[3]=player;cout <<arr[3]; break;
            case '5': arr[4]=player;cout <<arr[4]; break;
            case '6': arr[5]=player;cout <<arr[5]; break;
            case '7': arr[6]=player;cout <<arr[6]; break;
            case '8': arr[7]=player;cout <<arr[7]; break;
            case '9': arr[8]=player;cout <<arr[8]; break;
            case 'q': gameOver=1; break;
            default :break;
        }
        check = 1;
        switchPlayer();
    }
}

void logic()
{
    if((arr[0]==arr[1] && arr[1]==arr[2])||(arr[3]==arr[4] && arr[4]==arr[5])||(arr[6]==arr[7] && arr[7]==arr[8])){
        cout<<winner;
        gameOver = 1;
    }
    else if((arr[0]==arr[3] && arr[3]==arr[6])||(arr[1]==arr[4] && arr[4]==arr[7])||(arr[2]==arr[5] && arr[5]==arr[8])){
     cout <<winner;
     gameOver = 1;
    }
    else if((arr[0]==arr[4] && arr[4]==arr[8])||(arr[2]==arr[4] && arr[4]==arr[6])){
    cout<<winner;
    gameOver = 1;
    }

    for(int x=0; x<9; x++){
        if(!arr[x]==x+1 ){
        cout << "ITS A DRAW!"<<endl;
        //gameOver = 1;
        //cout << "IF YOU WANT TO PLAY AGAIN PRESS 'Y'"<<endl;
        }
    }
}

int main()
{   draw();
    while(!gameOver){
        if(check)  draw();
        input();
        logic();
    }

    //system("pause");
    return 0;
}
