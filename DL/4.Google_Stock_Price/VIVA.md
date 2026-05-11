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

Q31: How to perform feature selection in time series?
- A31: Use lag importance, correlation analysis, or model-based importance (e.g., permutation importance) on validation sets.

Q32: How to handle regime changes in financial series?
- A32: Detect change points, retrain models on recent data, or build regime-aware models that switch behavior.

Q33: What is seasonality decomposition?
- A33: Decompose series into trend, seasonal, and residual components (e.g., STL) to model each separately.

Q34: How to incorporate calendar effects (e.g., weekdays/months)?
- A34: Add time-based features like day-of-week, month, holiday indicators to capture periodic patterns.

Q35: What is data leakage in backtesting and how to avoid it?
- A35: Using future information (e.g., future scaled statistics) in training; avoid by strictly using past data when engineering features.

Q36: How to detect autocorrelation in residuals?
- A36: Plot ACF of residuals and perform Ljung-Box test to check for remaining autocorrelation.

Q37: How to select window normalization strategy for returns vs prices?
- A37: Returns stabilize variance and often suit modeling; price-level models require proper scaling and may need trend handling.

Q38: What is the effect of outliers on RNN training?
- A38: Outliers can skew loss and gradients leading to instability; consider robust loss, clipping, or outlier removal.

Q39: How to tune sequence length vs model capacity trade-off?
- A39: Longer sequences require larger models; balance via validation and prefer meaningful lags that capture dependencies.

Q40: How to use residual bootstrapping for interval forecasts?
- A40: Fit model residuals, sample residuals with replacement to generate forecast trajectories and compute quantiles.

Q41: What is multi-step forecasting and its challenges?
- A41: Predicting multiple future timesteps; challenges include error accumulation and designing appropriate architectures (direct vs recursive).

Q42: How to evaluate multi-step forecasts?
- A42: Use horizon-wise metrics (MAE per horizon), and visualize forecast envelopes across horizons.

Q43: How to include exogenous macro indicators in stock forecasting?
- A43: Align external indicators by timestamp as additional inputs; be cautious of their update frequency and look-ahead risk.

Q44: What are diebold-mariano tests used for?
- A44: Statistical tests comparing predictive accuracy between two forecasting models over the same period.

Q45: How to build a baseline model for time series tasks?
- A45: Use naive forecasts (last value), moving average, or simple ARIMA as baselines to compare advanced models.

Q46: How to interpret model weights or importance in RNNs?
- A46: Use input perturbation, occlusion tests, attention mechanisms, or gradient-based attribution to estimate importance.

Q47: How to detect structural breaks programmatically?
- A47: Use statistical tests for change points (e.g., PELT), monitor model performance drift, or run rolling-window analyses.

Q48: How to design experiments for model selection in finance?
- A48: Use time-respecting cross-validation, multiple holdouts, and economic metrics (e.g., P&L) beyond statistical error.

Q49: What is walk-forward vs expanding window evaluation?
- A49: Walk-forward retrains on a fixed window sliding forward; expanding window grows training history each step — choose based on stationarity.

Q50: Practical viva tip: how to justify model choice quickly?
- A50: Show baseline comparisons, validation metrics across horizons, and explain why chosen model fits domain patterns (seasonality, trend, nonlinearity).
