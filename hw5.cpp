#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Game
{
public:
	Game(const char *, const char *, float);
	//~Game();
	virtual void play();
	virtual void print();
	void calcBonus(){
		bonus = (balance * calcBonusPer()/100);
	}
	float getbalance(){
	return balance;}

protected:
	char *firstName, *lastName;
	int plays;
	float balance, bonus, initBalance;
	float calcBonusPer(){
	    if(balance < 0)
            return 0;
		if(balance <= 50)
			return 1.5;
		if(balance > 50 && balance <= 100)
			return 1.9;
		if(balance > 100 && balance <= 1000)
			return 2.5;
		return 2.9;
	}
};

void Game::play(){}
void Game::print(){}

Game::Game(const char *first, const char *last, float bal){
    firstName = new char[strlen(first)+1];
    strcpy(firstName,first);
    lastName = new char[strlen(last)+1];
    strcpy(lastName,last);
    balance = bal;
    initBalance = bal;
}

class MiniLotto:public Game
{
public:
  MiniLotto(const char *, const char *, float);
  void play();
  //void print();
};

MiniLotto::MiniLotto(const char *first, const char *last, float bal):Game(first,last,bal)
{
  //cout << "Welcome to MiniLotto! \n Please enter your full name: ";
  //getline(cin,name);
  cout << "How many games of MiniLotto would you like to play? ";
  cin >> plays;
}

void MiniLotto::play()
{
  int matches = 0;
  char pickOwn;
  int playerNums[5];
  int winningNums[5];
  for(int i = 0; i < plays; i++)
  {
    cout << "Starting MiniLotto Round" << endl;

    cout << "Would you like to pick your own numbers? (y/n) ";
    cin >> pickOwn;
    if(pickOwn == 'y')
    {
      cout << "Pick 5 distinct numbers from 1 to 35: ";
      for(int j = 0; j < 5; j++)
          cin >> playerNums[j];
    }
    else if(pickOwn == 'n')
    {
      cout << "Initiating Quick Pick.... " << endl;
      srand((unsigned)time(0));
      for(int k = 0; k < 5; k++)
      {
        playerNums[k] = rand()%35+1;
      }
    }
    cout << "Your numbers are ";
    for( int l = 0; l < 5; l++)
        cout << playerNums[l] << " ";
    cout << endl;

    cout << "The winning lotto numbers are..." << endl;
    for(int j = 0; j < 5; j++)
    {
      winningNums[j] = rand()%35+1;
      cout << winningNums[j] << " ";
    }
    cout << "Checking for  numbers..." << endl;
    for(int j = 0; j < 5; j++)
    {
      for(int k = 0; k < 5; k++)
      {
        if(playerNums[j] == winningNums[k])
          matches ++;
      }
    }
    cout << "You have " << matches << " numbers maatching." << endl;
    float winnings;
    if(matches == 3)
      winnings = 5;
    if(matches == 4)
      winnings = 1000;
    if(matches == 5)
      winnings = 250000;
    balance += winnings;
    cout << "You have won $" << winnings << " and your total winnings is now $" << initBalance-balance << endl << endl;
  }
}

class Blackjack:public Game{
public:
	Blackjack(const char *, const char *, float);
	~Blackjack();
	void play();
	void print();
};

Blackjack::Blackjack(const char *first, const char *last, float bal):Game(first,last,bal){
	cout << "How many times would you like to play Blackjack? ";
	cin >> plays;
}

void arrRemove(int arr[], int &size, int index){
	for(int i = index; i < size; i++){
		arr[i] = arr[i+1];
	}
	size -= 1;
}

void handPrint(int arr[],int size){
    if(size == 2)
        cout << arr[0] << " and " << arr[1];
    else{
        for(int i = 0; i < size; i++){
            if(i == size-1)
                cout << "and " << arr[i] << "";
            else
                cout << arr[i] << ", ";
        }
    }
}

void stringLower(char arr[]){
    for(int i = 0; i < sizeof(arr); i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A')
            arr[i] = arr[i] + ('z' - 'Z');
    }
}

bool stringMatch(char arr1[], char arr2[], int size){
    if(sizeof(arr1) < size)
        size = sizeof(arr1)+1;
    if(sizeof(arr2) < size)
        size = sizeof(arr2)+1;

    for(int i = 0; i < size; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }

    return true;
}

