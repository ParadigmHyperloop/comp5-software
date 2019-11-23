# Flight Computer devlopment
- Ensure Docker is installed and running on your machine
## Taskrunner setup for VsCode
- install VsCode `Tasks' extension by actboy168
- open comp5-software\OnPod\FlightComputer folder with VsCode
- replace the folder bath in .vscode/tasks.json line 28 command:`compile and run RC HelloWorld`, with your path. replace this -> `/c/hyperloop/comp5-software/OnPod/FlightComputer` 
- Try task buttons in blue taskbar at bottom of VsCode window:
    `echoTest` // should print `Hello taskrunner test good.`
    `build FC Image` // should build FC image `pi_fc:v1`
    `compile and run RC HellowWorld` // should print `---- Hello Paradigm!!! ----`

