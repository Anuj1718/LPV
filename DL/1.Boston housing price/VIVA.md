# Boston Housing Practical — Viva Questions & Answers (30+)

Q1: What is linear regression?
- A1: Linear regression models the relationship between input variables and a continuous target as a linear combination of inputs plus an intercept.

Q2: What is the difference between simple and multiple linear regression?
- A2: Simple linear regression has one predictor; multiple linear regression has two or more predictors.

Q3: What are the assumptions of ordinary least squares (OLS)?
- A3: Linearity, independence of errors, homoscedasticity (constant variance), no perfect multicollinearity, and normally distributed errors for inference.

Q4: Why scale features before training a gradient-based model?
- A4: Scaling ensures features have comparable ranges, which improves optimization convergence and stability.

Q5: How is the closed-form OLS solution computed?
- A5: Using the normal equation: β = (X^T X)^{-1} X^T y, where β are coefficients.

Q6: When is closed-form solution impractical?
- A6: For very large feature sets or when X^T X is singular or ill-conditioned; then iterative methods like gradient descent are preferred.

Q7: What is multicollinearity and why is it a problem?
- A7: Multicollinearity occurs when predictors are highly correlated, inflating coefficient variance and making estimates unstable.

Q8: How to detect multicollinearity?
- A8: Use Variance Inflation Factor (VIF) or examine correlation matrices of features.

Q9: What is heteroscedasticity and how to detect it?
- A9: Heteroscedasticity is non-constant error variance across observations; detect using residual plots or tests like Breusch-Pagan.

Q10: How to handle heteroscedasticity?
- A10: Use weighted least squares, transform the target, or robust standard errors.

Q11: What is R-squared and adjusted R-squared?
- A11: R^2 measures proportion of variance explained; adjusted R^2 penalizes adding irrelevant predictors and adjusts for model complexity.

Q12: What loss function is used for linear regression in this practical?
- A12: Mean Squared Error (MSE), the average of squared differences between predicted and actual values.

Q13: What is the difference between MSE and MAE?
- A13: MSE squares errors (sensitive to outliers), MAE uses absolute errors (more robust to outliers).

Q14: How does regularization work (Ridge/Lasso)?
- A14: Ridge adds L2 penalty to shrink coefficients, Lasso adds L1 penalty which can shrink some coefficients to zero for feature selection.

Q15: When would you use Lasso vs Ridge?
- A15: Use Lasso when you want sparse models/feature selection; use Ridge when you want to shrink coefficients without sparsity.

Q16: What is cross-validation and why use it?
- A16: Cross-validation partitions data into folds to estimate generalization performance more reliably and for hyperparameter tuning.

Q17: How to check for influential observations?
- A17: Use leverage, Cook's distance, or DFBETAS to detect points that unduly affect the model.

Q18: What is bias-variance tradeoff?
- A18: Bias is error from incorrect assumptions (underfitting); variance is error from sensitivity to training data (overfitting). Balance via model complexity and regularization.

Q19: How to interpret coefficients after scaling?
- A19: Coefficients represent change in target per one standardized unit; their relative magnitudes indicate relative importance.

Q20: What is polynomial regression?
- A20: Extending linear regression by adding polynomial terms (e.g., x^2) to model nonlinear relationships while still using linear coefficients.

Q21: How to perform feature selection?
- A21: Use statistical tests, recursive feature elimination, regularization (Lasso), or tree-based feature importance.

Q22: What is multicollinearity's effect on p-values and confidence intervals?
- A22: It inflates standard errors, leading to wider confidence intervals and less significant p-values.

Q23: How to report model uncertainty for coefficients?
- A23: Provide standard errors, t-statistics, p-values, and confidence intervals from OLS estimates.

Q24: How to detect non-linearity in residuals?
- A24: Plot residuals vs fitted values; patterns or curvature indicate non-linearity.

Q25: What are interaction terms and when to use them?
- A25: Interaction terms model effects where the impact of one feature depends on another (e.g., x1*x2); use when domain knowledge suggests interactions.