int handCalc(int arr[1],int size){
    int sum = 0;
    int ace = 0;

    for(int i = 0; i < size; i++){
        int val = arr[i];
        if(val == 1){
            val = 11;
            ace = 1;
        }
        sum += val;
    }

    while(ace >= 1 && ace <= 4 && sum > 21){
        sum = 0;
        int tempAceCount = 0;

        for(int i = 0; i < size; i++){
            int val = arr[i];
            if(val == 1){
                if(tempAceCount >= ace)
                    val = 11;
                tempAceCount++;
            }
            sum += val;
        }

        ace++;
    }

    return sum;
}

void Blackjack::play(){
	for(int play = 0; play < plays; play++){
		srand (time(NULL));

		float bet = 0;
		int hand[10];
		int handIndex = 0;
		int dealerHand[10];
		int dealerHandIndex = 0;
		int deckSize = 52;
		int deck[deckSize] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
		int action = 0; // 0 = nil action, 1 = hit, 2 = stay;
		int dealerAction = 0; // 0 = nil action, 1 = aggressive, 2 = defensive, 3 = call bluff;
		char response[10];

		while(bet <= 0){
			cout << "How much would you like to bet? (You have $" << balance << ")  ";
			cin >> bet;
		}

		balance -= bet;

		for(int i = 0; i < 2; i++){
			//dealer draws 1 card face up, and 1 card face down
			int index = rand()%deckSize;
			dealerHand[dealerHandIndex] = deck[index];
			dealerHandIndex++;
			if(i == 0)
				cout << "Dealer Drew " << deck[index] << " and a face down card" << endl;
			arrRemove(deck,deckSize,index);
			//player draws 2 starting cards
			index = rand()%deckSize;
			hand[handIndex] = deck[index];
			handIndex++;
			cout << "Drew " << deck[index] << endl;
			arrRemove(deck,deckSize,index);
		}

		cout << "Your hand is "; handPrint(hand,handIndex); cout << " which adds up to " << handCalc(hand,handIndex) << endl;

		//player chooses action as long as they aren't over 20
		while(handCalc(hand,handIndex) < 21 && action != 2){
			cout << "Hit or Stay?" << endl;
			cin >> response;

			stringLower(response);

			if(stringMatch(response,"hit",3)){
				action = 1;
				int index = rand()%deckSize;
				hand[handIndex] = deck[index];
				handIndex++;
				cout << "Drew " << deck[index] << endl << "Your hand is "; handPrint(hand,handIndex); cout << " which adds up to " << handCalc(hand,handIndex) << endl;
				arrRemove(deck,deckSize,index);
			}
			else if(stringMatch(response,"stay",4)){
				action = 2;
			}
		}

		if(handCalc(hand,handIndex) > 21)
			cout << "You bust!" << endl << "You lose $" << bet << endl;
		else if(handCalc(hand,handIndex) == 21 && handIndex == 2){
			cout << "Blackjack, you win!" << endl << "You win $" << bet*2 << endl;
			balance += bet*2;
		}
		else{
			while(!stringMatch(response,"smile",5) && !stringMatch(response,"bluff",5) && !stringMatch(response,"poker",5)){
				cout << "Choose an action (smile, bluff, poker)" << endl;
				cin >> response;

				stringLower(response);
			}

			if(stringMatch(response,"smile",5)){
				dealerAction = rand()%10; //the ai's brain is random

				if(dealerAction < 6){
					dealerAction = 1; //user smiled, go aggressive because dealer is nervous
					cout << "The dealer looks a little nervous" << endl;
				}g = new MiniLotto(first,last,balance);

    g->play();
	g->calcBonus();
	g->print();
	
	balance = g->getbalance();
				else if(dealerAction < 9){
					dealerAction = 2; //user smiled, go defensive in case they're smiling with reason
					cout << "The dealer looks at you with shifty eyes" << endl;
				}
				else{
					dealerAction = 3; //user smiled, let's go for that 1 in 10 bluff!
					cout << "The dealer tries to call your bluff!" << endl;
				}
			}
			else if(stringMatch(response,"bluff",5)){
				dealerAction = rand()%10; //the ai's brain is random

				if(dealerAction < 5){
					dealerAction = 3; //call that bluff!
					cout << "The dealer tries to call your bluff!" << endl;
				}
				else if(dealerAction < 8){
					dealerAction = 2; //scared of buff...
					cout << "The dealer seems scared of your hand" << endl;
				}
				else{
					dealerAction = 1; //GO BIG OR GO HOME!
					cout << "The dealer decides to draw aggressively" << endl;
				}
			}
			else if(stringMatch(response,"poker",5)){
				dealerAction = rand()%3; //randomly choose one of 3 choices

				if(dealerAction == 1){
					dealerAction = 1;
					cout << "The dealer decides to draw aggressively" << endl;
				}
				else if(dealerAction == 2){
					dealerAction = 2;
					cout << "The dealer decides to draw defensively" << endl;
				}
				else{
					dealerAction = 3;
					cout << "The dealer decides your poker face isn't good enough and calls your bluff" << endl;
				}
			}

			if(dealerAction == 1){ // aggressive, draw if less than 21
				while(handCalc(dealerHand,dealerHandIndex) < 19){
					int index = rand()%deckSize;
					dealerHand[dealerHandIndex] = deck[index];
					dealerHandIndex++;
					cout << "Dealer Drew " << deck[index] << endl;
					arrRemove(deck,deckSize,index);
				}
			}
			else if(dealerAction == 2){ // defensive, draw if less than 18
				while(handCalc(dealerHand,dealerHandIndex) < 16){
					int index = rand()%deckSize;
					dealerHand[dealerHandIndex] = deck[index];
					dealerHandIndex++;
					cout << "Dealer Drew " << deck[index] << endl;
					arrRemove(deck,deckSize,index);
				}
			}
			else{ // call bluff, the most dangerous option... somehow dealer knows how much player has...
				while(handCalc(dealerHand,dealerHandIndex) < 16 || handCalc(dealerHand,dealerHandIndex) <= handCalc(hand,handIndex)){
					int index = rand()%deckSize;
					dealerHand[dealerHandIndex] = deck[index];
					dealerHandIndex++;
					cout << "Dealer Drew " << deck[index] << endl;
					arrRemove(deck,deckSize,index);
				}
			}

			cout << "Your hand is "; handPrint(hand,handIndex); cout << " which adds up to " << handCalc(hand,handIndex) << endl;
			cout << "Dealer hand is "; handPrint(dealerHand,dealerHandIndex); cout << " which adds up to " << handCalc(dealerHand,dealerHandIndex) << endl;

			if(handCalc(dealerHand,dealerHandIndex) > 21){
				cout << "Dealer Bust!" << endl << "You win $" << bet*2 << endl;
				balance += bet*2;
			}
			else if(handCalc(hand,handIndex) > handCalc(dealerHand,dealerHandIndex)){
				cout << "You win!" << endl << "You win $" << bet*2 << endl;
				balance += bet*2;
			}
			else if(handCalc(hand,handIndex) == handCalc(dealerHand,dealerHandIndex)){
				cout << "Tie; push game" << endl << "You get your $" << bet << " back" << endl;
				balance += bet;
			}
			else{
				cout << "You lose!" << endl << "You lose $" << bet << endl;
			}
		}
	}
}

void Blackjack::print(){
	cout << "Final Results for " << firstName << " " << lastName << " after " << plays << " games of Blackjack:" << endl;
	cout << firstName << " " << lastName << " won a total of $" << balance-initBalance << endl;
	cout << "The casino will add a bonus of " << this->calcBonusPer() << "% to your winnings" << endl;
	cout << "The casino bonus is " << bonus << endl;
	cout << firstName << " " << lastName << " total winnings are $" << balance-initBalance + bonus << endl;
}

int main(){
    cout << fixed << showpoint << setprecision(2);

    char first[10], last[10];
    float balance;

    cout << "What is your first name? ";
    cin >> first;
    cout << "What is your last name? ";
    cin >> last;
    cout << "How much money do you have? ";
    cin >> balance;

	Game *g;
	g = new Blackjack(first,last,balance);

	g->play();
	g->calcBonus();
	g->print();

	balance = g->getbalance();

    g = new MiniLotto(first,last,balance);

    g->play();
	g->calcBonus();
	g->print();

	balance = g->getbalance();

	return 0;
}
