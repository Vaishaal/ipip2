//
//  Grid.cpp
//  ipip2
//
//  Created by Vaishaal Shankar on 5/23/12.    
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Grid.h"
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
using namespace std; 

Grid::Grid(double xStep, double yStep, double zStep, double size, set<double> allZ) {
    this->xStep = xStep;
    this->yStep = yStep;
    this->zStep = zStep;
    this->size = size;
    this->allContourZ  = allZ;
    allPlanes = new PlaneSet();
    

    
}

bool Grid::checkValid(double x, double y, double z){
    double xval = x/xStep;
    double yval = y/yStep;
    double zval = z/zStep;
    int ixval = (int) xval;
    int iyval = (int) yval;
    int izval = (int) zval;
    if (ixval == xval && iyval == yval && izval == zval) {
        return true;
    }
        return false;
    
}

ostream& operator<<(ostream& out, const Point &p) {
    return out << p.toString();
}

void Grid::fill(){ 
    double currentX = 0;
    double currentY = 0;
    double currentZ = 0;
    int xCount = 0;
    int yCount = 0;
    int zCount = 0;
    while (currentZ <= size) { 
        Plane * thisZ = new Plane();
        allPlanes->insert(make_pair(currentZ, thisZ));
        currentY = 0;
        while(currentY <= size){
            Line * thisY = new Line();
            thisZ->insert(make_pair(currentY, thisY));
            currentX = 0;
            while (currentX <= size){ 
                Point *newPoint = new Point(currentX,currentY,currentZ);
                
                
                cout << *newPoint << "\n";
                thisY->insert(make_pair(currentX, newPoint));
                currentX +=xStep;
            
            }
            currentY+=yStep;
        }
        allZ.insert(currentZ);
        currentZ+=zStep;
    }
    
                
    
}
Point Grid::findPoint(double x, double y, double z) { 
    Plane * myPlane = allPlanes->find(z)->second;
    Line * myLine = myPlane->find(y)->second;
    return myLine->find(x)->second;
    
}
double Grid::closestX(double value) {
    return ((int) value/xStep)  * xStep ;
}
double Grid::closestY(double value) {
    return ((int) value/yStep) * yStep;
}
bool Grid::addContours(Point first, Point second, double workingZ){  
    double workingZslice;
    Plane * workingPlane;
    if (first.zC != second.zC) {
        return false; 
    }
    double zSlice = workingZ;
    if (Zmap->count(zSlice)){
        workingZslice = (Zmap->find(zSlice))->second;
    }
        
    else{ 
        workingZslice = findNearestZ(first);
    }
    workingPlane = allPlanes->find(workingZslice)->second;
    double slope = ((second.yC - first.yC)/(second.xC - first.xC));
    double constant = first.yC - (first.xC * slope);   
    double startX = closestX(first.xC);
    double endX = closestX(second.xC);
    for (int x=startX;x<endX; x+=xStep) {
        double y = closestY(applyFunc(slope, constant, x));
        Point myPoint = findPoint(x, y, first.zC);
        myPoint.isContour = true;
        myPoint.organ = first.organ;
        }
    n 
}
double Grid::applyFunc(double slope, double intersect, double x)  {
    return slope*x + intersect;
}

bool Grid::testFunc(double slope, double intersect, double x) { 
    double value = x/xStep;
    if (value == (int) value) { 
        double y = applyFunc(slope, intersect, x);
        return checkValid(x, y, 0);
    }
    
    
}
double Grid::findNearestZ(Point input) {
     double ourZ = input.zC;
    double minDifference = 999999;
    double closeZ = 999999;
    double difference;

    for (double each:allContourZ) {
        difference = abs(each - ourZ);
        if (difference < minDifference) {
            minDifference = difference;
            closeZ = each;
        }
    }
    if (abs(closeZ - ourZ) > zStep) {
        closeZ = ourZ;
    };
    
    Zmap->insert(make_pair(ourZ, closeZ));
    return closeZ;
}

int main(int argc, char *argv[]) {
    Grid newGrid(2,2,2,100);
    newGrid.fill();

}


        
    
     
