// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR
//
// Section: 03
// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM   Location: UTM Johor 
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR          Location: UTM Johor 

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  23/4/2024    11:04         12:31           87 minutes
// Video link:
// https://drive.google.com/file/d/1D2wGX153EmC_vRA1G0mZCDGDqbsIOgiL/view?usp=drivesdk

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
    string name;
    string code;
    int score;

public:
    Subject();
    int credit() const;
    string grade() const;
    double point() const;
    void print() const;
    friend void readUserInput(Subject subjects[], int count);//friend function
    bool operator<(const Subject &other) const;//overloaded operator
};

// Accessor method to calculate point
double Subject::point() const
{
    // Calculate point based on grade
    if (grade() == "A+")
        return 4.00;
    else if (grade() == "A")
        return 4.00;
    else if (grade() == "A-")
        return 3.67;
    else if (grade() == "B+")
        return 3.33;
    else if (grade() == "B")
        return 3.00;
    else if (grade() == "B-")
        return 2.67;
    else if (grade() == "C+")
        return 2.33;
    else if (grade() == "C")
        return 2.00;
    else if (grade() == "C-")
        return 1.67;
    else if (grade() == "D+")
        return 1.33;
    else if (grade() == "D")
        return 1.00;
    else if (grade() == "D-")
        return 0.67;
    else
        return 0.00;
}

// Method to print subject information
void Subject::print() const
{
    cout << left << setw(15) << code;
    cout << left << setw(30) << name;
    cout << left << setw(10) << credit();
    cout << left << setw(10) << score;
    cout << left << setw(10) << grade();
    cout << left << setw(10) << setprecision(3) << point();
    cout << left << setw(10) << setprecision(3) << point() * credit();
    cout << endl;
}

// Overloaded '<' operator definition
bool Subject::operator<(const Subject &other) const
{
    return score < other.score;
}

// Define a regular function that determines the lower subject.
Subject lower(Subject a, Subject b){
    if (a < b)
    return a;
    else 
    return b;
}

int main()
{
    int subj, totalCredit = 0;
    double totalPoints = 0.0;
    cout << "How many subjects do you want to enter? =>  ";
    cin >> subj;

    Subject subjects[subj];
    readUserInput(subjects, subj);

    cout << endl << endl << "THE RESULT" << endl << endl;

    // Print the output table header
    cout << left << setw(15) << "Subject Code";
    cout << left << setw(30) << "Subject Name";
    cout << left << setw(10) << "Credit";
    cout << left << setw(10) << "Score";
    cout << left << setw(10) << "Grade";
    cout << left << setw(10) << "Point";
    cout << left << setw(10) << "Sub Total";
    cout << endl << endl;

   
    

    // Print subject information and calculate total points and credits
    for (int i = 0; i < subj; ++i)
    {
        subjects[i].print();
        totalPoints += subjects[i].point() * subjects[i].credit();
        totalCredit += subjects[i].credit();
    }

    // Print total points, credits, and GPA
    cout << endl;
    cout << "TOTAL POINT : " << totalPoints << endl;
    cout << "TOTAL CREDIT : " << totalCredit << endl;
    cout << "GPA : " << setprecision(3) << totalPoints / totalCredit << endl;

    // Find and print the lowest score subject
    cout << endl << "LOWEST SUBJECT : " << endl << endl;
    Subject lowest = subjects[0];
    for (int i = 1; i < subj; ++i)
    {
        lowest = lower(lowest, subjects[i]);
    }
    lowest.print();

    // Wait for user input before closing the console window
    cin.ignore();
    cin.get();

    return 0;
}

// Default constructor definition
Subject::Subject() : name(""), code(""), score(0) {}

// Accessor method to get credit
int Subject::credit() const { return code[7] - '0'; }

// Accessor method to get grade
string Subject::grade() const
{
    if (score >= 90)
        return "A+";
    if (score >= 80)
        return "A";
    if (score >= 75)
        return "A-";
    if (score >= 70)
        return "B+";
    if (score >= 65)
        return "B";
    if (score >= 60)
        return "B-";
    if (score >= 55)
        return "C+";
    if (score >= 50)
        return "C";
    if (score >= 45)
        return "C-";
    if (score >= 40)
        return "D+";
    if (score >= 35)
        return "D";
    if (score >= 30)
        return "D-";
    return "E";
}


// Function to read subjects from user input
//friend function
void readUserInput(Subject subjects[], int count)
{
    cin.ignore(); // Consume the newline character left in the input buffer

    for (int i = 0; i < count; ++i)
    {
        cout << "Enter info for subject #" << i + 1 << ":" << endl;
        cout << "Subject Code => ";
        cin >> subjects[i].code;

        cin.ignore(); // Consume the newline character left in the input buffer

        cout << "Subject name => ";
        getline(cin, subjects[i].name);

        cout << "Score earned => ";
        cin >> subjects[i].score;
    }
}