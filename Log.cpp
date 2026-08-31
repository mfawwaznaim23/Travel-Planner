#include "Log.h"

    log::log()
    {
        list.clear();
    }
    log::log(const log&  RHS)
    {
        for(int i=0;i<list.size();i++)
        {
            
            if(list.at(i)!=nullptr)
            {
                delete list.at(i);
                list.at(i)=nullptr;
                
            }
            list.pop_back();
        }


        for(int i=0;i<RHS.list.size();i++)
        {
            destination* _ptr=nullptr;
            if(RHS.list.at(i)!=nullptr)//think
            {
            if(RHS.list.at(i)->gettype()=='D')
            {
                _ptr=new destination(*RHS.list.at(i));
            }
            if(RHS.list.at(i)->gettype()=='M')
            {
                _ptr=new monumentdestination((monumentdestination&)*RHS.list.at(i));
            }
            if(RHS.list.at(i)->gettype()=='S')
            {
                _ptr=new snowdestination((snowdestination&)*RHS.list.at(i));
            }
            
            }
            list.push_back(_ptr);//
        }

    }

    log& log::operator=(const log& RHS)
    {
        if(this != &RHS)
        {
            for(int i=0;i<list.size();i++)
            {
                if(list.at(i) != nullptr)
                {
                    delete list.at(i);
                    list.at(i)=nullptr;
                }
                list.pop_back();
            }

            for(destination* _ptr: RHS.list)
            {
                destination* ptr=nullptr;
                if(_ptr!=nullptr)
                {
                  if(_ptr->gettype()=='D')
                {
                    ptr=new destination (*_ptr);
                }
                if(_ptr->gettype()=='M')
                {
                    ptr=new monumentdestination((monumentdestination&)*_ptr);//think
                }
                if(_ptr->gettype()=='S')
                {
                    ptr=new snowdestination((snowdestination&)*_ptr);
                }   
                }
                list.push_back(ptr);
               
            }
        }
        return *this;
    }
    log::~log()
    {
        for(int i=0;i<list.size();i++)
        {
            if(list.at(i)!=nullptr)
            {
                delete list.at(i);
                list.at(i)=nullptr;
            }
            list.pop_back();
        }
    }
    void log::add_destination(destination& dest_ptr)
    {
        destination* p=nullptr;
        if(dest_ptr.gettype()=='D')
        {
            p=new destination(dest_ptr);
        }
         if(dest_ptr.gettype()=='M')
        {
            p=new monumentdestination((monumentdestination&)dest_ptr);
        }
         if(dest_ptr.gettype()=='S')
        {
            p=new snowdestination((snowdestination&)dest_ptr);
        }
        list.push_back(p);

    }

    void log::print(ofstream& output_file) const
    {
        for(int i=0;i<list.size();i++)
        {
            if(list.at(i)!=nullptr)
            {
                list.at(i)->print(output_file);
            }
        }
    }