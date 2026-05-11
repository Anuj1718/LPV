# Google Stock Price Practical — Viva Questions & Answers (30+)

Q1: What is time series forecasting?
- A1: Forecasting predicts future values of a variable based on its historical observations and possibly exogenous inputs.

Q2: What is stationarity and why is it important?
- A2: Stationarity means statistical properties (mean, variance) are time-invariant; many time-series methods assume or work better with stationary data.

Q3: How to test for stationarity?
- A3: Use statistical tests like the Augmented Dickey-Fuller (ADF) test or inspect rolling statistics and plots.

Q4: What is differencing and when to use it?
- A4: Differencing subtracts previous values to remove trends and achieve stationarity for modeling.

Q5: What is autocorrelation (ACF) and partial autocorrelation (PACF)?
- A5: ACF measures correlation between series and lagged versions; PACF measures correlation with a lag after removing intermediate lag effects.

Q6: Why use RNNs for time series?
- A6: RNNs capture temporal dependencies via recurrent connections, allowing the model to use previous timesteps as context.

Q7: LSTM vs GRU vs SimpleRNN—differences?
- A7: LSTM and GRU have gating mechanisms to handle long-term dependencies; GRU is simpler with fewer parameters; SimpleRNN lacks gates and struggles with long contexts.

Q8: What is look-back/window size and how to choose it?
- A8: Window size is the number of past timesteps used as input; choose based on domain knowledge and validation performance.

Q9: How to split data in time-series tasks?
- A9: Use chronological splits (train on earlier times, test on later) and consider walk-forward validation for robust estimates.

Q10: What is walk-forward validation?
- A10: Iteratively train on expanding history and validate on the next period to mimic real-world forecasting.

Q11: Why scale training data only on training set?
- A11: To avoid data leakage; fit scalers on training data and apply to validation/test.

Q12: How to handle missing timestamps or irregular sampling?
- A12: Resample to a fixed frequency with interpolation, aggregation, or use models that handle irregular sequences.

Q13: What evaluation metrics are common?
- A13: MSE, RMSE, MAE, MAPE, and directional accuracy depending on application needs.

Q14: What is backtesting in time series?
- A14: Testing forecasting strategies on historical data to evaluate how they would have performed in the past.

Q15: How to incorporate exogenous variables (features)?
- A15: Include them as additional inputs aligned by timestamp (multi-variate time-series forecasting).

Q16: How to detect overfitting in time series models?
- A16: Validation performance degrades relative to training; check residuals and performance on holdout periods.

Q17: Why use ensembles for forecasting?
- A17: Ensembles average different models to reduce variance and often improve accuracy and robustness.

Q18: How does seasonality affect forecasting?
- A18: Seasonal patterns repeat over fixed periods; models must account for seasonality via features or model components.

Q19: What is differencing's effect on interpretability?
- A19: Differencing removes trends, making direct interpretation of levels harder; predictions need inverse transformation to original scale.

Q20: How to produce prediction intervals?
- A20: Use bootstrapping, quantile regression, Bayesian methods, or ensembles to estimate uncertainty.

Q21: How to select hyperparameters for RNNs?
- A21: Tune sequence length, number of layers/units, learning rate, batch size, regularization, and dropout using validation.

Q22: What are common preprocessing steps for financial time series?
- A22: Remove non-numeric entries, handle missing values, scale data, and add engineered features (returns, moving averages, volatility).

Q23: How to compute returns and why use them?
- A23: Returns = (price_t - price_{t-1})/price_{t-1}; they often stabilize variance and are useful features in finance.

Q24: How to avoid look-ahead bias when engineering features?
- A24: Ensure features at time t only use information available at or before t (no future data).

Q25: What is the role of regularization in RNNs?
- A25: Regularization (dropout, L2) reduces overfitting by penalizing large weights or randomly dropping units.

Q26: Why might an RNN produce poor long-term forecasts?
- A26: Due to vanishing gradients, insufficient memory capacity, or non-stationarity — consider LSTM/GRU or hybrid models.

Q27: How to interpret residuals in forecasting?
- A27: Residuals should be white noise (no autocorrelation); patterns indicate model deficiencies.

Q28: When to prefer ARIMA over RNNs?
- A28: ARIMA is interpretable and effective for linear stationary series and small datasets; RNNs handle complex nonlinear patterns and large datasets.

Q29: What is feature engineering for time series?
- A29: Creating lag features, rolling statistics, seasonal dummies, and technical indicators to provide context to models.

Q30: Practical viva tip: how to show your model is robust?
- A30: Demonstrate stable performance across multiple holdout periods, show residual diagnostics, and provide prediction intervals.
