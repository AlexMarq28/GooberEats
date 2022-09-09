//
//
//
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include "provided.h"
//
//
//using namespace std;
//
//bool loadDeliveryRequests(string deliveriesFile, GeoCoord& depot, vector<DeliveryRequest>&v);
//bool parseDelivery(string line, string& lat, string& lon, string& item);
//
////
////
////int main(){
////
////
////    StreetMap s;
////    s.load("/Users/alemarquezvera/cs32/AMProject4/AMProject4/mapdata.txt");
////    GeoCoord d("34.0625329", "-118.4470263"); //Weyburn and Broxton Depot
////    vector<DeliveryRequest> dr;
////    vector<DeliveryCommand> dc;
////    double dt;
////    DeliveryPlanner dp(&s);
////    DeliveryRequest r1("Beef Bulgogi:(Eng IV)",GeoCoord("34.0687443", "-118.4449195") );//Sproul Landing
////    DeliveryRequest r2("RyDunk Bier",GeoCoord("34.0685657", "-118.4489289") );//Gayley and Strathmore Beta Theta Pi
////    DeliveryRequest r3("illegal chick sandies",GeoCoord("34.0625329","-118.4470263") );//Broxton and Weyburn
////    DeliveryRequest r4("de neve late night coronavirus-infected pizza",GeoCoord("34.0616291","-118.4416199") );//Hilgard and Weyburn
////    DeliveryRequest r5("extra hot cheetos",GeoCoord("34.0656797","-118.4505131") );//Levering and Strathmore
////    DeliveryRequest r6("sprite",GeoCoord("34.0636860","-118.4453568") );//Le Conte and WestWood
////    DeliveryRequest r7("RyDunk Condoms",GeoCoord("34.0683189", "-118.4536522") );//Kelton and Ophir
////
////
////     dr.push_back(r1);
//////     dr.push_back(r2);
//////     dr.push_back(r3);
//////     dr.push_back(r4);
//////     dr.push_back(r5);
//////     dr.push_back(r6);
//////     dr.push_back(r7);
////
////
////
////    dp.generateDeliveryPlan(d, dr, dc, dt);
////    PointToPointRouter ptpr(&s);
////    list<StreetSegment> route;
////
////
////
////    for( int i=0;i<dc.size();i++){
////        cout<<dc[i].description()<<endl;
////    }
////    cout<<dt<<" miles"<<endl;
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////}
////
////
//
//
//
//
//
////Broxton and Weyburn: 34.0625329 -118.4470263
////Sproul Landing Intersection 34.0712323 -118.4505969
////De Neve Suites Intersection 34.0718238 -118.4525699
////Levering and Strathmore 34.0656797 -118.4505131
////Kelton and Ophir 34.0683189 -118.4536522
////Strathmore and Westwood Plaza (Eng IV) 34.0687443 -118.4449195
////Gayley and Strathmore (Beta Theta Pi frat) 34.0685657 -118.4489289
////De Neve Plaza @ Charles E Young Drive 34.0706349 -118.4492679
////Le Conte and Westwood Blvd 34.0636860 -118.4453568
////Broxton and Weyburn 34.0625329 -118.4470263
////Hilgard and Weyburn 34.0616291 -118.4416199
////Charles E Young and De Neve 34.0711774 -118.4495120
////Hilgard and Manning 34.0666168 -118.4395786
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
//
//
////
////int main(){
////
////    StreetMap s;
////    s.load("/Users/alemarquezvera/cs32/AMProject4/AMProject4/mapdata.txt");
////    vector<StreetSegment> segs;
////    GeoCoord g("34.0768503" ,"-118.4429619");
////    assert(s.getSegmentsThatStartWith(g, segs));
////
////
////              s.getSegmentsThatStartWith(g, segs);
////
////
////
////
////
////
////
////
////    PointToPointRouter p(&s);
////    list<StreetSegment> route;
////    double dist;
////    p.generatePointToPointRoute(GeoCoord("34.0768503" ,"-118.4429619"), GeoCoord("34.0712329","-118.4032474"), route, dist);
////
////    cout<<"Distance Travelled: "<<dist<<endl;
////    for(auto i=route.begin();i!=route.end();i++){
////
////           cout<<i->start.latitudeText <<", "<<i->start.longitudeText<<endl;
////           cout<<i->end.latitudeText <<", "<<i->end.longitudeText<<endl;
////
////
////
////       }
////
////
////
////
////}
//
//
//
//  int main(int argc, char *argv[])
//{
//    if (argc != 3)
//    {
//        cout << "Usage: " << argv[0] << " mapdata.txt deliveries.txt" << endl;
//        return 1;
//    }
//
//    StreetMap sm;
//
//    if (!sm.load(argv[1]))
//    {
//        cout << "Unable to load map data file " << argv[1] << endl;
//        return 1;
//    }
//
//    GeoCoord depot;
//    vector<DeliveryRequest> deliveries;
//    if (!loadDeliveryRequests(argv[2], depot, deliveries))
//    {
//        cout << "Unable to load delivery request file " << argv[2] << endl;
//        return 1;
//    }
//
//    cout << "Generating route...\n\n";
//
//    DeliveryPlanner dp(&sm);
//    vector<DeliveryCommand> dcs;
//    double totalMiles;
//    DeliveryResult result = dp.generateDeliveryPlan(depot, deliveries, dcs, totalMiles);
//    if (result == BAD_COORD)
//    {
//        cout << "One or more depot or delivery coordinates are invalid." << endl;
//        return 1;
//    }
//    if (result == NO_ROUTE)
//    {
//        cout << "No route can be found to deliver all items." << endl;
//        return 1;
//    }
//    cout << "Starting at the depot...\n";
//    for (const auto& dc : dcs)
//        cout << dc.description() << endl;
//    cout << "You are back at the depot and your deliveries are done!\n";
//    cout.setf(ios::fixed);
//    cout.precision(2);
//    cout << totalMiles << " miles travelled for all deliveries." << endl;
//}
//
//bool loadDeliveryRequests(string deliveriesFile, GeoCoord& depot, vector<DeliveryRequest>& v)
//{
//    ifstream inf(deliveriesFile);
//    if (!inf)
//        return false;
//    string lat;
//    string lon;
//    inf >> lat >> lon;
//    inf.ignore(10000, '\n');
//    depot = GeoCoord(lat, lon);
//    string line;
//    while (getline(inf, line))
//    {
//        string item;
//        if (parseDelivery(line, lat, lon, item))
//            v.push_back(DeliveryRequest(item, GeoCoord(lat, lon)));
//    }
//    return true;
//}
//
//bool parseDelivery(string line, string& lat, string& lon, string& item)
//{
//    const size_t colon = line.find(':');
//    if (colon == string::npos)
//    {
//        cout << "Missing colon in deliveries file line: " << line << endl;
//        return false;
//    }
//    istringstream iss(line.substr(0, colon));
//    if (!(iss >> lat >> lon))
//    {
//        cout << "Bad format in deliveries file line: " << line << endl;
//        return false;
//    }
//    item = line.substr(colon + 1);
//    if (item.empty())
//    {
//        cout << "Missing item in deliveries file line: " << line << endl;
//        return false;
//    }
//    return true;
//}
//
//
//
///*
// 34.0687443 -118.4449195:B-Plate salmon (Eng IV)
// 34.0685657 -118.4489289:Pabst Blue Ribbon beer (Beta Theta Pi)
// 34.0718238 -118.4525699:Skateboard (De Neve Suites)
// 34.0567807 -118.4249674:Coffee Beans (Coffee Bean Cafe)
// 34.0656797 -118.4505131:Avocado and Chicken Skillet (Atrium Apartments)
//
// */







