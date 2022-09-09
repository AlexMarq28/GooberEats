////
////#include "provided.h"
////#include <queue>
////#include <list>
////#include <map>
////#include <set>
////#include <string>
////#include "ExpandableHashMap.h"
////using namespace std;
////
////class PointToPointRouterImpl
////{
////public:
////    PointToPointRouterImpl(const StreetMap* sm);
////    ~PointToPointRouterImpl();
////    DeliveryResult generatePointToPointRoute(
////        const GeoCoord& start,
////        const GeoCoord& end,
////        list<StreetSegment>& route,
////        double& totalDistanceTravelled) const;
////private:
////    const StreetMap* m_streetMap;
////
////
////
////};
////
////PointToPointRouterImpl::PointToPointRouterImpl(const StreetMap* sm)
////{
////    m_streetMap=sm;
////
////
////}
////
////PointToPointRouterImpl::~PointToPointRouterImpl()
////{
////}
////
////DeliveryResult PointToPointRouterImpl::generatePointToPointRoute(
////        const GeoCoord& start,
////        const GeoCoord& end,
////        list<StreetSegment>& route,
////        double& totalDistanceTravelled) const
////{
////    multimap<double, GeoCoord> pointsToCheck;
////
////    pointsToCheck.insert (pair<double,GeoCoord>(distanceEarthMiles(start, end) ,start));
////    GeoCoord current;
////    vector<StreetSegment> segs;
////    pair<double,GeoCoord> p;
////
////    multimap<double,GeoCoord> adjacentPoints;
////    set<GeoCoord> visitedPoints;
////    double distanceToCurrent=0;
////
////    ExpandableHashMap<GeoCoord,GeoCoord> locationOfPreviousWayPoint;
////
////    bool found=false;
////    while(!pointsToCheck.empty()){
////
////        current=pointsToCheck.begin()->second;
////        distanceToCurrent=pointsToCheck.begin()->first-abs(distanceEarthMiles(current, end));
////
////        pointsToCheck.erase(pointsToCheck.begin());
////
////        segs.clear();
////
////        m_streetMap->getSegmentsThatStartWith(current, segs);
////        adjacentPoints.clear();
////        for(auto it=segs.begin();it!=segs.end();it++){
////
////
////
////            if(visitedPoints.find(it->end)==visitedPoints.end() ){
////                p.first= abs( distanceEarthMiles(current, it->end))+abs(+distanceEarthMiles(it->end, end))+distanceToCurrent;
////
////                visitedPoints.insert(it->end);
////                p.second=it->end;
////                pointsToCheck.insert(p);
////                locationOfPreviousWayPoint.associate(it->end,current);
////            }
////        }
////
////        if(current==end){
////            found=true;
////           bool routeCompleted=false;
////            StreetSegment tempSeg;
////            tempSeg.start = *locationOfPreviousWayPoint.find(current);
////            tempSeg.end = current;
////
////
////             while(!routeCompleted){
////
////
////
////
////                tempSeg.start = *locationOfPreviousWayPoint.find(tempSeg.end);
////
////
////
////                 route.push_back(tempSeg);
////                 tempSeg.end=tempSeg.start;
////                 if(tempSeg.start==start) routeCompleted=true;
////                }
////             list<StreetSegment> reversed=route;
////             list<StreetSegment>::iterator it2  = reversed.end();
////             it2--;
////
////             totalDistanceTravelled=0;
////             for( list<StreetSegment>::iterator it1=route.begin();it1 != route.end();it1++){
////
////                 totalDistanceTravelled+= distanceEarthMiles(it1->end, it1->start);
////
////                 *it1=*it2;
////
////                 it2--;
////                 }
////            vector <StreetSegment> data;
////            for(auto it1 = route.begin(); it1 != route.end(); ++it1){
////                data.clear();
////                m_streetMap->getSegmentsThatStartWith(it1->start, data);
////
////                for(auto it2= data.begin();it2!=data.end();++it2){
////
////                    if(!it1->end.latitudeText.compare(it2->end.latitudeText)&&!it1->end.longitudeText.compare(it2->end.longitudeText)){
////                         it1->name=it2->name;
////                        break;
////                    }
////                }
////            }
////       return DELIVERY_SUCCESS;
////             }
////        }
////    return NO_ROUTE;
////
////}
////
////
////
//////******************** PointToPointRouter functions ***************************
////
////// These functions simply delegate to PointToPointRouterImpl's functions.
////// You probably don't want to change any of this code.
////
////PointToPointRouter::PointToPointRouter(const StreetMap* sm)
////{
////    m_impl = new PointToPointRouterImpl(sm);
////}
////
////PointToPointRouter::~PointToPointRouter()
////{
////    delete m_impl;
////}
////
////DeliveryResult PointToPointRouter::generatePointToPointRoute(
////        const GeoCoord& start,
////        const GeoCoord& end,
////        list<StreetSegment>& route,
////        double& totalDistanceTravelled) const
////{
////    return m_impl->generatePointToPointRoute(start, end, route, totalDistanceTravelled);
////}
////
////
////
////
////
////
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include "provided.h"
//#include <queue>
//#include <list>
//#include <map>
//#include <set>
//#include <string>
//#include "ExpandableHashMap.h"
//using namespace std;
//
//class PointToPointRouterImpl
//{
//public:
//    PointToPointRouterImpl(const StreetMap* sm);
//    ~PointToPointRouterImpl();
//    DeliveryResult generatePointToPointRoute(
//        const GeoCoord& start,
//        const GeoCoord& end,
//        list<StreetSegment>& route,
//        double& totalDistanceTravelled) const;
//private:
//    const StreetMap* m_streetMap;
//
//
//
//};
//
//PointToPointRouterImpl::PointToPointRouterImpl(const StreetMap* sm)
//{
//    m_streetMap=sm;
//
//
//}
//
//PointToPointRouterImpl::~PointToPointRouterImpl()
//{
//}
//
//DeliveryResult PointToPointRouterImpl::generatePointToPointRoute(
//        const GeoCoord& start,
//        const GeoCoord& end,
//        list<StreetSegment>& route,
//        double& totalDistanceTravelled) const
//{
//
//    if(!start.latitudeText.compare(end.latitudeText) &&!end.longitudeText.compare(end.longitudeText) ){
//        route.clear();
//        totalDistanceTravelled=0;
//        return DELIVERY_SUCCESS;
//    }
//    route.clear();
//    multimap<double, GeoCoord> pointsToCheck;
//
//    pointsToCheck.insert (pair<double,GeoCoord>(distanceEarthMiles(start, end) ,start));
//    GeoCoord current;
//    vector<StreetSegment> segs;
//    pair<double,GeoCoord> p;
//
//
//    set<GeoCoord> visitedPoints;
//    double distanceToCurrent=0;
//
//    ExpandableHashMap<GeoCoord,GeoCoord> locationOfPreviousWayPoint;
//
//    bool found=false;
//    while(!pointsToCheck.empty()){
//
//        current=pointsToCheck.begin()->second;
//        pointsToCheck.erase(pointsToCheck.begin());
//        distanceToCurrent=pointsToCheck.begin()->first-abs(distanceEarthMiles(current, end));
//
//
//        if(! current.latitudeText.compare(end.latitudeText) &&!current.longitudeText.compare(end.longitudeText)){
//             found=true;
//            bool routeCompleted=false;
//             StreetSegment tempSeg;
//             //ExpandableHashMap<GeoCoord, GeoCoord> g;
//             if(locationOfPreviousWayPoint.find(current)!=nullptr){
//             tempSeg.start = *locationOfPreviousWayPoint.find(current);
//             }else return NO_ROUTE;
//             //tempSeg.start = g->find(current);
//             tempSeg.end = current;
//
//
//              while(!routeCompleted){
//
//
//
//
//                 tempSeg.start = *locationOfPreviousWayPoint.find(tempSeg.end);
//
//
//
//                  route.push_back(tempSeg);
//                  tempSeg.end=tempSeg.start;
//                  if(tempSeg.start==start) routeCompleted=true;
//                 }
//              list<StreetSegment> reversed=route;
//              list<StreetSegment>::iterator it2  = reversed.end();
//              it2--;
//
//              totalDistanceTravelled=0;
//              for( list<StreetSegment>::iterator it1=route.begin();it1 != route.end();it1++){
//
//                  totalDistanceTravelled+= distanceEarthMiles(it1->end, it1->start);
//
//                  *it1=*it2;
//
//                  it2--;
//                  }
//             vector <StreetSegment> data;
//             for(auto it1 = route.begin(); it1 != route.end(); ++it1){
//                 data.clear();
//                 m_streetMap->getSegmentsThatStartWith(it1->start, data);
//
//                 for(auto it2= data.begin();it2!=data.end();++it2){
//
//                     if(!it1->end.latitudeText.compare(it2->end.latitudeText)&&!it1->end.longitudeText.compare(it2->end.longitudeText)){
//                          it1->name=it2->name;
//                          return DELIVERY_SUCCESS;
//                         break;
//                     }
//                 }
//             }
//        return DELIVERY_SUCCESS;
//              }
//
//        segs.clear();
//
//        m_streetMap->getSegmentsThatStartWith(current, segs);
//
//
//        for(auto it=segs.begin();it!=segs.end();it++){
//
//
//
//            if(visitedPoints.find(it->end)==visitedPoints.end() ){
//                p.first= abs( distanceEarthMiles(current, it->end))+abs(+distanceEarthMiles(it->end, end))+distanceToCurrent;
//
//                visitedPoints.insert(it->end);
//                p.second=it->end;
//                pointsToCheck.insert(p);
//                locationOfPreviousWayPoint.associate(it->end,current);
//            }
//        }
//
////        if(! current.latitudeText.compare(end.latitudeText) &&!current.longitudeText.compare(end.longitudeText)){
////            found=true;
////           bool routeCompleted=false;
////            StreetSegment tempSeg;
////            //ExpandableHashMap<GeoCoord, GeoCoord> g;
////            if(locationOfPreviousWayPoint.find(current)!=nullptr){
////            tempSeg.start = *locationOfPreviousWayPoint.find(current);
////            }else return NO_ROUTE;
////            //tempSeg.start = g->find(current);
////            tempSeg.end = current;
////
////
////             while(!routeCompleted){
////
////
////
////
////                tempSeg.start = *locationOfPreviousWayPoint.find(tempSeg.end);
////
////
////
////                 route.push_back(tempSeg);
////                 tempSeg.end=tempSeg.start;
////                 if(tempSeg.start==start) routeCompleted=true;
////                }
////             list<StreetSegment> reversed=route;
////             list<StreetSegment>::iterator it2  = reversed.end();
////             it2--;
////
////             totalDistanceTravelled=0;
////             for( list<StreetSegment>::iterator it1=route.begin();it1 != route.end();it1++){
////
////                 totalDistanceTravelled+= distanceEarthMiles(it1->end, it1->start);
////
////                 *it1=*it2;
////
////                 it2--;
////                 }
////            vector <StreetSegment> data;
////            for(auto it1 = route.begin(); it1 != route.end(); ++it1){
////                data.clear();
////                m_streetMap->getSegmentsThatStartWith(it1->start, data);
////
////                for(auto it2= data.begin();it2!=data.end();++it2){
////
////                    if(!it1->end.latitudeText.compare(it2->end.latitudeText)&&!it1->end.longitudeText.compare(it2->end.longitudeText)){
////                         it1->name=it2->name;
////                        break;
////                    }
////                }
////            }
////       return DELIVERY_SUCCESS;
////             }
//        }
//    return NO_ROUTE;
//
//}
//
//
//
////******************** PointToPointRouter functions ***************************
//
//// These functions simply delegate to PointToPointRouterImpl's functions.
//// You probably don't want to change any of this code.
//
//PointToPointRouter::PointToPointRouter(const StreetMap* sm)
//{
//    m_impl = new PointToPointRouterImpl(sm);
//}
//
//PointToPointRouter::~PointToPointRouter()
//{
//    delete m_impl;
//}
//
//DeliveryResult PointToPointRouter::generatePointToPointRoute(
//        const GeoCoord& start,
//        const GeoCoord& end,
//        list<StreetSegment>& route,
//        double& totalDistanceTravelled) const
//{
//    return m_impl->generatePointToPointRoute(start, end, route, totalDistanceTravelled);
//}






