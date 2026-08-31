#include "MonumenDestination.h"

monumentdestination::monumentdestination(const string &_date, const string &_name, const string &_country, const string &_type, const double &_estimatedcost, const string &_monumentname, bool _heritagemonument)
    : MonumentName(_monumentname), HeritageMonument(_heritagemonument), destination(_date, _name, _country, _type, _estimatedcost)
{
}

void monumentdestination::set_HeritageMonument(const bool _heritagemonument)
{
    HeritageMonument = _heritagemonument;
}
void monumentdestination::set_MonumentName(const string &_monumentname)
{
    MonumentName = _monumentname;
}
bool monumentdestination::get_HeritageMonument() const
{
    return HeritageMonument;
}
string monumentdestination::get_MonumentName() const
{
    return MonumentName;
}
void monumentdestination::output_display() const
{
    cout << "You travelled to " << get_name() << "," << get_country() << " on a "
         << get_type() << " trip " << " on " << get_date() << " at a cost of " << get_estimatedCost() << "$";
    if (HeritageMonument == false)
    {
        cout << " to visit a monument " << MonumentName << "." << endl;
    }
    else
    {
        cout << " to a heritagemonument " << MonumentName << "." << endl;
    }
}
void monumentdestination::input_display() const
{
    cout << "The following details have been added to the log dont forget to save!" << endl;
    cout << "Date: " << get_date()<< endl;
    cout << "Destination: " <<get_name() << "," << get_country()<< endl;
    cout << "Cost: " << get_estimatedCost()<< endl;
    cout << "Vacation Type: " << get_type() << " Vacation" << endl;
    if(HeritageMonument == false)
    {
        cout<< "Monument: " << MonumentName<< endl;
    }
    else 
    {
        cout<< "Heritage Monument: " << MonumentName<< endl;
    }
}

char monumentdestination::gettype() const
{
    return 'M';
}
void monumentdestination::print(ofstream &output_file) const
{
    output_file << gettype() << " " << get_date() << " " << get_name() << " " << get_country() << " " << get_estimatedCost() << " " << get_type() << " " << get_MonumentName() << " " << get_HeritageMonument() << " " << endl;
}
