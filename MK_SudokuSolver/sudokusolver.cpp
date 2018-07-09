/* Copyright Mulholland Kierin, All rights reserved 
Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 This source is protected under the GNU license which you can read here:
 http://www.gnu.org/licenses/gpl-3.0.txt
 */
 

#include<iostream>
#include "ssheader.h"//meine Funktionen werden aufgerufen
#include "colors.h"//ermöglicht Farben in meinem Programm

#include<stdlib.h>
#include<conio.h>
#include <cstdlib> 
#include <ctime> //Für Sleep function

#include <string>//Für strings
#include <fstream>//Für I/O 
#include <windows.h>//für system cls
#include <cstringt.h>//Um string in int zu konvertieren
using namespace std;

//vordeklarationen	
int iFeld[field_height][field_width]={ 
	0,	0,0,0, 0,0,0, 0,0,0,

	0,	0,0,4, 0,0,2, 7,0,0,
	0,	0,0,0, 5,7,0, 0,0,0,
	0,	8,0,2, 0,1,0, 0,0,3,

	0,	0,0,0, 0,0,0, 0,6,9,
	0,  0,8,6, 0,0,0, 5,2,0,
	0,	3,1,0, 0,0,0, 0,0,0,

	0,	1,0,0, 0,9,0, 4,0,8,
	0,	0,0,0, 4,2,0, 0,0,0,
	0,	0,0,5, 8,0,0, 1,0,0,
};
//int iFeld[field_height][field_width];

int iFeldBesetzt[field_height][field_width];
int	iZeile[10][10];
int iFeldSektor[10][10];
int iTopfSchwarz[10]; //Alle Zahlen die man nicht braucht
int iTopfWeiss[10];	  //Alle Zahlen die man braucht
int iFlageSchwarz[10]; // Sucht die Zahlen die Als Resultat nicht gelten.
int iSektorRoh[10][10];
int iKolonne[10][10];
int iZaehler=0;
int iResultat=0;
int iSektorDefinition=0;
int iBesetzteFelder=0;//Zählt die Anzahl der Besetzten Felder
int iFlagFindResults=0;

int main()
{
Name();
}
void Name(){
cout<<blue<<" #####                                     "<<endl;
cout<<blue<<"#     # #    # #####   ####  #    # #    #"<<endl;
cout<<blue<<"#       #    # #    # #    # #   #  #    #"<<endl;
cout<<blue<<" #####  #    # #    # # " <<red<<char(5)<<blue<<"  # ####   #    #"<<endl;
cout<<blue<<"      # #    # #    # #    # #  #   #    #"<<endl;
cout<<blue<<"#     # #    # #    # #    # #   #  #    #"<<endl;
cout<<blue<<" #####   ####  #####   ####  #    #  ####"<<endl;
cout<<white<<"         Copyright:"<<" Mulholland Kierin"<<endl;
cout<<red<<"		 #####                                  "<<endl;
cout<<red<<"		 #     #  ####  #      #    # ###### #####"<<endl;
cout<<red<<"		 #       #    # #      #    # #      #    #"<<endl;
cout<<red<<"		  #####  # "<<blue<<char(3)<<red<<"  # #      #    # #####  #    #"<<endl;
cout<<red<<"		       # #    # #      #    # #      #####"<<endl;
cout<<red<<"		 #     # #    # #       #  #  #      #   #"<<endl;
cout<<red<<"		  #####   ####  ######   ##   ###### #    #"<<endl;
cout<<blue<<"		"<<endl;
int input;
  cout<<blue <<"            "<<endl;
  cout<<blue <<char(26)<<"       1.   Weiter"   <<endl;
  cout<<blue <<char(26)<<"       2.   Anleitung"<<endl;
  cout<<blue <<char(26)<<"       3.   Exit\n"<<endl;

  cout<<"                   Selection:  ";
  cin>> input;
  switch ( input ) {
   case 1:            
   vHead();
    break;
    case 2:            
   Anleitung();
    break;
   case 3:            //Dies sollte zwischen den funktionen wechseln
   system("exit");
    break;
  }
}