#include "ExpandableHashMap.h"
#include "provided.h"
#include <vector>
#include <list>
#include <string>
#include <initializer_list>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <thread>
#include <future>
#include <chrono>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <unistd.h>

using namespace std;

bool isNear(double x, double y)
{
    return abs(x - y) < 1e-5;
}

char* prepfile(const string& lines)
{
    static int nfiles = 0;
    static char filename[][40] = {
        "zzdatasmXXXXXX", "zzdatasmXXXXXX", "zzdatasmXXXXXX",
        "zzdatasmXXXXXX", "zzdatasmXXXXXX", "zzdatasmXXXXXX",
        "zzdatasmXXXXXX", "zzdatasmXXXXXX", "zzdatasmXXXXXX",
        "zzdatasmXXXXXX"
    };
    if (nfiles == sizeof(filename)/sizeof(filename[0]))
    {
        cerr << "Too many files" << endl;
        exit(1);
    }
    int fd = mkstemp(filename[nfiles]);
    if (nfiles == 0)
        atexit([]{ for (int k = 0; k < nfiles; k++) remove(filename[k]); });
    if (fd == -1)
    {
        cerr << "Cannot create " << filename[nfiles] << endl;
        exit(1);
    }
    close(fd);
    ofstream ofs(filename[nfiles]);
    if (!ofs)
    {
        cerr << "Cannot open " << filename[nfiles] << endl;
        exit(1);
    }
    char lastch = '\n';
    for (auto c : lines)
    {
        lastch = (c == '/' ? '\n' : c);
        ofs.put(lastch);
    }
    if (lastch != '\n')
        ofs.put('\n');
    return filename[nfiles++];
}

