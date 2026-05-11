# plant_disease.ipynb — Line-by-line explanation

This companion documents each code line in `plant_disease.ipynb` without modifying original notebook.

Cell: Imports

```python
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import matplotlib.pyplot as plt
```
- Imports Keras CNN layers and `ImageDataGenerator` for image augmentation and batch loading.

Cell: Paths

```python
train_path = "Plant_Disease_Dataset/train"
valid_path = "Plant_Disease_Dataset/valid"
test_path  = "Plant_Disease_Dataset/test"
```
- String paths pointing to training, validation, and test image directories.

Cell: Data generators

```python
train_datagen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=20,
    zoom_range=0.2,
    horizontal_flip=True,
)

valid_datagen = ImageDataGenerator(rescale=1./255)
test_datagen  = ImageDataGenerator(rescale=1./255)
```
- Training generator rescales pixel values and applies augmentation; validation/test only rescale.

Cell: Flow from directories

```python
train_data = train_datagen.flow_from_directory(
    train_path,
    target_size=(128, 128),
    batch_size=32,
    class_mode='categorical',
)

valid_data = valid_datagen.flow_from_directory(
    valid_path,
    target_size=(128, 128),
    batch_size=32,
    class_mode='categorical',
)

test_data = test_datagen.flow_from_directory(
    test_path,
    target_size=(128, 128),
    batch_size=32,
    class_mode='categorical',
)
```
- Creates iterators that read images from folders, resize to 128×128, and yield batches with one-hot labels.

Cell: Model architecture

```python
model = Sequential()

# Conv Layer 1
model.add(Conv2D(32, (3,3), activation='relu', input_shape=(128,128,3)))
model.add(MaxPooling2D(2,2))

# Conv Layer 2
model.add(Conv2D(64, (3,3), activation='relu'))
model.add(MaxPooling2D(2,2))

# Conv Layer 3
model.add(Conv2D(128, (3,3), activation='relu'))
model.add(MaxPooling2D(2,2))

# Flatten
model.add(Flatten())

# Fully Connected
model.add(Dense(128, activation='relu'))
model.add(Dropout(0.5))

# Output Layer
model.add(Dense(train_data.num_classes, activation='softmax'))

model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy'],
)

model.summary()
```
- Standard CNN: three convolution+pooling blocks, flatten to FC layers, dropout for regularization, softmax output for multi-class classification.

Cell: Training and plotting

```python
history = model.fit(
    train_data,
    epochs=3,
    validation_data=valid_data,
)

plt.plot(history.history['accuracy'], label='Training Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
plt.title("CNN Accuracy Graph")
plt.xlabel("Epochs")
plt.ylabel("Accuracy")
plt.legend()
plt.show()
```
- Trains model for 3 epochs (example) and plots accuracy curves.

Notes:
- `train_data.num_classes` is determined by folders under `train_path`.
- For production, consider more epochs, learning rate schedules, and monitoring with callbacks (EarlyStopping, ModelCheckpoint).

---

## Numeric choices & hyperparameter explanations

- Convolutional filters `32, 64, 128`: Increasing filter counts in deeper layers lets the model learn more complex features while keeping earlier layers lightweight.
- `target_size=(128,128)`: Chosen to give reasonable spatial resolution for plant details while limiting compute; adjust up for finer details or down for faster training.
- `batch_size=32`: A common batch size balancing GPU memory and statistical efficiency.
- `Dropout(0.5)`: Strong regularization on FC layers to reduce overfitting; conv layers often use lower dropout or spatial dropout.
- `epochs=3` (example): Short for demonstration — in practice use more epochs with early stopping and checkpoints.

These entries explain why common numeric values (kernel counts, image size, batch size, dropout) are used and trade-offs to consider.
