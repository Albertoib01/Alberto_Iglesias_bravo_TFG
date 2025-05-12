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


void moverServo(Servo& servo, int posicion) {
  servo.write(posicion);
  delay(15); 
}

void mostrar_letra(String letra){
  letra.toLowerCase();
  switch(letra[0]){
    case 'a':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(45);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra A");
      break;
    case 'b':
      miMenique.write(20);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra B");
      break;
    case 'c':
      miMenique.write(5);
      miAnular.write(5);
      miMedio.write(15);
      miIndice.write(15);
      miPulgar.write(15);
      delay(3000);
      Serial.println("Letra C");
      break;
    case 'd':
      miMenique.write(20);
      miAnular.write(5);
      miMedio.write(20);
      miIndice.write(20);
      miPulgar.write(20);
      delay(3000);
      Serial.println("Letra D");
      break;
    case 'e':
      miMenique.write(10);
      miAnular.write(10);
      miMedio.write(10);
      miIndice.write(10);
      miPulgar.write(0);
      delay(3000);
      Serial.println("Letra E");
      break;
    case 'f':
      miMenique.write(20);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(45);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra F");
      break;
    case 'g':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra G");
      break;
    case 'h':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(0);
      delay(3000);
      Serial.println("Letra H");
      break;
    case 'i':
      miMenique.write(20);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(45);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra I");
      break;
    case 'j':
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(45);
      miPulgar.write(45);
      miMenique.write(20);
      delay(1000);
      miMenique.write(10);
      delay(1000);
      miMenique.write(20);
      delay(3000);
      Serial.println("Letra J");
      break;
    case 'k':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(20);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra K");
      break;
    case 'l':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(0);
      miPulgar.write(0);
      delay(3000);
      Serial.println("Letra L");
      break;
    case 'm':
      miMenique.write(0);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra M");
      break;
    case 'n':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra N");
      break;
    case 'o':
      miMenique.write(20);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(20);
      miPulgar.write(20);
      delay(3000);
      Serial.println("Letra O");
      break;
    case 'p':
      miMenique.write(0);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra P");
      break;
    case 'q':
      miMenique.write(5);
      miAnular.write(5);
      miMedio.write(15);
      miIndice.write(15);
      miPulgar.write(20);
      delay(3000);
      Serial.println("Letra Q");
      break;
    case 'r':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra R");
      break;
    case 's':
      miMenique.write(20);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(45);
      miPulgar.write(0);
      delay(3000);
      Serial.println("Letra S");
      break;
    case 't':
      miMenique.write(20);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(40);
      miPulgar.write(40);
      delay(3000);
      Serial.println("Letra T");
      break;
    case 'u':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(0);
      miIndice.write(0);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra U");
      break;
    case 'v':
      miMenique.write(0);
      miAnular.write(0);
      miPulgar.write(45);
      miMedio.write(0);
      miIndice.write(0);      
      delay(1000);
      miMedio.write(10);
      miIndice.write(10);      
      delay(1000);
      miMedio.write(0);
      miIndice.write(0);      
      delay(3000);
      Serial.println("Letra V");
      break;
    case 'w':
      miMenique.write(0);
      miAnular.write(20);
      miPulgar.write(45);
      miMedio.write(0);
      miIndice.write(0);      
      delay(1000);
      miAnular.write(10);
      miMedio.write(10);
      miIndice.write(10);      
      delay(1000);
      miAnular.write(20);
      miMedio.write(0);
      miIndice.write(0);      
      delay(3000);
      Serial.println("Letra W");
      break;
    case 'x':
      miMenique.write(0);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(10);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra X");
      break;
    case 'y':
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(45);
      miPulgar.write(45);
      miMenique.write(20);
      delay(1000);
      miMenique.write(10);
      delay(1000);
      miMenique.write(20);
      delay(3000);
      Serial.println("Letra Y");
      break;
    case 'z':
      miMenique.write(20);
      miAnular.write(0);
      miMedio.write(45);
      miIndice.write(45);
      miPulgar.write(45);
      delay(3000);
      Serial.println("Letra Z");
      break;
  }
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
            } else if (header.indexOf("GET /servo") >= 0) {
              
              int servoNum = header.substring(header.indexOf("/servo") + 6, header.indexOf("?")).toInt();
              int pos = header.substring(header.indexOf("pos=") + 4).toInt();

              
              switch (servoNum) {
                case 1:
                  moverServo(miPulgar, pos);
                  client.println("Servo 1 movido a posición " + String(pos));
                  break;
                case 2:
                  moverServo(miIndice, pos);
                  client.println("Servo 2 movido a posición " + String(pos));
                  break;
                case 3:
                  moverServo(miMedio, pos);
                  client.println("Servo 3 movido a posición " + String(pos));
                  break;
                case 4:
                  moverServo(miAnular, pos);
                  client.println("Servo 4 movido a posición " + String(pos));
                  break;
                case 5:
                  moverServo(miMenique, pos);
                  client.println("Servo 5 movido a posición " + String(pos));
                  break;
                default:
                  client.println("Número de servo no válido");
                  break;
              }
              Serial.printf("Servo %d movido a posición %d\n", servoNum, pos);
            } else if (header.indexOf("GET /palabra?texto=") >= 0) {
              int start = header.indexOf("texto=") + 6;
              String palabra = header.substring(start, header.indexOf(" ", start));
              for (int i = 0; i < palabra.length(); i++) {
                mostrar_letra(String(palabra[i])); 
                delay(1000);
              }
              Serial.println("Ejecutando: Deletrear palabra " + palabra);
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
