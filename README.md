<div id="top"></div>

>This repository contains my work for C++ embedded course at Ynov Campus

<details>
  <summary>Summary</summary>
  <ol>
    <li><a href="#mqtt-with-c">MQTT with C++</a></li>
    <li><a href="#steganography-with-c">Steganography with C++</a></li>
  </ol>
</details>

# MQTT with C++

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#prerequisites">Prerequisites</a></li>
    <li><a href="#how-to-build">How to build</a></li>
    <li><a href="#how-to-launch-program">How to launch program</a></li>
    <li><a href="#result-for-receive-mqtt">Result for receive-mqtt</a></li>
    <li><a href="#result-for-publish-mqtt">Result for publish-mqtt</a></li>
    <li><a href="#publish-message-with-mqtt-x">Publish message with MQTT X</a></li>
  </ol>
</details>

## Prerequisites

- clone the repository : ```git clone https://github.com/DorianFournier/Embedded-cpp```
- go to the root directory : ```cd Embedded-cpp```

<p align="right"><a href="#top">:point_up_2:</a></p>

## How to build
> Same for publish-mqtt or receive-mqtt directory

1. go to publish-mqtt or receive-mqtt directory : ```cd publish-mqtt``` or ```cd receive-mqtt```
2. create **build** directory : ```mkdir build``` 
3. go to **build** directory : ```cd build```
4. run : ```cmake ..```
5. run : ```make```

<p align="right"><a href="#top">:point_up_2:</a></p>

## How to launch program 

1. go to build directory : ```cd build```
2. run : ```./build/receive-mqtt``` or ```./build/publish-mqtt```

<p align="right"><a href="#top">:point_up_2:</a></p>

## Result for receive-mqtt 
<div align="center">
  </br>
  <img src="images/receive-mqtt message test.png" alt="Receive-mqtt test">
  </br></br>
</div>

<p align="right"><a href="#top">:point_up_2:</a></p>

## Result for publish-mqtt
<div align="center">
  </br>
  <img src="images/publish-mqtt-message.png" alt="Receive-mqtt test">
  </br></br>
</div>

<p align="right"><a href="#top">:point_up_2:</a></p>

## Publish message with MQTT X
<div align="center">
  </br>
  <img src="images/publish-mqttx.png" alt="Publish on MQTT X">
  </br></br>
</div>

<p align="right"><a href="#top">:point_up_2:</a></p>

# Steganography with C++

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#use-python-tool">Use python tool</a></li>
    <li><a href="#qt-application">Qt application</a></li>
  </ol>
</details>

## Use python tool

> put yout image into : ```steganography-tool/images/before_encryption/```

- run the command : ```python steganography-tool/building_tool.py --file file_name.png```

1. enter the message you want ton encrypt
2. path to the new image with encrypted message : ```steganography-tool/images/after_encryption/```
2. check if the message has been successfully decrypted

<div align="center">
  </br>
  <img src="images/building_tool.png" alt="Result python tool">
  </br></br>
</div>

<p align="right"><a href="#top">:point_up_2:</a></p>

# Qt application

- Just below you can see the Qt application :

<div align="left">
  </br>
  <img src="images/application.png" alt="Qt application">
  </br></br>
</div>

- Click on "Choose file" button to select a .PNG file.

<div align="left">
  </br>
  <img src="images/browse_file.png" alt="Browse file">
  </br></br>
</div>

- Click on "Decrypt File". 
- The encrypted message will be print into TextBrowser
<div align="left">
  </br>
  <img src="images/decrypted_message.png" alt="Result python tool">
  </br></br>
</div>

<p align="right"><a href="#top">:point_up_2:</a></p>
