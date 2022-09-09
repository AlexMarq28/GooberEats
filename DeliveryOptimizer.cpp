#include "provided.h"
#include <vector>
#include <map>
using namespace std;

class DeliveryOptimizerImpl
{
public:
    DeliveryOptimizerImpl(const StreetMap* sm);
    ~DeliveryOptimizerImpl();
    void optimizeDeliveryOrder(
        const GeoCoord& depot,
        vector<DeliveryRequest>& deliveries,
        double& oldCrowDistance,
        double& newCrowDistance) const;
private:

    const double getCrowDistance(const vector<DeliveryRequest>& deliveries) const;
    PointToPointRouter router;
};

DeliveryOptimizerImpl::DeliveryOptimizerImpl(const StreetMap* sm):router(sm)
{





}

DeliveryOptimizerImpl::~DeliveryOptimizerImpl()
{
}

void DeliveryOptimizerImpl::optimizeDeliveryOrder(
    const GeoCoord& depot,
    vector<DeliveryRequest>& deliveries,
    double& oldCrowDistance,
    double& newCrowDistance) const
{
    if(deliveries.size()<=1)return;
    oldCrowDistance= getCrowDistance(deliveries);
    list<StreetSegment> r;
    double minDist=100000;
    router.generatePointToPointRoute(depot, deliveries[0].location, r, minDist);

    double temp;
    GeoCoord dummyCoord("10.0000000","10.0000000");

    vector<DeliveryRequest> tempDeliveries(deliveries);
    DeliveryRequest nextDelivery("",depot);
     DeliveryRequest dummyDelivery("",dummyCoord);  //fix dummydelivery value



    int minPos=0;
    for(int j=0;j<deliveries.size();j++){
         minDist=100000;
        minPos=0;
        while(!tempDeliveries[minPos].item.compare("")&&minPos<tempDeliveries.size())minPos++;
        minPos--;
            for(int i=0;i<tempDeliveries.size();i++){


//                router.generatePointToPointRoute(nextDelivery.location, deliveries[i].location, r, temp);
                temp=distanceEarthKM(nextDelivery.location, deliveries[i].location);

                if(temp<minDist&&tempDeliveries[i].item.compare("")){
                    minDist= temp;
                    nextDelivery=tempDeliveries[i];
                    minPos=i;

                }


    }




        for(int z=0;z<deliveries.size();z++){
            if(deliveries[z].item== nextDelivery.item&&deliveries[z].location==nextDelivery.location) {
                deliveries[z]=deliveries[j];
            }
        }
        deliveries[j]=nextDelivery;
        const auto it=minPos+tempDeliveries.begin();
        tempDeliveries.erase(it);

}







    newCrowDistance=getCrowDistance(deliveries);




}

const double DeliveryOptimizerImpl::getCrowDistance( const vector<DeliveryRequest>& deliveries) const{
    double result=0;


    for(int i=1;i<deliveries.size();i++){
        result+= distanceEarthMiles(deliveries[i-1].location, deliveries[i].location);

    }




    return result;

}

//******************** DeliveryOptimizer functions ****************************

// These functions simply delegate to DeliveryOptimizerImpl's functions.
// You probably don't want to change any of this code.

DeliveryOptimizer::DeliveryOptimizer(const StreetMap* sm)
{
    m_impl = new DeliveryOptimizerImpl(sm);
}

DeliveryOptimizer::~DeliveryOptimizer()
{
    delete m_impl;
}

void DeliveryOptimizer::optimizeDeliveryOrder(
        const GeoCoord& depot,
        vector<DeliveryRequest>& deliveries,
        double& oldCrowDistance,
        double& newCrowDistance) const
{
    return m_impl->optimizeDeliveryOrder(depot, deliveries, oldCrowDistance, newCrowDistance);
}

//#include "provided.h"
//#include <vector>
//using namespace std;
//
//class DeliveryOptimizerImpl
//{
//public:
//    DeliveryOptimizerImpl(const StreetMap* sm);
//    ~DeliveryOptimizerImpl();
//    void optimizeDeliveryOrder(
//        const GeoCoord& depot,
//        vector<DeliveryRequest>& deliveries,
//        double& oldCrowDistance,
//        double& newCrowDistance) const;
//};
//
//DeliveryOptimizerImpl::DeliveryOptimizerImpl(const StreetMap* sm)
//{
//}
//
//DeliveryOptimizerImpl::~DeliveryOptimizerImpl()
//{
//}
//
//void DeliveryOptimizerImpl::optimizeDeliveryOrder(
//    const GeoCoord& depot,
//    vector<DeliveryRequest>& deliveries,
//    double& oldCrowDistance,
//    double& newCrowDistance) const
//{
//    oldCrowDistance = 0;  // Delete these lines and implement this function correctly
//    newCrowDistance = 0;
//}
//
////******************** DeliveryOptimizer functions ****************************
//
//// These functions simply delegate to DeliveryOptimizerImpl's functions.
//// You probably don't want to change any of this code.
//
//DeliveryOptimizer::DeliveryOptimizer(const StreetMap* sm)
//{
//    m_impl = new DeliveryOptimizerImpl(sm);
//}
//
//DeliveryOptimizer::~DeliveryOptimizer()
//{
//    delete m_impl;
//}
//
//void DeliveryOptimizer::optimizeDeliveryOrder(
//        const GeoCoord& depot,
//        vector<DeliveryRequest>& deliveries,
//        double& oldCrowDistance,
//        double& newCrowDistance) const
//{
//    return m_impl->optimizeDeliveryOrder(depot, deliveries, oldCrowDistance, newCrowDistance);
//}
//
