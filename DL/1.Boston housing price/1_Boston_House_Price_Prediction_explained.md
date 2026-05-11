# 1_Boston_House_Price_Prediction.ipynb — Line-by-line explanation

This companion documents every code-line in `1_Boston_House_Price_Prediction.ipynb` (no changes to the original notebook).

Cell 1 (Imports):

```python
#Step 1: Import Libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
```
- Import numerical (`numpy`) and tabular (`pandas`) libraries.
- `matplotlib.pyplot` is for plotting.
- `train_test_split` splits data into train/test sets.
- `StandardScaler` scales features to zero mean and unit variance.
- `tensorflow` and Keras `Sequential`/`Dense` are used to build and train the neural network.

Cell 2 (Load dataset):

```python
#Step 2: Load Dataset
# Load dataset
df = pd.read_csv("1_boston_housing.csv")

# Remove quotes from column names (important for your dataset)
df.columns = df.columns.str.replace('"', '')

# Display first 5 rows
df.head()
```
- Reads CSV into a DataFrame `df`.
- Removes stray double-quote characters from column names.
- `df.head()` displays first rows for inspection.

Cell 3 (Features/target split):

```python
#Step 3: Split Features and Target
X = df.drop("MEDV", axis=1)   # Features
y = df["MEDV"]                # Target

print(X.shape, y.shape)
```
- `X` contains all columns except `MEDV` (the price); `y` is the target price column.
- `print` shows dataset dimensions.

Cell 4 (Train-test split):

```python
#Step 4: Train-Test Split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)
```
- Splits data with 20% reserved for testing; `random_state` ensures reproducible split.

Cell 5 (Scaling):

```python
#Step 5: Feature Scaling
scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
```
- Fit `StandardScaler` on training data and apply same transform to test data to avoid data leakage.

Cell 6 (Simple model build):

```python
model = Sequential()
model.add(Dense(1, input_shape=(X_train.shape[1],), activation='linear'))

model.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)

history = model.fit(
    X_train, y_train,
    epochs=100,
    validation_split=0.05,
    verbose=1,
)
```
- Constructs a `Sequential` model with a single `Dense` neuron (linear activation) — effectively linear regression.
- Compiles with `adam` optimizer and mean-squared-error loss; tracks mean absolute error.
- Trains (`fit`) for 100 epochs using 5% of training data for validation.

Cell 7 (Explicit model summary):

```python
#Step 6: Build Deep Neural Network
model = Sequential()

# Single neuron → behaves like linear regression
model.add(Dense(1, input_shape=(X_train.shape[1],), activation='linear'))

model.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)

model.summary()
```
- Repeats model definition and prints `model.summary()` to show layer parameters.

Cell 8 (Train model):

```python
#Step 7: Train Model
history = model.fit(
    X_train, y_train,
    epochs=100,
    batch_size=16,
    validation_split=0.2,
    verbose=1,
)
```
- Trains model with batch size 16 and 20% of training data used for validation.

Cell 9 (Evaluate):

```python
#Step 8: Evaluate Model
loss, mae = model.evaluate(X_test, y_test)

print("Test Loss (MSE):", loss)
print("Test MAE:", mae)
```
- Evaluates the trained model on the test set and prints loss and MAE.

Cell 10 (Predictions):

```python
#Step 9: Predictions
y_pred = model.predict(X_test)

# Compare actual vs predicted
for i in range(5):
    print(f"Actual: {y_test.iloc[i]:.2f} | Predicted: {y_pred[i][0]:.2f}")
```
- Produces predictions and prints first five pairs of actual vs predicted values.

Cell 11 (Plots):

```python
#Step 10: Plot Training Graphs
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.legend()
plt.title("Loss Graph")
plt.xlabel("Epochs")
plt.ylabel("Loss")
plt.show()
```
- Plots training and validation loss across epochs to inspect learning behaviour.

---

If you want, I can also generate a runnable `.py` script version with the same lines and inline comments, or export this companion to PDF.
