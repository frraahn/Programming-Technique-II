//? EXERCISE 4: ASSOCIATION

// Programming Technique II
                     
// Member 1's Name: DAYANG FARAH FARZANA BINTI ABANG IDHAM
// Member 2's Name: FARRA NURZAHIN BT ZAHARIL ANUAR

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  9/6          7:47 AM       8:23 AM        36   

// Video link:
// https://drive.google.com/drive/folders/1-5v0Ra9XdgKIxQhwtTDypZOrw8F4NvvO


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

class Polynomial
{
private:
    Term* terms;
    int numTerms;
public:
    Polynomial();
    ~Polynomial();
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
};

//----------------------------------------------------------------------------
int main()
{
    Polynomial polynom;
    polynom.input();
    
    cout << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++)
        cout << x << "  \t\t" << polynom.evaluate(x)<< endl;

    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e) {
    coef = c;
    exp = e;
}

int Term::exponent() const {
    return exp;
}

int Term::coefficient() const {
    return coef;
}

int Term::evaluate(int x) const {
   return coef*pow(x,exp);
}
//----------------------------------------------------------------------------

// class Polynomial
Polynomial::Polynomial() : terms(NULL), numTerms(0) {}

Polynomial::~Polynomial() {
    delete[] terms;
}

// Implement the constructor and the other methods of the class Polynomial
void Polynomial::input(){
    cout << "Enter a polynomial: \n";
    cout << setw(25) << "How many terms => ";
    cin >> numTerms;

    terms = new Term[numTerms];

    for(int i=0; i<numTerms; i++){
        int c, e;
        cout << setw(19) <<"Enter term #" << (i+1) << " (coef and exp) => ";
        cin >> c >> e;
        terms[i].set(c,e);  
    }
}

int Polynomial::evaluate(int x) const{
    int result=0;
    for (int i=0; i<numTerms; i++){
        result+=terms[i].evaluate(x);
    }
    return result;
}

Term Polynomial::largestTerm() const{
    Term largest=terms[0];
    for(int i=1; i<numTerms; ++i){
        if (terms[i].exponent() > largest.exponent())
        largest=terms[i];
    }
    return largest;
}

int Polynomial::degree() const{
    return largestTerm().exponent();
}

