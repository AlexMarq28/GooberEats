#include "provided.h"
#include <vector>
using namespace std;

class DeliveryPlannerImpl
{
public:
    DeliveryPlannerImpl(const StreetMap* sm);
    ~DeliveryPlannerImpl();
    DeliveryResult generateDeliveryPlan(
        const GeoCoord& depot,
        const vector<DeliveryRequest>& deliveries,
        vector<DeliveryCommand>& commands,
        double& totalDistanceTravelled) const;
private:
    DeliveryOptimizer optimizer;
    PointToPointRouter router;
    
    const string getDirection(double angle) const;
    
};
const string DeliveryPlannerImpl::getDirection(double angle) const {
    
    if(angle>=0&&angle<22.5)return "east";
    if(angle>=22.5&&angle<67.5)return "northeast";
    if(angle>=67.5&&angle<112.5)return "north";
    if(angle>=112.5&&angle<157.5)return "northwest";
    if(angle>=157.5&&angle<202.5)return "west";
    if(angle>=202.5&&angle<247.5)return "southwest";
    if(angle>=247.5&& angle < 292.5)return "south";
    if(angle>=292.5 && angle< 337.5)return "southeast";
    if(angle >= 337.5)return "east";
    return "";
    
    
    
}

DeliveryPlannerImpl::DeliveryPlannerImpl(const StreetMap* sm):router(sm),optimizer(sm)
{
}

DeliveryPlannerImpl::~DeliveryPlannerImpl()
{
}

DeliveryResult DeliveryPlannerImpl::generateDeliveryPlan(
    const GeoCoord& depot,
    const vector<DeliveryRequest>& deliveries,
    vector<DeliveryCommand>& commands,
    double& totalDistanceTravelled) const
{
    totalDistanceTravelled=0;
    double d=0;
    double d2=0;
    vector<DeliveryRequest> optDeliveries(deliveries);
    
    optimizer.optimizeDeliveryOrder(depot, optDeliveries, d, d);
    GeoCoord current=depot;
    list<StreetSegment> route;
    commands.clear();
   
    string lastStreet,direction;
    DeliveryCommand tempCommand;
    StreetSegment startSeg, endSeg;
    
    double angle;
 
    
    for(int i=0;i<optDeliveries.size()+1;i++){
        
        if(i<optDeliveries.size())current=optDeliveries[i].location;
      
        if(i==0){
            router.generatePointToPointRoute(depot, current, route, d);
        }else if(i==optDeliveries.size()){
            router.generatePointToPointRoute(optDeliveries[optDeliveries.size()-1].location, depot, route, d);
        }else router.generatePointToPointRoute(optDeliveries[i-1].location,current, route, d);
        totalDistanceTravelled+=d;
        if(i<optDeliveries.size())current=optDeliveries[i].location;
        else current=depot;
        lastStreet= route.begin()->name;
        
        for(auto it=route.begin();it!=route.end();it++){
            if(it->end==depot &&i==optDeliveries.size()){

                angle=angleBetween2Lines(*(--it), *(++it));

                if(angle<1||angle>359 ){
                    startSeg=*it;
                    lastStreet=it->name;
                    while(!it->name.compare(lastStreet)&&it!=route.end()){
                        it++;
                    }
                    it--;
                    endSeg=*it;
                    angle=angleOfLine(startSeg);

                    tempCommand.initAsProceedCommand(getDirection(angle), it->name, distanceEarthMiles(startSeg.start, endSeg.end));
                    commands.push_back(tempCommand);

                    it=route.end();
                    break;

                }else{

                   
                    if(angle>=1&&angle<180) direction="left";
                    else direction="right";
                    tempCommand.initAsTurnCommand(direction, it->name);
                    lastStreet=it->name;
                    commands.push_back(tempCommand);
                    angle=angleOfLine(*it);
                    tempCommand.initAsProceedCommand(getDirection(angle), it->name, distanceEarthMiles(it->start, it->end));
                    commands.push_back(tempCommand);
                    it=route.end();
                    break;
                }

            }
          
            if(!it->name.compare(lastStreet)){
                
                startSeg=*(it);
                do{
                    it++;
                }while(!it->name.compare(lastStreet)&&it!=route.end());
                it--;
                
                
                endSeg=*it;
                angle=angleOfLine(startSeg);
               
                tempCommand.initAsProceedCommand(getDirection(angle), lastStreet, max(distanceEarthMiles(startSeg.start, endSeg.start),distanceEarthMiles(startSeg.start, startSeg.end)));
                
            }else{
                if(it->name=="Westwood Boulevard"){
                    cout<<((--it)->name)<<", "<<(++it)->name<<endl;
                }
                angle=angleBetween2Lines(*(--it), *(++it));
                
                if(angle<1||angle>359 ){
                    startSeg=*it;
                    lastStreet=it->name;
                    while(!it->name.compare(lastStreet)&&it!=route.end()){
                        it++;
                    }
                    it--;
                    endSeg=*it;
                    angle=angleOfLine(startSeg);
                    lastStreet=it->name;
                    tempCommand.initAsProceedCommand(getDirection(angle), it->name, distanceEarthMiles(startSeg.start, endSeg.end));
                    commands.push_back(tempCommand);
                   
                    
                    continue;
                            
                }else{
                    
                    if(angle>=1&&angle<180) direction="left";
                    else direction="right";
                    tempCommand.initAsTurnCommand(direction, it->name);
                    lastStreet=it->name;
                    commands.push_back(tempCommand);
                    continue;
                    
                }
            }
            commands.push_back(tempCommand);
            lastStreet=(--it)->name;
            
            it++;
            
            
        
    }
        if(i<optDeliveries.size()){
        tempCommand.initAsDeliverCommand(optDeliveries[i].item);
        commands.push_back(tempCommand);
        
        }
        
    }
    
    
    
    return DELIVERY_SUCCESS;  // Delete this line and implement this function correctly
}

//******************** DeliveryPlanner functions ******************************

// These functions simply delegate to DeliveryPlannerImpl's functions.
// You probably don't want to change any of this code.

DeliveryPlanner::DeliveryPlanner(const StreetMap* sm)
{
    m_impl = new DeliveryPlannerImpl(sm);
}

DeliveryPlanner::~DeliveryPlanner()
{
    delete m_impl;
}

DeliveryResult DeliveryPlanner::generateDeliveryPlan(
    const GeoCoord& depot,
    const vector<DeliveryRequest>& deliveries,
    vector<DeliveryCommand>& commands,
    double& totalDistanceTravelled) const
{
    return m_impl->generateDeliveryPlan(depot, deliveries, commands, totalDistanceTravelled);
}
