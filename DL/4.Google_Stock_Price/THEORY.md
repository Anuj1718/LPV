# Google Stock Price Practical — Theory & Viva Questions

Topics: time series preparation for RNN, scaling, sequence windows, RNN architectures, evaluation of regression models.

Viva Q&A:
- Q: Why use `MinMaxScaler` for time series?
  - A: RNN activations often expect small numeric ranges; MinMax scales to [0,1] preserving shape.
- Q: What is `return_sequences=True` in the first RNN layer?
  - A: It makes the layer return the full sequence of hidden states (one per timestep), suitable when stacking RNN layers.
- Q: Why inverse-transform predictions?
  - A: Model trains on scaled values, so predictions must be inverse-transformed to the original price scale for interpretation.

Practical tips:
- Use LSTM/GRU for longer dependencies and consider scaling by training set only to avoid leakage.
