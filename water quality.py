import numpy as np
from sklearn.linear_model import LinearRegression


data = np.array([
    [10, 30, 25, 8],
    [15, 35, 28, 7],
    [20, 40, 30, 6],
    [25, 45, 32, 5],
    [30, 50, 35, 4]
])


X = data[:, :-1]
y = data[:, -1]


model = LinearRegression()
model.fit(X, y)

def predict_food_quality(methane_ppm, humidity, temperature):
    new_data = np.array([[methane_ppm, humidity, temperature]])  # New data with methane ppm, humidity, and temperature readings
    predicted_quality = model.predict(new_data)
    return predicted_quality[0]


methane_ppm = float(input("Enter methane ppm: "))
humidity = float(input("Enter humidity: "))
temperature = float(input("Enter temperature: "))


predicted_quality = predict_food_quality(methane_ppm, humidity, temperature)
print("Predicted Food Quality:", predicted_quality)

