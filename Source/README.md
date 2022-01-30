# Capnograph

This folder contains the source-code for the microcontroller.

## Setup
- Install or open VSCode
- Install [PlatformIO](https://platformio.org/)
- Try connecting a **ESP32**. If it is not recognised, install the appropiate "USB to TTL" driver
    - One example is [CP2102](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) bridge. Search drivers for the bridge your board uses.
- Ready. You can now Compile/Deploy/Test


## Coding Standard
```c++
class MyType
{
public:
    float myFloat = 0.f;

protected:
    bool bMyBool = false;


public:
    void MyFunction() {}

private:
    void MyOtherFunction() {}
};
```

- **Types** use UpperCamelCase (*MyType*)
    - **Templated types** start with T (*TMyTemplate*)
- **Variables** use lowerCamelCase (*myVar*)
    - **Booleans** start with b (*bMyVar*)
    - **Native** types are default initialized (`float i = 0.f;`)
- **Brackets** go always on a new line
- **Max line** size is between 80 and 100 chars.

- **Ordering**: Variables first, Functions later.
    - **Exposure** (public/protected/private) is ordered between variables or between functions
