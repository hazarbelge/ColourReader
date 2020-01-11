#define sensorcikis 12

#include <LiquidCrystal.h> 

LiquidCrystal lcd(7,6,5,4,3,2);
int Kirmizi=0 
int Yesil=0
int Mavi=0;

void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(sensorcikis, INPUT);
  lcd.begin(16,2);

  digitalWrite(s0,LOW); 
  digitalWrite(s1,HIGH);  
  Serial.begin(9600);

}

void loop() {
  
  lcd.print("K=");
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  Kirmizi = pulseIn(sensorcikis, LOW); 
  lcd.print(Kirmizi); 
  lcd.print("  ");
  lcd.setCursor(7, 0); 
  Serial.print("Kırmızı= ");
  Serial.print(Kirmizi); 
  Serial.print("  ");
  delay(65);
 
  lcd.print("Y=");
  digitalWrite(10, HIGH); 
  digitalWrite(11, HIGH);
  Yesil = pulseIn(sensorcikis, LOW); 
  lcd.print(Yesil); 
  lcd.setCursor(4, 1);
  Serial.print("Yeşil= ");
  Serial.print(Yesil); 
  Serial.print("   ");
  delay(65);

  lcd.print("M=");
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  Mavi = pulseIn(sensorcikis, LOW); 
  lcd.print(Mavi);
  Serial.print("Mavi= "); 
  Serial.print(Mavi); 
  Serial.println();
  lcd.setCursor(0, 0);
  delay(1111);
  
  lcd.clear(); 
  delay(162);

  lcd.setCursor(1,0); 

  lcd.print("Algilanan Renk");
  
  lcd.setCursor(2,1); 

  if(Kirmizi<530 && Mavi<530 && Yesil<530){
  Serial.print("Renk = Beyaz   ");
  lcd.print("Beyaz");  
  }

  else if(Kirmizi>1400 && Mavi>1400 && Yesil>1400) {
  Serial.print("Renk = Siyah   ");
  lcd.print("Siyah");  
  }
  
  else if(Kirmizi < 1100 && Kirmizi<Yesil-10 && Kirmizi<Mavi-10){
  Serial.print("Renk = Kırmızı   ");
  lcd.print("Kirmizi");
  }
  
  else if(Mavi < 1100 && Mavi<Yesil-10 && Mavi<Kirmizi-10){
  Serial.print("Renk = Mavi   ");
  lcd.print("Mavi");
  }

  else if(Yesil < 1100 && Yesil<Mavi-10 && Yesil<Kirmizi-10){
  lcd.print("Yesil");
  Serial.print("Renk = Yeşil   ");
  }
  
  else if(Mavi<Yesil && Yesil<Kirmizi && abs(Mavi-Yesil)<20){
  lcd.print("Cyan");
  Serial.print("Renk = Cyan   ");
  }
    
  else if(Mavi<Yesil && Kirmizi<Yesil && abs(Mavi-Kirmizi)<20){
  lcd.print("Magenta");
  Serial.print("Renk = Magenta   ");
  }

  else if(Yesil<Mavi && Kirmizi<Mavi && abs(Kirmizi-Yesil)<20){
  Serial.print("Renk = Sarı   ");
  lcd.print("Sari");
  }
  
  else{
  Serial.print("Renk algılanamadı   ");
  lcd.print("---");
  }
  
  Serial.println();
  delay(1111);
  lcd.clear();
  delay(160);
  }
