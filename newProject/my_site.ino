
void connectToWifi() {

  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void handleTheRequestPass() {
  String verif, pass;

  request = client.readStringUntil('\r');  // Read the request

  Serial.println(request);

  verif = request.substring(4, 18);
  pass = request.substring(19, 26);

  if (flag_print) {
    if (request.indexOf("/newpage?value") != -1) {

      if (pass.indexOf(passUser) != -1) {
        print_msg = "password greated:) ";
        is_pass_correct = true;
        is_web = true;
      }

      else {
        print_msg = "uncorrect password :(";
        is_pass_correct = false;
        is_web = false;
      }
    }
  }

  else {
    flag_print = 1;
  }
}
void sendResponsePass(WiFiClient client) {

  // Send the HTTP response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  client.println("<!DOCTYPE html>");
  client.println("<html lang=\"en\">");
  client.println("<head>");
  client.println("<meta charset=\"UTF-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width\">");
  client.println("<title>Genies homes</title>");

  //CSS
  client.println("<style>");
  client.println("body {");
  client.println("font-family: 'Roboto', sans-serif");
  client.println("background-color: #f2f2f2");
  client.println("margin: 0;");
  client.println("padding: 0;");
  client.println("}");

  client.println(".container {");
  client.println("max-width: 600px;");
  client.println("margin: 50px auto;");
  client.println("padding: 20px;");
  client.println("background-color: #fff;");
  client.println("border-radius: 10px;");
  client.println("box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);");
  client.println("}");


  client.println(".form-group {");
  client.println("margin-bottom: 20px;");
  client.println("}");


  client.println("label {");
  client.println("display: block;");
  client.println("font-weight: bold;");
  client.println("margin-bottom: 5px;");
  client.println("font-size: 20px;");
  client.println("}");


  client.println("input[type=\"text\"] {");
  client.println("width: 100%;");
  client.println("padding: 10px;");
  client.println("border: 1px solid #ccc;");
  client.println("border-radius: 5px;");
  client.println("box-sizing: border-box;");
  client.println("}");


  client.println(".greeting {");
  client.println("font-size: 15px;");
  client.println("font-weight: bold;");
  client.println("color: #333;");
  client.println("margin-top: 20px;");
  client.println("}");


  client.println(".custom-button {");
  client.println("background-color: darkcyan;");
  client.println("border: none;");
  client.println("color: white;");
  client.println("padding: 15px 32px;");
  client.println("text-align: center;");
  client.println("text-decoration: none;");
  client.println("display: inline-block;");
  client.println("font-size: 16px;");
  client.println("margin: 8px 4px;");
  client.println("cursor: pointer;");
  client.println("border-radius: 10px;");
  client.println(" }");
  client.println("</style>");

  //JS
  client.println("<script>");
  client.println("function getValueAndRedirect() {");

  // Get the value from the text box
  client.println("var textBoxValue = document.getElementById(\"thesis\").value;");

  // Encode the value to handle special characters properly
  client.println("var encodedValue = encodeURIComponent(textBoxValue);");

  // Update the location.href with the value
  client.println("location.href = \" /newpage?value=\" + encodedValue;");
  client.println("}");
  client.println("</script>");

  client.println("</head>");
  client.println("<body>");

  client.println("<div class=\"container\" >");
  client.println("<div class=\"form-group\">");
  client.println("<label for=\"thesis\">Enter Your Password:</label>");
  client.println("<input type=\"text\" id=\"thesis\" name=\"thesis\" placeholder=\"password\">");

  client.println("<button class=\"custom-button\" onclick=\"getValueAndRedirect() \">Send</button>");

  client.println("</div>");
  client.println("<div class=\"form-group\">");


  client.println("<p class=\"greeting\">");
  client.println(print_msg);
  client.println("</p>");

  client.println("</div>");
  client.println("</div>");
  client.println("</body>");
  client.println("</html>");
}

void handleTheRequestMain() {
  // Serial.println("New client connected.");
  // Read the request
  request = client.readStringUntil('\r');

  if (request.indexOf("FAN_ON") != -1) {
    fan_on();
  } else if (request.indexOf("FAN_Off") != -1) {
    fan_off();
  }
  if (request.indexOf("LIGHT_ON") != -1) {
    LEDs_on();
  } else if (request.indexOf("LIGHT_OFF") != -1) {
    LEDs_off();
  }
  if (request.indexOf("OPEN_DOOR") != -1) {
    open_door();
  } else if (request.indexOf("CLOSE_DOOR") != -1) {
    close_door();
  }
  if (request.indexOf("OPEN_WIN") != -1) {
    open_win();
  } else if (request.indexOf("CLOSE_WIN") != -1) {
    close_win();
  }
  if (request.indexOf("ADD_USER") != -1) {
    add_user = true;
  }
  if(request.indexOf("EXIT") != -1){
    is_pass_correct=false;
    is_web=false;
  }
}
void sendResponseMain(WiFiClient client) {
  // Send the HTTP response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  client.println("<!DOCTYPE html>");
  client.println("<html lang=\"en\">");
  client.println("<head>");
  client.println("    <meta charset=\"UTF-8\">");
  client.println("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
  client.println("    <title>Genius Home</title>");
  client.println("    <link rel=\"stylesheet\" href=\"main.css\">");
  client.println("    <script src=\"script1.js\"></script>");
  client.println("    <style>");
  client.println("        body, html {");
  client.println("            margin: 0;");
  client.println("            padding: 0;");
  client.println("            height: 100%;");
  client.println("            font-family: 'Segoe UI Light';");
  client.println("            background-color: '#f0f0f0';");
  client.println("            border-right: 5px solid darkcyan; /* גבול ימין */");
  client.println("        }");
  client.println("");
  client.println("        h3 {");
  client.println("            text-align: center;");
  client.println("            color: darkslategrey;");
  client.println("        }");
  client.println("");
  client.println("        .container {");
  client.println("            text-align: center;");
  client.println("            position: relative;");
  client.println("        }");
  client.println("");
  client.println("        .triangle {");
  client.println("            width: 120px;");
  client.println("            height: 120px;");
  client.println("            z-index: 100; /* Higher z-index to place it above the base element */");
  client.println("            display: block;");
  client.println("            margin: 0 auto;");
  client.println("        }");
  client.println("");
  client.println("        .text {");
  client.println("            font-size: 24px;");
  client.println("            margin: 0; /* Remove default margin */");
  client.println("            padding: 0; /* Remove default padding */");
  client.println("            line-height: 1; /* Adjust line height */");
  client.println("            font-family: \"Broken Kiss\";");
  client.println("            font-size: 35px;");
  client.println("        }");
  client.println("");
  client.println("        .text span {");
  client.println("            display: block;");
  client.println("            font-size: 32px;");
  client.println("            font-weight: bold;");
  client.println("            margin: 0; /* Remove default margin */");
  client.println("            padding: 0; /* Remove default padding */");
  client.println("            line-height: 1; /* Adjust line height */");
  client.println("            font-family: \"Adam\";");
  client.println("        }");
  client.println("");
  client.println("        /* Underline */");
  client.println("        .underline {");
  client.println("            width: 8%;");
  client.println("            margin: 10px auto; /* Center the underline and add some space above */");
  client.println("            border: none;");
  client.println("            height: 5px; /* Height of the underline */");
  client.println("            background-color: darkcyan; /* Color of the underline */");
  client.println("        }");
  client.println("");
  client.println("        /* Button container */");
  client.println("        .button-container {");
  client.println("            display: flex;");
  client.println("            justify-content: center; /* מרכז את האלמנטים במרכז */");
  client.println("            gap: 80px; /* רווח בין האלמנטים */");
  client.println("            margin-top: 20px; /* Adjust margin to space out button containers */");
  client.println("        }");
  client.println("");
  client.println("        /* Button wrapper */");
  client.println("        .button-wrapper {");
  client.println("            text-align: center;");
  client.println("        }");
  client.println("");
  client.println("        /* The switch - the box around the slider */");
  client.println("        .switch {");
  client.println("            display: inline-block;");
  client.println("            position: relative;");
  client.println("            width: 60px;");
  client.println("            height: 34px;");
  client.println("        }");
  client.println("");
  client.println("        /* Hide default HTML checkbox */");
  client.println("        .switch input {");
  client.println("            opacity: 0;");
  client.println("            width: 0;");
  client.println("            height: 0;");
  client.println("        }");
  client.println("");
  client.println("        .top-right-button :hover {");
  client.println("            background-color: #008b8b;");
  client.println("        }");
  client.println("");
  client.println("        button {");
  client.println("            background-color: darkcyan;");
  client.println("            color: white;");
  client.println("            border: none;");
  client.println("            padding: 10px 20px;");
  client.println("            font-size: 14px;");
  client.println("            cursor: pointer;");
  client.println("            border-radius: 5px;");
  client.println("            box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.2);");
  client.println("        }");
  client.println("");
  client.println("        button:hover {");
  client.println("            background-color: cadetblue;");
  client.println("        }");
  client.println("");
  client.println("        .button_off {");
  client.println("            background-color: #f0f0f0;");
  client.println("            color: darkcyan;");
  client.println("            border-color: darkcyan;");
  client.println("        }");
  client.println("");
  client.println("        .button_off:hover {");
  client.println("            background-color: gainsboro;");
  client.println("        }");
  client.println("");
  client.println("    </style>");
  client.println("</head>");
  client.println("<body>");
  client.println("            <button class=\"button_off\" onclick=\"location.href='EXIT'\">sigh out</button>");
  client.println("    <button class=\"add-user\" onclick=\"location.href='ADD_USER'\">להוספת משתמש </button>");
  client.println("");
  client.println("    <div class=\"container\">");
  client.println("        <svg class=\"triangle\" viewBox=\"0 0 150 100\">");
  client.println("            <path d=\"M 75 10");
  client.println("                     A 10 10 0 0 1 85 20");
  client.println("                     L 135 80");
  client.println("                     A 10 10 0 0 1 125 90");
  client.println("                     L 25 90");
  client.println("                     A 10 10 0 0 1 15 80");
  client.println("                     L 65 20");
  client.println("                     A 10 10 0 0 1 75 10");
  client.println("                     Z\"");
  client.println("                  fill=\"darkcyan\" />");
  client.println("        </svg>");
  client.println("        <div class=\"text\">Genius<span>Home</span></div>");
  client.println("        <hr class=\"underline\">");
  client.println("    </div>");
  client.println("");
  client.println("    <br />");
  client.println("    <br />");
  client.println("");
  client.println("    <h3>Remote control</h3>");
  client.println("    <br />");
  client.println("    <div class=\"button-container\">");
  client.println("");
  client.println("        <div class=\"button-wrapper\">");
  client.println("            <button class=\"button_off\" onclick=\"location.href='LIGHT_OFF'\">light off</button>");
  client.println("            <button onclick=\"location.href='LIGHT_ON'\">light on</button>");
  client.println("        </div>");
  client.println("");
  client.println("        <div class=\"button-wrapper\">");
  client.println("            <button class=\"button_off\" onclick=\"location.href='FAN_OFF'\">fan off</button>");
  client.println("            <button onclick=\"location.href='FAN_ON'\">fan on</button>");
  client.println("        </div>");
  client.println("");
  client.println("    </div>");
  client.println("    <div class=\"button-container\">");
  client.println("        <div class=\"button-wrapper\">");
  client.println("            <button class=\"button_off\" onclick=\"location.href='CLOSE_DOOR'\">close door</button>");
  client.println("            <button onclick=\"location.href='OPEN_DOOR'\">open door</button>");
  client.println("        </div>");
  client.println("");
  client.println("        <div class=\"button-wrapper\">");
  client.println("            <button class=\"button_off\" onclick=\"location.href='CLOSE_WIN'\">close window</button>");
  client.println("            <button onclick=\"location.href='OPEN_WIN'\">open window</button>");
  client.println("        </div>");
  client.println("    </div>");
  client.println("</body>");
  client.println("</html>");
}
void handleTheRequestAddUser() {
  read_RFID();

  request = client.readStringUntil('\r');
  String name_to_enter;
  int index = request.indexOf("OK");
  if (index != -1) {
    String value = request.substring(index + 2); 
    byte endIndex = value.indexOf(' ');
    if (endIndex != -1) {
      name_to_enter = value.substring(0, endIndex);  
    }
      addUser(name_to_enter, chipID);
      Serial.println("name is" + name_to_enter);
      Serial.println(chipID);

      add_user = false;
    }
  }
  void sendResponseAddUser(WiFiClient client) {
    client.println("<!DOCTYPE html>");
    client.println("<html lang=\"he\">");
    client.println("<head>");
    client.println("    <meta charset=\"UTF-8\">");
    client.println("    <title>sign up</title>");
    client.println("    <style>");
    client.println("        body, html {");
    client.println("            margin: 0;");
    client.println("            padding: 0;");
    client.println("            height: 100%;");
    client.println("            font-family: 'Segoe UI Light';");
    client.println("            background-color: #f0f0f0;");
    client.println("            border-right: 5px solid darkcyan; /* גבול ימין */");
    client.println("            direction: rtl;");
    client.println("            text-align: center;");
    client.println("        }");
    client.println("");
    client.println("        * {");
    client.println("            box-sizing: border-box;");
    client.println("        }");
    client.println("");
    client.println("        input[type=text], select, textarea {");
    client.println("            width: 20%;");
    client.println("            padding: 12px;");
    client.println("            border: 1px solid #ccc;");
    client.println("            border-radius: 4px;");
    client.println("            box-sizing: border-box;");
    client.println("            margin-top: 6px;");
    client.println("            margin-bottom: 16px;");
    client.println("            resize: vertical;");
    client.println("        }");
    client.println("");
    client.println("        input[type=submit] {");
    client.println("            background-color: darkcyan;");
    client.println("            color: white;");
    client.println("            padding: 12px 20px;");
    client.println("            border: none;");
    client.println("            border-radius: 4px;");
    client.println("            cursor: pointer;");
    client.println("        }");
    client.println("");
    client.println("        input[type=submit]:hover {");
    client.println("            background-color: cadetblue;");
    client.println("        }");
    client.println("");
    client.println("        .container {");
    client.println("            border-radius: 5px;");
    client.println("            background-color: #f2f2f2;");
    client.println("            padding: 20px;");
    client.println("            width: 100%;");
    client.println("        }");
    client.println("");
    client.println("        h3 {");
    client.println("            color: darkcyan;");
    client.println("        }");
    client.println("");
    client.println("        .nameUser {");
    client.println("            padding: 24px;");
    client.println("        }");
    client.println("    </style>");
    client.println("    <script>");
    client.println("        function addUser() {");
    client.println("            var name = document.getElementById('name').value;");
    client.println("            location.href = 'OK' +name ;");
    client.println("            alert('משתמש נוסף בהצלחה!');");
    client.println("            document.getElementById('userForm').reset();");
    client.println("        }");
    client.println("    </script>");
    client.println("</head>");
    client.println("<body>");
    client.println("    <br />");
    client.println("    <br />");
    client.println("    <h3>הוספת משתמש</h3>");
    client.println("");
    client.println("    <div class=\"container\">");
    client.println("        <form onsubmit=\"addUser(); return false;\" id=\"userForm\">");
    client.println("            <label class=\"nameUser\" for=\"name\">שם</label>");
    client.println("            <input type=\"text\" id=\"name\" placeholder=\"\">");
    client.println("            <br />");
    client.println("            <br />");
    client.println("            <h4>הצמד את הצ'יפ החדש לקורא הצ'יפים למשך 5 שניות</h4>");
    client.println("            <br />");
    client.println("            <input type=\"submit\" value=\"הוסף\">");
    client.println("        </form>");
    client.println("    </div>");
    client.println("</body>");
    client.println("</html>");
  }
