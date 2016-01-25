
Project Name: Home Automation using TM4C123G and RaspberryPi. 

Team: Aarthy Sundaram (EDM12B002)
      Kaviya R (EDM12B015)

Idea:  It is a design for home automation system using Raspberry pi, TM4C123 microcontroller and relay boards. Use of these components
 results in overall cost effective, scalable and robust implementation of the system. 
The commands from the user are processed in Raspberry Pi using Blynk App. 
Low-cost and energy efficient home automation system serves as a proof of concept.
 The design can be used in homes where elderly or physically challenged can control the lighting 
and others with their smartphones. 

Components: TM4C123G, RaspberryPi, 
	    Smartphone, Relay, LEDs (for lighting)


Number of Files: 2 

Dependency among the files: ledborg.py is run by the RaspberryPi. During its run, if the user enters the
    ipaddress of the Pi in his smartphone, he will be directed to the webpage index.html which contains the user interface. 
     Upon running blink.c in the TM4C123G, we can control various devices (LEDs, ServoMotors) etc, via internet. 





