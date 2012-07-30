ipip2 
=====

###Purpose 
To generate optimum dwell times in order to maximize radiation in the target region with the use of the simplex method (via CPLEX)

###Proposed plan 
So far I have just come up with an alogirthm for generating a dose grid in a reasonably speedy time. I'll start with the data structures used in this algorithm.

##Data Structures

#Point 
Represents a single dose point 

has five fields: 
```c
double xC - represents the x coordinate of the point.
```
```c
double yC - represents the y coordinate of the point.
```
```c
double zC  - represents the z coordinate of the point.
```
```c 
double organ - the organ that this point is inside or to the left of (for boundry points)
```
```c
double isContour - boolean that states whether this organ is a contour point or not 
```

#Line 
Represents a line of points with the same y and z coordinates. Represented by tr1:unordered_map (maps keys of x values to points);

#Plane 
Represents a plane of points with the same z coordinate. Represented by tr1:unordered_map (maps keys of y values to lines);

#PlaneSet
Represents the set of all planes. Represented by tr1:unordered_map (maps keys of z values to Planes) 


##The plan
Ok now we have all these data structures, what do we do with them? Ok this is where it gets kind of messy. The purpose of all these data structure is to generate a set of dose points (that vary by a user set xStep, yStep and zStep) that have the organ information filled. After that we can calculate dose rates, from which CPLEX (an optimization library for C++)  can generate the dwell times for the given dwell positions. 

How do we go about this in an efficent manner?

We imagine a box placed around our target region which consists of N dose points without the organ information (just generated through simple iteration). These dose points are organized by the data structures mentioned above. Then we would save the contour points in a similar manner. Next for each slice in the first box we would see if any slice in our set of contour slices correspond to it (by checking if any slice in the contour set is < 1. 





