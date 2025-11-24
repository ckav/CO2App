# CO2 Explorer 🌬️💨

A fun, educational CO2 monitor that connects to an Arduino sensor via USB. Built for library installations to teach children about the science of breathing!

**🌐 Live Demo:** [https://ckav.github.io/CO2App/home.html](https://ckav.github.io/CO2App/home.html)

**📦 Repository:** [https://github.com/ckav/CO2App](https://github.com/ckav/CO2App)

## Features

### Two Modes

| Mode | Description | Best For |
|------|-------------|----------|
| 🔬 **Technical Mode** | Full data analysis with charts, statistics, and CSV export | Researchers, educators, adults |
| 🌱 **Kids Mode** | Fun characters, collectible badges, science facts, celebrations | Children, library visitors |

### Technical Features
- Real-time CO2 monitoring via Web Serial API
- Works in Chrome/Edge (desktop and Android)
- Local storage - data persists between sessions
- CSV export for data analysis
- No server required - runs entirely in the browser

### Kids Mode Features
- "Sprout" the plant character that reacts to CO2 levels
- 5 collectible achievement badges
- Rotating fun facts about CO2, plants, and breathing
- Confetti celebrations for milestones
- Visual air quality meter

## Quick Start

1. Open [https://ckav.github.io/CO2App/home.html](https://ckav.github.io/CO2App/home.html) in Chrome or Edge
2. Connect your Arduino CO2 sensor via USB
3. Choose Technical or Kids mode
4. Click "Connect Sensor" and select your Arduino
5. Blow on the sensor and watch the readings!

## Files

```
CO2App/
├── home.html           # Landing page - choose your mode
├── index.html          # Technical/adult mode
├── library-mode.html   # Kid-friendly mode
├── README.md
└── .gitignore
```

## Hardware Requirements

### Components
- Arduino Uno (or compatible board)
- CO2 sensor (e.g., MH-Z19, SCD30, CCS811)
- USB cable
- Power source (USB)

### Arduino Code

Your Arduino should output CO2 readings via Serial at 9600 baud in this format:

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  int co2Value = readCO2Sensor(); // Your sensor reading function
  Serial.print("CO2ppm:");
  Serial.println(co2Value);
  delay(1000);
}
```

The app also accepts plain numbers or `CO2: XXX ppm` format.

## Library Installation Guide

### What You'll Need
- Arduino + CO2 sensor setup
- Perspex/acrylic enclosure (tamper-resistant)
- USB power from library outlet
- QR code printed and displayed
- Tablet or signage explaining the activity

### QR Code
Generate a QR code pointing to:
```
https://ckav.github.io/CO2App/home.html
```

Children scan the QR code with their phone, connect to the sensor, and start exploring!

### Suggested Signage Text
> **🌬️ Breath Explorer**
> 
> Did you know plants breathe in what you breathe out?
> 
> 1. Scan the QR code with your phone
> 2. Tap "Connect Sensor"  
> 3. Blow gently on the sensor
> 4. Watch your CO2 levels rise!
> 
> Can you earn all 5 badges? 🏆

## Browser Support

| Browser | Desktop | Mobile |
|---------|---------|--------|
| Chrome | ✅ | ✅ (Android) |
| Edge | ✅ | ✅ (Android) |
| Safari | ❌ | ❌ |
| Firefox | ❌ | ❌ |

Web Serial API is required. iOS/Safari not supported.

## Development

### Local Development
Just open any HTML file in Chrome - no build step required!

### Making Changes
1. Clone the repo: `git clone https://github.com/ckav/CO2App.git`
2. Edit the HTML/CSS/JS files
3. Test locally in Chrome
4. Commit and push to deploy via GitHub Pages

### Project Structure
- All code is vanilla HTML/CSS/JavaScript
- No dependencies or build tools
- Each page is self-contained

## Contributing

We welcome contributions! This is an open educational project.

### How to Contribute
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes
4. Test in Chrome with an Arduino (or use the demo mode in code)
5. Commit (`git commit -m 'Add amazing feature'`)
6. Push (`git push origin feature/amazing-feature`)
7. Open a Pull Request

### Ideas for Contributions
- [ ] Add more fun facts for kids mode
- [ ] Create additional badge achievements
- [ ] Add sound effects option
- [ ] Multi-language support
- [ ] Kiosk mode (auto-reconnect, no disconnect button)
- [ ] Historical data view (daily/weekly charts)
- [ ] Alert sounds when CO2 exceeds threshold
- [ ] Dark/light theme toggle
- [ ] 3D printable enclosure designs

## Collaborators

- **Claire** - Project lead, process design
- **sciogit** - Collaborator
- *(Add your name here when you contribute!)*

## Funding & Purpose

This project aims to create educational CO2 monitoring kits for public spaces like libraries, helping children learn about:
- The science of breathing and respiration
- How plants and humans exchange gases
- Air quality and ventilation
- Basic electronics and sensors

If you're interested in supporting or funding library installations, please get in touch!

## License

MIT License - feel free to use, modify, and distribute.

## Links

- **Live App:** [https://ckav.github.io/CO2App/home.html](https://ckav.github.io/CO2App/home.html)
- **Repository:** [https://github.com/ckav/CO2App](https://github.com/ckav/CO2App)
- **Issues:** [https://github.com/ckav/CO2App/issues](https://github.com/ckav/CO2App/issues)

---

Made with 💚 for curious minds everywhere
