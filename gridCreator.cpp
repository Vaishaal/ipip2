//  dataLoading.

#include "Point.h" 
using namespace std;
string PATH = "/Users/vaishaal/Documents/Research2012/" ;//Path to IPIP files
string PATIENTPATH = PATH + "DATA/";

zset allContourZSlices;




vector<string> stringSplit(string input) { 
    istringstream iss(input);
    vector<string> tokens;
  
    copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
         back_inserter<vector<string> >(tokens));
    return tokens;
}


/*  Returns a pair of a list containing all contour points and table of locations of the z slices within that list 
 *  @param string patientAnatomy the absolute path to the patient's anatomy.txt file 
 */


ContourPointListZSlistMapPair discretize(string patientAnatomy) { 
    //Returns a pair that contains a list of Point objects of all the contour points for a given 
    //patients anatomy.txt file, and a table mapping different Z axis
    //values to the corresponding index contours start in the list. 
    //Note that a particular value can have multiple corresponding indices, 
    //this marks contours for different organs on the same Z slice 
    
    
    //Opens an input stream to read the lines of the patient anatomy
    ifstream patientfile (patientAnatomy.c_str()); 
    
    //Instantiates the hashtable that maps Z values to indices
    contourSliceMap table;
    
    //The current organ that the loop is dealing with
    string workingOrgan;

    //The list containing all the contour points for this patient 
    sliceList superList; 
    
    //The line of text read from the anatomy file
    string line;
    
    int count = 0;
    double prevz = 0; 
    double z = 0;
    if (patientfile.is_open())
    {
        while ( patientfile.good() )
        {
            count++ ; 
            getline (patientfile,line);
            if (count >= 6) { //first 6 lines of all anatomy.txt files do not contain any information
                
                vector<string> tokens = stringSplit(line); //splits the string into a list delimeted by space
                int size = tokens.size(); //the size of the newly created token list signifies the content of the line being read
                if (size == 1) { //One element list starts contours for a new organ 
                    workingOrgan = tokens[0]; //New organ updated
                    getline(patientfile, line);//Skip the next line 
                }
                    
                else if (size == 3) {  //Three element list is a contour point
                    double x = atof(tokens[0].c_str()); //Gets x value
                    double y = atof(tokens[1].c_str()); //Gets y value
                    z = atof(tokens[2].c_str()); //Gets z value
                    
                    
                    //The z value is compared to the value before it to check if new Z slice has been entered, if it has
                    //
                    if (prevz != z) { 
                        allContourZSlices.insert(z);
                        table.insert(make_pair(z,superList.size()));
                        prevz = z; 

                    }
                    Point newPoint = Point(x,y,z,true); //Creates the point object 
                    newPoint.organ = workingOrgan; //Adds the organ to the object
                    superList.push_back(newPoint);//Adds the point object to the list
                
                
                    }
                }
                
            }
     
      
        patientfile.close();
        
    } else cout << "could not open file";
   
    
    return ContourPointListZSlistMapPair(superList,table); //Creates a pair containing the h
    
    

}
/* Creates ceiling(gridSize/zStep) flat grids bounded by a cubical box of side length gridSize, fills each grid with dose points 
 
 @param int gridSize the Size of the bounding cube around the grid 
 @param int xStep the x interval of the grid
 @param int yStep the y interval of the grid 
 @param int zStep the z interval of the grid (which is the space between any two adjacent flat planes in this grid) 
 
 */

        
int genGrid(ContourPointListZSlistMapPair input, int gridSize, int xStep = 2, int yStep = 2, int zStep = 3) {
    
    return 0;
    
    
    
}
int main(int argc, char *argv[]) {
    
    string patientAnatomy = PATIENTPATH + argv[1] + "/anatomy.txt"; 
    bool test = Point(1, 2, 3) == Point(1, 2 ,3); 
    ContourPointListZSlistMapPair pair = discretize(patientAnatomy);
 
  
    
    
    return 0;
            
}
        