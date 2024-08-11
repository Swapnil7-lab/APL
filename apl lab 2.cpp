#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Date {
public:
   
     int month;
    int year;
    int dayOfMonth;
    
   
    
    
    Date(int month, int year, int dayOfMonth)  {
        
        
        this->month=month;
        this->year=year;
        this->dayOfMonth=dayOfMonth;
    }
  int calculateDayOfWeek() {
        
        
   int mon;
   int year;
   year=this->year;
   if(month > 2)
      mon = month; //for march to december month code is same as month
   else{
      mon = (12+month); //for Jan and Feb, month code will be 13 and 14
      year--; //decrease year for month Jan and Feb
   }
   int y = year % 100; //last two digit
   int c = year / 100; //first two digit
   int w = (dayOfMonth + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
   w = w % 7;
  
 
  return w;
    }
        
    
    };


class Calendar {
private:
struct Notes{
    string content;
    Date date;
    };
    vector<string> daysOfWeek = {"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<Date> holidays;
    vector<Notes> notes;
    
  
public:
   
    string getDay(Date d)
    {
        return daysOfWeek[d.calculateDayOfWeek()];
    }
    string getMonth(Date d) {
        return months[d.month - 1];
    }

       int  getYear(Date d) {
        return (d.year);
    }

    void addNotetoDate(Date d,string str){
       struct Notes note ={str,d};
       notes.push_back(note);


    }
    void addHoliday(Date d) {
        int x=d.calculateDayOfWeek();
        if(x==0||x==1)
        {
            return;
        }
        holidays.push_back(d);
    }
   
    bool isPreceded(Date d1, Date d2)
    {   if (d1.year<d2.year)
            return true;
        if(d1.month<d2.month)
            return true;
        if(d1.dayOfMonth<d2.dayOfMonth)
            return true;
        
        return false;
    }
    int calculate(int month,int year){
        int i=0,j=0;
        while(i<holidays.size()){
           if(  holidays[i].month==month && holidays[i].year==year)
           j++;
           i++;
        }
        return j;
    }
    bool removeNoteFromDate(Date d)
    {  int n= notes.size();
       for(int i=0;i<n;i++)
       {
         if(notes[i].date.year==d.year && notes[i].date.month==d.month && notes[i].date.dayOfMonth==d.dayOfMonth )
         {  if (notes[i].content=="/0")
          {
            return false;
          }
            notes[i].content={"/0"};
            return true;
         }
       }
       return false;
    }
    int getNumberOfHolidays(int month, int year)
    { 
      Date d1(month,year,1);
      int x=d1.calculateDayOfWeek()+1;
      if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
      {
          switch(x) {
                        case 1:
                                return 10 + calculate(month,year);
                                break; 
                        case 2:
                                return 9 + calculate(month,year);
                                break; 
                        
                        case 3:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 4:
                                return 8 + calculate(month,year);
                                break;
                        case 5:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 6:
                                return 9 + calculate(month,year);
                                break;
                        case 7:
                                return 10 + calculate(month,year);
                                break;        

          }
                      
      }
      else if(month==4||month==6||month==9||month==11)
      {
          switch(x) {
                        case 1:
                                return 10 + calculate(month,year);
                                break; 
                        case 2:
                                return 9 + calculate(month,year);
                                break; 
                        
                        case 3:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 4:
                                return 8 + calculate(month,year);
                                break;
                        case 5:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 6:
                                return 8 + calculate(month,year);
                                break;
                        case 7:
                                return 9 + calculate(month,year);
                                break;        

          }
                      
      }
      else
      {
        if(year%100==0 && year %400==0|| year%4==0)
        {
            switch(x) {
                        case 1:
                                return 9 + calculate(month,year);
                                break; 
                        case 2:
                                return 9 + calculate(month,year);
                                break; 
                        
                        case 3:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 4:
                                return 8 + calculate(month,year);
                                break;
                        case 5:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 6:
                                return 8 + calculate(month,year);
                                break;
                        case 7:
                                return 8 + calculate(month,year);
                                break;        

          }
        }
        else
        {
            switch(x) {
                        case 1:
                                return 8 + calculate(month,year);
                                break; 
                        case 2:
                                return 8 + calculate(month,year);
                                break; 
                        
                        case 3:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 4:
                                return 8 + calculate(month,year);
                                break;
                        case 5:
                                return 8 + calculate(month,year);
                                break;
                        
                        case 6:
                                return 8 + calculate(month,year);
                                break;
                        case 7:
                                return 8 + calculate(month,year);
                                break;        

          }
        }
      }
      
      
     
    }
    

    


    Date iterateDate(Date d, int days) {
        // Handle month and year changes when incrementing days
        int daysInMonth = 31; // Default value for simplicity
        
        switch (d.month) {
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                daysInMonth = (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0)) ? 29 : 28;
                break;
        }
       

        

        if (d.dayOfMonth + days <= daysInMonth) {
            d.dayOfMonth += days;
        } else {
            d.dayOfMonth = days - (daysInMonth - d.dayOfMonth);
            if (d.month >= 12) {
                d.year++;
                d.month = 1;
            } else {
                d.month++;
            }
        }

        
        return d;
    }
    void getNotesFromDateTillN(Date d, int n)
    {   int j=0,i=0;
    int m= notes.size();
      int   k;
       while(j<m)
       {
             if(notes[j].date.year==d.year && notes[j].date.month==d.month && notes[j].date.dayOfMonth==d.dayOfMonth )
             {
                 k=j;
             }
             j++;
       }
       Date d1= iterateDate(d,n);
        while(i<m)
       {
             if(notes[i].date.year>d1.year && notes[j].date.month>d1.month && notes[j].date.dayOfMonth>d1.dayOfMonth )
             {
                 j=i-1;
             }
             i++;
       }
       while(k<j)
       {
        cout<<notes[k].content<<endl;
        k++;
       }
     
    }
    Date getNextWeekDay(Date d)
    {
         int x=d.calculateDayOfWeek()+1;
         Date d1=d;
         switch(x) {
                        case 1:
                               d1= iterateDate(d1,2);
                                return d1;
                                break; 
                        case 2:
                                d1= iterateDate(d1,1);
                                return d1;
                                break; 
                        
                        case 3:
                                d1= iterateDate(d1,1);
                                return d1;
                                break;
                        
                        case 4:
                                 d1= iterateDate(d1,1);
                                return d1;
                                break;
                        case 5:
                                d1= iterateDate(d1,1);
                                return d1;
                                break;
                        
                        case 6:
                                d1= iterateDate(d1,1);
                                return d1;
                                break;
                        case 7:
                                d1= iterateDate(d1,3);
                                return d1;
                                break;       

          }
    }
    Date getNextHoliday(Date d)
    {
             int x=d.calculateDayOfWeek()+1;
         Date d1=d;
         switch(x) {
                        case 1:
                               d1= iterateDate(d1,1);
                                return d1;
                                break; 
                        case 2:
                                d1= iterateDate(d1,6);
                                return d1;
                                break; 
                        
                        case 3:
                                d1= iterateDate(d1,5);
                                return d1;
                                break;
                        
                        case 4:
                                 d1= iterateDate(d1,4);
                                return d1;
                                break;
                        case 5:
                                d1= iterateDate(d1,3);
                                return d1;
                                break;
                        
                        case 6:
                                d1= iterateDate(d1,2);
                                return d1;
                                break;
                        case 7:
                                d1= iterateDate(d1,1);
                                return d1;
                                break;       

          }
    }
    void printMonthOfYear(int month, int year)
    {
        Date d1(month,year,1);
        int x=d1.calculateDayOfWeek()+1;
        int daysInMonth = 31; // Default value for simplicity
        
        switch (d1.month) {
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                daysInMonth = (d1.year % 4 == 0 && (d1.year % 100 != 0 || d1.year % 400 == 0)) ? 29 : 28;
                break;
        }
        switch(x) {
                        case 1:
                               
                                cout<<"     ";
                                cout<<"     ";
                                cout<<"     ";
                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==3)
                                        cout<<endl;

                                        cout<<i<<"  ";
                                }
                                
