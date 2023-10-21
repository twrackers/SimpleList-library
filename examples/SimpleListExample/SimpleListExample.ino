#include <SimpleList.h>

#include <Streaming.h>

// Define object to hold list of powers of 2.
SimpleList<unsigned int> powersOf2;

unsigned long count = 0;

void setup() {
  
  // Setup serial port for output.
  Serial.begin(115200);
  while (!Serial) {}

  // Test hasNext() method on empty list.
  if (powersOf2.hasNext() == NULL) {
    Serial << "empty list hasNext() PASS" << endl;
  } else {
    Serial << "empty list hasNext() FAIL" << endl;
  }
  
  // We will generate 15 values, the 0th to 14th powers of 2.
  const int num = 15;
  // Start with zeroth power of 2 = 1.
  unsigned int pwr = 1;
  // Iterate.
  for (int i = 0; i < num; ++i) {
    // Add the current power of 2 to the end of the list.
    powersOf2.add(pwr);
    // Compute the next one.
    pwr *= 2;
  }

  // Test access to list using current() method.
  powersOf2.rewind();
  int index = 0;
  while (powersOf2.hasNext()) {
    Serial << _WIDTH(index++, 2) << ": " << powersOf2.current() << endl;
    powersOf2.next();    // NOW skip to next item
  }
  
}

void loop() {
  
  // Increment line count.
  Serial << ++count << ":";
  
  // Rewind to the beginning of the list.
  powersOf2.rewind();
  
  // While there's a next entry in the list...
  while (powersOf2.hasNext()) {
    
    // Fetch entry and print it.
    // This also steps to the next entry.
    Serial << " " << powersOf2.next();
    
  }
  
  // Done, write end of line.
  // Output will be series of lines like:
  // 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384
  Serial << endl;
  
  delay(100);
  
}
