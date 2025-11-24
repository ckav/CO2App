# CO2 Monitor App

A simple web-based CO2 monitor that connects to an Arduino via USB using the Web Serial API.

## Features

- **Real-time Monitoring**: Connects to Arduino Uno via USB and reads CO2 PPM values.
- **Visualizations**: Plots data in real-time using Chart.js.
- **Data Persistence**: Saves readings to browser `localStorage` so data isn't lost on refresh.
- **Export**: Download your data as a CSV file.
- **Air Quality Indicators**: Visual feedback for Good, Moderate, and Poor air quality levels.

## Hardware Requirements

- Arduino Uno (or compatible board)
- CO2 Sensor (e.g., MH-Z19, SCD30) connected to the Arduino
- USB Cable

## Arduino Setup

Ensure your Arduino sketch outputs data to the Serial monitor in a format containing the text "CO2" or "ppm" followed by the value, for example:

```
CO2ppm:565
```

Baud rate should be set to **9600**.

## How to Use

1. Open `index.html` in a supported browser (Chrome, Edge, or Opera).
   - *Note: Web Serial API is not supported in Firefox or Safari (iOS).*
2. Connect your Arduino to your computer/Android phone via USB.
3. Click the **Connect Arduino** button.
4. Select your device from the list and click **Connect**.
5. The app will start displaying and plotting the CO2 levels.

## Browser Support

- **Desktop**: Chrome, Edge, Opera
- **Android**: Chrome (requires OTG cable to connect Arduino)
- **iOS**: Not supported (Web Serial API limitation)

## License

MIT
