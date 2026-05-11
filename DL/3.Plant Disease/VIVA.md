# Plant Disease Practical — Viva Questions & Answers (30+)

Q1: What is a convolutional neural network (CNN)?
- A1: A CNN is a type of neural network that uses convolutional layers to automatically learn spatial hierarchies of features from images.

Q2: What does a convolution filter (kernel) do?
- A2: A kernel slides over the image computing dot products to detect local features like edges or textures.

Q3: What is pooling and why use it?
- A3: Pooling reduces spatial dimensions (e.g., max-pooling), providing translation invariance and reducing computation.

Q4: What activation functions are common in CNNs?
- A4: ReLU is most common for hidden layers; softmax is used in output for multi-class classification.

Q5: Why rescale images to [0,1]?
- A5: It normalizes pixel ranges improving numerical stability and helps gradient-based optimization.

Q6: What is data augmentation and give examples?
- A6: Augmentation synthetically increases data via transformations like rotations, flips, zooms, brightness shifts, and cropping.

Q7: How to handle class imbalance in image datasets?
- A7: Use class weights, oversampling minority classes, targeted augmentation, or focal loss.

Q8: What is transfer learning?
- A8: Transfer learning uses a pretrained model (e.g., ResNet) and fine-tunes it on a new dataset, leveraging learned features.

Q9: Why use dropout in fully-connected layers?
- A9: Dropout randomly drops activations during training, reducing overfitting by preventing co-adaptation.

Q10: What is batch normalization and its benefits?
- A10: BatchNorm normalizes layer inputs across a mini-batch, stabilizing and accelerating training and allowing higher learning rates.

Q11: How to choose number of epochs?
- A11: Use validation performance and early stopping; too few underfits, too many overfits.

Q12: What is learning rate and how to tune it?
- A12: Learning rate controls optimizer step size; tune via grid search, learning rate schedules, or cyclic policies.

Q13: How to evaluate per-class performance?
- A13: Use precision, recall, and F1-score per class and inspect confusion matrices to find frequent misclassifications.

Q14: What is model fine-tuning vs feature extraction?
- A14: Feature extraction freezes pretrained base and trains new head; fine-tuning unfreezes some base layers to adapt pretrained weights.

Q15: How to prevent overfitting with small datasets?
- A15: Use transfer learning, extensive augmentation, regularization, and early stopping.

Q16: What is class_mode='categorical'?
- A16: It produces one-hot encoded labels for multi-class classification.

Q17: How to use validation data effectively?
- A17: Monitor validation loss/accuracy to choose hyperparameters and detect overfitting; do not use it as test data.

Q18: What optimizers are common for CNNs?
- A18: Adam, SGD with momentum, RMSprop; choice affects convergence speed and generalization.

Q19: Why visualize filters and feature maps?
- A19: To understand what features the network learns and diagnose training issues.

Q20: What is Grad-CAM and why use it?
- A20: Grad-CAM visualizes class-discriminative regions in images to explain model predictions.

Q21: How to speed up training?
- A21: Use GPUs, mixed precision, smaller batches, efficient data pipelines, and pretrained models.

Q22: How to handle varying image sizes/aspect ratios?
- A22: Use center-cropping, padding, or aspect-preserving resize to maintain important features.

Q23: What is label smoothing and why use it?
- A23: Label smoothing softens one-hot labels to reduce overconfidence and improve generalization.

Q24: How to choose batch size?
- A24: Trade-off between GPU memory, convergence stability, and generalization; tune based on hardware and validation.

Q25: How to detect dataset leakage in images?
- A25: Check whether same images or augmentations appear in both train and test sets; ensure splits are disjoint.

Q26: How to perform cross-validation with image data?
- A26: Use stratified K-fold by patient or grouping keys if images are not independent, or use repeated train/validation splits.

Q27: Why monitor training and validation curves?
- A27: To spot overfitting, underfitting, and optimization issues by comparing loss/accuracy curves.

Q28: What is class activation mapping used for in plant disease?
- A28: To highlight image regions the model uses to decide the disease label, useful for trust and debugging.

Q29: How to prepare a dataset for deployment inference?
- A29: Standardize preprocessing, save normalization parameters, and ensure model input pipeline matches training preprocessing.

Q30: Practical viva tip: what steps would you take if a model performs poorly on a particular class?
- A30: Inspect samples, increase augmentation for that class, collect more data, use class weights, or refine model architecture.
