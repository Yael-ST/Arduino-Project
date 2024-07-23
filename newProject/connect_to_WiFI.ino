const char* ssid = "HUAWEI_0E07";
const char* password = "benziST6863";

const String passUser = "1111";

bool is_pass_correct = false;
bool add_user = false;

String request, print_msg, print_name = "";

byte flag_print = 0;

WiFiClient client;
WiFiServer server(80);
void config_WiFi() {
  delay(500);
  connectToWifi();
  server.begin();  // Start the server
}
void WiFi2() {
  client = server.available();
  if (client) {
  //  Serial.println("New client connected.");

    if (is_pass_correct && !add_user) {
      handleTheRequestMain();
      sendResponseMain(client);
    }

    else if(!is_pass_correct) {
      handleTheRequestPass();    // Read the request
      sendResponsePass(client);  // Send the response
    }
    if (add_user) {
      handleTheRequestAddUser();    // Read the request
      sendResponseAddUser(client);  // Send the response
    }
    // Disconnect the client
    delay(10);
    client.stop();
 //   Serial.println("Client disconnected.");
   //is_web=false;
  }
}