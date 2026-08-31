#ifndef Snow_Destination_H
#define Snow_Destination_H


#include"Destination.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;






class snowdestination : public destination
{
    private:
    string snowsitename; //name of the snowdestination which they are visiting
    bool skisite;         // stores if the snowdestination is a place where people can ski
    
    public:

    snowdestination(const string& _date="MM/DD/YY",const string& _name="", const string& _country="",const string& _type="", const double& _estimatedcost=0,const bool& skisite=true,const string& _snowsitename="");
    void set_skisite(const bool& _skisite);
    void set_snowsitename(const string& _snowsitename);
    bool get_skisite() const;
    string get_snowsitename() const;
    virtual char gettype() const;
    virtual void output_display() const;
    virtual void input_display() const;
    virtual void print(ofstream& output_file) const;
    
};



#endif