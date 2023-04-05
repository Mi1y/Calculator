#include <iostream>
#include <stdexcept>
#include <limits>
#include <math.h>

using namespace std;

class Calculator
{

float a,b;

public:

    void result(){
    cout << "Wpisz pierwsza liczbe" << endl;
    cin >> a;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("To nie jest poprawne");
        }

    cout << "Wpisz druga liczbe" << endl;
    cin >> b;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("To nie jest poprawne");
        }
    }

    void result2(){
    cout << "Wpisz pierwsza liczbe" << endl;
    cin >> a;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("To nie jest poprawne");
        }
    }

template<typename T>
void check_overflow(T result) {
    if (result >numeric_limits<T>::max()) {
        throw overflow_error("przepelnienie wartosci");
    }
}

    float dodawanie(){
    float result = a + b;
    check_overflow(result);
    return result;
    }

    float odejmowanie(){
    float result = a - b;
    check_overflow(result);
    return result;
    }

    float mnozenie(){
    float result = a * b;
    check_overflow(result);
    return result;
    }

    float dzielenie()
    {
        if (a == 0 || b == 0){
            throw invalid_argument ("Nie wolno dzielic przez zero");
        return 0;
        }

        else {
            return a/b;
            }
    }
    float potegowanie(){
    float result = pow(a,b);
    check_overflow(result);
    return result;
    }

    float pierwiastkowanie(){
        if (a<0){
            cout <<"Nie mozna pierwiastkowac ujemne liczby" << endl;
            return 0;
        }
        else
            return sqrt(a);
    }
};

using namespace std;
int main()
{
    char wybor;
    Calculator calculator;
  cout << "Kalkulator: " << endl;
  cout <<" 1 - dodawanie" << endl;
  cout <<" 2 - odejmowanie" << endl;
  cout <<" 3 - mnozenie" << endl;
  cout <<" 4 - dzielenie" << endl;
  cout <<" 5 - potegowanie" << endl;
  cout <<" 6 - pierwiastkowanie" << endl;
do{
    try{
    cin >> wybor;
switch (wybor){
case '1':{
    calculator.result();
    cout << "Wynik to: " << calculator.dodawanie() << endl;
    break;
    }
case '2':{
    calculator.result();
    cout << "Wynik to: " << calculator.odejmowanie() << endl;
    break;
    }
case '3':{
    calculator.result();
    cout << "Wynik to: " << calculator.mnozenie() << endl;
    break;
    }
case '4':{
    calculator.result();
    cout << "Wynik to: " << calculator.dzielenie() << endl;
    break;
    }
case '5':{
    calculator.result();
    cout << "Wynik to: " << calculator.potegowanie() << endl;
    break;
    }
case '6':{
    calculator.result2();
    cout << "Wynik to: " << calculator.pierwiastkowanie() << endl;
    break;
    }
        }
    }

    catch (const exception& e) {
        cerr << "Blad: " << e.what() << endl;
    }
}
while (wybor >=1 && wybor <=6);
return 0;
}
