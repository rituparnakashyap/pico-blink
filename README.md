# Raspberry Pi Pico W - Bink program

This is a bink demo of onboard Pico W LED. Following are the feature list of this project
1. The onboard led binks on and off every second. 
1. Enabled development on devcontainer, while installing all required dependencies and creating an un-previledge user.  
1. Install all required VSCode extension required for developement.
1. Enabled debugging with the Raspberry Debug Probe. 
1. Enabled serial terminal monitoring with `minicom`. 
1. Enabled uploading the UF2 binary over Serial Wire Debug (SWD) protocol. 

# Setup
1. Clone the repository by using `git clone git@github.com:rituparnakashyap/pico-blink.git`.
1. Install docker - https://docs.docker.com/engine/install/
1. Setup the debug probe following this instruction - https://www.raspberrypi.com/documentation/microcontrollers/debug-probe.html
1. Install VSCode and open the pico-blink folder. The IDE should do all the rest, including installing required extension. 
1. VSCode should open the project within a Dev Container. Select the active kit as "GCC x.x.x arm-none-eabi".
1. Select the debug build variant and then build the project. This option should be (atleast for me) at the buttom of the VSCode window. 
1. In the left panel select "Run and Debug" option and thereafter select "Pico Debug" option. This will start a OpenOCD server and connect the GDB for on device debugging. 
1. To monitor the serial termial output use `showcom` (alias) command on the bash prompt of the container.
1. When you run the "Pico Debug" it should upload the elf debug binary (provide you selected the debug build variant) automatically onto the pico device. However if you want to upload the UF2 binary without having to connect the pico device on to your system and press the bootselect button, you can use the `upload-uf2` (alias) command on the bash prompt of the container. This will upload the uf2 file via the debug probe.


