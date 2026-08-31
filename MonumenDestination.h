#ifndef Monument_Destination_H
#define Monument_Destination_H
#include "Destination.h"



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


class monumentdestination: public destination
{

    private:
    bool HeritageMonument; // stores if the monument is recognized by UNESCO as a heritage monument
    string MonumentName; // stores the name of the monument 
    public:

    monumentdestination(const string& _date="MM/DD/YY",const string& _name="", const string& _country="",const string& _type="", const double& _estimatedcost=0,const string& _monumentname="", bool _heritagemonument=true);
    void set_HeritageMonument(const bool _heritagemonument);
    void set_MonumentName(const string& _monumentname);
    bool get_HeritageMonument() const;
    string get_MonumentName() const;
    virtual char gettype() const;
    virtual void output_display() const;
    virtual void input_display() const;
    virtual void print(ofstream& output_file) const;
};




#endif