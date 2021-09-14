#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int n = 0, m = 0, iterations = 0, sum = 0, temp = 0;
    const int UPPER_CONSTANT = 10;

    do{
        iterations = 0;
        while(true){

            cout << "Enter your number n: ";
            cin >> n;

            if(cin.fail() || n < 0){

                cin.clear();
                cin.ignore(32767,'\n');

            }else{
                break;
            }
        };


        while(true){

            cout << "Enter your number m: ";
            cin >> m;

            if(cin.fail() || n == 0){

                cin.clear();
                cin.ignore(32767,'\n');

            }else{
                break;
            }
        };


        do{
            sum = 0;
            iterations++;

            do{

                temp = 0 + rand() % (UPPER_CONSTANT + 1);
                sum = sum + temp;

            }while(sum < n);

            cout << "Total:\n" << sum << endl;

            if(iterations > 150){
                cout << "Maximum amount [500] iterations without result!\n" << endl;
                break;
            }
        }while(sum % m != 0);
    }while(sum % m != 0);
    cout << "Iterations:\n" << iterations << endl;

    return 0;
}
