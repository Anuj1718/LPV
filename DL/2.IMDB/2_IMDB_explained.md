# 2_IMDB.ipynb — Line-by-line explanation

This companion documents each code line in `2_IMDB.ipynb` without altering the original.

Cell: Imports and setup

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import re

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
```
- Imports numerical and data libraries, regex for text cleaning, TF-IDF vectorizer for text features, and a basic Keras MLP for classification.

Cell: Load dataset safely

```python
df = pd.read_csv(
    "IMDB_Dataset.csv",
    encoding_errors='ignore',
    on_bad_lines='skip',
    engine='python',
)

print("Dataset Loaded ✅")
print(df.head())
print(df.columns)
```
- Reads CSV robustly, skipping malformed lines and avoiding encoding errors.

Cell: Drop NA and check labels

```python
df = df.dropna()
print(df['sentiment'].unique())
print(df['sentiment'].isnull().sum())
df = df.dropna()
```
- Ensures dataset has no missing values; inspects unique sentiment labels.

Cell: Fix column names

```python
df.columns = ['review', 'sentiment']
```
- Renames columns to predictable names.

Cell: Text cleaning

```python
def clean_text(text):
    text = str(text)
    text = text.lower()
    text = re.sub(r'<.*?>', '', text)      # remove HTML
    text = re.sub(r'[^a-zA-Z ]', '', text) # remove symbols
    return text

df['review'] = df['review'].apply(clean_text)
```
- Defines a cleaning function that normalizes text, removes HTML tags and non-letter characters, and applies it to reviews.

Cell: Convert labels

```python
df['sentiment'] = df['sentiment'].map({'positive': 1, 'negative': 0})

print("\nSentiment Count:")
print(df['sentiment'].value_counts())
```
- Maps textual labels to binary integers and prints class distribution.

Cell: TF-IDF vectorization

```python
vectorizer = TfidfVectorizer(max_features=5000)
X = vectorizer.fit_transform(df['review']).toarray()
y = df['sentiment']
```
- Fits a TF-IDF vectorizer limited to 5000 features and transforms text into numeric vectors.

Cell: Train-test split

```python
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)
```
- Splits features and labels into training and testing sets.

Cell: Build and compile model

```python
model = Sequential()

model.add(Dense(128, activation='relu', input_shape=(X_train.shape[1],)))
model.add(Dense(64, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

model.compile(
    optimizer='adam',
    loss='binary_crossentropy',
    metrics=['accuracy'],
)

model.summary()
```
- Builds a simple MLP with two hidden layers and a sigmoid output for binary classification. Compiles with binary crossentropy.

Cell: Training

```python
history = model.fit(
    X_train, y_train,
    epochs=10,
    batch_size=32,
    validation_data=(X_test, y_test),
)
```
- Trains for 10 epochs, evaluating on the test set as validation data.

Cell: Plotting and final accuracy

```python
plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')

plt.title("Accuracy Graph")
plt.xlabel("Epochs")
plt.ylabel("Accuracy")
plt.legend()
plt.show()

loss, accuracy = model.evaluate(X_test, y_test)
print("\nFinal Accuracy:", accuracy)
```
- Plots training/validation accuracy and prints final test accuracy.

---

Potential follow-ups: add tokenization with `Tokenizer` + embedding layers, or use `TextVectorization` instead of `TfidfVectorizer` for end-to-end Keras models.
