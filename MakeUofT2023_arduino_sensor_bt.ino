// define pin numbers
const int trigPin = 9;
const int echoPin = 10;

// define variables
long duration;
int distance;
int avg;
int i = 0;
int sum = 0;
int saved_vals[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void setup() {
  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  // Start the serial communication
  Serial.begin(9600); 
}

void loop() {
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculate distance
  distance = duration * 0.034 / 2;
  // Limit region to 1 < distance < 200
  if(distance < 1){
    distance = 1;
  }
  else if (distance > 200){
    distance = 200;
  }
  sum = 0;
  // Make an array to keep track and calculate mean
  for (int x = 0; x < 10; x++){
    sum+=saved_vals[x];
  }
  // Calculate average of distance to reduce outliers
  avg = round(sum / 10);
  if((avg*0.8 < distance) && (distance < avg*1.2)){
    //Serial.print("Distance avg: ");
    Serial.println(distance);
  }
  // Print the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);
  saved_vals[i] = distance;
  // Modify index to be iterative from range 0-9
  if (i < 9){
    i++;
  }
  else{
    i = 0;
  }
  delay(30);
}