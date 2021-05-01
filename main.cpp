//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>

using namespace std; 
#include "Input_Validation_Extended.h"



class MenuItem
{
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count; 
  public:
    MenuItem(){
      count = 0;
    }

    string getName () const {
      return name;
    }
    double getCost () const {
      return itemCost;
    }
    string getDesc () const {
      return desc;
    }
    char getAL () const {
      return addLetter;
    }
    char getRL () const {
      return removeLetter;
    }
    int getCount () const {
      return count;
    }
    void addCount(){
      count++;
    }
    void removeCount(){
      count --;
    }

    void setName(string n){
      name = n;
    }
    void setCost (double c){
      itemCost = c;
    }
    void setDesc (string d){
      desc = d;
    }
    void setAddLetter(char al){
      addLetter = al;
    }
    void setRemoveLetter(char rl){
      removeLetter = rl;
    }


};

//function definitions
void populateMenu(vector <MenuItem> &entireMenu){
  //put some default values in our Menu
  const int numItems = 7; 

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Quesadilla", "Tacos", "Fajitas", "Chimi", "Churro"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  MenuItem Item1;
  MenuItem Item2;
  MenuItem Item3;
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;

  entireMenu.push_back(Item1);
  entireMenu.push_back(Item2);
  entireMenu.push_back(Item3);
  entireMenu.push_back(Item4);
  entireMenu.push_back(Item5);
  entireMenu.push_back(Item6);
  entireMenu.push_back(Item7);

  for(int i = 0; i < numItems; i++){
    entireMenu[i].setName(defaultMenuNames[i]);
    entireMenu[i].setAddLetter(defaultAddLetters[i]);
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]);
    entireMenu[i].setCost(3.00+i);
    entireMenu[i].setDesc("Delicious");
  }

}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    string color;
    switch(i) {
        case 0:
          // code block
          color = "\x1b[33;4m";
          break;
        case 1:
          // code block
          color = "\x1b[34;4m";
          break;
        case 2:
          // code block
          color = "\x1b[28;4m";
          break;
        case 3:
          // code block
          color = "\x1b[36;4m";
          break;
        case 4:
          // code block
          color = "\x1b[29;4m";
          break;
        case 5:
          // code block
          color = "\x1b[31;4m";
          break;
        case 6:
          //code block
          color = "\x1b[32;4m";
          break;
        default:
          // code block
          color = "\x1b[40;4m";
          break;
      }
    cout << color << m[i].getAL() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getCost() << setw(5) << "(" << m[i].getRL()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
    color = "\x1b[0m";
  }

  

}

double acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 

  

  do
  {
    string color = "\x1b[0m";
    string color2 = "\x1b[24;4m";

    cout << color << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAL())
      {
        
        cout << "\nMenu Item " << m[i].getAL() << " selected."; 
        m[i].addCount();  //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << color << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRL())
      {
        cout << "\nRemove Item " << m[i].getRL() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].removeCount(); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << color << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAL() && 
                option != m[i].getRL() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //handle reciept generation here
  cout << "TotalCost: $" << (subtotal*1.0825)<< endl;
  cout << "How much would you like to tip?" <<endl;
  cout << "\tRecommended Tip: $" << ((subtotal*1.0825) / 5) << endl;
  double tip = validateDouble(tip);
  //tax implemented here
  return (tip + (subtotal*1.0825));

  
}


void acceptPayment(double totalDue, vector <MenuItem> &m, int count){
  string payment = "";
  cout << endl << endl << "Would you like to pay with card (CC) or cash ($)?" << endl;
  payment = validateString(payment);
  double money;

  //assuming $ will be greater than total due, no split payments etc.
  //assuming if "cc" || "CC" not entered we are doing cash!
  if(payment == "CC" || payment == "cc"){
    cout << "Total Due: " << totalDue << endl;

    cout << "Enter Tender Amount: " << endl;
    double tender = validateDouble(tender);

    if(tender > totalDue){
        cout << "You entered  more than what is due" << endl;
        cout << "Only charging you for " << totalDue <<endl;
        cout << "*Processing Payment*" << endl;
        cout <<"Thank you for your business - Printing receipt" << endl;
      }
      else{
        cout << "*Processing Payment*" << endl;
        cout <<"Thank you for your business - Printing receipt" << endl;
      }
    
  }
  else{
    cout << "How much cash are you providing?" << endl;
    money = validateDouble(money);
    if(money == totalDue){ //exact change
      cout << "No change - Printing Receipt" << endl;
    }
    else{
      cout << "Change Due: $" << (money - totalDue) << "- Printing Receipt" << endl;
    }
  }

  
  ofstream myfile;
  myfile.open("C:\\report.html", std::ios::app);
  myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html
  myfile << fixed << setprecision(2) << endl;
  


  cout << "\n\n\t\t Thank you for shopping at Dr. T's shop" << endl;
  cout << "\t\t Guest #: " <<  count << endl << endl << endl;

  myfile << "\n\n\t\t Thank you for shopping at Dr. T's shop" << endl;
  myfile << "\t\t Guest #: " <<  count << endl << endl << endl;

    for(int i = 0; i < m.size(); i++){
      if(m[i].getCount() != 0){

        cout << "Item: " << setw(10) << m[i].getName() << setw(16) << "Quantity: " << m[i].getCount() << setw(10) << "\tCost: " << m[i].getCount() * m[i].getCost() << endl << endl;

        myfile << "Item: " << setw(10) << m[i].getName() << setw(16) << "Quantity: " << m[i].getCount() << setw(10) << "\tCost: " << m[i].getCount() * m[i].getCost() << endl << endl;
      }
    }

    if(payment == "CC" || payment == "cc"){
      cout << "Payment Method: CC" << endl;
      cout << "Total: " << totalDue << endl << endl << endl;
 
      myfile << "Payment Method: CC" << endl;
      myfile << "Total: " << totalDue << endl;

    }
    else{
      cout << "Payment Method: Cash" << endl;
        cout << "Total Due: " << totalDue << endl;
        cout << "Money Provided: " << money << endl;
        cout << "Change: " << money-totalDue << endl << endl << endl << endl;

        myfile << "Payment Method: Cash" << endl;
        myfile << "Total Due: " << totalDue << endl;
        myfile << "Money Provided: " << money << endl;
        myfile << "Change: " << money-totalDue << endl << endl;
    }


    myfile << endl << endl;
   //ending html
    myfile << "</body></html>";
    myfile.close();



}



int main() 
{
  int guestCount = 1;
  bool nextGuest = true;
  double dayTotal = 0;

  std::ofstream out;

  do{
  vector <MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  double total = acceptOrder(wholeMenu); 
  dayTotal += total;
  acceptPayment(total, wholeMenu, guestCount);

  cout << "Is there a next guest? (Y/N)" << endl;
  char guest = validateChar(guest);
  if(guest == 'y' || guest == 'Y'){
    nextGuest = true;
    guestCount ++;
  }
  else{
    nextGuest = false;
  }


  }while(nextGuest);

  cout << "We are rich, we made $" << dayTotal << " - Time to go home" << endl;


  
  return 0; 
}