1.Download and Install Arduino IDE 1.6.9 from http://www.filehorse.com/download-arduino/25855.

2.Testing of Arduino UNO
	->Connect Arduino UNO with laptop using USB cable.
	->Open Arduino IDE.Goto File->Example->Basic->Blink
	->If LED of Arduino is blinked then Arduino is working properly.

3.Connect the circuit on breadboard according to pin diagram of IC. 	

4.Mount Arduino GSM shield(SIM900) on arduino UNO.

5.Connect all enable pins of IC to digital pins(5-10) of Arduino GSM shield.

6.Connect USB Jack to laptop using USB cable

7.Add Adafruit_FONA library in Arduino IDE
	->Download Adafruit_FONA Library from https://learn.adafruit.com/adafruit-fona-mini-gsm-gprs-cellular-phone-module/arduino-test.

8.Upload Arduino code in Arduino IDE

9.Open Serial monitor to run the code.

10.press 'r' to read the message.It will automatically turn on vibrating modules.