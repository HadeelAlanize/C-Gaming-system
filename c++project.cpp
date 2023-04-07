
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<ctime>
using namespace std;
struct players {
   
    string name;
    int score;
    int hours;
   
   };

int size=0;
int number=size;
int itemnum=0;


string name;
int score;


players    *ply=new players[50];
 typedef players* Players;


int countdd=0;
int countdelete=0;
int countsort=0;
int countsearch=0;
int countupdate=0;
time_t now;
int i;


void menu();
bool dubl(string id,int &);
void add(int &);
void show(int &);
void delete_(Players ,int &sizep);
void sort(Players, int);
int price(int & score);
//function overloading 
int price(int hours,int score);
void update_(Players, int );
int search(Players ply, int size);
void savedata_person(Players ,int currentSize);


int main()
{
    int currentSizeb=0;
    int currentSizep=0;
    int ch;
    int size ;
   
   
    cout<<"\n Please Enter How Many Players: ";
    cin>>size;
   
   cout<<endl;
   cout<<"\t\t * Welcome To The System *"<<endl;
   cout<<endl;
   
   
    ifstream input; //load data from file
    input.open("players.txt");
    if(input.is_open())
    {  while(!input.eof())
        {
            input>>ply[currentSizeb].score;
            input>>ply[currentSizeb].name;
         
            currentSizeb++;
        }
        --currentSizeb;
    }
    else
        cout<<"File does not exist. "<<endl;
       
       
    do
    {
        menu();
        cout<<"------------------------- Your Choice -------------------------"<<endl;

        cout<<"Enter your choice: ";

        cin>>ch;
        switch (ch)
        {
        case 1:
                add(currentSizep);
                break;
     
   
        case 2:
                show(currentSizep);
                break;
        case 3:
        	
        	search(ply, currentSizep);
        	break;
        	
        case 4:
                update_(ply,currentSizep);
                break;
        case 5:
                delete_(ply,currentSizep);
                break;

        case 6:
                sort(ply,currentSizep);
         
                break;
               
     
                //hdeel
               
        case 0:
        {
            ofstream pfile;
            pfile.open("playeractivity.txt",ios::app);
            if(pfile.is_open())
            {
                pfile<<"=================================="<<endl;
                pfile<<" user activity log: "<<endl;
                pfile<<"Add: "<<countdd<<" Items"<<endl;
                pfile<<"Delete:"<<countdelete<<" Items"<<endl;
                pfile<<"Search: "<<countsearch<<" Times"<<endl;
                pfile<<"Sort: "<<countsort<<" Times"<<endl;
                pfile<<"Update: "<<countupdate<<" Items"<<endl<<endl;
                pfile<<"Date and time: ";
                now=time(NULL);
                pfile<<ctime(&now)<<endl;
                pfile<<"=================================="<<endl;
               
            }
            pfile.close();
            cout<<"=================================="<<endl;
            cout<<" user activity log: "<<endl;
            cout<<"Add: "<<countdd<<" Items"<<endl;
            cout<<"Delete:"<<countdelete<<" Items"<<endl;
            cout<<"Search: "<<countsearch<<" Times"<<endl;
            cout<<"Sort: "<<countsort<<" Times"<<endl;
            cout<<"Update: "<<countupdate<<" Items"<<endl<<endl;
            cout<<"Date and time: ";
            now=time(NULL);
            cout<<ctime(&now)<<endl;
            pfile<<"=================================="<<endl;
           
        }
                break;
        default:
            {
                cout<<"Thank you."<<endl;
                break;
            }
               
        }
       
    } while(ch!=0);

   
        delete[] ply;

return 0;

}

void menu(){
    cout<<endl;
    cout<<"1- Add new player record:\n2- Show players records:\n3- Search:\n4- Update player records:\n5- Delete player record: \n6- Sort players by scores: \n7- Press 0 to Exit."<<endl;
}
bool dubl(string id , int &currentSize){
    bool same=false;

    for(int i=0;i<currentSize;i++){
        if(ply[i].name==id)
        same=true;
    }
    return same;
}

 void add (int &currentSize )
{
again:
            cout<<"------------------------- Your Name ---------------------------"<<endl;
            cout<<endl<<"Enter player name: "<<endl;
            cin>>ply[currentSize].name;

            if(dubl(ply[currentSize].name,currentSize)==true){
                cout<<"Oops :),Player name already taken"<<endl;
                goto again;
            }
    cout<<"------------------------- Your Score -------------------------"<<endl;
    cout<<"Enter score : "<<endl;
    cin>>ply[currentSize].score;
    ply[currentSize].score=price(ply[currentSize].score);
    
    cout<<"------------------------- playing Hours -------------------------"<<endl;
    cout<<"how many hours do you play? : "<<endl;
    cin>>ply[currentSize].hours;
    ply[currentSize].score=price( ply[currentSize].hours, ply[currentSize].score);
    
    



   

 // file
    ofstream output;
    output.open("players.txt", ios::app);
    if(output.is_open())
    {
 
        output<<ply[currentSize].score<<endl;
        output<<ply[currentSize].name<<endl;
 

    }

    else
        cout<<"File does not exist.";
        output.close();
   
        ++currentSize;
        ++countdd;
   
}

