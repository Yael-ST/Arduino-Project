  void config_gas() {
    pinMode(MQ2, INPUT);  // MQ2 gas sensor as input
  }
  void read_gas() {
    val = analogRead(MQ2);  // Read the voltage value of A0 port and assign it to val
    if (val > 240)
      return true;
    else
      return false;
  }
