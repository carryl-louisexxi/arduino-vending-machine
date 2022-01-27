//setting up start button the ON/OFF state
const int sstart= A1;
const int chippybutton=12;
const int oishibutton=11;
const int piatosbutton=10;
const int dyesbutton=13;
const int singkobutton=A0;
//setting up food
const int piatos= 7;
const int oishi= 6;
const int chippy= 5;
//setting up money
const int dyes= 3;
const int kinse= 4;
const int singko=2;
//setting up change
const int suklidyes=9;
const int suklisingko=8;
//settign up the button state

int state=0;
int singkos=0;
int dyess=0;
int chippys=0;
int oishis=0;
int piatoss=0;

void setup() {
 //initialize the outputs and inputs
  pinMode(piatos, OUTPUT);
  pinMode(oishi, OUTPUT);
  pinMode(chippy, OUTPUT);
  pinMode(dyes, OUTPUT);
  pinMode(kinse,OUTPUT);
  pinMode(singko, OUTPUT);
  pinMode(suklidyes, OUTPUT);
  pinMode(suklisingko, OUTPUT);
  pinMode(sstart, INPUT);
  pinMode(chippybutton, INPUT);
  pinMode(oishibutton, INPUT);
  pinMode(piatosbutton, INPUT);
  pinMode(singkobutton, INPUT);
  pinMode(dyesbutton, INPUT);

}

void loop() {
 switch(state){
  case 0: //state 0
  digitalWrite(piatos, LOW);
  digitalWrite(oishi,LOW);
  digitalWrite(chippy,LOW);
  digitalWrite(kinse, LOW);
  digitalWrite(dyes,LOW);
  digitalWrite(singko, LOW);
  digitalWrite(suklidyes, LOW);
  digitalWrite(suklisingko, LOW);
  if(digitalRead(sstart)==HIGH){ //if gipindot si start then it will go to state 1
    delay(1000);
    state=1;
  }else{
    state=0; //if wala gipindot si 1 then it will just go back sa state 0 which is off tanan
  }
  break;
  case 1: //state 1
  singkos=digitalRead(singkobutton);
  dyess=digitalRead(dyesbutton);
  
  digitalWrite(piatos, LOW);
  digitalWrite(oishi,LOW);
  digitalWrite(chippy,LOW);
  digitalWrite(kinse, LOW);
  digitalWrite(dyes,LOW);
  digitalWrite(singko, LOW);
  digitalWrite(suklidyes, LOW);
  digitalWrite(suklisingko, LOW);
  if(singkos==HIGH){ //if naay nihulog og singko then moadto sya sa state 2
    delay(1000);
    state=2;
  } else if(dyess==HIGH){ //if dyes then adto sa state 3
    delay(1000);
    state=3;
  }else{
    state=1;  // try to ask if pwede ba ni: else wala sa choices ag gipindot then it will just go back to state 1 and mag wait syag balig 10 seconds; if wala gihapoy nipindot tehn it will just turn off
  }
  break;
  case 2: //state 2 mo on si singko
   singkos=digitalRead(singkobutton);
   dyess=digitalRead(dyesbutton);
   chippys=digitalRead(chippybutton);
   
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, HIGH);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    if(singkos==HIGH){ // if mohulog napud og singko then it will go to state 3
      delay(1000);
      state=3;
    } else if(dyess==HIGH){ //if mohulog og ten then it will go to state 4
      delay(1000);
      state=4;
    } else if(chippys==HIGH){ //if mopindot og chippy then it will go to state 5
      delay(1000);
      state=5;
    } else{
      state=2; //if neither sa papilian ag gipindot then it will just go back to state 2
    }
  break;
  case 3: //state 3; mo on si ten
    singkos=digitalRead(singkobutton);
   dyess=digitalRead(dyesbutton);
   chippys=digitalRead(chippybutton);
   oishis=digitalRead(oishibutton);
   
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,HIGH);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    if(singkos==HIGH){ //if mohulog og singko then it will just go to state 4
      delay(1000);
      state=4;
    }else if(dyess==HIGH){  //if mohulog og dyes then it will just go to state 6
      delay(1000);
      state=6;
    }else if(oishis==HIGH){   //if mopili og oishi then it will just go to state 7
      delay(1000);
      state=7;
    }else if(chippys==HIGH){   //if mopili og chippy then it will just go to state 8
      delay(1000);
      state=8;
    }else {     //if neither sa papilian then it will just go to state 4
      state=3;
    }
  break; 
  case 4: //state 4 ; mo on si kinse
    singkos=digitalRead(singkobutton);
   dyess=digitalRead(dyesbutton);
   chippys=digitalRead(chippybutton);
   oishis=digitalRead(oishibutton);
   
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, HIGH);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    if(singkos==HIGH){   //if mohulog og singko then it will just go to state 13
      delay(1000);
      state=13;
    }else if(dyess==HIGH){ //if mohulog og dyes then it will just go to state 12
      delay(1000);
      state=12;
    } else if(piatoss==HIGH){ //if mopili og piatos then it will just go to state 9
      delay(1000);
      state=9;
    } else if(oishis==HIGH){   //if mopili og oishi then it will just go to state 10
      delay(1000);
      state=10;
    } else if(chippys==HIGH){   //if mopili og chippy then it will just go to state 11
      delay(1000);
      state=11;
    }else {     //if neither sa papilian then it will just go to state 4
      state=4;
    }
  break;
  case 5:  //state 5 ; gipili si chippy, mo on si chippy after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,HIGH);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=0;
  break;
  case 6:   //state 6; mo on si dyes, gikaon si dyes after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,HIGH);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, HIGH);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=3;
  break;
  case 7:   //state 7; gipili si oishi, mo on si oishi after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,HIGH);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=0;
  break;
  case 8:   //state 8; gipili si chippy, mo on si oishi and iyang sukli after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,HIGH);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, HIGH);
    delay(2000);
    state=0;
  break;
  case 9:  //state 9; gipili si piatos, mo on si piatos after 2 seconds kay balik sa state 0
    digitalWrite(piatos, HIGH);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=0;
  break;
  case 10:   //state 10; gipili si oishi, mo on si oishi after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,HIGH);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, HIGH);
    delay(2000);
    state=0;
  break;
  case 11:   //state 11; gipili si chippy, mo on si chippy after 2 seconds kay balik sa state 0
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,HIGH);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, HIGH);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=0;
  break;
  case 12:   //state 12; gipindot si dyes, mo on si dyes but iya rang kan-on ag kwarta after 2 seconds kay balik sa state 4
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,HIGH);
    digitalWrite(singko, LOW);
    digitalWrite(suklidyes, HIGH);
    digitalWrite(suklisingko, LOW);
    delay(2000);
    state=4;
  break;
  case 13:  //state 13; gipindot si singko, mo on si singko but iya rang kan-on ag kwarta after 2 seconds kay balik sa state 4
    digitalWrite(piatos, LOW);
    digitalWrite(oishi,LOW);
    digitalWrite(chippy,LOW);
    digitalWrite(kinse, LOW);
    digitalWrite(dyes,LOW);
    digitalWrite(singko, HIGH);
    digitalWrite(suklidyes, LOW);
    digitalWrite(suklisingko, HIGH);
    delay(2000);
    state=4;
  break;
 }
}
