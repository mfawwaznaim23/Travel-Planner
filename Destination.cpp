#include "Destination.h"

void destination::set_name(const string &_name)
{
   name = _name;
}
void destination::set_country(const string &_country)
{
   country = _country;
}
void destination::set_estimatedCost(const double &_estimatedcost)
{
   estimatedCost = _estimatedcost;
}
void destination::set_type(const string &_type)
{
   type = _type;
}
string destination::get_type() const
{
   return type;
}
string destination::get_name() const
{
   return name;
}
string destination::get_country() const
{
   return country;
}
double destination::get_estimatedCost() const
{
   return estimatedCost;
}
void destination::set_date(string& _date)
{
   date=_date;
}
string destination::get_date() const
{
   return date;
}
char destination::gettype() const
{
   return 'D';
}

void destination::output_display() const
{
   cout << "You are travelling to " << name << " in " << country << " on a " << type << " trip " << "at a cost of " << estimatedCost << "." << endl;
}
void destination :: input_display() const 
{
cout<<"The following details have been added to the log dont forget to save!" << endl;
cout<<"Date: " << date;
cout<<"Destination: " << name << "," << country;
cout<<"Cost: "<<estimatedCost;

}


void destination::print(ofstream& output_file) const
{
   output_file << name;

}
