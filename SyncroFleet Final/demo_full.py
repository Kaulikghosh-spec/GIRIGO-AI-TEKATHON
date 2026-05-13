import subprocess
import os
import time

def clear_screen():
    # Clears the terminal for a clean UI feel
    os.system('cls' if os.name == 'nt' else 'clear')

def show_header():
    print("="*45)
    print("   🚍 SYNCRO-FLEET: AI ROUTE DISPATCHER")
    print("       Tekathon 2k26 | Backend Demo")
    print("="*45)

def run_ai_logic(mode):
    engine_path = "./engine"
    
    if not os.path.exists(engine_path):
        print("\n[!] Error: C++ 'engine' binary not found!")
        print("Compile your C++ code as 'engine' in this folder first.")
        return

    # Call the C++ Backend
    subprocess.run([engine_path, str(mode)])

    # Read the results from the C++ output file
    try:
        with open("route_result.txt", "r") as f:
            lines = f.readlines()
            time_val = lines[0].strip()
            strategy = lines[1].strip()
            path = lines[2].strip()

            print("\n" + "-"*45)
            print(f"✅ AI OPTIMIZATION SUCCESSFUL")
            print(f"⏱  Real Travel Time: {time_val} mins")
            print(f"🧠 Strategy: {strategy}")
            print(f"📍 Path: {path}")
            print("-"*45)
    except FileNotFoundError:
        print("\n[!] Error: C++ ran but didn't create route_result.txt")

def main():
    while True:
        clear_screen()
        show_header()
        print("\nSELECT A SCENARIO:")
        print(" [0] 🚀 EXPRESS MODE (Flyover Bypass)")
        print(" [1] 👥 SERVICE MODE (Ground Corridor)")
        print(" [2] 🚉 STATION MODE (Dynamic Response)")
        print(" [q] ❌ EXIT DEMO")
        
        choice = input("\nEnter choice: ").lower()
        
        if choice == 'q':
            print("\nExiting Syncro-Fleet. Good luck at Tekathon!")
            break
        elif choice in ['0', '1', '2']:
            print(f"\n[AI] Processing Scenario {choice}...")
            time.sleep(1) # Simulated calculation time
            run_ai_logic(int(choice))
            input("\nPress Enter to return to menu...")
        else:
            print("\n[!] Invalid input. Try again.")
            time.sleep(1)

if __name__ == "__main__":
    main()