void load(StreetMap& sm, const string& lines)
{
    sm.load(prepfile(lines));
}

#define gc(x,y) GeoCoord(#x,#y)
#define ss(x1,y1,x2,y2,n) StreetSegment(GeoCoord(#x1,#y1), GeoCoord(#x2,#y2), n)

double actualdist(const GeoCoord& depot, const vector<DeliveryRequest>& req)
{
    if (req.empty())
        return 0;
    double dist = 0;
    dist += distanceEarthMiles(depot, req.front().location);
    for (int k = 0; k < req.size() - 1; k++)
        dist += distanceEarthMiles(req[k].location, req[k+1].location);
    dist += distanceEarthMiles(req.back().location, depot);
    return dist;
}

bool lessdo(const DeliveryRequest& lhs, const DeliveryRequest& rhs)
{
    if (lhs.location < rhs.location) return true;
    if (rhs.location < lhs.location) return false;
    return lhs.item < rhs.item;
}

bool eqdo(const DeliveryRequest& lhs, const DeliveryRequest& rhs)
{
    return lhs.location == rhs.location  &&  lhs.item == rhs.item;
}

bool doit(DeliveryOptimizer& dop, const GeoCoord& depot,
    vector<DeliveryRequest>& req, double& odist, double& ndist,
    double& oactdist, double& nactdist)
{
    oactdist = actualdist(depot, req);
    auto oldreq = req;
    sort(begin(oldreq), end(oldreq), lessdo);
    dop.optimizeDeliveryOrder(depot, req, odist, ndist);
    nactdist = actualdist(depot, req);
    auto newreq = req;
    sort(begin(newreq), end(newreq), lessdo);
    return oldreq.size() == newreq.size()  &&
        equal(begin(oldreq), end(oldreq), begin(newreq), eqdo);
}

bool matches(const DeliveryCommand& cmd, char type, string name, string dir, double& cumdist)
{
    if (type != 'P')
    {
        cerr << "Wrong call to matches P!" << endl;
        return false;
    }
    cumdist += cmd.dist();
    return cmd.type() == type  &&  cmd.name() == name  &&  cmd.dir() == dir;
}

bool matches(const DeliveryCommand& cmd, char type, string name, string dir)
{
    if (type != 'T')
    {
        cerr << "Wrong call to matches T!" << endl;
        return false;
    }
    return cmd.type() == type  &&  cmd.name() == name  &&  cmd.dir() == dir;
}

