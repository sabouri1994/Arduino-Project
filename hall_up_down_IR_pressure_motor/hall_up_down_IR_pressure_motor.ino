//int  hall_up_array[24];
//int  hall_down_array[24];
//int  IR_array[24];
//int pressure_array[24];

int  hu[24];
int  hd[24];
int  Ir[24];
int  p[24];

int Mt[]={0,1,2,3,4,5,6,7,8,9,10,12,11,20,21,22,13,14,16,23,19,18,17,24,15}; //motor lookup table for new connection
int cell=9,cell2,j,t=0;   // cell selection
const int sensor_pressure = A8; // analog multiplexer output
int val=0;


void setup() {
  //selector (hall down & up , IR sensor)
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);

//multiplexer out (hall down & up , IR sensor)
pinMode(2, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
pinMode(10, INPUT);

// selector (pressure)
pinMode(A9, OUTPUT);
pinMode(A10, OUTPUT);
pinMode(A11, OUTPUT);
pinMode(A12, OUTPUT);



// MOTOR OUT (multiplexer)
pinMode(23, OUTPUT);//(M1-M8)
pinMode(33, OUTPUT);//(M9-M16)
pinMode(43, OUTPUT);//(M17-M24)

// motor selector (M1-M8)
pinMode(25, OUTPUT);
pinMode(27, OUTPUT);
pinMode(29, OUTPUT);
pinMode(31, OUTPUT);

//motor selector (M9-M16)
pinMode(35, OUTPUT);
pinMode(37, OUTPUT);
pinMode(39, OUTPUT);
pinMode(41, OUTPUT);

//motor selector (M17-M24)
pinMode(45, OUTPUT);
pinMode(47, OUTPUT);
pinMode(49, OUTPUT);
pinMode(51, OUTPUT);


pinMode(11, OUTPUT); //S1  (VOLTAGE TRANSISTOR)
pinMode(12, OUTPUT); //S2  (VOLTAGE TRANSISTOR)

  // key
  pinMode(14, INPUT);
  pinMode(16, INPUT);

Serial.begin(9600);

}

