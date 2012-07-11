//
//  Point.h
//  ipip2
//
//  Created by Vaishaal Shankar on 5/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ipip2_Point_h
#define ipip2_Point_h
#include <string>
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm> 
#include <iterator> 
#include <sstream> 
#include <set>
#include  <vector>

#include <tr1/unordered_map> 
class Point;
using namespace std; 
typedef tr1::unordered_multimap<double,int> contourSliceMap;
typedef set<double> zset;
typedef vector<Point> sliceList; 
typedef pair<sliceList, contourSliceMap> ContourPointListZSlistMapPair;

// Point class holds all information for each individual dose point.
// Data can be extracted into string using extract method
// Constructor can also construct object with same format string 
// Constructor can construct with explicit parameter values, isContour is defaulted to false 
class Point
{
    public:
        bool isSentinel; 
        bool isContour; 
        double xC;
        double yC;
        double zC; 
        string organ; 
        Point(double x, double y, double z, bool contour = false); 
        Point(bool Sentinel); 
        string toString() const; 
    

};


#endif
