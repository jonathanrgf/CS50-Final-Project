//Jonathan R. Gonzalez
// castle automation project for CS50

 #include <SPI.h>
 #include <Ethernet.h>

 #include <Servo.h>
 Servo servo; // create servo object to control a servo

 byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //physical mac address
 byte ip[] = { 10, 0, 0, 177 }; // fixed IP addr in LAN
 byte gateway[] = { 10, 0, 0, 1 }; // internet access via router
 byte subnet[] = { 255, 255, 255, 0 }; //subnet mask
 EthernetServer server(80); //server port

 String readString;
 //////////////////////
 void setup()
 {
     pinMode(2, OUTPUT); //pin selected to control LED
     pinMode(3, OUTPUT); //pin selected to control LED
     pinMode(4, OUTPUT); //pin selected to control LED
     pinMode(5, OUTPUT); //pin selected to control LED
     pinMode(6, OUTPUT); //pin selected to control LED
     servo.attach(7);
     //start Ethernet
     Ethernet.begin(mac, ip, gateway, subnet);
     server.begin();
     //the pin for the servo co
     //enable serial data print
     Serial.begin(9600);
     Serial.println("server Castle LED test 5.0"); // so I can keep track
 }

 void loop()
 {
     // Create a client connection
     EthernetClient client = server.available();
     if (client)
     {
         while (client.connected())
         {
             if (client.available()) 
             {
                 char c = client.read();

                 //read char by char HTTP request
                 if (readString.length() < 100) 
                 {

                     //store characters to string
                      readString += c;
                     //Serial.print(c);
                 }

             //if HTTP request has ended
             if (c == '\n') 
             {
 
                 /* redirect user back to homa/castle page */
                 Serial.println(readString); //print to serial monitor for debuging
                 client.println("HTTP/1.1 200 OK"); //send new page
                 client.println("Content-Type: text/html");
                 client.println();     
                 client.println("<HTML>");
                 client.println("<HEAD>");
                 client.println("<meta http-equiv='refresh' content='0; url=http://10.0.0.23/' />  ");
                 client.println("</HEAD>");
                 client.println("<BODY>");
                 client.println("<H1>SENT</H1>");
                 client.println("<table>");
                 client.println("<tr><td>light1</td><td>");
                 client.println(digitalRead(2));
                 client.println("</td></tr>"); 
                 client.println("<tr><td>light2</td><td>");
                 client.println(digitalRead(3));
                 client.println("</td></tr>"); 
                 client.println("<tr><td>light3</td><td>");
                 client.println(digitalRead(4));
                 client.println("</td></tr>"); 
                 client.println("<tr><td>light4</td><td>");
                 client.println(digitalRead(5));
                 client.println("</td></tr>"); 
                 client.println("<tr><td>light5</td><td>");
                 client.println(digitalRead(6));
                 client.println("</td></tr>"); 
                 client.println("</table>");
                 
                 client.println("</BODY>");
                 client.println("</HTML>");


                 delay(1);
                 //stopping client
                 client.stop();


                 /* control arduino pin 2 to 7 */
                 int curr_state;
                 // LED1
                 if(readString.indexOf("?light1") >0)
                 {
                     curr_state = digitalRead(2); //set current state to state of led       
                    
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 2 state is");
                     Serial.println(curr_state);    
                     
                     // check if LED is OFF
                     if(curr_state == LOW) 
                     {
                         // Set pin to HIGH (turn pin on)
                         digitalWrite(2, HIGH);   // set pin 2 to HIGH(LED1)               
                         Serial.println("LED On"); 
                     }
                     
                     // chekc if LED is ON
                     if(curr_state == HIGH) // check if LED is ON
                     {
                         // Set pin to LOW (turn pin off)
                         digitalWrite(2, LOW); // set pin 2 to LOW (LED 1)
                         Serial.println("LED Off");
                     }
                 }
                 
                 // LED2
                 if(readString.indexOf("?light2") >0)
                 {
                     curr_state = digitalRead(3); //set current state to state of led       
                    
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 3 state is");
                     Serial.println(curr_state);    
                     
                     // check if LED is OFF
                     if(curr_state == LOW) 
                     {
                         // Set pin to HIGH (turn pin on)
                         digitalWrite(3, HIGH); //set pin 3 to HIGH (LED 2)                  
                         Serial.println("LED On"); 
                     }
                     
                     // chekc if LED is ON
                     if(curr_state == HIGH) // check if LED is ON
                     {
                         // Set pin to LOW (turn pin off)
                         digitalWrite(3, LOW); // set pin 3 to LOW (LED 2)
                         Serial.println("LED Off");
                     }
                 }
                 
                 // LED3
                 if(readString.indexOf("?light3") >0)
                 {
                     curr_state = digitalRead(4); //set current state to state of led       
                    
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 3 state is");
                     Serial.println(curr_state);    
                     
                     // check if LED is OFF
                     if(curr_state == LOW) 
                     {
                         // Set pin to HIGH (turn pin on)
                         digitalWrite(4, HIGH); // set pin 4 to HIGH (LED 3)                  
                         Serial.println("LED On"); 
                     }
                     
                     // chekc if LED is ON
                     if(curr_state == HIGH) // check if LED is ON
                     {
                         // Set pin to LOW (turn pin off)
                         digitalWrite(4, LOW); // set pin 4 to LOW (LED 3)
                         Serial.println("LED Off");
                     }
                 }
                 
                 // LED4
                 if(readString.indexOf("?light4") >0)
                 {
                     curr_state = digitalRead(5); //set current state to state of led       
                    
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 4 state is");
                     Serial.println(curr_state);    
                     
                     // check if LED is OFF
                     if(curr_state == LOW) 
                     {
                         // Set pin to HIGH (turn pin on)
                         digitalWrite(5, HIGH); // set pin 5 to HIGH (LED 4)                  
                         Serial.println("LED On"); 
                     }
                     
                     // chekc if LED is ON
                     if(curr_state == HIGH) // check if LED is ON
                     {
                         // Set pin to LOW (turn pin off)
                         digitalWrite(5, LOW); // set pin 5 to LOW (LED 4)
                         Serial.println("LED Off");
                     }
                 }
                 
                 // FRONT DOOR AND MAIN ROOM LED
                 // LED 5 will turn ON when door opens(servo opens) and OFF when door closes                              
                 int pos = 0;
                 if (readString.indexOf("?dooropen") >0)
                 {
                     for(pos = 0; pos < 180; pos += 3)  // goes from 0 degrees to 180 degrees 
                     {                                  // in steps of 1 degree 
                      servo.write(pos);              // tell servo to go to position in variable 'pos' 
                      delay(30);                       // waits 30ms for the servo to reach the position 
                     } 
                   
                     curr_state = digitalRead(6); //set current state to state of led                         
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 5 state is");
                     Serial.println(curr_state);    
                     
                     // check if LED is OFF
                     if(curr_state == LOW) 
                     {
                         // Set pin to HIGH (turn pin on)
                         digitalWrite(6, HIGH); // set pin 6 to HIGH (LED 5)                  
                         Serial.println("LED On"); 
                     }
                 }
                 if (readString.indexOf("?doorclose") >0)
                 {
                     for(pos = 180; pos>=1; pos-=3)     // goes from 180 degrees to 0 degrees 
                     {                                
                     servo.write(pos);              // tell servo to go to position in variable 'pos' 
                     delay(15);                       // waits 15ms for the servo to reach the position 
                     } 
                     
                     curr_state = digitalRead(6); //set current state to state of led  
                     // print current LED state to serial monitor for debuging
                     Serial.println("LED pin 5 state is");
                     Serial.println(curr_state);    
                     
                     // chekc if LED is ON
                     if(curr_state == HIGH) // check if LED is ON
                     {
                         // Set pin to LOW (turn pin off)
                         digitalWrite(6, LOW); // set pin 6 to LOW (LED 5)
                         Serial.println("LED Off");
                     }
                 }
                 
                 if (readString.indexOf("?partymode") >0)
                 {
                      // blink led 10 times
                      for(int i = 0; i < 20; i++)
                      {
                          digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
                          delay(50);
                          digitalWrite(3, HIGH);
                          delay(75);
                          digitalWrite(4, HIGH);
                          delay(25);
                          digitalWrite(5, HIGH);
                          delay(10);
                          digitalWrite(6, HIGH);   
                          delay(5);               // wait for a second
                          digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
                          delay(50);
                          digitalWrite(3, LOW);
                          delay(75);
                          digitalWrite(4, LOW);
                          delay(25);
                          digitalWrite(5, LOW);
                          delay(10);
                          digitalWrite(6, LOW);
                          delay(5);
                      }                        
                 }
               readString=""; //clearing string for next read

             }
           }
         }
     }
 } 
