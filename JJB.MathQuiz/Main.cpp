#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string filepathQuestions = "C:\\Temp\\QuizQuestions.txt";
	string filepathResults = "C:\\Temp\\QuizResults.txt";
	string question1;
	string question2;
	string question3;
	string answer1;
	string answer2;
	string answer3;
	srand(time(NULL));
	int randonNumber1 = 0;
	int randonNumber2 = 0;
	int randonNumber3 = 0;
	int currentline = 1;

	string line;

	ifstream ifs(filepathQuestions);

	while (getline(ifs, line))
	{
		currentline++;
	}

	randonNumber1 = rand() % currentline + 1;
	randonNumber2 = rand() % currentline + 1;
	randonNumber3 = rand() % currentline + 1;

	ifs.clear();
	ifs.seekg(0, ios::beg);

	currentline = 1;

	while (getline(ifs, line))
	{

		if (currentline == randonNumber1)
		{
			question1 = line;
		}
		if (currentline == randonNumber2)
		{
			question2 = line;
		}
		if (currentline == randonNumber3)
		{
			question3 = line;
		}

		currentline++;
	}

	cout << "Question 1: " << question1 << " = ";
	cin >> answer1;
	cout << "\n";
	cout << "Question 2: " << question2 << " = ";
	cin >> answer2;
	cout << "\n";
	cout << "Question 3: " << question3 << " = ";
	cin >> answer3;
	cout << "\n";

	ifs.close();

	ofstream ofs(filepathResults);

	ofs << question1 << " = " << answer1 << "\n";
	ofs << question2 << " = " << answer2 << "\n";
	ofs << question3 << " = " << answer3 << "\n";

	ofs.close();

	cout << "Answers saved to QuizResults.txt";

	(void)_getch;
	return 0;
}