bool matches(const DeliveryCommand& cmd, char type, string item)
{
    if (type != 'D')
    {
        cerr << "Wrong call to matches D!" << endl;
        return false;
    }
    return cmd.item() == item;
}

void xxxtestone(int n)
{
    StreetMap sm;
    vector<DeliveryRequest> req;
    vector<DeliveryCommand> cmds;
    double dist = 0;

    switch (n)
    {
             default: {
    cout << "Bad argument" << endl;
        } break; case  1: {
    load(sm, "Broadway/2/1.2 2.3 1.4 2.5/1.4 2.5 1.5 2.5/");
    DeliveryPlanner dp(&sm);
    dp.generateDeliveryPlan(gc(1.2,2.3), req, cmds, dist);
    assert(cmds.empty()  &&  dist == 0);
        } break; case  2: {
    load(sm, "Kasturba Gandhi Marg/2/1.0 2.0 2.0 3.0/2.0 3.0 1.0 3.0/");
    DeliveryPlanner dp(&sm);
    req.push_back({ "A", gc(1.0,3.0) });
    dist = -999;
    dp.generateDeliveryPlan(gc(1.0,2.0), req, cmds, dist);
    assert(dist > 0);
        } break; case  3: {
    load(sm, "Elm/2/1.0 2.0 2.0 3.0/2.0 3.0 1.0 3.0/");
    DeliveryPlanner dp(&sm);
    req.push_back({ "rice", gc(1.0,3.0) });
    dp.generateDeliveryPlan(gc(1.0,2.0), req, cmds, dist);
    assert(cmds.size() == 3);
    double cumdist = 0;
    assert(matches(cmds[0], 'P', "Elm", "northeast", cumdist));
    assert(matches(cmds[1], 'D', "rice"));
    assert(matches(cmds[2], 'P', "Elm", "north", cumdist));
    assert(isNear(dist, 333.577));
    assert(isNear(dist, cumdist));
        } break; case  4: {
    load(sm, "Elm/1/1.0 2.0 2.0 3.0/Oak/1/2.0 3.0 1.0 3.0/");
    DeliveryPlanner dp(&sm);
    req.push_back({ "rice", gc(1.0,3.0) });
    dp.generateDeliveryPlan(gc(1.0,2.0), req, cmds, dist);
    assert(cmds.size() == 7);
    double cumdist = 0;
    assert(matches(cmds[0], 'P', "Elm", "northeast", cumdist));
    assert(matches(cmds[1], 'T', "Oak", "right"));
    assert(matches(cmds[2], 'P', "Oak", "south", cumdist));
    assert(matches(cmds[3], 'D', "rice"));
    assert(matches(cmds[4], 'P', "Oak", "north", cumdist));
    assert(matches(cmds[5], 'T', "Elm", "left"));
    assert(matches(cmds[6], 'P', "Elm", "southwest", cumdist));
    assert(isNear(dist, 333.577));
    assert(isNear(dist, cumdist));
        } break; case  5: {
    load(sm, "Elm/1/1.0 2.0 2.0 3.0/Oak/1/2.0 3.0 3.0 4.0/");
    DeliveryPlanner dp(&sm);
    req.push_back({ "rice", gc(3.0,4.0) });
    dp.generateDeliveryPlan(gc(1.0,2.0), req, cmds, dist);
    assert(cmds.size() == 5);
    double cumdist = 0;
    assert(matches(cmds[0], 'P', "Elm", "northeast", cumdist));
    assert(matches(cmds[1], 'P', "Oak", "northeast", cumdist));
    assert(matches(cmds[2], 'D', "rice"));
    assert(matches(cmds[3], 'P', "Oak", "southwest", cumdist));
    assert(matches(cmds[4], 'P', "Elm", "southwest", cumdist));
    assert(isNear(dist, 390.722));
    assert(isNear(dist, cumdist));
        }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    if (n < 1  ||  n > 5)
    {
        cout << "Bad test number" << endl;
        return 1;
    }
    xxxtestone(n);
    cout << "Passed" << endl;
}
