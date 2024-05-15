//setters


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