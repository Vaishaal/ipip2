ipip2 
=====

###Purpose 
To generate optimum dwell times in order to maximize radiation in the target region with the use of the simplex method (via CPLEX)

###Proposed plan 
So far I have just come up with an alogirthm for generating a dose grid in a reasonably speedy time. I'll start with the data structures used in this algorithm.

##Data Structures

#Point 
Represents a dose point has five fields: 
```c
double xC - represents the x coordinate of the point.
```
```c
double yC - represents the y coordinate of the point.
```
```c
double zC  - represents the z coordinate of the point.
```