void vHead()
{




vFeldInitialisieren();
	//vFeldBestimmen(iFeld);
	//Ausgabe
	system("cls");
	vAusgabeArray();
	//vEingabe();
	vFeldBestimmen();
	vFeldBesetzt();
	 do
    {
		 iBesetzteFelder=iSolver();
    }
  while (iBesetzteFelder!=81);
  if (iFlagFindResults==0){
  
  cout<<"finished";
  }
  else{
  int input;
  cout<<blue <<"            "<<endl;
 
  cout<<blue <<char(26)<<"       1.   Exit\n"<<endl;

  cout<<"                   Selection:  ";
  cin>> input;
  switch ( input ) {
   case 1:            //Dies sollte zwischen den funktionen wechseln
   system("exit");
    break;
  }
  }


}
int iSolver()
{
//+++++++++++++++++++++++++++
	for(int iheight=1;iheight!=10;iheight++){
			
			iZaehler=0;
				for (int iwidth=1;iwidth!=10;iwidth++){
					iZaehler=0;
					if(iFeldBesetzt[iheight][iwidth]==1){}
					else{
		iResultat=iAlgorithm(iheight,iwidth);
		
		if(iResultat!=0){
		iFlagFindResults++;
			
	//Schreibe die gefundenen Zahlen in eine Text datei	
		ofstream outfile;
        outfile.open ("SudokuResultate.txt");
                 outfile<<"iResultat "<<iheight<<":"<<iwidth<<" :"<<endl;
		outfile.close();
		
		
		Sleep(0);

		 vAusgabeResultat(iFeld,iheight,iwidth,iResultat);
		iFeldBesetzt[iheight][iwidth]=2;
		}
	

		
					}}
		}

//+++++++++++++++++++++
	iBesetzteFelder=0;
	for(int x=0;x<10;x++){
		for (int y=0;y<10;y++){
		if (iFeldBesetzt[x][y]==1 || iFeldBesetzt[x][y]==2)
			iBesetzteFelder++;
		}
	}



	//vAusgabeFeldBesetzt();
	//vEingabe(iFeld);

return iBesetzteFelder;
}

void vFeldBestimmen()
{
for(	 int iheight=1;iheight<field_height;iheight++){ //für die Höhe
	
		for (int iwidth=1 ;iwidth <field_width;iwidth++){
		
			
			if (iFeld[iheight][iwidth]!=0){
			iFeldBesetzt[iheight][iwidth]=1;
			}
			else{
				iFeldBesetzt[iheight][iwidth]=0;
			}
			

			
 
		
		
		
		}
}




}
//Setzt alle Arrays auf 0
void vFeldInitialisieren(){  //das Sudoku Feld wird auf 0 gesetzt mit einer Vorschlaufe
	
for(	 int iheight=1;iheight<field_height;iheight++){    //für die höhe
		for (int iwidth=1 ;iwidth <field_width;iwidth++){
		
			iFeld[field_width][field_height]=0;
			iFeldBesetzt[iheight][iwidth]=0;
			iZeile[iheight][iwidth]=0;
			iKolonne[iheight][iwidth]=0;
			
		
		}
	}
}


void vAusgabeArray()
{

	// Wir benutzen Ascii charachter um die Buchschtaben anzuzeigen
 cout << "     ";
 for (int x = 65; x < field_size-1 + 65; x++){ cout <<blue<< char(x) << " "; //Buchstaben
 if(x-65==2 || x-65==5 || x-65==8){ cout<<"  ";}
 }

 cout << endl; cout << "   ";
		
	for (int i = 0;i < 25;i++) {  cout<<char(219); } //obere linie 
 cout << endl;
 for (int x = 1; x < field_size; x++)
 {
  if(x==4 || x==7 || x==10)
  {
   cout << "   ";
   for(int i=0;i<25;i++)
   {
    cout<<char(219);
   }
   cout<<endl;
   cout <<blue<< " " << x << " ";
  }else{
   cout <<blue<< " " << x << " ";
  }
  cout<<char(219)<< " ";
  for (int y = 1; y < field_width; y++)
  {
  
	  if(iFeldBesetzt[x][y]==1){

	  cout <<red << iFeld[x][y] << " ";

	  }
	  if(iFeldBesetzt[x][y]==2){

	  cout <<yellow << iFeld[x][y] << " ";

	  }
	 if(iFeldBesetzt[x][y]==0){

	  cout <<blue << iFeld[x][y] << " ";
	  }
  
	  
	  if(y==3 || y==6 || y==9)
   {
    cout<<blue<<char(219)<<" ";
   }
  }
  cout << endl;
 }
 cout << "   ";
 for (int i = 0;i < 25;i++)
 {
 cout<<char(219);
 }
 cout << endl;

}