void loop() {  
// key test for motor (up & down)******************************

j=24;
if (Mt[j]<=16){
    if(digitalRead(14)==HIGH ){
    motor(0,Mt[j],0,0,1,0);
    }
    else if(digitalRead(16)==HIGH){
     motor(0,Mt[j],0,0,-1,0); 
    }
    else {
    motor(0,Mt[j],0,0,0,0); 
    }
}
else{
if(digitalRead(14)==HIGH ){
motor(0,0,Mt[j],0,0,1);
}
else if(digitalRead(16)==HIGH){
 motor(0,0,Mt[j],0,0,-1); 
}
else {
motor(0,0,Mt[j],0,0,0); 
}
}

//*************************************************************

/// start code for all cells###############################

//if(pressure_array[cell]<400 && hall_up_array[cell]!=1){
//motor(0,Mt[cell],0,0,1,0);
//}
//else if(pressure_array[cell]>400 && hall_down_array[cell]!=1){
//motor(0,Mt[cell],0,0,-1,0); 
//}
//else {
//motor(0,Mt[cell],0,0,0,0); 
//}

///###########################
//do{
//
//// scan sensors  //****************************
//for ( int i = 1 ; i <= 24 ; i += 1){
//  hu[i-1]=hall_up(i); 
//  hd[i-1]=hall_down(i); 
//  Ir[i-1]=IR(i); 
//  p[i-1]=pressure(i); 
//}
//int  hall_up_array[]={0,hu[0],hu[1],hu[2],hu[3],hu[4],hu[5],hu[6],hu[7],hu[8],hu[9],hu[11],hu[10],hu[19],hu[20],hu[21],hu[12],hu[13],hu[15],hu[22],hu[18],hu[17],hu[16],hu[23],hu[14]};
//int  hall_down_array[]={0,hd[0],hd[1],hd[2],hd[3],hd[4],hd[5],hd[6],hd[7],hd[8],hd[9],hd[11],hd[10],hd[19],hd[20],hd[21],hd[12],hd[13],hd[15],hd[22],hd[18],hd[17],hd[16],hd[23],hd[14]};
//int  IR_array[]={0,Ir[0],Ir[1],Ir[2],Ir[3],Ir[4],Ir[5],Ir[6],Ir[7],Ir[8],Ir[9],Ir[11],Ir[10],Ir[19],Ir[20],Ir[21],Ir[12],Ir[13],Ir[15],Ir[22],Ir[18],Ir[17],Ir[16],Ir[23],Ir[14]};
//int  pressure_array[]={0,p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[8],p[9],p[11],p[10],p[19],p[20],p[21],p[12],p[13],p[15],p[22],p[18],p[17],p[16],p[23],p[14]};
//
//
//if (Mt[cell]<=16){
//     if( hall_up_array[cell]!=0){    
//        motor(0,Mt[cell],0,0,0,0);
//        cell=cell+1;
//        break;
//      }
//      else{
//        motor(0,Mt[cell],0,0,1,0);
//        }
//    }
//else{
//     if( hall_up_array[cell]!=0){    
//      motor(0,0,Mt[cell],0,0,0);
//      cell=cell+1;
//      break;
//      }
//      else{
//      motor(0,0,Mt[cell],0,0,1);
//      }
//}
//if (cell==25){
//  t=1;
//  cell=9;
//}
//
//}while(t==0);





do{

// scan sensors  //****************************
for ( int i = 1 ; i <= 24 ; i += 1){
  hu[i-1]=hall_up(i); 
  hd[i-1]=hall_down(i); 
  Ir[i-1]=IR(i); 
  p[i-1]=pressure(i); 
}
int  hall_up_array[]={0,hu[0],hu[1],hu[2],hu[3],hu[4],hu[5],hu[6],hu[7],hu[8],hu[9],hu[11],hu[10],hu[19],hu[20],hu[21],hu[12],hu[13],hu[15],hu[22],hu[18],hu[17],hu[16],hu[23],hu[14]};
int  hall_down_array[]={0,hd[0],hd[1],hd[2],hd[3],hd[4],hd[5],hd[6],hd[7],hd[8],hd[9],hd[11],hd[10],hd[19],hd[20],hd[21],hd[12],hd[13],hd[15],hd[22],hd[18],hd[17],hd[16],hd[23],hd[14]};
int  IR_array[]={0,Ir[0],Ir[1],Ir[2],Ir[3],Ir[4],Ir[5],Ir[6],Ir[7],Ir[8],Ir[9],Ir[11],Ir[10],Ir[19],Ir[20],Ir[21],Ir[12],Ir[13],Ir[15],Ir[22],Ir[18],Ir[17],Ir[16],Ir[23],Ir[14]};
int  pressure_array[]={0,p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7],p[8],p[9],p[11],p[10],p[19],p[20],p[21],p[12],p[13],p[15],p[22],p[18],p[17],p[16],p[23],p[14]};

//  *************************************************
if (Mt[cell]<=16){
  if ( pressure_array[cell]>300){
     if( hall_down_array[cell]!=0){    
      motor(0,Mt[cell],0,0,0,0);
      break;
      }
      else{
      motor(0,Mt[cell],0,0,-1,0);
      }
  }
  else{
    motor(0,Mt[cell],0,0,0,0);
  }
}
else{
  if ( pressure_array[cell]>300){
     if( hall_down_array[cell]!=0){    
      motor(0,0,Mt[cell],0,0,0);
      break;
      }
      else{
      motor(0,0,Mt[cell],0,0,-1);
      }
  }
  else{
    motor(0,0,Mt[cell],0,0,0);
  }
}


//j=18;
// moniror senssors
Serial.print(hall_up_array[j]);
Serial.print('*');
Serial.print(hall_down_array[j]);
Serial.print('*');
Serial.print(IR_array[j]);
Serial.print('*');
Serial.println(pressure(11));
Serial.print("    ");
//Serial.println(cell);
//
//
//Serial.print(hall_up_array[cell2]);
//Serial.print('*');
//Serial.print(hall_down_array[cell2]);
//Serial.print('*');
//Serial.print(IR_array[cell2]);
//Serial.print('*');
//Serial.println(pressure_array[cell2]);
//  for ( int i =0 ; i<=23 ; i+=1){
//  Serial.print(hall_up_array[i]);
//  Serial.print('*');
//  delay(50);
//  if (i==23)
//   Serial.println(' ');
val = pressure_array[cell];
}while(val>400);

cell=cell+1;
if (cell==25){
  cell=9;}



}// END Of void Loop

