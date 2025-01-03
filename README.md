# WebSocket controlled smoke machine mod
Smoke machines are pretty cool. Smoke machines you can wirelessly control are even cooler, but they're also way more expensive. So instead of spending a lot of money on one I decided to spend a lot of time on modding the dirt cheap smoke machine I already own! Sharing my code and files online in case someone else has interest in doing something similar :)

https://github.com/user-attachments/assets/eef2c1eb-12a6-4686-8a88-89f622232f13

I've got a BeamZ S500 smoke machine which can be triggered by a button that's on a control unit. Luckily for us the pins on that button stick out massively on the other side, so soldering some wires to it is super easy:

![smokemachine](https://github.com/user-attachments/assets/b76ad1ca-e51b-4261-9ecb-4a23feef477f)

When the button is pressed electricity flows between those two pins, which triggers the smoke machine. So all we have to do is connect those pins through a relay so we can control the smoke machine with a microcontroller. I'm hooking it up to my websocket based show effects infrastructre system called [Meffec](https://github.com/BreakTools/Meffec), but I'm sure you could come up with any number of ways of controlling a simple relay. My "tech stack" is an ESP32 C3 Super Mini board and the Arduino framework using PlatformIO for the code. For fun I'm also adding a little 128x64 OLED display, for showing things like the smoke status and if the unit is connected to WiFi and stuff. Here's the diagram for all the electronics:

![moddiagram](https://github.com/user-attachments/assets/3a8397f8-a7ec-49c5-9d64-e05168006e07)

I've also modeled and 3d printed a mount so I can screw the whole system to the bottom of the smoke machine's control unit (STL and FreeCAD file can be found in the resources folder):
![model](https://github.com/user-attachments/assets/6241a9f9-74c8-4e27-bf93-9fc28dc33b93)

And that's pretty much it! Total cost of the mod was about 8 euros, not a bad price for a wireless upgrade!

![finalcase](https://github.com/user-attachments/assets/6cbaef6a-d5ae-4851-9d2f-f0b7aecdfa1f)

Please be careful with the button wiring if you're planning on doing a mod like this yourself, as the voltage across it is roughly 70V. 

## Future work
Couple of things about this system that could be improved still:
- Whenever the relay turns off there's electrical noise which messes up the OLED display. I've "fixed" this now by just adding a delay after the relay turns off but this is clearly a hardware problem and should be fixed.
- I should buy some smaller screws that actually fit the relay.
- The 3d printed case could use some walls, but I don't have long enough screws to make that happen. I guess I need to buy more screws.
- Yeah I should go and buy some screws, like a nice good set of screws.
