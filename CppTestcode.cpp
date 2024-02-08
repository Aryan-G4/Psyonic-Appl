


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if(lineStream.fail()){
            cout << "Error: invalid command" << endl;
        }
        
        else if (command != "maxShapes" && command != "create" && 
            command != "move" && command != "rotate" && 
            command != "draw" && command != "delete"){
                cout << "Error: invalid command"<<endl;
            }


        else if (lineStream.eof()){
            cout << "Error: too few arguments" << endl;
        }

        

        //////////////////////////////////////////////////////
        else if(command == "maxShapes"){ //MAX SHAPES COMMAND (expecting ">maxshapes 8")
            int size;
            lineStream >> size; //assign the next value to size
            
            //error cases
            if (lineStream.fail()){
                if (lineStream.eof() == true){
                    cout << "Error: too few arguments"<<endl;//end of file?? put in some values user cmon
                } 
                
                else{
                    cout << "Error: invalid argument"<<endl; //not a valid integer
                }
            }

            if (size < 1){ // invalid array size bruih
                cout << "Error: invalid value" << endl;
            }

            if (!lineStream.eof()){ //why are we not at the end of file
                cout << "Error: too many arguments" << endl;
            }

            //valid input
            else{
                shapesArray = new Shape*[size]; //new array the size of size
                int arrayspot = 0;
                while (arrayspot < size){
                    shapesArray[arrayspot] = nullptr;
                    arrayspot++;
                }
                max_shapes = size;
                shapeCount = 0;
                cout << "New database: max shapes is " << size << endl;
                
            }
        }






        else if(command == "create"){ // CREATE a new mf shape
            string newname;
            lineStream >> newname;
            
            if (lineStream.fail()){
                if (lineStream.eof()){
                    cout << "Error: too few arguments"<<endl;
                }
                else{
                    cout << "Error: invalid argument"<<endl;
                }
            }
            else if (newname == "all" || newname == "ellipse" || newname == "rectangle" || 
                        newname == "circle" || newname == "triangle" || newname == "maxShapes" || 
                        newname == "create" || newname == "move" || 
                        newname == "rotate" || newname == "draw"){
                            cout << "Error: invalid shape name" << endl;
                        }

            else if (max_shapes == shapeCount){
                cout << "Error: shape array is full" << endl;
            }

            else{
                
                bool existname = false;
                int n =0;
                //cout << "max_shapes is " << max_shapes <<endl; //TESTER CODE
                while (!existname && n < max_shapes){
                    if (shapesArray[n] != nullptr && newname == shapesArray[n]->getName()){
                        existname = true;
                    }
                    else if (shapesArray[n] == nullptr) /*(newname == shapesArray[n]->getName())*/{
                        
                        n++;
                    }
                    else{
                        n++;
                    }
                    
                }
                if (existname){ 
                    cout << "Error: shape " << newname << " exists"<< endl;
                
                }
                else{ // shape name valid
                    string newtype;
                    lineStream >> newtype;

                    if (lineStream.fail()){
                        if (lineStream.eof()){
                            cout << "Error: too few arguments"<<endl;
                        }
                        else{
                            cout << "Error: invalid argument"<<endl;
                        }
                    }

                    else if (newtype != "ellipse" && newtype != "circle" && 
                        newtype != "rectangle" && newtype != "triangle" ){
                            cout << "Error: invalid shape type" << endl;
                    }

                    else{ //type is valid
                        int xloc;
                        lineStream >> xloc;

                        if (lineStream.fail()){
                            if (lineStream.eof()){
                                cout << "Error: too few arguments"<<endl;
                            }
                            else{
                                cout << "Error: invalid argument"<<endl;
                            }      
                        }

                        else if (xloc < 0){
                            cout << "Error: invalid value" << endl;
                        }
                        else{
                            int yloc;
                            lineStream >> yloc;
                            if (lineStream.fail()){
                                if (lineStream.eof()){
                                    cout << "Error: too few arguments"<<endl;
                                }
                                else{
                                    cout << "Error: invalid argument"<<endl;
                                }      
                            }

                            else if (yloc < 0){
                                cout << "Error: invalid value" << endl;
                            }
                            else{
                                int xsize;
                                lineStream >> xsize;
                                if (lineStream.fail()){
                                    if (lineStream.eof()){
                                        cout << "Error: too few arguments"<<endl;
                                    }
                                    else{
                                        cout << "Error: invalid argument"<<endl;
                                    }      
                                }

                                else if (xsize < 0){
                                    cout << "Error: invalid value" << endl;
                                }
                                else{
                                    int ysize;
                                    lineStream >> ysize;
                                    if (lineStream.fail()){
                                        if (lineStream.eof()){
                                            cout << "Error: too few arguments"<<endl;
                                        }
                                        else{
                                            cout << "Error: invalid argument"<<endl;
                                        }      
                                    }

                                    else if (ysize < 0){
                                        cout << "Error: invalid value";
                                    }

                                    else if (newtype == "circle" && ysize != xsize){
                                        cout << "Error: invalid value" <<endl;
                                    }

                                    else if (!lineStream.eof()){ //why are we not at the end of file
                                        cout << "Error: too many arguments" << endl;
                                    }

                                    else{ // WE ARE GOOD TO GO
                                    
                                    int emptyspot = 0;
                                    
                                    while (shapesArray[emptyspot] != nullptr && emptyspot < max_shapes){
                                        emptyspot ++;
                                    }
                                    //cout << "empty spot chosen is " << emptyspot << endl;
                                    shapesArray[emptyspot] = new Shape(newname, newtype, xloc, xsize, yloc, ysize);
                                    cout << "Created " << newname << ": "<< newtype << " "
                                    << xloc <<" "<< yloc <<" "<< xsize << " "<< ysize << endl;
                                    shapeCount++;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }   
        }


        else if(command == "move"){ // MOVE IT
            string movename;
            
            lineStream  >> movename;

            
            if (lineStream.fail()){
                if (lineStream.eof()){
                    cout << "Error: too few arguments"<<endl;
                }
                else{
                    cout << "Error: invalid argument"<<endl;
                }
            }

            else{
                bool existname = false;
                int n =0;
                //cout << "max_shapes is " << max_shapes <<endl; //TESTER CODE
                while (!existname && n < max_shapes){
                    if (shapesArray[n] != nullptr && movename == shapesArray[n]->getName()){
                        //cout << "shape #" << n << " has a name of " << shapesArray[n]->getName() <<endl;
                        existname = true;
                    }
                    else if (shapesArray[n] == nullptr) /*(newname == shapesArray[n]->getName())*/{
                        
                        n++;
                    }
                    else{
                        n++;
                    }
                    
                }
                if (!existname){ 
                    cout << "Error: shape " << movename << " not found"<< endl;
                
                }
            
                /*bool existname = false;
                int n =0;
                while (!existname || n < max_shapes){
                    if (movename == shapesArray[n]->getName()){
                        existname = true;
                    }
                    else{
                        n++;
                    }
                }

                if (!existname){
                    cout << "Error: shape " << movename << " not found"<< endl;
                }*/

                else {
                    int xloc;
                    lineStream >> xloc;

                    if (lineStream.fail()){
                        if (lineStream.eof()){
                            cout << "Error: too few arguments"<<endl;
                        }
                        else{
                            cout << "Error: invalid argument"<<endl;
                        }      
                    }

                    else if (xloc < 0){
                        cout << "Error: invalid value" << endl;
                    }
                    else{
                        int yloc;
                        lineStream >> yloc;
                        if (lineStream.fail()){
                            if (lineStream.eof()){
                                cout << "Error: too few arguments"<<endl;
                            }
                            else{
                                cout << "Error: invalid argument"<<endl;
                            }      
                        }

                        

                        else if (yloc < 0){
                            cout << "Error: invalid value" << endl;
                        }

                        else if (!lineStream.eof()){ //why are we not at the end of file
                            cout << "Error: too many arguments" << endl;
                        }

                        else{
                            shapesArray[n]->setXlocation(xloc);
                            shapesArray[n]->setYlocation(yloc);
                            cout << "Moved " << movename << " to " << xloc << " " << yloc << endl;
                        }
                    }


                }
            }    

        }

        else if (command == "rotate"){
            string rotname;
            lineStream  >> rotname;

            
            if (lineStream.fail()){
                if (lineStream.eof()){
                    cout << "Error: too few arguments"<<endl;
                }
                else{
                    cout << "Error: invalid argument"<<endl;
                }
            }

            else{
                bool existname = false;
                int n =0;
                //cout << "max_shapes is " << max_shapes <<endl; //TESTER CODE
                while (!existname && n < max_shapes){
                    if (shapesArray[n] != nullptr && rotname == shapesArray[n]->getName()){
                        //cout << "shape #" << n << " has a name of " << shapesArray[n]->getName() <<endl;
                        existname = true;
                    }
                    else if (shapesArray[n] == nullptr) /*(newname == shapesArray[n]->getName())*/{
                        
                        n++;
                    }
                    else{
                        n++;
                    }
                    
                }
                if (!existname){ 
                    cout << "Error: shape " << rotname << " not found"<< endl;
                
                }
            
                /*bool existname = false;
                int n =0;
                while (!existname || n < max_shapes){
                    if (rotname == shapesArray[n]->getName()){
                        existname = true;
                    }
                    else{
                        n++;
                    }
                }

                if (!existname){
                    cout << "Error: shape " << rotname << " not found"<< endl;
                }*/

                else {
                    int angle;
                    lineStream >> angle;

                    if (lineStream.fail()){
                        if (lineStream.eof()){
                            cout << "Error: too few arguments"<<endl;
                        }
                        else{
                            cout << "Error: invalid argument"<<endl;
                        }      
                    }


                    else if (angle < 0 || angle > 360){
                        cout << "Error: invalid value" << endl;
                    }

                    else if (!lineStream.eof()){ //why are we not at the end of file
                        cout << "Error: too many arguments" << endl;
                    }                    

                    else{
                        shapesArray[n]->setRotate(angle);
                        cout << "Rotated " << rotname << " by " << angle << " degrees" << endl;
                    }
                }
            }            
        }

        else if (command == "draw"){
            string sketch;
            lineStream  >> sketch;

            
            if (lineStream.fail()){
                if (lineStream.eof()){
                    cout << "Error: too few arguments"<<endl;
                }
                else{
                    cout << "Error: invalid argument"<<endl;
                }
            }



            else if (sketch == "all"){
                
                //cout << max_shapes << " is max shapes" << endl;
                cout << "Drew all shapes" << endl;
                if (shapeCount != 0){
                    for (int i = 0; i < max_shapes; i++){
                        if (shapesArray[i] != nullptr){
                            //cout << " ";
                            shapesArray[i]->draw();
                        }
                        else{
                            //i++;
                        }
                    }
                }    //cout <<endl;
            }

            else{
                bool existname = false;
                int n =0;
                //cout << "max_shapes is " << max_shapes <<endl; //TESTER CODE
                while (!existname && n < max_shapes){
                    if (shapesArray[n] != nullptr && sketch == shapesArray[n]->getName()){
                        //cout << "shape #" << n << " has a name of " << shapesArray[n]->getName() <<endl;
                        existname = true;
                    }
                    else if (shapesArray[n] == nullptr) /*(newname == shapesArray[n]->getName())*/{
                        
                        n++;
                    }
                    else{
                        n++;
                    }
                    
                }
                if (!existname){ 
                    cout << "Error: shape " << sketch << " not found"<< endl;
                
                }

                else if (!lineStream.eof()){ //why are we not at the end of file
                    cout << "Error: too many arguments" << endl;
                }                

                else{
                    cout << "Drew ";
                    shapesArray[n]-> draw();
                    //cout << endl;
                }

            }
        }

       
       
       
       
       
        else if (command == "delete"){
            string badshape;
            lineStream  >> badshape;

            if (lineStream.fail()){
                if (lineStream.eof()){
                    cout << "Error: too few arguments"<<endl;
                }
                else{
                    cout << "Error: invalid argument"<<endl;
                }
            }

        

            else if (badshape == "all"){
                if (!lineStream.eof()){ //why are we not at the end of file
                    cout << "Error: too many arguments" << endl;
                }
                else{
                    cout << "Deleted: all shapes"<<endl;
                    if (shapeCount != 0){
                        shapeCount = 0;
                        for (int i = 0; i <max_shapes; i++){
                            if (shapesArray[i] == nullptr){
                                
                                i++;
                            }
                            else{
                                delete shapesArray[i];
                                //shapesArray[i] == nullptr;
                                i++;
                            }
                        }
                    }
                }
            }

            else{
                bool existname = false;
                int n = 0;
                //cout << "max_shapes is " << max_shapes <<endl; //TESTER CODE
                while (!existname && n < max_shapes){
                    if (shapesArray[n] != nullptr && badshape == shapesArray[n]->getName()){
                        //cout << "shape #" << n << " has a name of " << shapesArray[n]->getName() <<endl;
                        existname = true;
                    }
                    else if (shapesArray[n] == nullptr) /*(newname == shapesArray[n]->getName())*/{
                        
                        n++;
                    }
                    else{
                        n++;
                    }
                    
                }
                if (!existname){ 
                    cout << "Error: shape " << badshape << " not found"<< endl;
                
                }

                else if (!lineStream.eof()){ //why are we not at the end of file
                    cout << "Error: too many arguments" << endl;
                }   

                else{
                    cout << "Deleted shape " << badshape << endl;
                    delete shapesArray[n];
                    shapesArray[n] = nullptr;
                    shapeCount -= 1;
                }

            }





        }

       

        else{
            cout << "Error: invalid command" << endl; //nothing bro said makes sense
        }
        //////////////////////////////////////////////////////
        
        
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    
    
    // Delete all shapes
    for (int i=0; i < max_shapes; i++){
        if (shapesArray[i] != nullptr){
            delete shapesArray[i];
            //shapesArray[i] == nullptr;
        }
    }
    delete [] shapesArray;

    return 0;
}