int hall_up(int H_1){
if (H_1==1){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  up1 = digitalRead(2);
return up1;
}

if (H_1==2){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  up2 = digitalRead(2);
return up2;
}
if (H_1==3){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  up3 = digitalRead(2);
return up3;
}

if (H_1==4){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  up4 = digitalRead(2);
return up4;
}

if (H_1==5){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  up5 = digitalRead(2);
return up5;
}

if (H_1==6){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  up6 = digitalRead(8);
return up6;
}

if (H_1==7){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  up7 = digitalRead(8);
return up7;
}

if (H_1==8){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  up8 = digitalRead(8);
return up8;
}

if (H_1==9){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  up9 = digitalRead(8);
return up9;
}

if (H_1==10){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  up10 = digitalRead(8);
return up10;
}

if (H_1==11){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  up11 = digitalRead(8);
return up11;
}

if (H_1==12){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  up12 = digitalRead(7);
return up12;
}

if (H_1==13){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  up13 = digitalRead(7);
return up13;
}

if (H_1==14){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  up14 = digitalRead(7);
return up14;
}

if (H_1==15){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  up15 = digitalRead(7);
return up15;
}

if (H_1==16){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  up16 = digitalRead(7);
return up16;
}

if (H_1==17){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  up17 = digitalRead(9);
return up17;
}

if (H_1==18){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  up18 = digitalRead(9);
return up18;
}

if (H_1==19){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  up19 = digitalRead(9);
return up19;
}

if (H_1==20){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  up20 = digitalRead(9);
return up20;
}

if (H_1==21){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  up21 = digitalRead(9);
return up21;
}

if (H_1==22){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  up22 = digitalRead(10);
return up22;
}

if (H_1==23){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  up23 = digitalRead(10);
return up23;
}

if (H_1==24){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  up24 = digitalRead(10);
return up24;
}
}


int hall_down(int H_2){ //**************************************************************************************//
if (H_2==1){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  down1 = digitalRead(2);
return down1;
}

if (H_2==2){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int down2 = digitalRead(2);
return down2;
}
if (H_2==3){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  down3 = digitalRead(2);
return down3;
}

if (H_2==4){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  down4 = digitalRead(2);
return down4;
}

if (H_2==5){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  down5 = digitalRead(2);
return down5;
}

if (H_2==6){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  down6 = digitalRead(8);
return down6;
}

if (H_2==7){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  down7 = digitalRead(8);
return down7;
}

if (H_2==8){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  down8 = digitalRead(8);
return down8;
}

if (H_2==9){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  down9 = digitalRead(8);
return down9;
}

if (H_2==10){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  down10 = digitalRead(8);
return down10;
}

if (H_2==11){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  down11 = digitalRead(8);
return down11;
}

if (H_2==12){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  down12 = digitalRead(7);
return down12;
}

if (H_2==13){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  down13 = digitalRead(7);
return down13;
}

if (H_2==14){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  down14 = digitalRead(7);
return down14;
}

if (H_2==15){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  down15 = digitalRead(7);
return down15;
}

if (H_2==16){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  down16 = digitalRead(7);
return down16;
}

if (H_2==17){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  down17 = digitalRead(9);
return down17;
}

if (H_2==18){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  down18 = digitalRead(9);
return down18;
}

if (H_2==19){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  down19 = digitalRead(9);
return down19;
}

if (H_2==20){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  down20 = digitalRead(9);
return down20;
}

if (H_2==21){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  down21 = digitalRead(9);
return down21;
}

if (H_2==22){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  down22 = digitalRead(10);
return down22;
}

if (H_2==23){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  down23 = digitalRead(10);
return down23;
}

if (H_2==24){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  down24 = digitalRead(10);
return down24;
}

}

int IR(int RX){ //**************************************************************************************//
if(RX <= 12){
  digitalWrite(11,1);
  digitalWrite(12,0);
}
else{
  digitalWrite(11,0);
  digitalWrite(12,1);
}

if (RX==1){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  IR1 = digitalRead(2);
return IR1;
}

if (RX==2){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int IR2 = digitalRead(2);
return IR2;
}
if (RX==3){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR3 = digitalRead(2);
return IR3;
}

if (RX==4){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR4 = digitalRead(2);
return IR4;
}

if (RX==5){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR5 = digitalRead(2);
return IR5;
}

if (RX==6){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR6 = digitalRead(8);
return IR6;
}

if (RX==7){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR7 = digitalRead(8);
return IR7;
}

if (RX==8){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR8 = digitalRead(8);
return IR8;
}

if (RX==9){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR9 = digitalRead(8);
return IR9;
}

if (RX==10){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR10 = digitalRead(8);
return IR10;
}

if (RX==11){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  IR11 = digitalRead(8);
return IR11;
}

if (RX==12){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
int  IR12 = digitalRead(7);
return IR12;
}

if (RX==13){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR13 = digitalRead(7);
return IR13;
}

if (RX==14){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR14 = digitalRead(7);
return IR14;
}

if (RX==15){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR15 = digitalRead(7);
return IR15;
}

if (RX==16){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR16 = digitalRead(7);
return IR16;
}

if (RX==17){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  IR17 = digitalRead(9);
return IR17;
}

if (RX==18){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
int  IR18 = digitalRead(9);
return IR18;
}

if (RX==19){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR19 = digitalRead(9);
return IR19;
}

if (RX==20){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,1);
int  IR20 = digitalRead(9);
return IR20;
}

