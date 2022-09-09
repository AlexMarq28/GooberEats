#include "provided.h"
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>
#include "ExpandableHashMap.h"
using namespace std;

unsigned int hasher(const GeoCoord& g)
{
    return std::hash<string>()(g.latitudeText + g.longitudeText);
}

class StreetMapImpl
{
public:
    StreetMapImpl();
    ~StreetMapImpl();
    bool load(string mapFile);
    bool getSegmentsThatStartWith(const GeoCoord& gc, vector<StreetSegment>& segs) const;
    
private:
    ExpandableHashMap<GeoCoord, vector<StreetSegment>> m_data;
    
};

StreetMapImpl::StreetMapImpl()
{
}

StreetMapImpl::~StreetMapImpl()
{
}

bool StreetMapImpl::load(string mapFile)
{
    ifstream infile(mapFile);    // infile is a name of our choosing
    if ( ! infile )                // Did opening the file fail?
    {
        cerr << "Error: Cannot open " << mapFile<<"!"<< endl;
        return false;
    }
    
    
    
    string s,t;
    int k=0;
    string pointALat, pointALong,pointBLat, pointBLong;
    while(infile){
        s="";
        getline(infile,s);
        infile >> k;
        infile.ignore(10000, '\n');
        for(int i=0;i<k;i++){
            infile>>pointALat;
            infile>>pointALong;
            infile>>pointBLat;
            infile>>pointBLong;
            getline(infile,t);
           
            
            GeoCoord pointA(pointALat,pointALong);
            GeoCoord pointB(pointBLat,pointBLong);
            
            
            StreetSegment blank;
            StreetSegment seg1(pointA,pointB, s);
            StreetSegment seg2(pointB, pointA,s);
           
            pair<StreetSegment,StreetSegment> pair2(seg2,blank);
            vector<StreetSegment>* ptr = m_data.find(pointA);
            
            
            if(ptr==nullptr){
                vector<StreetSegment>newvec;
                newvec.push_back(seg1);
                m_data.associate(pointA, newvec);
            }else{
                ptr->push_back(seg1);
            }
                

           ptr = m_data.find(pointB);
                      
                      
                      if(ptr==nullptr){
                          vector<StreetSegment>newvec;
                          newvec.push_back(seg2);
                          m_data.associate(pointB, newvec);
                      }else{
                          ptr->push_back(seg2);
                      }
                          
            
            
           
            
            
            
            
        }
        
        
    }
    

    return true;
}

bool StreetMapImpl::getSegmentsThatStartWith(const GeoCoord& gc, vector<StreetSegment>& segs) const
{
   
    const vector<StreetSegment>* p = m_data.find(gc);
    if(p==nullptr)return false;
    segs.clear();
    segs=*p;
    return true;  // Delete this line and implement this function correctly
}

//******************** StreetMap functions ************************************

// These functions simply delegate to StreetMapImpl's functions.
// You probably don't want to change any of this code.

StreetMap::StreetMap()
{
    m_impl = new StreetMapImpl;
}

StreetMap::~StreetMap()
{
    delete m_impl;
}

bool StreetMap::load(string mapFile)
{
    return m_impl->load(mapFile);
}

bool StreetMap::getSegmentsThatStartWith(const GeoCoord& gc, vector<StreetSegment>& segs) const
{
   return m_impl->getSegmentsThatStartWith(gc, segs);
}
