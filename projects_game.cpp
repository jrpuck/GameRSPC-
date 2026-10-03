#include<iostream>
#include<cmath>
using namespace std;


enum choice {Rock = 1, Paper=2,Scissors = 3};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}


int EnchoiceComputer(){
    return RandomNumber(1,3);
}

int ChoicePlayer(int &playerChoice){
    do{
        cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
        cin >> playerChoice;

    }while(playerChoice < 1 || playerChoice > 3);
    
    return playerChoice;
}

void Affichage(int rounds, int playerChoice, int computerChoice,int result){
    string choices[] = {"Rock", "Paper", "Scissors"};
    cout << "_______________________Round["<<rounds<<"]_____________________"<<endl ;
    cout << " Player chose  : " << choices[playerChoice - 1] <<endl;
    cout << " Computer chose: " << choices[computerChoice - 1] << endl;
    cout << " Result: ";
    if(result == 0){
        cout << "[No Winner]"<<endl;
    }else if(result == 1){
        cout << "[Player Wins]"<<endl;
    }else if(result == 2){
        cout << "[Computer Wins]"<<endl;   
    }
}

short int DetermineWinner(int playerChoice, int computerChoice){
    int result;
    if(playerChoice == computerChoice){
        result = 0;
    }else if((playerChoice == choice::Rock && computerChoice == Scissors) || 
             (playerChoice == Paper && computerChoice == Rock) || 
             (playerChoice == Scissors && computerChoice == Paper)){
        result = 1;
    }else{
        result = 2;

    }
    return result;
}

void EndAffichage(int rounds,int scorePlayer,int scoreComputer){
    cout << "_______________________Game Over_____________________"<<endl ;
    cout << " Total Rounds Played: " << rounds <<endl;
    cout << " Player Score  : " << scorePlayer <<endl;
    cout << " Computer Score: " << scoreComputer << endl;
    if(scorePlayer > scoreComputer){
        cout << "[Player Wins the Game]"<<endl;
    }else if(scorePlayer < scoreComputer){
        cout << "[Computer Wins the Game]"<<endl;   
    }else{
        cout <<"The result is : " << "[No Winner]"<<endl;
    }
}

void PlayGame(){
    char playAgain;
    short int totalRounds=0;
    int scorePlayer=0, scoreComputer=0;
    do{
    int rounds=0;
    system("color 0F");
    cout << "How many rounds do you want to play? ";
    cin >> rounds;
    for(int i = 0; i < rounds; i++){
        int playerChoice = ChoicePlayer(playerChoice);
        int computerChoice = EnchoiceComputer();
        short int result = DetermineWinner(playerChoice,computerChoice);
        Affichage(i+1,playerChoice,computerChoice,result);
        if(result == 1){
            scorePlayer++;
            system("color 0A");
        }else if(result == 2){
            scoreComputer++;
            system("color 0C");
        }else{
            system("color 0E");
        }
    }
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    totalRounds += rounds;
    if(playAgain == 'n' || playAgain == 'N'){
        EndAffichage(totalRounds,scorePlayer,scoreComputer);
    }

}while(playAgain == 'n' || playAgain == 'N');

}
int main(){
    srand((unsigned)time(NULL));
    PlayGame();
    return 0;
}



