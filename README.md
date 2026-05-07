#  ECG Signal Acquisition and Noise Filtering

##  Problem

Many people in this current generation are suffering with various heart problems such as heart blockage,heart attacks.Especially those within age 18-40 years are facing this.
Raw ECG (Electrocardiogram) signals are often affected by noise such as powerline interference, motion artifacts, and environmental disturbances.
This noise makes it difficult to analyze heart activity accurately.

##  Solution

This project helps the people to recognise the issue earlier and take preventive measures.It also helps the doctor to analyse the heart condition.
This project acquires ECG signals using sensors and applies filtering techniques to reduce noise.
The processed signal is then visualized in real-time on an OLED display and also monitored using the serial plotter.

##  Features

* Real-time ECG signal acquisition
* Noise filtering using smoothing technique
* Live waveform display on OLED
* Serial Monitor output for raw values
* Serial Plotter visualization for analysis

##  Technologies Used

* Arduino
* OLED Display (SSD1306)
* Embedded C
* ECG Sensor / Electrodes
* Signal Processing (Low-pass filtering)

##  Block Diagram

[Block Diagram](block_diagram.jpg)

##  Circuit Diagram

[Circuit Diagram](circuit_diagram.jpg)

##  Working

The ECG signal is captured using electrodes connected to the Arduino analog pin.
The raw signal contains noise, which is reduced using a simple filtering technique (weighted averaging).

The filtered signal is:

* Displayed as a waveform on the OLED screen
* Printed to the Serial Monitor
* Visualized using the Serial Plotter

This helps in observing heart signal patterns more clearly.

##  Demo / Output

vedio_ecg.mp4

##  How to Run

1. Connect ECG electrodes properly to the circuit
2. Connect OLED display via I2C
3. Upload the code to Arduino
4. Open Serial Monitor / Serial Plotter
5. Observe waveform on OLED and graph on plotter

##  Results

* Raw ECG signal successfully acquired
* Noise reduced using filtering
* Smooth waveform observed on OLED and Serial Plotter

##  Future Scope

* Advanced filtering (Butterworth / Kalman filter)
* Wireless ECG monitoring system
* Integration with mobile or web applications
* AI-based heart disease prediction

##  Output

Output1.jpg
Output2.jpg
