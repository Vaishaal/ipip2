//
//  Grid.h
//  ipip2
//
//  Created by Vaishaal Shankar on 5/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ipip2_Grid_h
#define ipip2_Grid_h
#include "Point.h"
#include <string>
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm> 
#include <iterator> 
#include <sstream> 
#include <set>
#include <tr1/unordered_map> 




typedef tr1:: unordered_map<double, Point> Line;
typedef tr1:: unordered_map<double, Line *> Plane;

typedef tr1::unordered_map<double, Plane *> PlaneSet;
typedef tr1::unordered_map<double, double> Zmapping;
typedef tr1::unordered_map<Point, string> boundryMap;
using namespace std; 

class Grid { 

    double xStep;
    double yStep;
    double zStep;
    double size; 
    PlaneSet *allPlanes;
    Zmapping *Zmap;
    set<double> allContourZ;    
    
    set<double> allZ;
    public:
        bool addPoint(Point point); //Adds a point if it falls within the x, y and z intervals 
        double applyFunc(double slope, double intersect, double x) ;
        double closestX(double x);
        bool testFunc(double slope, double intersect, double x);
        Point findPoint(double x, double y, double z);
        bool addContours(Point first, Point second, double workingZ); //Adds all points that fall on both the designated x & y intervals and the line between the two given points on the given z plane. 
        void addAllContours(ContourPointListZSlistMapPair);
        double findNearestZ(Point input);
    bool drawLine(Point first, Point second); 
        bool checkValid(double x, double y, double z); 
        void fill();
        double closestY(double value);

    Grid(double xStep, double yStep, double zStep,double size);

};







#endif
