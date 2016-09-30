/*Amie Newman and Charles Clayton
 *Last modified: 9/30/16
 *File: stacker.cpp
 *Desc: Implementation of stacker.h. Loads files, stacks and averages them, and saves the stacked image.
 */
#include "stacker.h"

stacker::stacker(){  //construcor to give temp same values as pixels
  temp = pixels;
   }

void stacker::setNumImages(int num){ //set numberOfImages
  numberOfImages = num;
}

void stacker::loadFile(string file, int numberOfImages){ //reads data from file into temp and sums the values of each struct member and puts the sums in pixels
  int num;
  pixel color;
  inputFileName = file; //original fileName to not be manipulated
  
  fileName = file;  //fileName to be manipulated in loadFile

  for(int i = 1; i <= numberOfImages; i++){
    stringstream toNumber;  //stringstream to convert an int to a string to use in manipulation further down
    toNumber << i;
    string number = toNumber.str();

    if( i > 9)
      {                                                                //string manipulation to find the correct files
	fileName = fileName + "/" + fileName + "_0" + number + ".ppm";
      }
    else
      {
	fileName = fileName + "/" + fileName + "_00" + number  + ".ppm";
      }
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    inFile >> magic_number;
    inFile >> width;
    inFile >> height;
    inFile >> max_color;    //read in magic_number "P3" then the width, height, and max_color depth
    
    int j = 0;        //sentinel loop counter
    
    while(inFile){
      if(i == 1)
	{
	  inFile >> color.red;   
	  inFile >> color.green;
	  inFile >> color.blue;    //read in each initial struct member and then push those values to pixels and temp
	  pixels.push_back(color);
	  temp.push_back(color);
	}
	else
	  {
	    inFile >> color.red;                  //reads in struct values to temp then stores the sums in pixels
	    inFile >> color.green;
	    inFile >> color.blue;
	    temp[j].red = color.red;
	    temp[j].green = color.green;
	    temp[j].blue = color.blue;
	    pixels[j].red += temp[j].red;
	    pixels[j].green += temp[j].green;
	    pixels[j].blue += temp[j].blue;
	    j++;
	  }
    }
    
    cout << fileName << endl;  //output for user to track stacking
    inFile.close(); //close file
    fileName = file; //reset fileName for next manipulation
  }
  
}


void stacker::average(){              //loops through pixels and divides each struct in pixels by numberOfImages to get the averaged image and replaces in pixels
  for(int i = 0; i < pixels.size(); i++){
    pixels[i].red = pixels[i].red / numberOfImages;
    pixels[i].green = pixels[i].green / numberOfImages;
    pixels[i].blue = pixels[i].blue / numberOfImages;
  }
}

void stacker::saveToDisk(){
  
  ofstream outFile;                       
  output = inputFileName + ".ppm";
  outFile.open(output.c_str());            //create ofstream and open file for writing

   
  outFile << magic_number << endl;
  outFile << width << " " << height << endl;
  outFile << max_color << endl;      //output ppm file header

  average(); //call to average so pixels has the average values before printing to file
  
  for(int i = 0; i < pixels.size(); i++){      //loop through pixels and write to file in triplet format
    outFile << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << " ";
  }
  cout << "Stacked image written to: " << output << endl;
  outFile.close();  //close ofstream
}
