# Automatic-Humidity-FeedBack-Control-System
An Automatic Humidity Feedback Control System is a classic closed-loop engineering setup designed to maintain the moisture level of an environment at a specific, predetermined value, regardless of external disturbances.

Since you are diving into control systems, it is easiest to break this down using standard control theory terminology and map it directly to the physical hardware you would use to build it.

The Core Components
The Plant (The Environment): This is the physical space you are trying to control. It could be a greenhouse, an incubator, a cigar humidor, or just a room.

The Sensor (The Feedback Loop): A digital sensor (like a DHT22 or BME280) continuously measures the current moisture level in the air. This real-time reading is your Process Variable (PV).

The Controller (The Brain): This is your microcontroller (like an ESP8266 or Arduino). It stores your desired humidity level, known as the Set Point (SP).

The Error Detector: Inside the controller's code, it continuously calculates the Error: Error = Set Point - Process Variable.

The Actuator (The Muscle): The hardware that physically changes the environment based on the controller's commands.

Positive Error (Too dry): The controller triggers a relay to turn on a humidifier or water mister.

Negative Error (Too humid): The controller triggers a relay to turn on an exhaust fan or a dehumidifier.

How the Logic Works
There are generally two ways you can program the logic for this type of system:

Bang-Bang (On/Off) Control: This is the simplest method. If the humidity drops below the Set Point, the humidifier turns on at 100% power. Once it hits the target, it shuts off completely. To prevent the relays from clicking on and off rapidly when the humidity hovers right at the target, you usually program in a deadband or hysteresis (e.g., only turn on if it drops 2% below the target, and turn off when it goes 2% above).

PID Control: For precise environments (like industrial manufacturing), a Proportional-Integral-Derivative controller is used. Instead of just "On" or "Off", the controller might use PWM (Pulse Width Modulation) to adjust the speed of a fan or the intensity of a humidifier. As the current humidity gets closer to the Set Point, the system slows down the actuators to gently land on the target without overshooting.
