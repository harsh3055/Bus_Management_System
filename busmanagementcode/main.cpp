#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<windows.h>
using namespace std;

void Initiate()
{
     system("color 09");
     system("cls");
}

static int B = 0;
class Bus_Reservation
{
  char bus_no[5];
  char driver_name[10];
  char arrival_time[10];
  char departure_time[10];
  char from[20];
  char to[20];
  char seat[8][4][10];

public:
  void add_bus();
  void reserve_bus();
  void empty();
  void show_bus();
  void is_bus_available();
  void position(int i);
}

bus[15];

void Bus_Reservation::add_bus()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 06 );

  cout<<"Enter bus number: ";
  cin>>bus[B].bus_no;

  cout<<"Enter driver's name: ";
  cin>>bus[B].driver_name;

  cout<<"Arrival time: ";
  cin>>bus[B].arrival_time;

  cout<<"Departure time: ";
  cin>>bus[B].departure_time;

  cout<<"From: ";
  cin>>bus[B].from;

  cout<<"To: ";
  cin>>bus[B].to;

   cout<<"\nOperation Completed Successfully";

  bus[B].empty();
  B++;

  getch();

}

void Bus_Reservation::reserve_bus()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 04);
  int seat;
  char number[5];
  top:
  cout<<"Bus number: ";
  cin>>number;
  int n;
  for(n=0;n<=B;n++)
  {
    if(strcmp(bus[n].bus_no, number)==0)
    break;
  }
  while(n<=B)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passenger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat is already reserved.\n";
      }
      }
    if(n>B)
    {
      cout<<"Enter correct bus no.: \n";
      goto top;
    }
    cout<<"\nOperation Completed Successfully";
	getch();
  }


void Bus_Reservation::empty()
{

  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[B].seat[i][j], "Empty");
    }
  }
}

void Bus_Reservation::show_bus()
{ HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 02 );
  int n;
  char number[5];
  cout<<"Enter bus number: ";
  cin>>number;
  for(n=0;n<=B;n++)
  {
    if(strcmp(bus[n].bus_no, number)==0)
    break;
  }
  while(n<=B)
  {
  	cout<<"\n------------------------------------------\n";
  	cout<<"Bus no: "<<bus[n].bus_no
  	<<"\ndriver_name: "<<bus[n].driver_name<<"\nArrival time: "
  	<<bus[n].arrival_time<<"\nDeparture time: "<<bus[n].departure_time
  	<<"\nFrom: "<<bus[n].from<<"\nTo: "<<
  	bus[n].to<<"\n";
  	cout<<"------------------------------------------\n";
  	bus[0].position(n);

  	int a=1;
  	for (int i=0; i<8; i++)
  	{
    	for(int j=0;j<4;j++)
    	{
      	a++;
      	if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      	cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    	}
  	}
  	break;
  	}
  	if(n>B)
    	cout<<"Enter correct bus no: ";

  	getch();
}

void Bus_Reservation::position(int l)
{

    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 02 );
  int s=0;
  int k=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          k++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
    cout<<"\n\nThere are "<<k<<" seats Empty in Bus Number: "<<bus[l].bus_no;
  }

void Bus_Reservation::is_bus_available()
{

    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 01 );
  for(int n=0;n<B;n++)
  {
  		cout<<"\n------------------------------------------\n";
    	cout<<"Bus number: "<<bus[n].bus_no<<"\ndriver_name: "<<bus[n].driver_name
    	<<"\nArrival time: "<<bus[n].arrival_time<<"\nDeparture Time: "
    	<<bus[n].departure_time<<"\nFrom: "<<bus[n].from<<"\nTo: "
    	<<bus[n].to;
    	cout<<"\n------------------------------------------\n";
  }
getch();
}

int main()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

system("cls");
int w;
while(1)
{
system("cls");
    Initiate();

  cout<<"\n";
  cout<<"\t\t\t------------------------------------------\n";
  SetConsoleTextAttribute(color, 06 );
  cout<<"\t\t\t1. Add Bus\n\t\t\t";
  SetConsoleTextAttribute(color, 04 );
  cout<<"2. Reserve A Seat\n\t\t\t";
  SetConsoleTextAttribute(color, 02 );
  cout<<"3. Show Seat Availability\n\t\t\t";
  SetConsoleTextAttribute(color, 01 );
  cout<<"4. Bus Availability\n\t\t\t";
  SetConsoleTextAttribute(color, 07 );
  cout<<"5. Exit";
  SetConsoleTextAttribute(color, 011 );
  cout<<"\n\t\t\t------------------------------------------\n";
  cout<<"\n\t\t\tEnter your choice: ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[B].add_bus();
      break;
    case 2:  bus[B].reserve_bus();
      break;
    case 3:  bus[0].show_bus();
      break;
    case 4:  bus[0].is_bus_available();
      break;
    case 5:  exit(0);
  }
}
return 0;
}
