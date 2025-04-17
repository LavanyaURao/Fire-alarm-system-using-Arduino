# Fire-alarm-system-using-Arduino

👋Introduction:
Fire accidents can lead to serious loss of life and property, so early detection is essential. This project introduces an Arduino-based Fire Detection System that uses multiple sensors to sense fire, smoke, and heat. The system gives audio warnings to take prompt action in the event of an emergency.

📍components Used:
 
Arduino Uno – Microcontroller to process sensor data
Flame Sensor – Identifies infrared (IR) radiation of fire
MQ-2 Gas Sensor – Identifies smoke and toxic gases (CO, LPG, methane)
DHT11 Temperature & Humidity Sensor – Tracks environmental temperature
Buzzer – Sounds alarm on detection of fire or smoke
Breadboard – For connecting the circuit

🔧 Working Principle:
The Fire Hazard Detection System uses three sensors:

- DHT11: Measures temperature. If it’s ≥ 35°C, it signals possible overheating.

- Flame Sensor: Detects infrared light from fire. It sends a LOW signal when a flame is detected.

- MQ-2 Smoke Sensor: Detects smoke. An analog value ≥ 150 indicates smoke is present.

The buzzer turns ON only when all three conditions are met:
🔥 Flame detected (LOW)
🌡️ Temperature ≥ 35°C
💨 Smoke level ≥ 150

If any one condition isn’t met, the buzzer stays OFF.
NOTE: Adjust threshold values below based on your environment and sensor sensitivity.You can test with a matchstick or lighter to tune values.

🚀 Applications:
Home and industrial fire safety
Gas leakage detection in factories and kitchens
Warehouse and office early warning systems

✅Conclusion:
This project is an effective and economical fire detection system employing Arduino and sensors. It provides improved fire safety through early detection and immediate alert, minimizing damage from fire.

[![Demo video]([https://upload.wikimedia.org/wikipedia/commons/1/1b/YouTube_icon_%282013-2017%29.png](https://images.app.goo.gl/m6XYdrGSeN7wgefe9))](https://youtu.be/ljhyIYjHzDA?si=b9Hbis93xoR81TuE)

