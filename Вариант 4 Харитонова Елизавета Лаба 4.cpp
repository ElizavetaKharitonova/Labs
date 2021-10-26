#include <iostream>
#include <time.h>
#include <string>


using namespace std;


class myHero{

 const int LOWER_BOUND = 1;
 const int UPPER_BOUND = 30;

 double power;
 double price;
 string act = "";
 string hero_name = "";

 public:
  myHero(string act, string hero_name) : act(act), hero_name(hero_name){
    power = LOWER_BOUND + rand() % (UPPER_BOUND + 1);
    price = LOWER_BOUND + rand() % (UPPER_BOUND + 1);
  }

   action(){
    int c = 0;
    cout << "\n\tactions for " << hero_name << ":" << endl
         << "\t  1. pure power" << endl
         << "\t  2. price" << endl
         << "\t  3. pure dependence" << endl
         << "\t  4. actions" << endl
         << "\t  5. new values" << endl
         << "\t  6. exit\n\n\t";
     cin >> c;
     choice(c);
  }

  choice(int c){
    switch(c){
        case 1:
            cout << "\n\tpure power:\t" << power;
            action();
            break;
        case 2:
            cout << "\n\tprice:\t" << price;
            action();
            break;
        case 3:
            cout << "\n\tdependence:\t" << power/price;
            action();
            break;
        case 4:
            cout << "\n\tactions:\t" << act;
            action();
            break;
        case 5:
            new_values();
            action();
            break;
        case 6:
            cout << "\tGoodbye!\n";
            break;
        default:
            action();
            break;
      }
  }

  new_values(){
        int new_price = 0;
        while(true){

            cout << "Enter your new price: ";
            cin >> new_price;

            if(cin.fail() || new_price < 1){

                cin.clear();
                cin.ignore(32767,'\n');

            }else{
                break;
            }
        }

        power = power * new_price/price;
        price = new_price;

  }


  string getAct(){ return act; }

  ~myHero(){}
};

class myDruid : public myHero{

 public:

  myDruid() : myHero("Do damage", "druid"){}

  ~myDruid(){}
};


class myMonk : public myHero{

 public:

  myMonk(): myHero("Restore the strength points", "monk"){}

  ~myMonk(){}
};

int main()
{
    srand(time(0));

    myMonk *mn = new myMonk;
    myDruid *dr = new myDruid;
    int c = 0;

    for(;;){

        cout << "\n\n\t1. druid\n\t2. monk\n\tother: exit\n\n\t";
        cin >> c;

        if(c == 1){

           dr->action();

        }else if(c == 2){

           mn->action();

        }else{

           break;

        }
    }

    delete mn;
    delete dr;

    return 0;
}
