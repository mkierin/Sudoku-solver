/* Copyright Mulholland Kierin, All rights reserved 
Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 This source is protected under the GNU license which you can read here:
 http://www.gnu.org/licenses/gpl-3.0.txt
 */

int const field_height=10;
int const field_width=10;
int const field_size=10;
void vFeldBestimmen();
void vFeldInitialisieren();
void vAusgabeArray(); //Ausgabe vom sudoku Feld
int iAlgorithm(int iheight,int iwidth);



void vEingabe(); // Eingabe von Zahlen ins Sudoku Feld

void vFeldBesetzt();
void vAusgabeFeldBesetzt();
void vAusgabeResultat(int iFeld[field_height][field_width],int iheight,int iwidth,int iResultat);
int iSolver();
void vEingabe();
void Name();
void vHead();
void Anleitung();



