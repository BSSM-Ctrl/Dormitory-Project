#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID "bssm_free"
#define WIFI_PASSWORD "bssm_free"

#define DHTTYPE DHT11
#define DHTPIN_A 2

//함수
Servo OnServo;
Servo ModeServo;
int OnServoPin = D3;
int ModeServoPin = D4;

DHT DHT(DHTPIN_A, DHTTYPE);

int Mode = 0;
int On = 0;

float Temperature, Humidity;

void setup()
{
  OnServo.attach(OnServoPin);
  ModeServo.attach(ModeServoPin);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("Mode", 0);
  Firebase.setFloat("T-Max", 0);
  Firebase.setFloat("T-Min", 0);
  Firebase.setFloat("H-Max", 0);
  Firebase.setFloat("H-Min", 0);
  Firebase.setFloat("Temperature", 0);
  Firebase.setFloat("Humidity", 0);
}

void loop()
{
  float Temperature = DHT.readTemperature();
    float Humidity = DHT.readHumidity();
    Firebase.setFloat("Temperature", Temperature);
    Firebase.setFloat("Humidity", Humidity);

    // 냉방모드
    if (Firebase.getInt("Mode") == 0)
    {
        while (Mode % 3 != Firebase.getInt("Mode"))
        {
            Mode++;
            for (int i = 85; i > 25; i--)
            {
                Mode_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                Mode_servo.write(i);
                delay(10);
            }
        }
        if ((On % 2 == 1) && (Temperature < Firebase.getFloat("MinTemperature") || Temperature > Firebase.getFloat("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Temperature >= Firebase.getFloat("MinTemperature") && Temperature <= Firebase.getFloat("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
    }
    // 난방모드
    else if (Firebase.getInt("Mode") == 1)
    {
        while (Mode % 3 != Firebase.getInt("Mode"))
        {
            Mode++;
            for (int i = 85; i > 25; i--)
            {
                Mode_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                Mode_servo.write(i);
                delay(10);
            }
        }
        if ((On % 2 == 1) && (Temperature < Firebase.getFloat("MinTemperature") || Temperature > Firebase.getFloat("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Temperature >= Firebase.getFloat("MinTemperature") && Temperature <= Firebase.getFloat("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
    }
    // 제습모드
    else if (Firebase.getInt("Mode") == 2)
    {
        while (Mode % 3 != Firebase.getInt("Mode"))
        {
            Mode++;
            for (int i = 85; i > 25; i--)
            {
                Mode_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                Mode_servo.write(i);
                delay(10);
            }
        }
        if ((On % 2 == 1) && (Humidity < Firebase.getFloat("MinHumidity") || Humidity > Firebase.getFloat("MaxHumidity")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Humidity >= Firebase.getFloat("MinHumidity") && Humidity <= Firebase.getFloat("MaxHumidity")))
        {
            for (int i = 85; i > 25; i--)
            {
                On_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On_servo.write(i);
                delay(10);
            }
            On++;
        }
    }
    delay(500);
}
