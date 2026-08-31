 #include "SnowDestination.h"


snowdestination:: snowdestination(const string& _date,const string& _name, const string& _country,const string& _type, const double& _estimatedcost,const bool& _skisite,const string& _snowsitename)
:skisite(_skisite),snowsitename(_snowsitename),destination(_date,_name,_country,_type,_estimatedcost)
{

}
void snowdestination::set_skisite(const bool& _skisite)
{
    skisite=_skisite;
}
void snowdestination::set_snowsitename(const string& _snowsitename)
{
    snowsitename=_snowsitename;
}
bool snowdestination::get_skisite() const
{
 return skisite;
}
string snowdestination::get_snowsitename() const
{
    return snowsitename;
}
void snowdestination:: output_display() const
 {
     cout << "You travelled to " << get_name() << "," << get_country() << " on a " 
        << get_type() << " trip " << " on " << get_date()<<" at a cost of " << get_estimatedCost()<< "$";
        if(skisite==false)
        {
            cout<< " to visit a snowdestination " << snowsitename << "." << endl;
        }
        else
        {
            cout<< " to a skisite " << snowsitename << "." << endl;
        }
        
 }
 void snowdestination:: input_display() const 
{
    cout << "The following details have been added to the log dont forget to save!" << endl;
    cout << "Date: " << get_date()<< endl;
    cout << "Destination: " <<get_name() << "," << get_country()<< endl;
    cout << "Cost: " << get_estimatedCost()<< endl;
    cout << "Vacation Type: " << get_type() << " Vacation" << endl;
    if(skisite == false)
    {
        cout<< "Snowsitename: " << snowsitename<< endl;
    }
    else 
    {
        cout<< "Skisite: " << snowsitename<< endl;

    }

}
 
char snowdestination::gettype() const
{
    return 'S';
}

void snowdestination::print(ofstream& output_file) const
 {
    
    output_file <<gettype()<< " " << get_date() <<" "<< get_name() << " " << get_country() << " " << get_estimatedCost()  << " " << get_type()<< " " << get_snowsitename()<< " " << get_skisite() << " "   << endl;
 }