                                break; 
                        case 2:
                                cout<<"      ";
                                cout<<"      ";
                                cout<<"      ";
                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==2)
                                        cout<<endl;

                                        cout<<i<<"  ";
                                }
                                
                                break; 
                        
                        case 3: { 
                                 int i=1;
                                  cout<<i<<"  ";
                                 for (i;i<=daysInMonth;i++)
                                 {    
                                        if(i%7==1)
                                        cout<<endl;

                                        cout<<i<<"  ";
                                 }
                                  break;
                                }

                        
                        case 4: 
                                {
                                         cout<<"   ";

                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==0)
                                        cout<<endl;

                                        cout<<i<<"  ";
                                }
                                
                                break;
                                }

                               
                        case 5:

                                cout<<"      ";
                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==6)
                                        cout<<endl;

                                        cout<<i<<" ";
                                }
                                
                                break;
                        case 6:

                                cout<<"         ";
                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==5)
                                        cout<<endl;

                                        cout<<i<<" ";
                                }
                                
                                break;
                        case 7:
                               cout<<"            ";
                                for (int i=1;i<=daysInMonth;i++)
                                {    
                                        if(i%7==4)
                                        cout<<endl;

                                        cout<<i<<" ";
                                }
                                
                                break;     

          }

    }
    int daysInMonth(int month, int year) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return 29;
    }
    return days[month];
}
    int calculateDaysToDate(Date d) {
    int daysToDate = d.dayOfMonth;
    for (int m = 1; m < d.month; ++m) {
        daysToDate += daysInMonth(m, d.year);
    }
    return daysToDate;
}
    int calculateDistance(Date start, Date end) {
    int daysStart = calculateDaysToDate(start) + start.year * 365;
    int daysEnd = calculateDaysToDate(end) + end.year * 365;

    for (int year = start.year; year < end.year; ++year) {
        daysEnd += (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
    }

    return abs(daysEnd - daysStart);
}
int getDistanceBetweenDates(Date d1, Date d2)
{
        int x=calculateDistance(d1,d2);
        return x;
}
    
};

int main() {
   

return 0;



}