#include "provided.h"
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include "ExpandableHashMap.h"
using namespace std;

class PointToPointRouterImpl
{
public:
    PointToPointRouterImpl(const StreetMap* sm);
    ~PointToPointRouterImpl();
    DeliveryResult generatePointToPointRoute(
        const GeoCoord& start,
        const GeoCoord& end,
        list<StreetSegment>& route,
        double& totalDistanceTravelled) const;
private:
    const StreetMap* m_streetMap;
    
    
    
};

PointToPointRouterImpl::PointToPointRouterImpl(const StreetMap* sm)
{
    m_streetMap=sm;
    
    
}

PointToPointRouterImpl::~PointToPointRouterImpl()
{
}

DeliveryResult PointToPointRouterImpl::generatePointToPointRoute(
        const GeoCoord& start,
        const GeoCoord& end,
        list<StreetSegment>& route,
        double& totalDistanceTravelled) const
{
    route.clear();
    vector<StreetSegment> tempss;
    if(!m_streetMap->getSegmentsThatStartWith(start,tempss)) return BAD_COORD;
    if(!m_streetMap->getSegmentsThatStartWith(end,tempss)) return BAD_COORD;
    
    
    route.clear();
    
    if(start.latitudeText==end.latitudeText&&end.longitudeText==start.longitudeText){
        totalDistanceTravelled=0;
        route.clear();
    }
    multimap<double, GeoCoord> pointsToCheck;
    
    pointsToCheck.insert (pair<double,GeoCoord>(distanceEarthMiles(start, end) ,start));
    GeoCoord current;
    vector<StreetSegment> segs;
    pair<double,GeoCoord> p;
 
    multimap<double,GeoCoord> adjacentPoints;
    set<GeoCoord> visitedPoints;
    double distanceToCurrent=0;
    
    ExpandableHashMap<GeoCoord,GeoCoord> locationOfPreviousWayPoint;
    
    bool found=false;
    while(!pointsToCheck.empty()){
        
        current=pointsToCheck.begin()->second;
        distanceToCurrent=pointsToCheck.begin()->first-abs(distanceEarthMiles(current, end));
        
        pointsToCheck.erase(pointsToCheck.begin());
        
        segs.clear();
        
        m_streetMap->getSegmentsThatStartWith(current, segs);
        adjacentPoints.clear();
        for(auto it=segs.begin();it!=segs.end();it++){
            
           
          
            if(visitedPoints.find(it->end)==visitedPoints.end() ){
                p.first= abs( distanceEarthMiles(current, it->end))+abs(+distanceEarthMiles(it->end, end))+distanceToCurrent;
                
                visitedPoints.insert(it->end);
                p.second=it->end;
                pointsToCheck.insert(p);
                locationOfPreviousWayPoint.associate(it->end,current);
            }
        }
        
        if(current==end){
            found=true;
           bool routeCompleted=false;
            StreetSegment tempSeg;
            if(locationOfPreviousWayPoint.find(current)==nullptr) return NO_ROUTE;
            tempSeg.start = *locationOfPreviousWayPoint.find(current);
            tempSeg.end = current;

             
             while(!routeCompleted){
                
                 
               
                 
                tempSeg.start = *locationOfPreviousWayPoint.find(tempSeg.end);
              
                 
                 
                 route.push_back(tempSeg);
                 tempSeg.end=tempSeg.start;
                 if(tempSeg.start==start) routeCompleted=true;
                }
             list<StreetSegment> reversed=route;
             list<StreetSegment>::iterator it2  = reversed.end();
             it2--;
             
             totalDistanceTravelled=0;
             for( list<StreetSegment>::iterator it1=route.begin();it1 != route.end();it1++){
                 
                 totalDistanceTravelled+= distanceEarthMiles(it1->end, it1->start);
                 
                 *it1=*it2;
                 
                 it2--;
                 }
            vector <StreetSegment> data;
            for(auto it1 = route.begin(); it1 != route.end(); ++it1){
                data.clear();
                m_streetMap->getSegmentsThatStartWith(it1->start, data);
              
                for(auto it2= data.begin();it2!=data.end();++it2){
                    
                    if(it1->end.latitudeText==(it2->end.latitudeText)&&it1->end.longitudeText==(it2->end.longitudeText)){
                         it1->name=it2->name;
            
                        break;
                    }
                }
                 
            }
       return DELIVERY_SUCCESS;
             }
        }
    return NO_ROUTE;
    
}
  
 

//******************** PointToPointRouter functions ***************************

// These functions simply delegate to PointToPointRouterImpl's functions.
// You probably don't want to change any of this code.

PointToPointRouter::PointToPointRouter(const StreetMap* sm)
{
    m_impl = new PointToPointRouterImpl(sm);
}

PointToPointRouter::~PointToPointRouter()
{
    delete m_impl;
}

DeliveryResult PointToPointRouter::generatePointToPointRoute(
        const GeoCoord& start,
        const GeoCoord& end,
        list<StreetSegment>& route,
        double& totalDistanceTravelled) const
{
    return m_impl->generatePointToPointRoute(start, end, route, totalDistanceTravelled);
}
