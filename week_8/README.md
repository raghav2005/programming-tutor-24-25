# Week 8

- [Leetcode](#leetcode)
- [Haskell](#haskell)
- [Engineering Challenges (ESP32 \<-\> ThingsBoard)](#engineering-challenges-esp32---thingsboard)

## Leetcode

- [Leaf-Similar Trees (Easy)](https://leetcode.com/problems/leaf-similar-trees/)
  - [Python Solution](leetcode_sols/leetcode_1_sol.py)
- [Longest ZigZag Path in a Binary Tree (Medium)](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)
  - [Python Solution](leetcode_sols/leetcode_2_sol.py)

## Haskell

- binary trees
- tree traversals
  - pre-order
  - in-order
  - post-order
- insert
- search
- height
- count nodes
- is balanced
- list to tree
- mirror
- map tree

refer to [tree_def.hs](tree_def.hs) for the implementation of these functions.

## Engineering Challenges (ESP32 <-> ThingsBoard)

- initialisation:

  - `<ThingsBoard.h>` - to be able to connect to ThingsBoard

  - `<WiFi.h>` - to be able to connect to the WiFi

  - a `personal access token` (to be generated from within ThingsBoard)

  - at the beginning of the file:

    ```c++
    // the below code assumes you're using a personal hotspot / other network connection with no separate login system required e.g. a redirect to a webpage (will not work for eduroam)

    // helper macro to calculate array size
    #define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

    #define WIFI_AP_NAME "wifi-name" // replace wifi-name with the WiFi SSID
    #define WIFI_PASSWORD "wifi-password" // replace wifi-password with the WiFi's password

    #define TOKEN "token" // replace token with the token generated from the above step
    #define THINGSBOARD_SERVER "thingsboard.cloud"

    WiFiClient espClient;
    ThingsBoard tb(espClient); // initialise ThingsBoard instance

    int updateDelay = 1000; // initial update delay - 1000ms
    bool subscribed = false;
    String to_send = ""; // initialised string for message to send
    ```

- setup:

  - WiFi:

    ```c++
    Serial.println("Connecting to AP ...");

    WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected to AP");
    ```

  - RPC:

    ```c++
    if (!subscribed) {
        // perform a subscription. All consequent data processing will happen in callbacks as denoted by callbacks[] array.
        if (!tb.RPC_Subscribe(callbacks, COUNT_OF(callbacks))) {
        Serial.println("Failed to subscribe for RPC");
        // return;
        }

        subscribed = true;
    }
    ```

  - ThingsBoard:

    ```c++
    if (!tb.connected()) {
        subscribed = false;
        
        if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
            Serial.println("Failed to connect");
        }
    }
    ```

- RPC (Remote Procedure Calls):

  - RPC handlers:

    ```c++
    RPC_Callback callbacks[] = {
    { "getpHValue", get_pH},
    { "setpHValue", set_pH},
    { "getTempValue", get_Temp},
    { "setTempValue", set_Temp},
    { "getRPMValue", get_RPM},
    { "setRPMValue", set_RPM},
    };
    ```

    - in the code above, the string value is what should be entered in ThingsBoard for the relevant view/controller, and the other/second value is the name of a function in your code which will be called when that the relevant ThingsBoard view/controller is updated.

  - RPC getter code example (temperature):

    ```c++
    // don't worry about what this code does - you just need it to handle the getTemp message which may come from ThingsBoard

    // processes function for RPC call "getTempValue"
    // RPC_Data is a JSON variant, that can be queried using operator[]
    // see https://arduinojson.org/v5/api/jsonvariant/subscript/ for more details
    RPC_Response get_Temp(const RPC_Data &data) {
    Serial.println("get Temp");

    return RPC_Response(NULL, updateDelay);
    }
    ```

  - RPC setter code example (temperature):

    ```c++
    // this code is for when ThingsBoard / the user is telling the ESP32 to set/change the value of an actuator

    // processes function for RPC call "setValue"
    // RPC_Data is a JSON variant, that can be queried using operator[]
    // see https://arduinojson.org/v5/api/jsonvariant/subscript/ for more details
    RPC_Response set_Temp(const RPC_Data &data) {
    Serial.print("Set Temp: ");
    Serial.print(data);

    // process data as you need to and put it into the to_send string to be sent to the Nucleo
    // replace the line below which whatever you need - remember that data will be an int/float and you need to send a String
    to_send = "";

    return RPC_Response(NULL, data);
    }
    ```

- ESP32 -> ThingsBoard:

  - to send something to ThingsBoard from the ESP32 (temperature example):

    ```c++
    // to send a float
    tb.sendTelemetryFloat("temperature", val_temperature); // replace val_temperature with the value to send, and the temperature string should be set as the receiving end in ThingsBoard

    // to send an int
    tb.sendTelemetryInt("temperature", val_temperature);
    ```

    - you should constantly be sending sensor data to ThingsBoard, so the code above should go somewhere into you main `loop()`.

  - right at the end of the main `loop()`, you must have the following line of code:

    ```c++
    tb.loop(); // process messages
    ```

- auxiliary requirements in main loop (towards the end):

    ```c++
    // reconnect to WiFi if needed
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.begin(WIFI_AP_NAME, WIFI_PASSWORD);
        
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        
        Serial.println("Connected to AP");
        return;
    }

    // reconnect to ThingsBoard if needed
    if (!tb.connected()) {
        subscribed = false;

        if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
            Serial.println("Failed to connect");
        }
    }

    // resubscribe for RPC if needed
    if (!subscribed) {
        if (!tb.RPC_Subscribe(callbacks, COUNT_OF(callbacks))) {
            Serial.println("Failed to subscribe for RPC");
        }

        subscribed = true;
    }
    ```

<!-- ## Sketches

For the diagrams drawn during the session, refer to [this pdf](sketches.pdf). -->