void show(int &currentSize)
{
    if(currentSize==0)

   { cout<<"players do not exist. "<<endl;
       
       return;
       
   }
    cout<<endl;
    cout<<"\t\tNames\t\tScores"<<endl;
    for(int i=0; i<currentSize;++i){
        cout<<(i+1)<<"-Player \t"<<ply[i].name<<"\t\t"<<ply[i].score<<endl;}
   
   
}
 
void delete_(Players ply,int &sizep)
{
    bool find=false;
 
   
    cout<<"------------------------- Name to Delete -------------------------"<<endl;
    cout<<"Enter player name to delete:\n";
    cin>>name;
   
    for (int i=0;i<=sizep;i++)
        if (ply[i].name==name)
        {
            for (int j=i; j<sizep; j++)
            {
                ply[j]=ply[j+1];
               
            }
            sizep--;
           
            find=true;
            cout<<"\nPlayer deleted.";
            savedata_person(ply,sizep);
            break;
        }
       
    if (find==false)
        cout<<"Player not found.\n";
   
   
    ++countdelete;
    cout<<endl;

}

  int search(Players ply, int size){
    int i;
    string  name;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Please enter the name of player you want to search: ";
    cin>>name;
    
    
   
    for ( i=0; i<size ;++i )
        if (ply[i].name==name)
        {
           cout<<"name: "<<ply[i].name<<"\n";
           cout<<"score: "<<ply[i].score<<"\n";
           
            break;
        }
           return -1;
       }

void sort(Players ply,int currentSize)
 {
     
     if(currentSize==0)
     {
         cout<<"Nothing to sort! "<<endl;
       
            return;
     }

     players temp;
     for(int i=0;i<currentSize-1;i++)
     {
         for(int j=0;j<currentSize-1;j++)
             if(ply[j].score<ply[j+1].score)
            {
                 temp=ply[j];
                 ply[j]=ply[j+1];
                 ply[j+1]=temp;
                 
             }
     }
     cout<<"Sorted."<<endl;
   
     cout<<"\tNames\tScores"<<endl;
     for(int i=0; i<currentSize;++i){
         cout<<(i+1)<<"-Player \t"<<"\t\t"<<ply[i].name<<"\t\t"<<ply[i].score<<endl;}
     
     savedata_person(ply,currentSize);
     ++ countsort;
 }

void update_(Players ply,int size)
{
    bool find=false;
    string nameN ;
    cout<<"------------------------- Player to Update -------------------------"<<endl;
    cout<<endl<<"Enter player to update:" <<endl;
    cin>> nameN;
         

   
    for(int i=0;i<size;i++)
    {
        if (ply[i].name==nameN)
        {
            cout<<"------------------------- New Score -------------------------"<<endl;
            cout<<"Enter new score: ";
            cin>>score;
            ply[i].score=score;
            ply[i].score=price(ply[i].score);
            cout<<endl<<"the Player\n "<<"Name:"<<ply[i].name<<"\t\tScore:"<<ply[i].score<<"\nis Updated"<<endl;
           
            find=true;
            savedata_person(ply,size);
            break;
        }
       
    }
    if (find==false)
        cout<<"Player not found."<<endl;
   
    ++countupdate;
}

int price(int & score)
{
    if (score>=300){
    score+=500;
        cout<<"congrats you won 500 points !"<<endl;

    }
    cout<<"------------------------------"<<endl;

    return score;
   
}
//function overloading 
int price(int hours, int score){
	if(hours>=3){
	score+=300;
	cout<<"congrats you won 300 points !"<<endl;
	}
	return score;
}

void savedata_person(Players ply, int currentSize)
{
    ofstream output;
    output.open("PlayerInfo.txt");
    if(output.is_open())
        for(int i=0;i<currentSize;i++)
        {
            output<<ply[i].name<<endl;
            output<<ply[i].score<<endl;
           
        }
    else
        cout<<"File does not exist.";
    output.close();
   
}
