#include<iostream>
#include"colors.h" //für Farben
#include<string>
#include<windows.h> //für sleep
#include"headerj.h" //für diverse funktionen
using namespace std;

void vbody()
{
	//header 
	cout<<red<<char(201);
	Sleep(time);					
	for(int x=1;x<field_width-1;x++){
	cout<<red<<char(205);
		Sleep(time);
	}
	cout<<red<<char(187)<<endl;
	Sleep(time);
	//content no text
	cout<<red<<char(186);
	Sleep(time);
	for(int x=1;x<field_width-1;x++){
	cout<<" ";
		
	}
	cout<<red<<char(186)<<endl;
	Sleep(time);

	//content text

	cout<<red<<char(186);
	Sleep(time);
	for(int x=1;x<10;x++){    
	cout<<" ";
		
	}
	cout<<blue<<char(184);Sleep(time);cout<<red<<" ";Sleep(time);cout<<red<<"M";Sleep(time);cout<<red<<"u";Sleep(time);cout<<red<<"h";Sleep(time);cout<<red<<"o";Sleep(time);cout<<red<<"l";Sleep(time);cout<<red<<"l";Sleep(time);cout<<red<<"l";Sleep(time);cout<<red<<"a";Sleep(time);cout<<red<<"n";Sleep(time);cout<<red<<"d";Sleep(time);cout<<red<<" ";Sleep(time);
	cout<<red<<"K";Sleep(time);cout<<red<<"i";Sleep(time);cout<<red<<"e";Sleep(time);cout<<red<<"r";Sleep(time);cout<<red<<"i";Sleep(time);cout<<red<<"n";Sleep(time);

for(int x=1;x<field_width-29;x++){
	cout<<" ";
		
	}
	


	cout<<red<<char(186)<<endl;
	Sleep(time);

	//content text underline in blue
	cout<<red<<char(186);
	Sleep(time);
	for(int x=1;x<10;x++){
	cout<<" ";
		
	}
	for(int x=1;x<20;x++){
	cout<<blue<<char(196);
		
	}
	for(int x=1;x<field_width-29;x++){
	cout<<" ";
	}
	cout<<red<<char(186)<<endl;
	Sleep(time);
//footer
	cout<<red<<char(200);
	Sleep(time);					
	for(int x=1;x<field_width-1;x++){
	cout<<red<<char(205);
		Sleep(time);
	}
	cout<<red<<char(188)<<endl;
	Sleep(time);
	


Sleep(time*200);
system("cls");

}