//Algorithmus um die Leeren Felder zu lösen
int iAlgorithm(int iheight,int iwidth){

//Input in Zeile 

		int iYheight=0;
		int iYwidth=0;
//		//überprüfen in welchem Sektor iheight und iwdith ist
//
if			(iheight>0 && iheight<4 && iwidth>0 && iwidth<4)		 {iSektorDefinition=1;iYheight=1;iYwidth=1;} //if
else if		(iheight>0 && iheight<4 && iwidth>3 && iwidth<7)		 {iSektorDefinition=2;iYheight=1;iYwidth=4;} //if
else if		(iheight>0 && iheight<4 && iwidth>6 && iwidth<10)		 {iSektorDefinition=3;iYheight=1;iYwidth=7;} //if
            
else if		(iheight>3 && iheight<7 && iwidth>0 && iwidth<4)		 {iSektorDefinition=4;iYheight=4;iYwidth=1;} //if
else if		(iheight>3 && iheight<7 && iwidth>3 && iwidth<7)         {iSektorDefinition=5;iYheight=4;iYwidth=4;} //if
else if		(iheight>3 && iheight<7 && iwidth>6 && iwidth<10)        {iSektorDefinition=6;iYheight=4;iYwidth=7;} //if
           
else if		(iheight>6 && iheight<10 && iwidth>0 && iwidth<4)        {iSektorDefinition=7;iYheight=7;iYwidth=1;} //if
else if		(iheight>6 && iheight<10 && iwidth>3 && iwidth<7)        {iSektorDefinition=8;iYheight=7;iYwidth=4;} //if
else if		(iheight>6 && iheight<10 && iwidth>6 && iwidth<10)       {iSektorDefinition=9;iYheight=7;iYwidth=7;} //if
		
		//Der Sektor wird im Sektor array hinein geschrieben:
for(int x=1;x<4;x++){
	for(int y=1;y<4;y++){
			iSektorRoh[x][y]=iFeld[iYheight][iYwidth];
			iYwidth++; 
	}
	iYwidth=iYwidth-3;
	iYheight++;  //nachdem die Breite des Sektors erreicht wurde wird die höhe um 1 addiert
}		
//*************************************Ausgaben fürs Testen**************************************
//cout<<"Sektor  ";cout<<iSektorDefinition;cout<<endl;
//cout<<"Yheight  ";cout<<iYheight;cout<<endl;
	
/*cout<<"Ywidth  ";cout<<iYwidth;cout<<endl;	*/	
//cout<<"height  ";cout<<iheight;cout<<endl;
//	
//cout<<"width  ";cout<<iwidth;cout<<endl;
//cout<<"iSektor :      ";
//	for(int x=1;x<4;x++){
//		for (int y=1;y<4;y++){
//		cout<<iSektorRoh[x][y];
//		}}
//	cout<<endl;
//cout<<"iZeile     ";
//cout<<iwidth;
//cout<<"  :";
//	for(int x=1;x<10;x++){
//		cout<<iFeld[iheight][x];
//	}
//
//	cout<<endl;
//	cout<<"iKolonne   ";
//cout<<iheight;
//cout<<"  :";
//	for(int x=1;x<10;x++){
//		cout<<iFeld[x][iwidth];
//	}
//cout<<endl;
//cout<<endl;
//************************************************************************************************
	//TopfSchwarz bilden, also alle Zahlen markieren die man nicht braucht in einem Blumentopf hinein werfen
 //Alle Nummer Sammel Arrays wieder auf Null setzen:
for (int x=1;x<10;x++){		iTopfSchwarz[x]=0;	iTopfWeiss[x]=0;	iFlageSchwarz[x]=0; 
} iZaehler=0;
// Aufzähen der Arrays von 1 bis 9		x ist die höhe		Falls eine Zahlt vorkommt, dann in den Topf schreiben
		for(int x=1;x<10;x++){for (int y=1;y<10;y++){			if (iFeld[x][iwidth]==y){						iTopfSchwarz[y]=y;}}}
		
		for(int m=1;m<4;m++){   //Sektor in topf schreiben
			for  (int n=1;n<4;n++)	{	
				for (int y=1;y<10;y++){		
					if (iSektorRoh[m][n]==y){
						iTopfSchwarz[y]=y;
					}
				}
			}
		}

		for(int x=1;x<10;x++){for (int y=1;y<10;y++){			if (iSektorRoh[x][y]==y){		iTopfSchwarz[y]=y;}}}
		for(int x=1;x<10;x++){for (int y=1;y<10;y++){			if (iFeld[iheight][x]==y){						iTopfSchwarz[y]=y;}}}

 //TopfWeiss bilden, alle Zahlen sind aufgelistet die man braucht
 for(int x=1;x<10;x++){for(int y=1;y<10;y++){			if ( iTopfSchwarz[x] == y ) {	iFlageSchwarz[x] = 1;	}if ( iTopfSchwarz[x] == 0 ) {	iFlageSchwarz[x] = 0;	}}}  
	
 //TopfWeiss bilden, alle Zahlen die im Schwarzen Topf nicht vorhanden sind kommen drin
 for(int x=1;x<10;x++){for(int y=1;y<10;y++){			if ( iFlageSchwarz[x] == 0 ) {	iTopfWeiss[x] = x; 		}if ( iFlageSchwarz[x] == 1 ) {	iTopfWeiss[x] = 0;		}}}

// Mit einem Zähler schaut man wie viele Lösungen im Topf sind
for(int x=1;x<10;x++){									if ( iTopfWeiss[x] != 0 ) {		iZaehler++;}}
//Man überprüft den Zaehler, falls es nur eine Lösung hat, dann gibt man die Lösung aus.
if (iZaehler==1){ 
	int t=1	;
	for(int x=1;x<10;x++ ){
		if(iTopfWeiss[x]==0){
			t++;}
		if(iTopfWeiss[x]!=0){
			iResultat=t;}
		}
 
	
}
if (iZaehler!=1){iResultat=0;
}

//end algorithm loop
	//  **************************************vvv Ausgabe der Werte für Test Zwecke vvv**********************************
//ausgabe des schwarzen Topfes
 //cout<<"iTopf 1:       ";
	//for(int x=1;x<10;x++){
	//		
	//	cout<<iTopfSchwarz[x];
	//}
	////ausgabe der schwarzen Flagen
	//cout<<endl;
 //cout<<"iFlageSchwarz: ";
	//for(int x=1;x<10;x++){
	//		
	//	cout<<iFlageSchwarz[x];
	//}
	////ausgabe des weissen Topfes
	//cout<<endl;
 //cout<<"iTopfWeiss:    ";
	//for(int x=1;x<10;x++){
	//		
	//	cout<<iTopfWeiss[x];
	//}cout<<endl;
	////ausgabe des weissen Topfes
	//cout<<endl;
 //cout<<"iZaehler:    ";	
	//	cout<<iZaehler<<endl;
	//
//cout<<endl;
////ausgabe des weissen Topfes

//cout<<endl;
//cout<<"**************************************";
//cout<<endl;

//  **************************************^^^ Ausgabe der Werte für Test Zwecke ^^************************************
return iResultat;
	}

