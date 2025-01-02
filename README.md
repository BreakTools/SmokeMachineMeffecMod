# WebSocket controlled smoke machine mod
Smoke machines are pretty cool. Smoke machines you can wirelessly control are even cooler, but they're also way more expensive. So instead of spending a lot of money on one I decided to spend a lot of time on modding the dirt cheap smoke machine I already own! Sharing my code and files online in case someone else has interest in doing something similar :)


I've got a BeamZ S500 smoke machine which can be triggered by a button that's on a control unit. Luckily for us the pins on that button stick out massively on the other side, so soldering some wires to it is super easy:

![smokemachine](https://github.com/user-attachments/assets/b76ad1ca-e51b-4261-9ecb-4a23feef477f)

When the button is pressed electricity flows between those two pins, which triggers the smoke machine. So all we have to do is connect those pins through a relay so we can control the smoke machine with a microcontroller. I'm hooking it up to my websocket based show effects infrastructre system called [Meffec](https://github.com/BreakTools/Meffec), but I'm sure you could come up with any number of ways of controlling a simple relay. My "tech stack" is an ESP32 C3 Super Mini board and the Arduino framework using PlatformIO for the code. For fun I'm also adding a little 128x64 OLED display, for showing things like the smoke status and if the unit is connected to WiFi and stuff. Here's the diagram for all the electronics:

![moddiagram](https://github.com/user-attachments/assets/3a8397f8-a7ec-49c5-9d64-e05168006e07)

I've also modeled and 3d printed a mount so I can screw the whole system to the bottom of the smoke machine's control unit (STL and FreeCAD file can be found in the resources folder):
![model](https://github.com/user-attachments/assets/6241a9f9-74c8-4e27-bf93-9fc28dc33b93)

Please be careful with the button wiring if you're planning on doing a mod like this yourself, as the voltage across it is roughly 70V. 
