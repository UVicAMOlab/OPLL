void setup() {

////////
//PIN ARRANGEMENT
////////
int dataPin=;
int clkPin=;
int cePin=;


////////
//INITIALIZATION LATCH
////////
int CR=;
int PD1=;
int MOC=;
int Polarity=;
int CP3=;
int FLE=;
int FLM=;
int TCC=;
int Current1=;
int Current2=;
int PD2=;
int P=;
int IArray[24];


////////
//REFERENCE LATCH
////////
int R=;       ////give int
int abw=;     ////give binary selection number ie 0,1,2,3
int tmb=;     //// ' '
int ldp=;     //// ' '
int refArray[24];

////////
//N COUNTER LATCH
////////
int N =;      //// ' '
int CPG =;
// FIND A,B and declare as such
int NArray[24];



////////
//BOOK KEEPING ASSIGNMENTS
////////


pinMode(dataPin, OUTPUT);
pinMode(clkPin, OUTPUT);
pinMode(cePin, OUTPUT);
digitalWrite(dataPin, LOW);
digitalWrite(clkPin, LOW);
digitalWrite(cePin, LOW); 




IArray[0] = 1;
IArray[1] = 1;
IArray[2] = bitRead(CR,0);
IArray[3] = bitRead(PD1,0);
IArray[4] = bitRead(MOC,0);
IArray[5] = bitRead(MOC,1);
IArray[6] = bitRead(MOC,2);
IArray[7] = bitRead(Polarity,0);
IArray[8] = bitRead(CP3,0);
IArray[9] = bitRead(FLE,0);
IArray[10] = bitRead(FLM,0);
IArray[11] = bitRead(TCC,0);
IArray[12] = bitRead(TCC,1);
IArray[13] = bitRead(TCC,2);
IArray[14] = bitRead(TCC,3);
IArray[15] = bitRead(Current1,0);
IArray[16] = bitRead(Current1,1);
IArray[17] = bitRead(Current1,2);
IArray[18] = bitRead(Current2,0);
IArray[19] = bitRead(Current2,1);
IArray[20] = bitRead(Current2,2);
IArray[21] = bitRead(PD2,0);
IArray[22] = bitRead(P,0);
IArray[23] = bitRead(P,1);


refArray[0] = 0;
refArray[1] = 0;
refArray[2] = bitRead(R,0);
refArray[3] = bitRead(R,1);
refArray[4] = bitRead(R,2);
refArray[5] = bitRead(R,3);
refArray[6] = bitRead(R,4);
refArray[7] = bitRead(R,5);
refArray[8] = bitRead(R,6);
refArray[9] = bitRead(R,7);
refArray[10] = bitRead(R,8);
refArray[11] = bitRead(R,9);
refArray[12] = bitRead(R,10);
refArray[13] = bitRead(R,11);
refArray[14] = bitRead(R,12);
refArray[15] = bitRead(R,13);
refArray[16] = bitRead(abw,0);
refArray[17] = bitRead(abw,1);
refArray[18] = bitRead(tmb,0);
refArray[19] = bitRead(tmb,1);
refArray[20] = bitRead(ldp,0);
refArray[21] = 0;
refArray[22] = 0;
refArray[23] = 0;


NArray[0] = 1;
NArray[1] = 0;
NArray[2] = bitRead(A,0);
NArray[3] = bitRead(A,1);
NArray[4] = bitRead(A,2);
NArray[5] = bitRead(A,3);
NArray[6] = bitRead(A,4);
NArray[7] = bitRead(A,5);
NArray[8] = bitRead(B,0);
NArray[9] = bitRead(B,1);
NArray[10] = bitRead(B,2);
NArray[11] = bitRead(B,3);
NArray[12] = bitRead(B,4);
NArray[13] = bitRead(B,5);
NArray[14] = bitRead(B,6);
NArray[15] = bitRead(B,7);
NArray[16] = bitRead(B,8);
NArray[17] = bitRead(B,9);
NArray[18] = bitRead(B,10);
NArray[19] = bitRead(B,11);
NArray[20] = bitRead(B,12);
NArray[21] = bitRead(CPG,0);
NArray[22] = 0;
NArray[23] = 0;


/////////
//PROGRAMING INITILIZATION LATCH
/////////
delay(1000) // waits to make sure adf4107 is properly powered

for (int i = 0; i < 24; i++) {
  digitalWrite(clkPin, LOW);
  digitalWrite(dataPin, IArray[i]);
  digitalWrite(clkPin, LOW);
}

/////////
//PROGRAMING N LATCH
/////////
for (int i = 0; i < 24; i++) {
  digitalWrite(clkPin, LOW);
  digitalWrite(dataPin, NArray[i]);
  digitalWrite(clkPin, LOW);
}

/////////
//PROGRAMING R LATCH
/////////
for (int i = 0; i < 24; i++) {
  digitalWrite(clkPin, LOW);
  digitalWrite(dataPin, refArray[i]);
  digitalWrite(clkPin, LOW);
}


/////////
//RESUME OPERATION
/////////

digitalWrite(cePin , HIGH);


}
void loop() {
  // put your main code here, to run repeatedly:

}
