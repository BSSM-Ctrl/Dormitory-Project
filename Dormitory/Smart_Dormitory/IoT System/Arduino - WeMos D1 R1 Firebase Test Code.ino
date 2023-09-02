#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "bssm_free"
#define WIFI_PASSWORD "bssm_free"
#define DATABASE_URL "iot-dormitory-door-default-rtdb.firebaseio.com"
#define DATABASE_SECRET "wMUmeverLoUTy9QRfZIMVvlEwPLgYjRHnMaiHGTv"
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long dataMillis = 0;
int On_value, Off_value;

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
    config.database_url = DATABASE_URL;
    config.signer.tokens.legacy_token = DATABASE_SECRET;
    Firebase.reconnectWiFi(true);
    Firebase.begin(&config, &auth);
    delay(1000);

    if (Firebase.RTDB.setInt(&fbdo, "On")) == true)
        Serial.println("On set ok");
    if (Firebase.RTDB.setInt(&fbdo, "Off")) == true)
        Serial.println("Off set ok");
}
void loop()
{
    if (millis() - dataMillis > 3000)
    {
        dataMillis = millis();

        if (Firebase.RTDB.getInt(&fbdo, "On") == true)
        {
            String temp = fbdo.to<const char *>();
            On_value = temp.toInt();
            Serial.print("On: ");
            Serial.println(On_value);
        }
        else
            Serial.println(fbdo.errorReason().c_str());

        if (Firebase.RTDB.getInt(&fbdo, "Off") == true)
        {
            String temp = fbdo.to<const char *>();
            Off_value = temp.toInt();
            Serial.print("Off: ");
            Serial.println(Off_value);
        }
        else
            Serial.println(fbdo.errorReason().c_str());
    }
}
