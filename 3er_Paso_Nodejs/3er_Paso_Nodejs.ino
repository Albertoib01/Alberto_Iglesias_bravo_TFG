#include <WiFi.h>
#include <ESP32Servo.h>


Servo miMenique;
Servo miAnular;
Servo miMedio;
Servo miIndice;
Servo miPulgar;


static const int anular26 = 26;
static const int menique27 = 27;
static const int medio25 = 25;
static const int indice33 = 33;
static const int pulgar32 = 32;


const char* ssid = "ssid_router";
const char* password = "contraseña";


WiFiServer server(80);
String header; 

void setup() {
  Serial.begin(115200);

  
  miMenique.attach(menique27);
  miAnular.attach(anular26);
  miMedio.attach(medio25);
  miIndice.attach(indice33);
  miPulgar.attach(pulgar32);


  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}


void mano_cerrada() {
  miMenique.write(0);
  miAnular.write(0);
  miMedio.write(20);
  miIndice.write(20);
  miPulgar.write(20);
  delay(3000);
}

void mano_abierta() {
  miMenique.write(20);
  miAnular.write(20);
  miMedio.write(0);
  miIndice.write(0);
  miPulgar.write(0);
  delay(3000);
}

void dedo_1a1() {
  miMenique.write(20);
  delay(1000);
  miAnular.write(20);
  delay(1000);
  miMedio.write(0);
  delay(1000);
  miIndice.write(0);
  delay(1000);
  miPulgar.write(0);
  delay(2000);

  miMenique.write(0);
  delay(1000);
  miAnular.write(0);
  delay(1000);
  miMedio.write(20);
  delay(1000);
  miIndice.write(20);
  delay(1000);
  miPulgar.write(20);
  delay(3000);
}

void loop() {
  WiFiClient client = server.available(); 

  if (client) {
    Serial.println("Nuevo cliente conectado.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;

        if (c == '\n') {
          if (currentLine.length() == 0) {
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
        

           
            if (header.indexOf("GET /mano_cerrada") >= 0) {
              mano_cerrada();
              Serial.println("Ejecutando: Mano Cerrada");
            } else if (header.indexOf("GET /mano_abierta") >= 0) {
              mano_abierta();
              Serial.println("Ejecutando: Mano Abierta");
            } else if (header.indexOf("GET /dedo_1a1") >= 0) {
              dedo_1a1();
              Serial.println("Ejecutando: Mover Dedo 1 a 1");
            }

            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
