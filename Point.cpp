//
//  Point.cpp
//  ipip2
//
//  Created by Vaishaal Shankar on 5/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Point.h"
#include <sstream>






Point::Point(double x, double y, double z, bool contour) { 
    isContour = contour;
    xC = x;
    yC= y;
    zC = z; 
}

Point::Point(bool sentinel) {
    isSentinel = true;
    
}

 string Point::toString() const{ 
    std::ostringstream strs;
    strs << xC << " | " << yC << " | " << zC << " | " << organ <<  "\n"; 
    return strs.str();
    
};
