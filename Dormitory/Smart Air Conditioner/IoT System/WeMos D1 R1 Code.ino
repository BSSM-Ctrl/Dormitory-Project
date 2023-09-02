#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>
#include <DHT.h>

#define FIREBASE_HOST "" // Firebase 주소
#define FIREBASE_AUTH "" // Firebase 비밀번호
#define WIFI_SSID "bssm_free"
#define WIFI_PASSWORD "bssm_free"
#define DHTTYPE DHT11
#define DHTPIN_A 2
Servo On.OFF_servo;
Servo Mode_servo;
DHT DHT(DHTPIN_A, DHTTYPE);

int servoPin1 = D3;
int servoPin2 = D4;
int Mode = 0;
int On = 0;
float Temperature, Humidity;

void setup()
{
    Serial.begin(115200);
    DHT.begin();
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.setInt("Mode", 0);
    Firebase.setInt("MaxTemperature", 0);
    Firebase.setInt("MinTemperature", 0);
    Firebase.setInt("MaxHumidity", 0);
    Firebase.setInt("MinHumidity", 0);
    On.OFF_servo.attach(servoPin1);
    Mode_servo.attach(servoPin2);
}

void loop()
{

    float Temperature = DHT.readTemperature();
    float Humidity = DHT.readHumidity();

    if (DHT.read(Temperature, Humidity) != 0)
        continue;
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
        if ((On % 2 == 1) && (Temperature < Firebase.getInt("MinTemperature") || Temperature > Firebase.getInt("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Temperature >= Firebase.getInt("MinTemperature") && Temperature <= Firebase.getInt("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
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
        if ((On % 2 == 1) && (Temperature < Firebase.getInt("MinTemperature") || Temperature > Firebase.getInt("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Temperature >= Firebase.getInt("MinTemperature") && Temperature <= Firebase.getInt("MaxTemperature")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
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
        if ((On % 2 == 1) && (Humidity < Firebase.getInt("MinHumidity") || Humidity > Firebase.getInt("MaxHumidity")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            On++;
        }
        else if ((On % 2 == 0) && (Humidity >= Firebase.getInt("MinHumidity") && Humidity <= Firebase.getInt("MaxHumidity")))
        {
            for (int i = 85; i > 25; i--)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            for (int i = 25; i < 85; i++)
            {
                On.OFF_servo.write(i);
                delay(10);
            }
            On++;
        }
    }
    delay(500);
}