

#define IN1 26
#define IN2 27
#define ENA 14

#define PWM_CHANNEL 0
#define PWM_FREQ 1000
#define PWM_RESOLUTION 8 // 0-255

void main_l293d_setup() {
  client.publish(topic_motor, "run motor 1");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // PWM cho ENA (điều chỉnh tốc độ)
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(ENA, PWM_CHANNEL);

  // Ban đầu motor dừng
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  ledcWrite(PWM_CHANNEL, 0);
}

void main_l293d_loop() {
  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);
  // ledcWrite(PWM_CHANNEL, 100); // tốc độ ~78%
  

}

void moveForward() {

  // motor.setSpeed(wheelSpeed); 
  // motor1.setSpeed(wheelSpeed); 
  // motor2.setSpeed(wheelSpeed); 
  // motor3.setSpeed(wheelSpeed);
  // motor1.run(FORWARD);
  // motor.run(FORWARD); 
  // motor3.run(FORWARD);
  // motor2.run(FORWARD);
  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);
}


