// decoder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// decoder.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct message {
	int messageNum;
	string codedMessage;
	string decodedMessage;
};

int main(){
	string filename;
	char* ciperLine = new char[27];
	int numberOfMessages;

	int message_number = 0;

	// ask user to chose file to be opened
	// UNCOMMENT THIS SHIT
	// cout << "Enter a filename: " << endl;
	// cin >> filename;
	ifstream in_file;
	// in_file.open(filename);
	// DELETE THIS SHIT
	in_file.open("input1.txt");

	if (!in_file.is_open())	{
		cout << "Could not open file " << filename << endl;
		return 1;
	}	else	{
		// Pulls what each letter will be and places it into an array for access later
		for (int i = 0; i < 26; i++)		{
			string currCypherPair;
			getline(in_file, currCypherPair);
			ciperLine[i] = currCypherPair[4];
		}

		string number_of_message;
		getline(in_file, number_of_message);
		int numberOfMessages = atoi(number_of_message.c_str());

		message** messages = new message*[numberOfMessages]();

		for (int i = 0; i < numberOfMessages; i++) {
			// Iterate over each messages
			message* currMessage = new message();
			currMessage->messageNum = i;

			getline(in_file, currMessage->codedMessage);
			char* decodedMessage = new char[currMessage->codedMessage.length() + 1];
			cout << "WAT\n" << currMessage->codedMessage;

			// Decipher the message
			for (int j = 0; j < currMessage->codedMessage.length(); j++) {
				// Replace letter in string with actual value

				// Get the current letter and convert to upper
				char currLetter = toupper(currMessage->codedMessage[j]);

				// Get the ASCII value for that letter
				int intValue = int(currLetter);

				// If char is 65 <= 90; Replace
				if (intValue >= 65 && intValue <= 90) {
					char decodedChar = ciperLine[intValue - 65];
					decodedMessage[j] = decodedChar;
				}
				else {
					decodedMessage[j] = currLetter;
				}
			}

			cout << "WAT\n" << currMessage->codedMessage;

			currMessage->decodedMessage = decodedMessage;

			cout << "WAT\n" << currMessage->codedMessage;
			messages[i] = currMessage;
		}

		cout << endl << endl << endl;

		message* thing = messages[0];
		cout << thing->codedMessage << " ... \n" << thing->decodedMessage << endl;
		// cout << messages[1].codedMessage << " ... " << messages[1].decodedMessage << endl;
	}
	return 0;}
/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;





int main()
{
	string filename;
	string cipher_line[26];
	string temp_string;
	string number_of_message;
	
	


	// ask user to chose file to be opened
	cout << "Enter a filename: " << endl;
	cin >> filename;
	ifstream in_file;
	in_file.open(filename);

	if (!in_file.is_open())
	{
		cout << "Could not open file " << filename << endl;
		return 1;
	}

	else
	{

		// Pulls what each letter will be and places it into an array for access later
		for (int i = 0; i < 26; ++i)
		{
			getline(in_file, temp_string);
			cipher_line[i] = temp_string[4];
		}

		getchar(in_file)
		//getline(in_file, number_of_message);
		int message_value = stoi(number_of_message);
		

		
		struct messages
		{
			int messageNum;
			string codedMessage;
			string decodedMessage;
		};

		messages message_array[];

		
	}


	return 0;
}*/