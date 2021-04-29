//Per Gaddis 9th Edition 
//Edits by Dr. Tyson McMillan 
//Student Name: Date 4-01-2020
#include <iostream>
using namespace std; 

//class definitions 
class Rectangle
{
  private:
    double width;
    double length;
  public:        //function prototypes for the member functions 
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};
//function definitions for each of our member functions 
void Rectangle::setWidth(double w)
{
  width = w; 
}

void Rectangle::setLength(double l)
{
  length = l; 
}

double Rectangle::getWidth() const
{
  return width; //return the private attribute, width
}

double Rectangle::getLength() const
{
  return length; //return the private attribute, length
}

double Rectangle::getArea() const
{
  return (length * width);
}

int main() 
{
  Rectangle r;  //r is an instance of the class Rectangle, an object
  r.setWidth(5.2); //set the private member with to 5.2 via the public setter
  cout << r.getWidth()<< endl; //print the current value of the private width

  //Dr_T Challenge 1 set the r's length to 7.8
  r.setLength(7.8); 

  //print the length on screen
  cout << r.getLength() << endl; 

  //print the statment on screen (use) getArea here
  cout << "\nThe area of a Rectangle with width="
       << r.getWidth() << " and length=" 
       << r. getLength() << " is " 
       << r.getArea() << endl;  
  /*
    A rectangle with with w = (getter) and len = (getter) 
    has an area of (use r.getArea())
    //upload the share URL to extra credit item 15
  */
  return 0;   
}