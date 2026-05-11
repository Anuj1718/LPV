# Boston Housing Practical — Theory & Viva Questions

Summary of practical: linear regression implemented via a single-neuron deep network (Keras). Steps: dataset loading, preprocessing (scaling), train/test split, model build, training, evaluation, plotting.

Common viva Q&A:
- Q: Why scale features before training?
  - A: Scaling ensures gradients have balanced magnitudes and helps optimizers converge faster; standardization centers features and scales by variance.
- Q: Why keep a validation split during training?
  - A: To monitor generalization performance and detect overfitting during training.
- Q: Why does a single Dense(1) with linear activation implement linear regression?
  - A: Because the model computes a weighted sum (plus bias) producing a linear combination of inputs — same form as linear regression.
- Q: How do MSE and MAE differ?
  - A: MSE penalizes larger errors more (squared), MAE gives the average absolute error and is more robust to outliers.

Possible viva tasks:
- Show how to add L2 regularization to the Dense layer; explain effect on weights.
- Convert model to include hidden layers (non-linear) and explain how capacity and overfitting change.
