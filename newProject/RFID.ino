void config_RFID() {
  Serial2.begin(9600);
  delay(1000);
  Serial.println("INIT DONE");
  //addUser("004673EA");
}

void addUser(String nameUser, String chipNum) {
  users[users_size].nameUser = nameUser;
  users[users_size].chipNum = chipNum;
  users_size++;
}
void read_RFID() {

  int ssvalue;
  bool call_extract_tag;

  if (Serial2.available() > 0) {

    call_extract_tag = false;

    ssvalue = Serial2.read();

    if (ssvalue == -1) {
      Serial.println("Return : got -1");
      return;
    }

    if (ssvalue == 2) {
      buffer_index = 0;
      Serial.println("Buffer index is 0 : got 2");
    }


    if (ssvalue == 3) {         // tag has been fully transmitted
      call_extract_tag = true;  //extract tag at the end of the function call
      Serial.println("tag has been fully transmitted");
    }


    if (buffer_index >= BUFFER_SIZE) {
      Serial.println("Error: Buffer overflow detected");
      return;
    }

    buffer[buffer_index++] = ssvalue;  //everything is allrigh => copy current value to buffer

    if (call_extract_tag == true) {

      if (buffer_index == BUFFER_SIZE) {
        String name = extract_tag();
        String print_str;
        if (name == "") {
          print_str = "You can't enter our home ";
          is_register = false;
        } else {
          print_str = "welcome " + name;
          is_register = true;
        }
        print_OLED(print_str);

      }

      else {  //something is wrong... start again loccking for preamble  (value 2)
        buffer_index = 0;
        return;
      }
    }
  }
}

String extract_tag() {

  uint8_t msg_head = buffer[0];
  uint8_t *msg_data = buffer + 1;
  uint8_t *msg_data_version = msg_data;
  uint8_t *msg_data_tag = msg_data + 2;
  uint8_t *msg_checksum = buffer + 11;
  uint8_t msg_tail = buffer[13];
  Serial.println("- - - - - - ");

  Serial.print("Message Head: ");
  Serial.println(msg_head);

  Serial.print("Message Data (HEX): ");

  // msg_data
  Serial.print("[DATA] ");

  for (int i = 0; i < DATA_SIZE; i++)
    Serial.print(char(msg_data[i]));

  Serial.println("");


  // msg_data_version
  Serial.print("[version] ");

  for (int i = 0; i < DATA_VERSION_SIZE; i++)
    Serial.print(char(msg_data_version[i]));

  Serial.println("");


  // msg_data_tag
  Serial.print("[DATA Tag] ");
  chipID = "";
  for (int i = 0; i < DATA_TAG_SIZE; i++) {
    Serial.print(char(msg_data_tag[i]));
    chipID += char(msg_data_tag[i]);  //build num
  }


  Serial.println("");


  // msg_checksum
  Serial.print("[CheckSum] ");

  for (int i = 0; i < CHECKSUM_SIZE; i++)
    Serial.print(char(msg_checksum[i]));

  Serial.println(" ");


  // Message Tail
  Serial.print("Message Tail: ");
  Serial.println(msg_tail);



  for (byte i = 0; i < users_size; i++) {
    if (users[i].chipNum.indexOf(chipID) != -1)
      return users[i].nameUser;
  }
  return "";
}
