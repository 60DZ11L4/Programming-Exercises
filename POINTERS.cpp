/************************************************
*						*
*	Dynamic Matrix with Pointers		*
*		Fill - Search			*
*						*
************************************************/

#include	<iostream>
#include	<string>
#include	<cstring>
#include	<stdio.h>

using namespace std;

int	columns	= 2;
int	rows;

string	entry;
string	**matrix_pointer;
string	Title;
string	Author;
string	search;


void	intro();
void	requestData();
void	showData(string **);
void	deleteData(string **);

int main(){
	intro();
	requestData();
	showData(matrix_pointer);
	deleteData(matrix_pointer);
	return 0;
}


void intro(){
	system("clear");
	cout << "\n\n\t\t__________________________" << endl;
	cout << "\t\t< Welcome to Linux Library >" << endl;
	cout << "\t\t**************************" << endl;
}

void requestData(){
	cout << "\n\a\tHow may books do you want to register?: ";
	getline(cin, entry);
	rows = stoi(entry);
	matrix_pointer = new string *[rows];

	for(int i = 0; i < rows; i++){
		matrix_pointer[i] = new string[columns];

		cout << "\n\t\t________ Book " << i + 1 << " ________\n"<< endl;
		cout << "\tTitle:\t ";
		getline(cin, Title);

		cout << "\tAuthor:\t ";
		getline(cin, Author);

		matrix_pointer[i][0] = Title;
		matrix_pointer[i][1] = Author;
	}
}

void showData(string **matrix_pointer){
	int counter = 0;
	cout << "\n\n\n\n\t**** Enter the information to your search ****"<< endl;
	cout << "\n\tSearch by Title: ";
	getline(cin, search);

	for (int i = 0; i < rows; i++){
		Title	=	matrix_pointer[i][0];
		Author 	=	matrix_pointer[i][1];
		if (strcasecmp(Title.c_str(), search.c_str()) == 0){
			counter++;
			cout << "\n\a\t[Book found! Title: " << Title << "  Author: " << Author << "]\n\n" << endl;
		}
	}
	if (counter == 0){
		cout << "\n\a\t[Book dont found in database, exiting...]\n\n" << endl;
	}
}

void deleteData(string **matrix_pointer){
	for(int i = 0; i < rows; ++i){
		delete[] matrix_pointer[i];
	}
	delete[] matrix_pointer;
}
