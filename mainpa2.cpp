#include "Destination.h"
#include "SnowDestination.h"
#include "MonumenDestination.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void runprogram(string &date, snowdestination &s1, monumentdestination &m1, log &user1, string &name, string &country, string &type, double &estimatedCost, char &dest_type, char &ski_site, char &her_mon, string &snowplacename, string &mounumentname);

int main()
{

  snowdestination s1;
  monumentdestination m1;
  log user1;
  string name;
  string country;
  string type;
  double estimatedCost;
  char dest_type;
  char ski_site;
  char her_mon;
  string snowplacename;
  string mounumentname;
  char obj_typ;
  bool condition;
  bool found = false;
  string date;
  string type1;

  bool _continue = true;
  char bios;
  ifstream input_file;
  input_file.open("database.txt");
  if (input_file.is_open() == true)
  {
    while (input_file >> obj_typ)
    {
      found = true;

      if (obj_typ == 'S')
      {
        input_file >> date >> name >> country >> estimatedCost >> type1 >> snowplacename >> condition;
        s1.set_date(date);
        s1.set_name(name);
        s1.set_estimatedCost(estimatedCost);
        s1.set_skisite(condition);
        s1.set_type(type1);
        s1.set_country(country);
        s1.set_snowsitename(snowplacename);

        user1.add_destination(s1);
      }
      if (obj_typ == 'M')
      {
        input_file >> date >> name >> country >> estimatedCost >> type1 >> mounumentname >> condition;
        m1.set_date(date);
        m1.set_country(country);
        m1.set_estimatedCost(estimatedCost);
        m1.set_HeritageMonument(condition);
        m1.set_MonumentName(mounumentname);
        m1.set_name(name);
        m1.set_type(type1);

        user1.add_destination(m1);
      }
    }
    input_file.close();
  }
  else
  {
    cout << "File not found!" << endl;
  }
  cout << "--------------------------------------" << endl;
  cout << "-Hi what would you like to do today? -" << endl;

  do
  {
    cout << "--------------------------------------" << endl;
    cout << "--> View trip history      (press'H')-" << endl;
    cout << "--> Add trips              (press'T')-" << endl;
    cout << "--> Save and end session   (press'E')-" << endl;
    cout << "--------------------------------------" << endl;
    cin >> bios;
    if (bios == 'H')
    {

      if (!found)
      {
        cout << "No history found!" << endl;
        cout << "Add trips first" << endl;
      }

      input_file.open("database.txt");

      if (input_file.is_open() == true)
      {
        while (input_file >> obj_typ)
        {

          if (obj_typ == 'S')
          {
            input_file >> date >> name >> country >> estimatedCost >> type1 >> snowplacename >> condition;
            s1.set_date(date);
            s1.set_name(name);
            s1.set_estimatedCost(estimatedCost);
            s1.set_skisite(condition);
            s1.set_type(type1);
            s1.set_country(country);
            s1.set_snowsitename(snowplacename);
            s1.output_display();
          }
          if (obj_typ == 'M')
          {
            input_file >> date >> name >> country >> estimatedCost >> type1 >> mounumentname >> condition;
            m1.set_date(date);
            m1.set_country(country);
            m1.set_estimatedCost(estimatedCost);
            m1.set_HeritageMonument(condition);
            m1.set_MonumentName(mounumentname);
            m1.set_name(name);
            m1.set_type(type1);
            m1.output_display();
          }
        }
        input_file.close();
      }
      else
      {
        cout << "File not found!" << endl;
      }
    }
    else if (bios == 'T')
    {
      runprogram(date, s1, m1, user1, name, country, type, estimatedCost, dest_type, ski_site, her_mon, snowplacename, mounumentname);
      _continue = true;
    }
    else if (bios == 'E')
    {
      ofstream output_file;
      output_file.open("database.txt");
      if (output_file.is_open() == true)
      {
        user1.print(output_file);
        output_file.close();
      }
      else
      {
        cout << "File not found!" << endl;
      }
      cout << "GoodBye!" << endl;
      _continue = false;
    }
  } while (_continue);

  return 0;
}

void runprogram(string &date, snowdestination &s1, monumentdestination &m1, log &user1, string &name, string &country, string &type, double &estimatedCost, char &dest_type, char &ski_site, char &her_mon, string &snowplacename, string &mounumentname)
{
  cout << "Enter the date of travel ie(MM/DD/YY): ";
  cin >> date;
  cout << endl;

  cout << "Enter the name of the destination city : ";
  cin >> name;
  cout << endl;

  cout << "Enter the name of the destination country: ";
  cin >> country;
  cout << endl;

  cout << "Enter the type of travel(ie summer/winter/spring vacation): ";
  cin >> type;
  cout << endl;

  cout << "Enter the estimated cost of destination: ";
  cin >> estimatedCost;
  cout << endl;

  cout << "Enter the type of destination(ie snowdestination(S)/monumentdestination(M)): ";
  cin >> dest_type;
  cout << endl;

  cout << "(Warning: Dont use space in names of destination sites)" << endl;

  if (dest_type == 'S')
  {
    cout << "Is your snow destination a ski site(Y/N): ";
    cin >> ski_site;
    cout << endl;

    if (ski_site == 'Y')
    {
      cout << "Enter the name of the skisite: ";
      cin >> snowplacename;
      cout << endl;
      s1.set_name(name);
      s1.set_estimatedCost(estimatedCost);
      s1.set_skisite(true);
      s1.set_type(type);
      s1.set_country(country);
      s1.set_snowsitename(snowplacename);
      s1.set_date(date);
      user1.add_destination(s1);
      s1.input_display();
    }
    else
    {
      cout << "Enter the name of the snowsite: ";
      cin >> snowplacename;
      cout << endl;

      s1.set_name(name);
      s1.set_estimatedCost(estimatedCost);
      s1.set_skisite(false);
      s1.set_type(type);
      s1.set_country(country);
      s1.set_snowsitename(snowplacename);
      s1.set_date(date);
      user1.add_destination(s1);

      s1.input_display();
    }
  }

  if (dest_type == 'M')
  {
    cout << "Is your monument destination recognized as a UNESCO heritage site(Y/N): ";
    cin >> her_mon;
    cout << endl;

    if (her_mon == 'Y')
    {
      cout << "Enter the name of the heritagemonument: ";
      cin >> mounumentname;
      cout << endl;
      m1.set_country(country);
      m1.set_estimatedCost(estimatedCost);
      m1.set_HeritageMonument(true);
      m1.set_MonumentName(mounumentname);
      m1.set_name(name);
      m1.set_type(type);
      m1.input_display();
      m1.set_date(date);
      user1.add_destination(m1);
    }
    else
    {
      cout << "Enter the name of the monument: ";
      cin >> mounumentname;
      cout << endl;

      m1.set_country(country);
      m1.set_estimatedCost(estimatedCost);
      m1.set_HeritageMonument(false);
      m1.set_MonumentName(mounumentname);
      m1.set_name(name);
      m1.set_type(type);
      m1.set_date(date);
      m1.input_display();
      user1.add_destination(m1);
    }
  }
}
