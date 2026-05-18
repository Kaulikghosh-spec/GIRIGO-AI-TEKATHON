# GIRIGO-AI-TEKATHON
# 🚏 GIRIGO-AI: Smart City Dynamic Route Rationalization

![Python](https://img.shields.io/badge/Frontend-Python_Streamlit-blue)
![C++](https://img.shields.io/badge/Backend-Native_C++-red)
![Status](https://img.shields.io/badge/Status-Tekathon_2026_Ready-success)

*GIRIGO-AI* is a context-aware, predictive routing engine built for smart-city infrastructure. Developed for Tekathon 2k26, it solves the severe traffic bottleneck issues in the Maheshtala corridor caused by sudden passenger surges and infrastructure damage.

## 🧠 The Architecture (Decoupled Microservice)
GIRIGO-AI utilizes a highly optimized decoupled architecture:
* *The Frontend (Python/Streamlit):* Handles the reactive UI, live time-engine syncing, and geospatial map rendering using *Folium* and the *OSRM API* for real-world street geometry snapping.
* *The Backend (Native C++):* Calculates route optimizations in milliseconds. Python passes the environment state to the C++ engine, which executes *Dijkstra’s Algorithm* with a priority queue to calculate dynamic weight penalties, returning the optimal path to the frontend.

## 🚀 Key Features
1. *Live Train Surge Detection:* Actively monitors the Eastern Railway timetable. When a train arrives at Nangi Station, the AI autonomously shifts routing weights to manage the predicted passenger surge.
2. *Dynamic Pricing Algorithm:* Calculates exact fares based on base rates, distance, time/traffic penalties, flyover tolls, and surge multipliers.
3. *AI Predictive Infrastructure Scanner:* Simulates satellite topography and rainfall correlation to predict road degradation, forcing autonomous emergency detours.
4. *Google Maps-Style Traffic Visuals:* Color-coded animated paths (Blue = Fast, Orange = Moderate, Red = Severe Jam/Surge).

## 🛠️ Tech Stack
* *UI & Dashboard:* Streamlit, CSS (Glassmorphism)
* *Geospatial Rendering:* Folium (Leaflet.js), OSRM API
* *Algorithm Engine:* C++ (Dijkstra's Shortest Path)

## ⚙️ How to Run Locally
1. Clone this repository to your local machine.
2. Compile the C++ engine:
   ```bash
   g++ engine.cpp -o engine.exe
---

## 📬 Contact & Connect

If you have any questions about **GIRIGO-AI**, want to collaborate, or just want to talk about pathfinding algorithms, feel free to reach out!

[![Gmail](https://img.shields.io/badge/Gmail-kaulikghosh123456789%40gmail.com-EA4335?style=for-the-badge&logo=gmail&logoColor=white)](mailto:kaulikghosh123456789@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/kaulik-ghosh-372802351)

*Formally active on GitHub and LinkedIn. For quick inquiries, please use LinkedIn messaging.*
