# Epic Snake Game
* Library Pre-requisites : 
  * ```Linux```:
    * Debian Based Distributions : 
       ```build-essential``` ```libsdl2-2.0```  ```libsdl2-dev``` ```libsdl2-image-dev``` ```libsdl2-ttf-dev``` ```libsdl2-mixer-dev```
    * Install equaivalent packages of the above mentioned by following these command:
      
      Install C++
      ``` 
        sudo apt-get install g++
      ```
      Install libsdl2-2.0
      ``` 
        sudo apt-get install libsdl2-2.0
      ```
      Install libsdl2-dev
      ``` 
        sudo apt-get install libsdl2-dev
      ```
      Install libsdl2-image-dev
      ``` 
        sudo apt-get install libsdl2-image-dev
      ```
      Install libsdl2-ttf-dev
      ``` 
        sudo apt-get install libsdl2-mixer-dev
      ```
      Install libsdl2-ttf-dev
      ``` 
        sudo apt-get install libsdl2-ttf-dev
      ```

  * Compile with:
      ```
       g++ src/*.cpp -Iinclude -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o epicsnakegame && ./epicsnakegame
      ``` 
