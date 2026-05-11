# Google_Stock_Price.ipynb — Line-by-line explanation

This companion documents each code-line in `Google_Stock_Price.ipynb` without changing the original notebook.

Cell: Imports

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.preprocessing import MinMaxScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, SimpleRNN
```
- Imports numeric and plotting libraries, `MinMaxScaler` to scale time series between 0 and 1, and a simple RNN-based model.

Cell: Load data and take `Open` column

```python
#2. Load Dataset
df = pd.read_csv("Google_Stock_Price.csv", thousands=',')

# Take Open column
data = df['Open'].values.reshape(-1, 1)
```
- Reads CSV, treating thousands separators, then extracts the `Open` price column and reshapes to a 2D array.

Cell: Clean non-numeric and scale

```python
scaler = MinMaxScaler(feature_range=(0,1))
# Clean non-numeric values like 'GOOGL' / NaN from Open column, then scale
data = pd.to_numeric(df['Open'], errors='coerce').dropna().values.reshape(-1, 1)
data_scaled = scaler.fit_transform(data)
```
- Converts `Open` column to numeric coercing invalid entries to NaN, drops them, reshapes, and applies min-max scaling.

Cell: Train/test split

```python
train_size = int(len(data_scaled) * 0.8)

train_data = data_scaled[:train_size]
test_data = data_scaled[train_size:]
```
- Uses 80% of the time series for training; remainder for testing.

Cell: Create dataset helper (look-back 60)

```python
def create_dataset(dataset):
    X = []
    y = []
    
    for i in range(60, len(dataset)):
        X.append(dataset[i-60:i, 0])
        y.append(dataset[i, 0])
    
    return np.array(X), np.array(y)

X_train, y_train = create_dataset(train_data)
X_test, y_test = create_dataset(test_data)
```
- `create_dataset` builds sequences of length 60 (previous 60 timesteps) as inputs `X` and the next value as `y`.

Cell: Reshape for RNN

```python
X_train = np.reshape(X_train, (X_train.shape[0], X_train.shape[1], 1))
X_test = np.reshape(X_test, (X_test.shape[0], X_test.shape[1], 1))
```
- Reshapes to 3D shape (samples, timesteps, features) required by RNN layers.

Cell: Model definition

```python
model = Sequential()

model.add(SimpleRNN(50, return_sequences=True, input_shape=(60,1)))
model.add(SimpleRNN(50))
model.add(Dense(1))

model.compile(optimizer='adam', loss='mean_squared_error')

model.summary()
```
- Builds a two-layer SimpleRNN model followed by a Dense output for regression; compiles with MSE loss.

Cell: Train, predict, inverse scale, and plot

```python
model.fit(X_train, y_train, epochs=20, batch_size=32)

predicted = model.predict(X_test)
predicted = scaler.inverse_transform(predicted)
real = scaler.inverse_transform(y_test.reshape(-1,1))

plt.plot(real, color='red', label='Real Price')
plt.plot(predicted, color='blue', label='Predicted Price')
plt.title("Google Stock Price Prediction (RNN)")
plt.xlabel("Time")
plt.ylabel("Price")
plt.legend()
plt.show()
```
- Trains model and predicts on test sequences; inverse-transforms scaled values back to original price range and plots real vs predicted price.

Notes:
- RNNs like `SimpleRNN` capture temporal dependencies but may suffer from vanishing gradients; consider `LSTM`/`GRU` for longer sequences.

---

## Numeric choices & hyperparameter explanations

- `look-back = 60`: Using 60 previous timesteps (e.g., 60 days) is a common heuristic to capture recent trends and seasonality; tune based on validation performance.
- RNN units `50`: Number of hidden units per RNN layer; 50 balances model expressiveness and computational cost for a simple example.
- `epochs=20`, `batch_size=32`: Training duration and batch size; more epochs may improve performance but risk overfitting — monitor validation.
- `feature_range=(0,1)` in `MinMaxScaler`: Scales inputs to [0,1], suitable for RNN activations; ensure scaler is fitted on training data only.

These notes explain common numeric choices used in the notebook and why they were selected.