void vEingabe()

{
	cout<<red<<"Um eine Eingabe zu wiederholen druecken Sie 'b' \n (0 muessen Sie auch eingeben.)\n";
	int Zahl=0;
char Eingabe=0;
for (int y = 1; y < 10; y++) // Bei der Abfrage soll es A1 abfragen und bei der nächsten Zahl A2 
{
for (int x = 1; x < 10; x++) //
{
cout<<blue<< char(64+x) << y <<": ";
cin>>  Eingabe;
if(Eingabe =='b')
{
	x = x - 2;
	system("cls");
	vAusgabeArray();
}
else if(Eingabe =='f')
{
	iFeld[y][x] = 0;
	system("cls");
	vAusgabeArray();
}
else if(Eingabe!='b' && Eingabe!='f')
{
	Zahl = (int)Eingabe-'0';
if(Zahl>9)
{
	x--;
}

else{
	iFeld[y][x] = Zahl;
	system("cls");
	vAusgabeArray();
}
}
}
}
}


void vAusgabeResultat(int iFeld[field_height][field_width],int iheight,int iwidth,int iResultat)
{
 
           
          
            iFeld[iheight][iwidth] = iResultat;
            system("cls");
	        vAusgabeArray();
			
			
	        
	         
                    
                       
}// end void

void vFeldBesetzt()
{
	
	
	
for(	 int iheight=1;iheight<field_height;iheight++){ //für die Höhe
	cout<<endl;
		for (int iwidth=1 ;iwidth <field_width;iwidth++){
		
			
			//cout<<iFeldBesetzt[iheight][iwidth];
			

			
 
		
		
		
		}
}

}



//Extras
void Anleitung()
{
system("cls");
cout<<red<<"Herzlich Wilkommen bei meinem grandiosen Sudoku Solver "<<endl;
cout<<"__________________________________________________________";
cout<<blue<<""<<endl;
cout<<"Um den Sudoku loesen zu koennen, muessen Sie die Zahlen ins Sudokufeld eintragen. "<<endl;
cout<<"0er muessen auch eingetragen werden./n";
cout<<"Zur vereinfachten Eingabe koennen Sie die Zahlen auch hintereinander eingeben "<<endl;
cout<<"Bsp: A1:000100034000   <-- fuellt die ganze Zeile auf."<<endl;
cout<<"___________________________________________________________";

int input;
  cout<<blue <<"            "<<endl;
  cout<<blue <<char(26)<<"       1.   Weiter"   <<endl;
  cout<<blue <<char(26)<<"       2.   Anleitung"<<endl;
  cout<<blue <<char(26)<<"       3.   Exit\n"<<endl;

  cout<<"                   Selection:  ";
  cin>> input;
  switch ( input ) {
   case 1:            
   vHead();
    break;
    case 2:            
   Anleitung();
    break;
   case 3:            //Dies sollte zwischen den funktionen wechseln
   system("exit");
    break;
  }
}
