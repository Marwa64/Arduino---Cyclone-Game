int button1 = 12;
int button2 = 11;

bool start = false;
bool victory = false;
int delayTime = 30;
int menuDelay = 400;
int pause = 1000;

int score = 0;

void setup() {
  // put your setup code here, to run once:
 for (int i = 1; i <= 8; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
}

void loop() {
  // Menu State
  while (start == false){
    if (digitalRead(button2) == HIGH){
      digitalWrite(3, HIGH);
    }
    if (digitalRead(button1) == HIGH){
      start = true;
      break;
    }
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    delay(menuDelay);
    
    for (int i = 1; i < 8; i++){
      if (digitalRead(button1) == HIGH){
        start = true;
        break;
      }
      digitalWrite(i, LOW);
      digitalWrite(i + 1, HIGH);
      delay(menuDelay);
    }
    
    if (start == false){
      for (int i = 8; i > 2; i--){
        if (digitalRead(button1) == HIGH){
          start = true;
          break;
        }
        digitalWrite(i, LOW);
        digitalWrite(i - 1, HIGH);
        delay(menuDelay);
      }
    }
  }

  
  // Game
  if (start){
     if (digitalRead(button1) == HIGH){
      if (digitalRead(1) == HIGH || digitalRead(8) == HIGH){
        score++;
        delay(pause);
        
        // displaying the score
        for (int i = 0; i < score; i++){
          for (int j = 1; j < 9; j++){
            digitalWrite(j, HIGH);
          }
          
          delay(menuDelay);
          
          for (int j = 1; j < 9; j++){
            digitalWrite(j, LOW);
          }

          delay(menuDelay);
        }
        
      }
      delay(pause);
      if (score >= 5){
        start = false;
        victory = true;
      }
     }
     
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    delay(delayTime);
    
    for (int i = 1; i < 8; i++){
      if (digitalRead(button1) == HIGH){
        if (digitalRead(1) == HIGH || digitalRead(8) == HIGH){
          score++;
          delay(pause);
          
          // displaying the score
          for (int i = 0; i < score; i++){
            for (int j = 1; j < 9; j++){
              digitalWrite(j, HIGH);
            }
            
            delay(menuDelay);
            
            for (int j = 1; j < 9; j++){
              digitalWrite(j, LOW);
            }
  
            delay(menuDelay);
          }
        }
        delay(pause);
        if (score >= 5){
          start = false;
          victory = true;
          break;
        }
      }
      digitalWrite(i, LOW);
      digitalWrite(i + 1, HIGH);
      delay(delayTime);
    }

    if (start == true){
      for (int i = 8; i > 2; i--){
        if (digitalRead(button1) == HIGH){
          if (digitalRead(1) == HIGH || digitalRead(8) == HIGH){
            score++;
            delay(pause);
            
            // displaying the score
            for (int i = 0; i < score; i++){
              for (int j = 1; j < 9; j++){
                digitalWrite(j, HIGH);
              }
              
              delay(menuDelay);
              
              for (int j = 1; j < 9; j++){
                digitalWrite(j, LOW);
              }
    
              delay(menuDelay);
            }
          }
          delay(pause);
          if (score >= 5){
            start = false;
            victory = true;
            break;
          }
        }
        digitalWrite(i, LOW);
        digitalWrite(i - 1, HIGH);
        delay(delayTime);
      }
    }
  }

  // Declare Victory
  if ( victory == true){
    victory = false;
    score = 0;
    for (int i = 1; i < 9 ; i++){
      digitalWrite(i, LOW);
    }
    delay(pause);
  }
}
