#include "Adafruit_FONA.h"

#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

// this is a large buffer for replies
char replybuffer[255];

// We default to using software serial. If you want to use hardware serial
// (because softserial isnt supported) comment out the following three lines 
// and uncomment the HardwareSerial line
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

// Hardware serial is also possible!
//  HardwareSerial *fonaSerial = &Serial1;

// Use this for FONA 800 and 808s
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
// Use this one for FONA 3G
//Adafruit_FONA_3G fona = Adafruit_FONA_3G(FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;
int ledPin1 = 5;                       // Active led pin
int ledPin2 = 6;                       // Active led pin
int ledPin3 = 7;                       // Active led pin
int ledPin4 = 8;                       // Active led pin
int ledPin5 = 9;                       // Active led pin
int ledPin6 = 10;                       // Active led pin
int timer = 1000;                       // timing of one dot
int count;

void setup() {
  while (!Serial);

  Serial.begin(115200);
  Serial.println(F("FONA basic test"));
  Serial.println(F("Initializing....(May take 3 seconds)"));

  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  type = fona.type();
  Serial.println(F("FONA is OK"));
  Serial.print(F("Found "));
  switch (type) {
    case FONA800L:
      Serial.println(F("FONA 800L")); break;
    case FONA800H:
      Serial.println(F("FONA 800H")); break;
    case FONA808_V1:
      Serial.println(F("FONA 808 (v1)")); break;
    case FONA808_V2:
      Serial.println(F("FONA 808 (v2)")); break;
    case FONA3G_A:
      Serial.println(F("FONA 3G (American)")); break;
    case FONA3G_E:
      Serial.println(F("FONA 3G (European)")); break;
    default: 
      Serial.println(F("???")); break;
  }
  
  // Print module IMEI number.
  char imei[15] = {0}; // MUST use a 16 character buffer for IMEI!
  uint8_t imeiLen = fona.getIMEI(imei);
  if (imeiLen > 0) {
    Serial.print("Module IMEI: "); Serial.println(imei);
  }

  // Optionally configure a GPRS APN, username, and password.
  // You might need to do this to access your network's GPRS/data
  // network.  Contact your provider for the exact APN, username,
  // and password values.  Username and password are optional and
  // can be removed, but APN is required.
  //fona.setGPRSNetworkSettings(F("your APN"), F("your username"), F("your password"));

  // Optionally configure HTTP gets to follow redirects over SSL.
  // Default is not to follow SSL redirects, however if you uncomment
  // the following line then redirects over SSL will be followed.
  //fona.setHTTPSRedirect(true);
   pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT);
 pinMode(ledPin4, OUTPUT);
 pinMode(ledPin5, OUTPUT);
 pinMode(ledPin6, OUTPUT);
 count=0;

  printMenu();
}

void printMenu(void) {
  Serial.println(F("-------------------------------------"));
  Serial.println(F("[?] Print this menu"));
  
    // SMS
  Serial.println(F("[N] Number of SMSs"));
  Serial.println(F("[r] Read SMS #"));
  Serial.println(F("[R] Read All SMS"));
  Serial.println(F("[d] Delete SMS #"));
  Serial.println(F("[s] Send SMS"));
  Serial.println(F("[u] Send USSD"));
}

//char text[] = "ABC";         // Transmittet text




void start(){                         // rapid blink at startup
 //for(int i = 0; i < 50; i++){
    Serial.print(F("start running "));
   digitalWrite(ledPin1, HIGH);
   digitalWrite(ledPin2, HIGH);
   digitalWrite(ledPin3, HIGH);
   digitalWrite(ledPin4, HIGH);
   digitalWrite(ledPin5, HIGH);
   digitalWrite(ledPin6, HIGH);
   delay(5*timer);
   digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
   digitalWrite(ledPin3, LOW);
   digitalWrite(ledPin4, LOW);
   digitalWrite(ledPin5, LOW);
   digitalWrite(ledPin6, LOW);
   delay(timer);
 //}
 //delay(7 * timer);
}

void a(){
  digitalWrite(ledPin1,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  delay(timer/2);
}

void b(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin3,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin3,LOW);
  delay(timer/2);
}

void c(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  delay(timer/2);
}