Q26: Why is train/test split important and how to choose split ratio?
- A26: To estimate generalization; common splits are 70/30 or 80/20, but use cross-validation for more reliable estimates.

Q27: How to handle categorical variables?
- A27: Encode using one-hot/dummy variables, ordinal encoding, or target encoding depending on nature and model.

Q28: What preprocessing should not be done on the whole dataset?
- A28: Fitting scalers or encoders on the entire dataset causes data leakage — fit on training only.

Q29: How to use PCA with linear regression?
- A29: PCA reduces dimensionality and can mitigate multicollinearity; use PCA components as predictors, mindful of interpretability loss.

Q30: How to validate model assumptions?
- A30: Check residual plots, normal Q-Q plots, variance tests, multicollinearity diagnostics, and re-run models on held-out data.

Q31: Practical viva tip: how would you explain coefficient significance?
- A31: Show p-values and confidence intervals; small p-value indicates coefficient statistically different from zero under model assumptions.

Q32: How to handle outliers in features or target?
- A32: Detect via boxplots or z-scores; handle by transformation, capping, or robust models that downweight outliers.

Q33: What is robust regression?
- A33: Regression methods (e.g., Huber, RANSAC) less sensitive to outliers than OLS by using alternative loss or sampling.

Q34: How does feature engineering help linear models?
- A34: Creating interaction terms, polynomials, or domain-specific transforms can enable linear models to capture nonlinearities.

Q35: How to choose between parametric and non-parametric models?
- A35: Parametric (linear) models are interpretable and fast; non-parametric (trees, kernels) capture complex patterns but may need more data.

Q36: How to detect multivariate outliers?
- A36: Use Mahalanobis distance or leverage statistics to find points with unusual combinations of features.

Q37: What is heteroscedasticity's effect on confidence intervals?
- A37: It invalidates standard OLS variance estimates; use robust SEs to get valid intervals.

Q38: When is log-transforming the target useful?
- A38: When errors scale with magnitude or distribution is skewed; log-transform stabilizes variance and linearizes multiplicative effects.

Q39: How to interpret interaction term coefficients?
- A39: An interaction coefficient quantifies how the effect of one predictor changes per unit of another predictor.

Q40: What diagnostics plots would you show in a viva?
- A40: Residuals vs fitted, Q-Q plot, leverage vs residuals (Cook's distance), and histogram of residuals.

Q41: How to present model selection in viva?
- A41: Show candidate models, cross-validation scores, chosen metrics, and rationale for chosen model balancing performance and interpretability.

Q42: How to validate model stability across time or subgroups?
- A42: Run stratified evaluations, time-based splits, or evaluate on multiple holdout sets to ensure consistent performance.

Q43: What is the role of the intercept term in linear regression?
- A43: The intercept is the predicted target when all predictors are zero (after scaling this interpretation changes accordingly).

Q44: How to compute prediction intervals for new observations?
- A44: Use the estimated variance of residuals and parameter uncertainty to compute intervals around predictions (wider than CI for mean).

Q45: What is the difference between prediction interval and confidence interval?
- A45: Confidence interval estimates uncertainty of the mean prediction; prediction interval captures variability for individual observations (wider).

Q46: How to handle missing values in features?
- A46: Use imputation (mean/median/multivariate), model-based imputation, or remove rows/columns depending on missingness pattern.

Q47: How to choose which features to keep in final model?
- A47: Use domain knowledge, statistical significance, effect size, feature importance, and cross-validation performance.

Q48: How to explain model limitations to a non-technical audience?
- A48: Focus on predictive accuracy, uncertainty, key drivers, and caution about extrapolation beyond training data.

Q49: What ethical concerns exist when predicting housing prices?
- A49: Potential bias if features correlate with protected attributes; ensure fairness, privacy, and avoid discriminatory inputs.

Q50: Practical viva tip: if asked to improve the model quickly in an exam, what would you do?
- A50: Check data quality, add simple regularization, try a small nonlinear model (e.g., random forest), and validate on hold-out set.
