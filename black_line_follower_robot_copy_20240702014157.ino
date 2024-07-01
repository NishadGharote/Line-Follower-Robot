
#define ML1 17
#define ML2 5
#define MR1 4
#define MR2 16
#define L_Sens 19
#define R_Sens 18

void setup() {  
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT); 
  pinMode(L_Sens,INPUT);
  pinMode(R_Sens,INPUT);
  Serial.begin(115200);
}

void loop() {
  uint8_t L_Data=(digitalRead(L_Sens));
  uint8_t R_Data=(digitalRead(R_Sens));
  Serial.print("This is sensor value: ");
  Serial.print(L_Data);
  Serial.print("");
  Serial.print(R_Data);





if (L_Data==0 and R_Data==0 ) {

      digitalWrite(ML1, HIGH);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, HIGH);
      digitalWrite(MR2, LOW);
      Serial.println("forward");

    } 
   else if (L_Data==1 and R_Data==0) {
      digitalWrite(ML1, LOW);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, HIGH);
      digitalWrite(MR2, LOW);
      Serial.println("LEFT");

    } else if (L_Data==0 and R_Data==1) {
      digitalWrite(ML1, HIGH);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, LOW);
      digitalWrite(MR2, LOW);
      Serial.println("RIGHT");

    }
}
    
  


