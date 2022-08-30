#include <Adafruit_Fingerprint.h>
#include <ESP8266WiFi.h>;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(D3, D4);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

const char* ssid     = "Dragon ";   //replace with your own SSID
const char* password = "wifi119177";    //replace with your own password
const char* host = "api.pushingbox.com";
int led= D6;


String member = "";
int flag = 0;
void setup()
{


  pinMode(D6,OUTPUT);


  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("WELCOME");
  delay(2000);
  

  lcd.clear();

  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  lcd.setCursor(0, 0);
  Serial.print("Connecting to WiFi...       ");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  lcd.setCursor(0, 0);
  lcd.print("WiFi connected          ");
  lcd.setCursor(0, 1);
  lcd.print("IP:");
  lcd.setCursor(4, 1);
  lcd.print(WiFi.localIP());
  delay(1500);

  while (!Serial);
  delay(100);
  Serial.println("\n\n Waiting for Fingerprint Sensor");
  lcd.setCursor(0, 0);
  lcd.print("    Waiting for           ");
  lcd.setCursor(0, 1);
  lcd.print("      Sensor              ");
  delay(1500);
  finger.begin(57600);

  if (finger.verifyPassword())
  {
    Serial.println("Found Successfully");
    lcd.setCursor(0, 0);
    lcd.print("Sensor found!         ");
    lcd.setCursor(0, 1);
    lcd.print("                      ");
    delay(1500);
    lcd.setCursor(0, 1);
    lcd.print("Place finger     ");
    delay(1500);
  } else
  {
    Serial.println("Fingerprint sensor not found!!!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Not found!         ");
    lcd.setCursor(0, 1);
    lcd.print("                      ");
    while (1)
    {
      delay(1);
    }
  }
}

void loop()
{ 
  int fingerprintID = getFingerprintID();
  delay(50);
  if (fingerprintID >=1 &&  fingerprintID <66)
  {
  if (fingerprintID == 1)
  {
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome ZEEM");
    lcd.setCursor(0, 0);
    lcd.print("Welcome ZEEM         ");
    lcd.setCursor(0, 1);
    lcd.print("ID 1706085           ");
    connecthost("1706085");
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");
    flag=0;
 
  }
  else if (fingerprintID == 2)
  {
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome RABBY");
    lcd.setCursor(0, 0);
    lcd.print("Welcome RABBY         ");
    lcd.setCursor(0, 1);
   lcd.print("ID 1706086             ");
    connecthost("1706086");
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");
    flag = 0;
 
  }
  else if (fingerprintID == 4)
  {

    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome UTSAB");
    lcd.setCursor(0, 0);
    lcd.print("Welcome UTSAB          ");
    lcd.setCursor(0, 1);
    lcd.print("ID 1706084             ");
    connecthost("1706084");
    flag = 0;
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");

    
  }
    else if (fingerprintID == 11)
  {

    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome TAHSIN");
    lcd.setCursor(0, 0);
    lcd.print("Welcome TAHSIN         ");
    lcd.setCursor(0, 1);
    lcd.print("ID 1706095             ");
    connecthost("1706095");
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");
    flag = 0;
    flag = 0;

    
  }

   else if (fingerprintID == 15)
  {

    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome TUSHAR");
    lcd.setCursor(0, 0);
    lcd.print("Welcome TUSHAR         ");
    lcd.setCursor(0, 1);
    lcd.print("ID 1706009             ");
    connecthost("1706009");
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");
    flag = 0;
    flag = 0;
  }
  
  else
  {
    Serial.println("Waiting for valid finger!!!");
    lcd.setCursor(0, 0);
    lcd.print(" Place a Valid       ");
    lcd.setCursor(0, 1);
    lcd.print("     Finger           ");
  }
  }

  else
  {
  if (fingerprintID == 70)
  {
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Welcome ZEEM");
    lcd.setCursor(0, 0);
    lcd.print("Welcome ZEEM         ");
    lcd.setCursor(0, 1);
    lcd.print("ID 1706085           ");
    connecthost("1706085");
    delay(1500);
    lcd.setCursor(0, 0);
    lcd.print("Place another");
    lcd.setCursor(0, 1);
    lcd.print("   finger   ");
    flag = 0;
  
   
  }
  }
  
}

int getFingerprintID()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  return finger.fingerID;
}

void connecthost(String data)
{
int fingerprintID = getFingerprintID();
  delay(50);
  if (fingerprintID >=1 &&  fingerprintID <66)
{
  if (flag == 0)
  {
    member = data;
    flag = 1;
    Serial.print("connecting to ");
    Serial.println(host);
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) 
    {
      Serial.println("connection failed");
      return;
    }

    // We now create a URL for the request
    String url = "/pushingbox?";
    url += "devid=";
    url += "v6E1E5B6D2DC5603";
    url += "&Name=" + String(member);

    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
      Serial.print("Data Sent!");
    }

    Serial.println();
    Serial.println("closing connection");
  }
 }
 else 
 { 
  if (flag == 0)
 
  {
    member = data;
    flag = 1;
    Serial.print("connecting to ");
    Serial.println(host);
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) 
    {
      Serial.println("connection failed");
      return;
    }

    // We now create a URL for the request
    String url = "/pushingbox?";
    url += "devid=";
    url += "vB155E41DAD4EAC4";
    url += "&Name=" + String(member);

    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
      Serial.print("Data Sent!");
    }
  }

    Serial.println();
    Serial.println("closing connection");
  
 }
 
}
