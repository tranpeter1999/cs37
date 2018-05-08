#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void arrRemove(int arr[], int &size, int index){
	for(int i = index; i < size; i++){
		arr[i] = arr[i+1];
	}
	size -= 1;
}

void arrPrint(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

void stringLower(char arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A')
            arr[i] = arr[i] + ('z' - 'Z');
    }
}

bool arrMatch(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    srand (time(NULL));

	int handValue = 0;
	int deckSize = 52;
	int deck[deckSize] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	char response[5];

    for(int i = 0; i < 2; i++){
        int index = rand()%52;
        handValue += deck[index];
        cout << "Drew " << deck[index] << endl;
        arrRemove(deck,deckSize,index);
    }

    cout << endl << endl << "Hand Value : " << handValue;

    while(handValue < 21){
        cout << "Hit or Stay?";
        cin >> response;

        cout << response;
        stringLower(response,5);
        cout << response;
    }

	return 0;
}
