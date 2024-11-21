# Week 7

- [Leetcode](#leetcode)
- [Haskell](#haskell)
- [Engineering Challenges (ESP32 \<-\> Nucleo Connection via I2C)](#engineering-challenges-esp32---nucleo-connection-via-i2c)

## Leetcode

- [Determine if Two Strings Are Close (Medium)](https://leetcode.com/problems/determine-if-two-strings-are-close/) 
  - [Python Solution](leetcode_sols/leetcode_1_sol.py)

## Haskell

- typeclasses
  
  - `Eq` - equality (must define == and /=)
  
  - `Ord` - ordering (must define <, <=, >, >=)
  
  - `Num` - numbers (providing +, -, *, /, etc.)
  
  - `Integral` - subclass of num for Int/Integer
  
  - `Fractional` - subclass of num for Float/Double
  
  - `Show` - allows converting to a human-readable String
  
  - `Read` - allows converting a String back into another type
  
  - `Enum` - sequentially ordered types that can be enumerated
  
  - `Bounded` - has an upper and lower bound
  
  - there are more but we don't need to go over them right now (honestly, just the first 5 here are enough)

- lambda functions

  - `\var1 var2 ... -> function`

  - e.g. `\x y -> x + y`

- partially applied functions

- cons (`:`) vs append (`++`)

- `map` - `map f xs`

- `filter` - `filter f xs`

  - this is filter true i.e. `filter (>5) (take 10 [1..])` results in `[6,7,8,9,10]`

- `fold`

  - `foldl` - `foldl f acc xs` means append acc to the beginning of xs and apply the operation f from left to right

    - e.g. `foldl (/) 4 [1,2,4]` =>

    - 4 : (1 : (2 : (4 : []))) =>

    - (((4 / 1) / 2) / 4) =>

    - ((4 / 2) / 4) =>

    - 2 / 4 =>

    - 0.5

  - `foldr` - `foldr f acc xs` means append acc to the end of xs and apply the operation f from right to left

    - e.g. `foldr (/) 2 [8,12,24,4]` =>

    - 8 : (12 : (24 : (4 : 2))) =>

    - 8 / (12 / (24 / (4 / 2))) =>

    - 8 / (12 / (24 / 2)) =>

    - 8 / (12 / 12) =>

    - 8 / 1 =>

    - 8.0

  - `foldl1` / `foldr1` - no `acc`

## Engineering Challenges (ESP32 <-> Nucleo Connection via I2C)

- internet connection:

  - `"esp_wpa2.h` - for eduroam

  - `<WiFi.h>` - for other networks e.g. cellular 
  - hotspot
  
  - we found it easier to code the hotspot version (although this was sometimes a bit sensitive - ensure you have "maximize compatibility" enabled for iOS devices)

- ESP32 <-> nucleo connection:
  
  - `<Wire.h>`
  
  - ESP32 side:
  
    - before setup:

        ```c++
        #define I2C_SDA 21
        #define I2C_SCL 22
        
        // assuming nucleo is slave and ESP32 is master
        #define SLAVE_ADDR 12
        #define MASTER_ADDR 11
        ```

    - setup:

        ```c++
        Serial.begin(9600);
        Wire.begin(I2C_SDA, I2C_SCL);
        ```

    - request `x` bytes from nucleo:

        ```c++
        Wire.requestFrom(SLAVE_ADDR, x);
        ```

    - read `x` bytes sent from nucleo: <a id="read-x-bytes"></a>

        ```c++
        while (Wire.available()) {
            // read a character from the I2C buffer
            char c = Wire.read();
            // do what you need to with the character
        }
        ```

    - send `x` bytes to nucleo:

        ```c++
        Wire.beginTransmission(SLAVE_ADDR);
        for (int i = 0; i < x; i++) {
            Wire.write(c); // replace c with a single byte of data
        }
        Wire.endTransmission();
        ```

  - nucleo side:
    - before setup:

        ```c++
        #define SLAVE_ADDR 12
        #define MASTER_ADDR 11
        ```

    - setup:

        ```c++
        // join I2C bus with slave address
        Wire.begin(SLAVE_ADDR);
        Wire.onRequest(requestEvent);
        Wire.onReceive(receiveEvent);
        Serial.begin(9600);
        ```

      - define the functions `void requestEvent() {}` and `void receiveEvent() {}` somewhere outside `setup()`

    - `requestEvent()` - i.e. send `x` bytes to ESP32:

        ```c++
        Wire.write(c); // replace c with a single byte of data
        ```

      - this should probably be put in a for loop for `x` amount of times - i.e. however many bytes were requested by the ESP32

    - `receiveEvent()` - i.e. read `x` bytes sent from ESP32:
      - same as [read `x` bytes sent from nucleo](#read-x-bytes)

- ESP32 <-> ThingsBoard connection:
  
  - `<ThingsBoard.h>`
  
  - I'll cover this in more detail next time

<!-- ## Sketches

For the diagrams drawn during the session, refer to [this pdf](sketches.pdf). -->