if (RX==21){
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR21 = digitalRead(9);
return IR21;
}

if (RX==22){
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
int  IR22 = digitalRead(10);
return IR22;
}

if (RX==23){
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR23 = digitalRead(10);
return IR23;
}

if (RX==24){
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,1);
digitalWrite(6,0);
int  IR24 = digitalRead(10);
return IR24;
}

 digitalWrite(11,0);
 digitalWrite(12,0);

}


int pressure(int p){ //************************************************************************************//
if (p==1){
digitalWrite(A9,0);
digitalWrite(A10,0);
digitalWrite(A11,0);
digitalWrite(A12,0);
int  p1 = analogRead(sensor_pressure);
return p1;
}

else if (p==2){
digitalWrite(A9,255);
digitalWrite(A10,0);
digitalWrite(A11,0);
digitalWrite(A12,0);
int  p2 = analogRead(sensor_pressure);
return p2;
}

else if (p==3){
digitalWrite(A9,0);
digitalWrite(A10,255);
digitalWrite(A11,0);
digitalWrite(A12,0);
int  p3 = analogRead(sensor_pressure);
return p3;
}

if (p==4){
digitalWrite(A9,255);
digitalWrite(A10,255);
digitalWrite(A11,0);
digitalWrite(A12,0);
int  p4 = analogRead(sensor_pressure);
return p4;
}

if (p==5){
digitalWrite(A9,0);
digitalWrite(A10,0);
digitalWrite(A11,255);
digitalWrite(A12,0);
int  p5 = analogRead(sensor_pressure);
return p5;
}

if (p==6){
digitalWrite(A9,255);
digitalWrite(A10,0);
digitalWrite(A11,255);
digitalWrite(A12,0);
int  p6 = analogRead(sensor_pressure);
return p6;
}

if (p==7){
digitalWrite(A9,0);
digitalWrite(A10,255);
digitalWrite(A11,255);
digitalWrite(A12,0);
int  p7 = analogRead(sensor_pressure);
return p7;
}

if (p==8){
digitalWrite(A9,255);
digitalWrite(A10,255);
digitalWrite(A11,255);
digitalWrite(A12,0);
int  p8 = analogRead(sensor_pressure);
return p8;
}

if (p==9){
digitalWrite(A9,0);
digitalWrite(A10,0);
digitalWrite(A11,0);
digitalWrite(A12,255);
int  p9 = analogRead(sensor_pressure);
return p9;
}

if (p==10){
digitalWrite(A9,255);
digitalWrite(A10,0);
digitalWrite(A11,0);
digitalWrite(A12,255);
int  p10 = analogRead(sensor_pressure);
return p10;
}

if (p==11){
digitalWrite(A9,0);
digitalWrite(A10,255);
digitalWrite(A11,0);
digitalWrite(A12,255);
int  p11 = analogRead(sensor_pressure);
return p11;
}

if (p==12){
digitalWrite(A9,255);
digitalWrite(A10,255);
digitalWrite(A11,0);
digitalWrite(A12,255);
int  p12 = analogRead(sensor_pressure);
return p12;
}

if (p==13){
digitalWrite(A9,0);
digitalWrite(A10,0);
digitalWrite(A11,255);
digitalWrite(A12,255);
int  p13 = analogRead(sensor_pressure);
return p13;
}

if (p==14){
digitalWrite(A9,255);
digitalWrite(A10,0);
digitalWrite(A11,255);
digitalWrite(A12,255);
int  p14 = analogRead(sensor_pressure);
return p14;
}

if (p==15){
digitalWrite(A9,0);
digitalWrite(A10,255);
digitalWrite(A11,255);
digitalWrite(A12,255);
int  p15 = analogRead(sensor_pressure);
return p15;
}

if (p==16){
digitalWrite(A9,255);
digitalWrite(A10,255);
digitalWrite(A11,255);
digitalWrite(A12,255);
int  p16 = analogRead(sensor_pressure);
return p16;
}

if (p==17){
int  p17 = analogRead(A0);
return p17;
}

if (p==18){
int  p18 = analogRead(A1);
return p18;
}

if (p==19){
int  p19 = analogRead(A2);
return p19;
}

if (p==20){
int  p20 = analogRead(A3);
return p20;
}

if (p==21){
int  p21 = analogRead(A4);
return p21;
}

if (p==22){
int  p22 = analogRead(A5);
return p22;
}

if (p==23){
int  p23 = analogRead(A6);
return p23;
}

if (p==24){
int  p24 = analogRead(A7);
return p24;
}

}


