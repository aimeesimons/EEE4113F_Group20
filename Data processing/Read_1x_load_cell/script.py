import serial
from datetime import datetime
import csv

# Define file path and open in append mode
with open('Test 10 ttapping.csv', mode='a', newline='') as sensor_file:
  sensor_writer = csv.writer(sensor_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)

  # Write header row only once (assuming the file is empty)
  if sensor_file.tell() == 0:
    sensor_writer.writerow(["Average", "Moving Average", "Median", "Exponential Average", "Timestamp"])

  # Serial communication setup
  com = "COM6"
  baud = 9600
  ser = serial.Serial(com, baud, timeout=0.1)

  while True:
    # Read data from Arduino
    data = ser.readline().decode('utf-8').rstrip().split(',')

    # Check if data is valid (has 4 values)
    if len(data) == 4:
      try:
        # Convert data to numerical values (modify based on data type)
        values = [float(val) for val in data]

        # Get timestamp
        timestamp = datetime.now()

        # Write data and timestamp to CSV
        sensor_writer.writerow(values + [timestamp])
        print(f"Data written to SensorData.csv: {values} - {timestamp}")
      except ValueError:
        print("Error: Invalid data received")
    else:
      print("Error: Incorrect number of values received")
