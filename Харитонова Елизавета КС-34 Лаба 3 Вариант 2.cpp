#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#define N 65
#define DEF_DATE 1900
#define FULL_AGE 18
using namespace std;

struct User{

    string name;
    string firstname;
    string middlename;
    int date_of_birth;
    int age;
    int user_id;

};


string randomazing(){
    ostringstream temp;
    temp.str("");
    temp << 1 + rand() % N;
    return temp.str();
}

void personComputing(User *person, int n, int curdate){
    for(int i = 0; i < n; i++){
        (*(person + i)).age = curdate - person[i].date_of_birth;
    }
}


void structRandomizing(User *person, int n, int curdate){
    for (int i  = 0; i < n; i++){
        (*(person + i)).user_id = i + 1;
        (*(person + i)).name = "NAME" + randomazing();
        (*(person + i)).firstname = "FIRSTNAME" + randomazing();
        (*(person + i)).middlename = "MIDDLENAME" + randomazing();
        (*(person + i)).date_of_birth = (curdate-N) + rand()%(N - FULL_AGE);
    }
}

int GetDate(){
    time_t t;
    struct tm *nabor;
    time(&t);
    nabor = localtime(&t);
    return DEF_DATE + (nabor -> tm_year);

}

double GetMediumAge(User *person, int n){
    double tmp = 0;
    for(int i = 0; i < n; i++){
        tmp = tmp + (*(person + i)).age;
    }
    return tmp/n;

}

void PersonDisplay(User *person, int n){

    cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";

    cout << endl
        << left << setw(5) << "+" << left << setw(5)  << "ID"
        << left << setw(5) << "+" << left << setw(10) <<"NAME"
        << left << setw(5) << "+" << left << setw(15) << "FIRSTNAME"
        << left << setw(5) << "+" << left << setw(15) << "MIDDLENAME"
        << left << setw(5) << "+" << left << setw(5)  << "B.DATE"
        << left << setw(5) << "+" << left << setw(6)  << "AGE"
        << left << setw(1) << "+" ;

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";

    for(int i=0; i < n; i++){
        cout <<  endl
            << left << setw(5) << "+" << left << setw(5) << person[i].user_id
            << left << setw(5) << "+" << left << setw(10) << person[i].name
            << left << setw(5) << "+" << left << setw(15) << person[i].firstname
            << left << setw(5) << "+" << left << setw(15) << person[i].middlename
            << left << setw(5) << "+" << left << setw(5) << person[i].date_of_birth
            << left << setw(5) << "+" << left << setw(6) << person[i].age
            << left << setw(1) << "+" ;
    }

    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}



int main(){
    srand(time(0));

    User *person;
    int curdate = GetDate(), n = 0;

    while(true){

        cout << "\n\tAmount of person: ";
        cin >> n;

        if(cin.fail() || n < 2){

            cin.clear();
            cin.ignore(32767,'\n');

        }else{
            break;
        }
    };

    person = new User[n];

    structRandomizing((&person)[0], n, curdate);
    personComputing((&person)[0], n, curdate);


    PersonDisplay(person, n);

    cout << endl << endl << "Medium age of staff: " <<GetMediumAge((&person)[0], n) << endl;

    delete[] person;
    return 0;
}
