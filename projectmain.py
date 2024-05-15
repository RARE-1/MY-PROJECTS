import pandas as pd
import yfinance as yf
from sklearn.model_selection import train_test_split 
from sklearn.linear_model import LinearRegression
from sklearn import metrics
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

# Define the start and end dates for the stock data 
start_date = '2010-01-01'
end_date = '2022-12-31'

# Download the TSLA stock data using the 'yfinance' library
stock_data = yf.download('TSLA', start=start_date, end=end_date)

# Reset the index to convert the data into a pandas DataFrame
stock_data.reset_index(inplace=True)

# Convert 'Date' to a numerical column (number of days since 1970-01-01)
stock_data['DateNum'] = (stock_data['Date'] - pd.Timestamp("1970-01-01")) // pd.Timedelta('1D')

# Use the 'High' price as the value to predict
stock_data['Prediction'] = stock_data[['High']].shift(-1)

# Remove the last row as it does not have a prediction
stock_data = stock_data[:-1]

# Split the data into 'x' (features) and 'y' (target)
x = stock_data.drop(['Prediction', 'Date'], axis=1)
y = stock_data['Prediction']

# Split the data into training and testing sets
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

# Create and train the model
model = LinearRegression()
model.fit(x_train, y_train)

# Test the model using the testing data
predictions = model.predict(x_test)

# Calculate the mean absolute error (a measure of prediction accuracy)
mae = metrics.mean_absolute_error(y_test, predictions)

print(f'Mean Absolute Error: {mae}')

# Plot the actual vs predicted prices
plt.figure(figsize=(10,5))
plt.plot(mdates.num2date(x_test['DateNum']), y_test, color='blue', label='Actual Price')
plt.plot(mdates.num2date(x_test['DateNum']), predictions, color='red', linewidth=2, label='Predicted Price')
plt.title('Tesla Stock Price Prediction')
plt.xlabel('Date')
plt.ylabel('Price')
plt.legend()
plt.show()

import joblib
# Save the trained model to disk
joblib.dump(model, 'linear_regression_model.pkl')
