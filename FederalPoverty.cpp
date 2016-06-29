/* file FederalPoverty.cpp
   Prints a table of above average income 
   + average income + percentage of below average income households*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAXNUMBER = 25;

struct household
{
       string IDnumber;
       int annual_income;   
       int household_members;
       bool ispoor;       
       
};

void gethouseholds (ifstream &, household[], int &);

int find_average(const household[],int);

void print_over_average(ostream &, const household [],int num_items, int average);

int below_poverty_level(const household[], int );

bool below_poverty(const household &);

int main()
{
    household houselist[MAXNUMBER];
    int numItems =0;
    int average_income;
    int percent;
     ifstream fin;
     ofstream fout;
     int numpoor;
     fin.open("Povertylist.txt");
     fout.open("povertyReport.txt");
   
     // test the files
    
    
    
      gethouseholds(fin, houselist, numItems);
      average_income = find_average(houselist, numItems);
      // write average to file
      fout << "The average income of the households is $"<< average_income << endl << endl;
              
      print_over_average( fout,houselist,numItems,average_income);
      numpoor = below_poverty_level(houselist,numItems); 
      fout << "The percentage of households below poverty level is  " << numpoor <<"%";
      //below_poverty(houselist);     
     // write % below poverty to a file
    
    
    
     
    
   system("pause");
      
    return 0;
}

void gethouseholds(ifstream & fin, household houselist[], int& numItems) 
{  
     int m,a,p;   
     
     fin >> houselist[numItems].IDnumber;
     while( fin and numItems < MAXNUMBER)
   {
        fin >> houselist[numItems].annual_income
            >> houselist[numItems].household_members;
            
            a = houselist[numItems].annual_income;
            m = houselist[numItems].household_members;
            p = 10830 +3740*(m-1);
            houselist[numItems].ispoor = p > a;
            
            
            numItems ++;
        
           
         fin >> houselist[numItems].IDnumber; 
    } // eof loop
      
}     
int find_average(const household houselist[],int numItems)
    { 
      int z=0,sum_of_income = 0,average;
      while(z < numItems)
      {       
             sum_of_income = sum_of_income + houselist[z].annual_income;  
             z++;
       }
          average = float(sum_of_income)/numItems + 0.5;
     
          return average;
     
     }    
     
void print_over_average (ostream & fout, const household houselist[], int num_items, int average) 
     {
             int b,member,income;
             string IDnum; 
         fout<< "Table showing households with above average Income\n"<<endl                   
             << "ID Number" << " "  << "Household Income" << " " <<  " Num of Household Members"<< endl
             <<  "--------" << "  " << "----------------" << " " <<   "----------------------"<< endl;   
                           
             
             for(b = 0; b < num_items; b++)
            {
     // need if statement
             IDnum = houselist[b].IDnumber;     
              income = houselist[b].annual_income;
              member = houselist[b].household_members;    
             if(houselist[b].ispoor ==0)
             fout << "   " <<  IDnum  << "           $" << income <<  "           " << member << endl;
             
            }           
                              
     }
int below_poverty_level(const household houselist[], int numItems) {
          
          int num_of_poor,percent,b;
          
            for(b = 0; b < numItems; b++)
            {
            if(houselist[b].ispoor ==1)
             num_of_poor++;
             }    
            percent = float(num_of_poor*100)/numItems + 0.5;
            return percent;
          
          }





