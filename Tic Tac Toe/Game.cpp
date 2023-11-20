#include <iostream>

using namespace std;

char space[3][3]={{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
int row, column;
char Token = 'x';
bool tie;
string p1, p2;


void func1(){
    
    
    cout<<"Enter name of first player:"<<endl;
    cin >> p1;
    cout<<"Enter name of second player: "<<endl;
    cin >> p2;
    cout<<p1<< " will start first as he/she is the first player"<<endl;
    cout<<p2<< " will start second as he/she is the second player"<<endl;
 
    cout<< "     |     |     "<<endl;
    cout<< " "<<space[0][0]<<"   | "<<space[0][1]<<"   | "<<space[0][2]<<endl;
    cout<< "_____|_____|_____"<<endl;
    cout<< "     |     |     "<<endl;
    cout<< " "<<space[1][0]<<"   | "<<space[1][1]<<"   | "<<space[1][2]<<endl;
    cout<< "_____|_____|_____"<<endl;
    cout<< "     |     |     "<<endl;
    cout<< " "<<space[2][0]<<"   | "<<space[2][1]<<"   | "<<space[2][2]<<endl;
    cout<< "     |     |     "<<endl;

}

void func2(){

    int digit;
    
    if (Token=='x'){
        cout<<p1<<"Enter the Game."<<endl;
        cin>>digit;

    }

    if (Token=='O'){
        cout<<p1<<"Enter the Game."<<endl;
        cin>>digit;
        }

        if (digit==1){
            row=0;
            column=0;

        }
        if (digit==2){
            row=0;
            column=1;
            
        }
        if (digit==3){
            row=0;
            column=2;
            
        }
        if (digit==4){
            row=1;
            column=0;
            
        }
        if (digit==5){
            row=1;
            column=1;
            
        }
        if (digit==6){
            row=1;
            column=2;
            
        }
        if (digit==7){
            row=2;
            column=0;
            
        }
        if (digit==8){
            row=2;
            column=1;
            
        }
        if (digit==9){
            row=2;
            column=2;
            
        }

        else if(digit<1 || digit>9){
            cout<<"ERROR: Invalid digit!"<<endl;
        }

    if (Token=='x' && space[row][column] != 'x' && space[row][column] != 'O'){
            space[row][column] = 'x';
            Token = 'O';
        }

     else if(Token=='x' && space[row][column] != 'x' && space[row][column] != 'O'){
            space[row][column] = 'O';
            Token = 'x';
        }

    else{
            cout<<"There is no empty space to plot the token!"<<endl; 
            func2();
        }
}

bool func3(){
    for (int i=0; i<3; i++){
        if (space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
        return true;
        }
        if (space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
            return true;
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){ 
            if (space[i][j] != 'x' && space[i][j] != 'O'){
                return false;
            }
        }
    }
    tie=true;
    return false;
    
}

int main(){
    while(!func3()){
        func1();
        func2();
        func3();
    }

    if (Token=='x' && tie == false){
        cout<<p2<<"WINS!!!"<<endl;
    }
    else if(Token=='O' && tie == false){
        cout<<p1<<"WINS!!!"<<endl;
    }
    else{
        cout<<"ITS A DRAW!!!"<<endl;
    }

}