int motor(int A,int B,int C,int dirA,int dirB,int dirC){//dir=0 stop, dir=1 up, dir=-1 down********************************************************************************************

if (A==1 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,0);
digitalWrite(29,0);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==1 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,0);
digitalWrite(29,0);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==2 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,1);
digitalWrite(29,0);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==2 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,1);
digitalWrite(29,0);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==3 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,0);
digitalWrite(29,1);
digitalWrite(31,0);
digitalWrite(23,1);

}

else if (A==3 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,0);
digitalWrite(29,1);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==4 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,1);
digitalWrite(29,1);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==4 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,1);
digitalWrite(29,1);
digitalWrite(31,0);
digitalWrite(23,1);
}

else if (A==5 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,0);
digitalWrite(29,0);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==5 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,0);
digitalWrite(29,0);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==6 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,1);
digitalWrite(29,0);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==6 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,1);
digitalWrite(29,0);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==7 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,0);
digitalWrite(29,1);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==7 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,0);
digitalWrite(29,1);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==8 && dirA==1){
digitalWrite(25,0);
digitalWrite(27,1);
digitalWrite(29,1);
digitalWrite(31,1);
digitalWrite(23,1);
}

else if (A==8 && dirA==-1){
digitalWrite(25,1);
digitalWrite(27,1);
digitalWrite(29,1);
digitalWrite(31,1);
digitalWrite(23,1);
}
else if(dirA==0){
  digitalWrite(23,0);
}


if (B==9 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==9 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==10 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==10 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==11 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,0);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==11 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,0);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==12 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==12 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,0);
digitalWrite(33,1);
}

else if (B==13 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==13 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,0);
digitalWrite(39,0);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==14 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==14 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,1);
digitalWrite(39,0);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==15 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,0);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==15 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,0);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==16 && dirB==1){
digitalWrite(35,0);
digitalWrite(37,1);
digitalWrite(3,1);
digitalWrite(41,1);
digitalWrite(33,1);
}

else if (B==16 && dirB==-1){
digitalWrite(35,1);
digitalWrite(37,1);
digitalWrite(39,1);
digitalWrite(41,1);
digitalWrite(33,1);
}
else if(dirB==0){
  digitalWrite(33,0);
}


if (C==17 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,0);
digitalWrite(49,0);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==17 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,0);
digitalWrite(49,0);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==18 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,1);
digitalWrite(49,0);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==18 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,1);
digitalWrite(49,0);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==19 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,0);
digitalWrite(49,1);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==19 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,0);
digitalWrite(49,1);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==20 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,1);
digitalWrite(49,1);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==20 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,1);
digitalWrite(49,1);
digitalWrite(51,0);
digitalWrite(43,1);
}

else if (C==21 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,0);
digitalWrite(49,0);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==21 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,0);
digitalWrite(49,0);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==22 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,1);
digitalWrite(49,0);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==22 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,1);
digitalWrite(49,0);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==23 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,0);
digitalWrite(49,1);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==23 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,0);
digitalWrite(49,1);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==24 && dirC==1){
digitalWrite(45,0);
digitalWrite(47,1);
digitalWrite(49,1);
digitalWrite(51,1);
digitalWrite(43,1);
}

else if (C==24 && dirC==-1){
digitalWrite(45,1);
digitalWrite(47,1);
digitalWrite(49,1);
digitalWrite(51,1);
digitalWrite(43,1);
}
else if(dirC==0){
  digitalWrite(43,0);
}
  
}
