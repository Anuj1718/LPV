# Plant Disease Practical — Theory & Viva Questions

Topics: convolutional neural networks (CNN), image preprocessing, augmentation, multi-class classification.

Short viva questions:
- Q: Why use `rescale=1./255`?
  - A: Pixel values 0–255 are scaled to 0–1 to improve numerical stability and convergence.
- Q: What does `class_mode='categorical'` mean?
  - A: Labels are returned as one-hot encoded vectors for multi-class classification.
- Q: Why add `Dropout`?
  - A: Dropout reduces overfitting by randomly zeroing activations during training.

Practical tips:
- Use transfer learning (e.g., pretrained ResNet/MobileNet) for small datasets to improve accuracy and convergence.
- Monitor validation loss and use `EarlyStopping` to prevent overfitting.
