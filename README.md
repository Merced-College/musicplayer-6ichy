# musicPlayer
assessment for cpsc-25

1. Architecture lead - Richy Manzo
2. Algorithms and Data Lead - Andreas Hitt 
3. Hardware/Integration Lead - Esteban Mora

Richy focused on making sure the files could connect with eachother with no conflicts while I populated the algorithms, user controls and such. Esteban worked on the connection between the physical board and the code, doing things such as matching the pins physically with the pin numbers in the code. 


For the wiring notes, Esteban used outline/website the professor provided us. We used a 1k ohm resistor for the RX pin. Throught the class period we noitced that the RX and TX wire are switch on the Arduino and that is how we were able to get the speaker to work. The How to run/use the serial commands

The showMenu() method displays all available functions to the serial monitor. The AudioPlayer cpp file contians the logic for all of the functions, such as playing a speciic track number, playing next, playing previous, setting the volume, or pausing/unpausing depending on the whether or not the speaker is stopped. In the main function, we have if statements which call the different methods according to what the command the user enters in the terminal.