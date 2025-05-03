import pandas as pd
from sklearn.tree import DecisionTreeRegressor
import serial
import time
from collections import deque
import pyttsx3

data_file_path = 'C:/Users/alfre/Downloads/ECHOSIGN_Training_Data.csv'
data = pd.read_csv(data_file_path)

features = ['f0','f1','f2','f3','f4']
a = data[features]
b = data['ans']

model = DecisionTreeRegressor(random_state=1)
model.fit(a, b)


ser = serial.Serial('COM4', 9600)  
engine = pyttsx3.init()
recent_preds = deque(maxlen=2)
last_stable_pred = None

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print("Received:", line)
            try:
                
                f0i, f1i, f2i, f3i, f4i = map(int, line.split(','))

                
                serial_input = pd.DataFrame({
                    'f0': [f0i],
                    'f1': [f1i],
                    'f2': [f2i],
                    'f3': [f3i],
                    'f4': [f4i]
                })
                prediction = model.predict(serial_input)[0]

                
                recent_preds.append(prediction)

                
                if recent_preds.count(prediction) > 1:
                
                    if prediction != last_stable_pred:

                        print(f"Stable prediction: {prediction:.3f}")

                        
                        if prediction ==10:
                            print("ALIF")
                            t="ADIS"
                        elif prediction == 20:
                            print("DAAL")
                            t=""
                        elif prediction ==30:
                            print("NOON")
                            t="ADNOC"
                        elif prediction == 40:
                            print("OW")
                            t="From"
                        elif prediction == 50:
                            print("Kaaf")
                            t="GOODBYE"
                        elif prediction == 60:
                            print("Eien")
                        elif prediction == 1:
                            print("An'a")
                            t="We are"
                        elif prediction == 2:
                            print("Alfred")
                            t="ALFRED"
                        elif prediction == 3:
                            print("HELLO")
                            t="hello"
                        elif prediction == 4:
                            print("Haron")
                            t="haron"
                        elif prediction == 5:
                            print("AND")
                            t="and"
                        elif prediction == 6:
                            print("THIS")
                        elif prediction == 7:
                            print("OUR")
                            t="This is our"
                        elif prediction == 8:
                            print("Prototype")
                            t="Prototype" 

                        else:
                            t=""


                        engine.say(t)
                        engine.runAndWait()
                        
                        last_stable_pred = prediction

            except ValueError:
                print("Invalid input format. Expected: x,y,z,a,b")
except KeyboardInterrupt:
    print("Serial reading stopped.")
    ser.close()
