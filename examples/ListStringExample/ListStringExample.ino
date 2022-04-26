#include <List.h>

#include <Streaming.h>

// Define object to hold list of pointers to String objectss.
List<String*> stringList;

unsigned long count = 0;

void setup() {
  // Setup serial port for output.
  Serial.begin(115200);
  // We will generate 15 String objects.
  const int num = 15;
  // Start with zeroth power of 2 = 1.
  unsigned int pwr = 1;
  // Define separator String objects.
  String sep1 = String("[");
  String sep2 = String("] ");
  // Create Strings and add them to List.
  for (int i = 0; i < num; ++i) {
    // Create String of power of 2.
    String* str = new String(sep1 + String(pwr) + sep2);
    // Add the current String to the end of the List.
    stringList.add(str);
    // Compute the next power of 2.
    pwr *= 2;
  }
}

void loop() {
  // Increment line count.
  Serial << ++count << ": ";
  // Rewind to the beginning of the list.
  stringList.rewind();
  // While there's a next entry in the list...
  while (stringList.hasNext()) {
    // Fetch entry and print it.
    // This also steps to the next entry.
    Serial << *stringList.next();
  }
  // Done, write end of line.
  // Output will be series of numbered lines like:
  // [1] [2] [4] [8] [16] [32] [64] [128] [256] [512] [1024] [2048] [4096] [8192] [16384]
  Serial << endl;
  delay(100);
}
