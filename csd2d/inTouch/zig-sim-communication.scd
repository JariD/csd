// open UDP port communication and then check which ports are currently open
thisProcess.openUDPPort(125476);
thisProcess.openPorts;

~gyroSetter.value(,4,5);

//function for setting X, Y, Z of the gyroscope
(
~gyroSetter = { |x, y, z|
	~xGyro = x;
	~yGyro = y;
	~zGyro = z;
	~xGyro.postln;
	~yGyro.postln;
	~zGyro.postln;
};)


//oscDataloop
(
~oscData.free;
~oscData = OSCFunc({|msg|
	msg.postln;
	~gyroSetter.value(msg[1],msg[2],msg[3]);
},'ZIGSIM/jer/gravity');
)