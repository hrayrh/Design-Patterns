#include <iostream>

class Command
{
public:
	virtual void execute() = 0;
};
 
class Light 
{
public:
	void on() {
		std::cout << "The light is on\n";
	}
	void off() {
		std::cout << "The light is off\n";
	}
}; 

class LightOnCommand : public Command 
{
public:
        LightOnCommand(Light *light) : mLight(light) {}
	void execute(){
		mLight->on();
	}
private:
	Light *mLight;
};
 
class LightOffCommand : public Command 
{
public:
        LightOffCommand(Light *light) : mLight(light) {}
	void execute(){
		mLight->off();
	}
private:
	Light *mLight;
};

class RemoteControl 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
private:
	Command *mCmd;
};
 
int main() 
{
	Light *light = new Light;

	LightOnCommand *lightOn = new LightOnCommand(light);
	LightOffCommand *lightOff = new LightOffCommand(light);

	RemoteControl *control = new RemoteControl;

	control->setCommand(lightOn);
	control->buttonPressed();
	control->setCommand(lightOff);
	control->buttonPressed();
    control->setCommand(lightOn);
	control->buttonPressed();
	delete light, lightOn, lightOff, control;

	return 0;
}