void d(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin4,LOW);
  delay(timer/2);
}
void e(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin4,LOW);
  delay(timer/2);
}
void f(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  delay(timer/2);
}
void g(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  delay(timer/2);
}
void h(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  delay(timer/2);
}
void i(){
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  delay(timer);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  delay(timer/2);
}
void j(){
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  delay(timer/2);
}
void k(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void l(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void m(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void n(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void o(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void p(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void q(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void r(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void s(){
  Serial.print(F("s running "));
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
  Serial.print(F("s stops "));
}
void t(){
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  delay(timer);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  delay(timer/2);
}
void u(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}
void v(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}
void w(){
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}

void x(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}
void y(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}
void z(){
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  delay(timer);
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  delay(timer/2);
}



void braille(byte letter) {           // time to transmit
//  Serial.println(letter, DEC);
   Serial.print(char(letter));
  Serial.println(F("running "));
 if (letter == 'a') {a();}
 if (letter == 'b') {b();}
 if (letter == 'c') {c();}
 if (letter == 'd') {d();}
 if (letter == 'e') {e();}
 if (letter == 'f') {f();}
 if (letter == 'g') {g();}
 if (letter == 'h') {h();}
 if (letter == 'i') {i();}
 if (letter == 'j') {j();}
 if (letter == 'k') {k();}
 if (letter == 'l') {l();}
 if (letter == 'm') {m();}
 if (letter == 'n') {n();}
 if (letter == 'o') {o();}
 if (letter == 'p') {p();}
 if (letter == 'q') {q();}
 if (letter == 'r') {r();}
 if (letter == 's') {s();}
 if (letter == 't') {t();}
 if (letter == 'u') {u();}
 if (letter == 'v') {v();}
 if (letter == 'w') {w();}
 if (letter == 'x') {x();}
 if (letter == 'y') {y();}
 if (letter == 'z') {z();}
 if (letter == 'A') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);a();}
 if (letter == 'B') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);b();}
 if (letter == 'C') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);c();}
 if (letter == 'D') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);d();}
 if (letter == 'E') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);e();}
 if (letter == 'F') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);f();}
 if (letter == 'G') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);g();}
 if (letter == 'H') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);h();}
 if (letter == 'I') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);i();}
 if (letter == 'J') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);j();}
 if (letter == 'K') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);k();}
 if (letter == 'L') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);l();}
 if (letter == 'M') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);m();}
 if (letter == 'N') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);n();}
 if (letter == 'O') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);o();}
 if (letter == 'P') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);p();}
 if (letter == 'Q') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);q();}
 if (letter == 'R') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);r();}
 if (letter == 'S') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);s();}
 if (letter == 'T') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);t();}
 if (letter == 'U') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);u();}
 if (letter == 'V') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);v();}
 if (letter == 'W') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);w();}
 if (letter == 'X') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);x();}
 if (letter == 'Y') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);y();}
 if (letter == 'Z') {digitalWrite(ledPin6,HIGH);delay(timer/2);digitalWrite(ledPin6,LOW);z();}
 if (letter == '1') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);a();}
 if (letter == '2') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);b();}
 if (letter == '3') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);c();}
 if (letter == '4') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);d();}
 if (letter == '5') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);e();}
 if (letter == '6') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);f();}
 if (letter == '7') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);g();}
 if (letter == '8') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);h();}
 if (letter == '9') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);i();}
 if (letter == '0') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer/2);
          digitalWrite(ledPin2,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);j();}
 if (letter == ',') {digitalWrite(ledPin3,HIGH);delay(timer);digitalWrite(ledPin3,LOW);delay(timer/2);}
 if (letter == ';') {digitalWrite(ledPin3,HIGH);digitalWrite(ledPin5,HIGH);delay(timer);digitalWrite(ledPin3,LOW);digitalWrite(ledPin5,LOW);delay(timer/2);}
 if (letter == ':') {digitalWrite(ledPin3,HIGH);digitalWrite(ledPin4,HIGH);delay(timer);digitalWrite(ledPin3,LOW);digitalWrite(ledPin4,LOW);delay(timer/2);}
 if (letter == '-') {digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);delay(timer/2);}
 if (letter == '.') {digitalWrite(ledPin3,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin6,HIGH);delay(timer);digitalWrite(ledPin3,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin6,LOW);delay(timer/2);}
 if (letter == '!') {digitalWrite(ledPin3,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);delay(timer);digitalWrite(ledPin3,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);delay(timer/2);}
 if (letter == '/') {digitalWrite(ledPin2,HIGH);digitalWrite(ledPin5,HIGH);delay(timer);digitalWrite(ledPin2,LOW);digitalWrite(ledPin5,LOW);delay(timer/2);}
 if (letter == ' ')                 {delay(2 * timer);}                        // This makes 7 * tempo for space
 //else                               {digitalWrite(ledPin1,HIGH);digitalWrite(ledPin2,HIGH);digitalWrite(ledPin3,HIGH);digitalWrite(ledPin4,HIGH);digitalWrite(ledPin5,HIGH);digitalWrite(ledPin6,HIGH);delay(timer);
  //                                   digitalWrite(ledPin1,LOW);digitalWrite(ledPin2,LOW);digitalWrite(ledPin3,LOW);digitalWrite(ledPin4,LOW);digitalWrite(ledPin5,LOW);digitalWrite(ledPin6,LOW);} 
 //delay(2 * tempo);      // this makes 3 * tempo for letter end, and 7 * tempo for space
}

