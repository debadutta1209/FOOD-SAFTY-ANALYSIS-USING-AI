from sklearn.linear_model import LinearRegression

def collect_data():
    methane_ppm = float(input("Enter methane ppm: "))
    humidity = float(input("Enter humidity (%): "))
    temperature = float(input("Enter temperature (°C): "))
    ph_factor = float(input("Enter pH factor: "))
    return methane_ppm, humidity, temperature, ph_factor

methane_ppm, humidity, temperature, ph_factor = collect_data()

methane_threshold = 50
humidity_threshold = 70
temperature_threshold = 10
ph_threshold = 7.0  # pH level considered safe

is_safe = (methane_ppm < methane_threshold) and (humidity < humidity_threshold) and (temperature < temperature_threshold) and (ph_factor > ph_threshold)

if is_safe:
    print("Food is safe.")
else:
    print("Food is not safe.")

X = [[methane_ppm, humidity, temperature, ph_factor]]
y = [0]

model = LinearRegression()
model.fit(X, y)

y_pred = model.predict(X)

print("Prediction:", y_pred[0])