#ifndef Destination_h
#define Destination_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


class destination
{
private:
 string name;// name of destination city
 string country;
 string type; // example summer/spring/winter vacation
 string date;
 double estimatedCost;

 public:
 destination(const string& _date="MM/DD/YY",const string& _name="", const string& _country="",const string& _type="", const double& _estimatedcost=0)
 :name(_name),country(_country),type(_type),estimatedCost(_estimatedcost){};
 void set_name(const string& _name);
 void set_country(const string& _country);
 void set_estimatedCost(const double& _estimatedcost);
 void set_type(const string& _type);
 string get_type() const;
 string get_name() const;
 string get_country() const;
 double get_estimatedCost () const;
 void set_date(string& _date);
 string get_date() const;
 virtual char gettype() const; //helps me get the type of derived class object stored in base class pointer vector(in container class)
 virtual void output_display() const ;//prints data from the file which stores trip logs  onto the console when the user requests trip history(database.txt)
 virtual void input_display() const ; //prints data  when you add a trip to the container class(prints in the console)
 virtual void print(ofstream& output_file) const; // to print data in the file (database.txt)
 
};

#endif