void loop() {
  Serial.print(F("FONA> "));
  while (! Serial.available() ) {
    if (fona.available()) {
      Serial.write(fona.read());
    }
  }

  char command = Serial.read();
  Serial.println(command);


  switch (command) {
    case '?': {
        printMenu();
        break;
      }
      case 'r': {
        // read an SMS
        flushSerial();
        Serial.print(F("Read #"));
        //uint8_t smsn = readnumber();
        int8_t smsn = fona.getNumSMS();
        Serial.print(F("smsn kiiiiiiiii value hai"));Serial.println(smsn);
        smsn-=3;
        Serial.print(F("\n\rReading SMS #")); 

        // Retrieve SMS sender address/phone number.
        if (! fona.getSMSSender(smsn, replybuffer, 250)) {
          Serial.println("Failed!");
          break;
        }
        Serial.print(F("FROM: ")); Serial.println(replybuffer);

        // Retrieve SMS value.
        uint16_t smslen;
        if (! fona.readSMS(smsn, replybuffer, 250, &smslen)) { // pass in buffer and max len!
          Serial.println("Failed!");
          break;
        }
        //Serial.print(F("***** SMS #")); Serial.print(smsn);
        //Serial.print(" ("); Serial.print(smslen); Serial.println(F(") bytes *****"));
        else
        {
         for(int i=1;i<=5;i++)
           Serial.println(replybuffer);
         Serial.println(strlen(replybuffer));  
        //Serial.println(F("*****"));
        if(count==0){
        start();
         for (int i = 0; i < strlen(replybuffer); i++) {
            braille(replybuffer[i]);
            delay(timer);
          }
          count=1;
          break;
        }
        break;
        }
        break;
      }
    case 'R': {
        // read all SMS
        int8_t smsnum = fona.getNumSMS();
        uint16_t smslen;
        int8_t smsn;

        if ( (type == FONA3G_A) || (type == FONA3G_E) ) {
          smsn = 0; // zero indexed
          smsnum--;
        } else {
          smsn = 1;  // 1 indexed
        }

        for ( ; smsn <= smsnum; smsn++) {
          Serial.print(F("\n\rReading SMS #")); Serial.println(smsn);
          if (!fona.readSMS(smsn, replybuffer, 250, &smslen)) {  // pass in buffer and max len!
            Serial.println(F("Failed!"));
            break;
          }
          // if the length is zero, its a special case where the index number is higher
          // so increase the max we'll look at!
          if (smslen == 0) {
            Serial.println(F("[empty slot]"));
            smsnum++;
            continue;
          }

          Serial.print(F("***** SMS #")); Serial.print(smsn);
          Serial.print(" ("); Serial.print(smslen); Serial.println(F(") bytes *****"));
          Serial.println(replybuffer);
          Serial.println(F("*****"));
        }
        break;
      }

    case 'd': {
        // delete an SMS
        flushSerial();
        Serial.print(F("Delete #"));
        uint8_t smsn = readnumber();

        Serial.print(F("\n\rDeleting SMS #")); Serial.println(smsn);
        if (fona.deleteSMS(smsn)) {
          Serial.println(F("OK!"));
        } else {
          Serial.println(F("Couldn't delete"));
        }
        break;
      }

    case 's': {
        // send an SMS!
        char sendto[21], message[141];
        flushSerial();
        Serial.print(F("Send to #"));
        readline(sendto, 20);
        Serial.println(sendto);
        Serial.print(F("Type out one-line message (140 char): "));
        readline(message, 140);
        Serial.println(message);
        if (!fona.sendSMS(sendto, message)) {
          Serial.println(F("Failed"));
        } else {
          Serial.println(F("Sent!"));
        }

        break;
      }
       default: {
        Serial.println(F("Unknown command"));
        printMenu();
        break;
      }
      

  }
  // flush input
  flushSerial();
  while (fona.available()) {
    Serial.write(fona.read());
  }
  
}

void flushSerial() {
  while (Serial.available())
    Serial.read();
}

char readBlocking() {
  while (!Serial.available());
  return Serial.read();
}
uint16_t readnumber() {
  uint16_t x = 0;
  char c;
  while (! isdigit(c = readBlocking())) {
    //Serial.print(c);
  }
  Serial.print(c);
  x = c - '0';
  while (isdigit(c = readBlocking())) {
    Serial.print(c);
    x *= 10;
    x += c - '0';
  }
  return x;
}

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout) {
  uint16_t buffidx = 0;
  boolean timeoutvalid = true;
  if (timeout == 0) timeoutvalid = false;

  while (true) {
    if (buffidx > maxbuff) {
      //Serial.println(F("SPACE"));
      break;
    }

    while (Serial.available()) {
      char c =  Serial.read();

      //Serial.print(c, HEX); Serial.print("#"); Serial.println(c);

      if (c == '\r') continue;
      if (c == 0xA) {
        if (buffidx == 0)   // the first 0x0A is ignored
          continue;

        timeout = 0;         // the second 0x0A is the end of the line
        timeoutvalid = true;
        break;
      }
      buff[buffidx] = c;
      buffidx++;
    }

    if (timeoutvalid && timeout == 0) {
      //Serial.println(F("TIMEOUT"));
      break;
    }
    delay(1);
  }
  buff[buffidx] = 0;  // null term
  return buffidx;
}

