// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR
//
// Section: 3
// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM    Location: SARAWAK (i.e. where are you currently located)
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR           Location: SELANGOR

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  15/4/2024    11:04        

// Video link:
//   _________


#include <iostream>
#include <string>

using namespace std;


class Subject 
{
	string name;
	string code;
	int score;
	
	public:
	//Parameterized constructor
	Subject(string name="", string code="", int score=0): name(name), code(code), score(score) {}

	//Default constructor
	Subject():name(""), code(""), score(0) {}

	//Destructor
	~Subject(){
		//Does nothing
	}

	//Accessors
	string getName() const {return name;}
	string getCode() const {return code;}
	int getScore() const {return score;}

	//Mutators
	void setName(string name){this->name=name;}
	void setCode(string code){this->code=code;}
	void setScore(int score){this->score-score;}
	
	//Method to determine the grade earned
	string determineGrade() const{
		
		if (score>89)
			return "A+";
		else if (score>79)
			return "A";
		else if (score>74)
			return "A-";
		else if (score>69)
			return "B+";
		else if (score>64)
			return "B";
		else if (score>59)
			return "B-";
		else if (score>54)
			return "C+";
		else if (score>49)
			return "C";
		else if (score>44)
			return "C-";
		else if (score>39)
			return "D+";
		else if (score>34)
			return "D";
		else if (score>29)
			return "D-";	
		else 
		return "E";									
	} 
	
	//Method to determine grade value
	float determineGradePoint() const{
		string grade=determineGrade();
		if (grade=="A+"||grade=="A")
		return 4.00;
		else if (grade=="A-")
		return 3.67;
		else if (grade=="B+")
		return 3.33;
		else if (grade=="B-")
		return 2.67;
		else if (grade=="C+")
		return 2.33;
		else if (grade=="C")
		return 2.00;
		else if (grade=="C-")
		return 1.67;
		else if (grade=="D+")
		return 1.33;
		else if (grade=="D")
		return 1.00;
		else if (grade=="D-")
		return 0.67;
		else 
		return 0.00;
	}

	//Method to determine point earned for the 
	float determinePoint(int creditHours) const{
		return determineGradePoint()*creditHours;
	}
};

int main()
{
	string name, code;
	int score;
	
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin, name);
	cout << endl;

	cout << "  Subject code => ";
	getline(cin, code);
	cout << endl;

	cout << "  Score earned => ";
	cin >> score;
	cout << endl;

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	Subject subject(name, code, score);

	cout << "Subject Code : " << subject.getCode() << endl;
	cout << "Subject Name : " << subject.getName() << endl;
	cout << "Credit Hour  : " << (subject.getCode().back()-'0') << endl; // assumming last character of code is the credit hour
	cout << "Score Earned : " << subject.getScore() <<endl;
	cout << "Grade Earned : " << subject.determineGrade() << endl;
	cout << "Grade Point  : " << subject.determineGradePoint() << endl;
	cout << "Point Earned : " << subject.determinePoint(subject.getCode().back()-'0') << endl;
	cout << endl;

	
	system("pause");

	return 0;
}
