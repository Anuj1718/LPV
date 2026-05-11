# IMDB Practical — Viva Questions & Answers (30+)

Q1: What steps are involved in text preprocessing?
- A1: Lowercasing, removing HTML, removing non-alphabetic characters, tokenization, stopword removal, and optionally stemming/lemmatization.

Q2: What is tokenization?
- A2: Tokenization splits text into meaningful units (words, subwords, or characters) for downstream processing.

Q3: Difference between stemming and lemmatization?
- A3: Stemming heuristically trims word endings; lemmatization uses vocabulary and morphological analysis to return base forms.

Q4: What is TF-IDF and why use it?
- A4: TF-IDF weights terms by frequency in a document and inverse frequency in corpus to highlight informative words.

Q5: When to use embeddings over TF-IDF?
- A5: Use embeddings when semantic relationships and context matter, or when using neural networks that can exploit dense vectors.

Q6: What is the Out-Of-Vocabulary (OOV) problem?
- A6: OOV occurs when new tokens at inference were not seen during training; handle by using subword tokenization or reserving an OOV token.

Q7: How to choose `max_features` for TF-IDF?
- A7: Balance memory and informativeness — choose via validation; common values range from a few thousand to tens of thousands.

Q8: Why use `binary_crossentropy` for binary classification?
- A8: It measures the difference between predicted probabilities and actual binary labels and suits sigmoid outputs.

Q9: How to evaluate text classifiers beyond accuracy?
- A9: Use precision, recall, F1-score, confusion matrix, ROC-AUC, and class-specific metrics.

Q10: How to handle class imbalance in sentiment datasets?
- A10: Use class weights, resampling, synthetic examples (SMOTE for text is hard), or adjust thresholds based on precision/recall trade-offs.

Q11: What is n-gram modeling and when to use it?
- A11: N-grams capture local sequences of tokens (bigrams, trigrams) useful for phrases; increases feature dimensionality.

Q12: What is sequence padding and why is it needed?
- A12: Padding makes variable-length sequences uniform length for batch training in neural networks.

Q13: How to convert TF-IDF features to input for Keras?
- A13: TF-IDF produces dense (or sparse) numeric arrays; convert to numpy arrays (`toarray()`) before feeding to Keras MLPs.

Q14: What is embedding layer and how does it differ from TF-IDF?
- A14: Embedding maps tokens to dense vectors learned during training, capturing semantics; TF-IDF is a sparse, frequency-based representation.

Q15: When to use transfer learning (pretrained language models)?
- A15: Use pretrained models like BERT when dataset is small or when contextual understanding significantly improves performance.

Q16: How to prevent overfitting in neural text classifiers?
- A16: Use dropout, regularization, smaller architectures, early stopping, and augmentation via synonym replacement.

Q17: What is word-level vs character-level modeling?
- A17: Word-level models use word tokens; character-level models use characters and can handle misspellings and OOV but need larger models.

Q18: How to handle very long documents?
- A18: Truncate to a max length, use hierarchical models, or extract salient passages via heuristics.

Q19: What is out-of-domain data and its effect?
- A19: Out-of-domain data differs from training distribution and degrades model performance; consider domain adaptation.

Q20: How to interpret false positives and negatives for sentiment?
- A20: False positives predict positive when negative — inspect labeling quality, sarcasm, negation handling, and ambiguous language.

Q21: What hyperparameters are commonly tuned?
- A21: Learning rate, batch size, number of epochs, architecture sizes (hidden units), regularization strength, and vocabulary size.

Q22: What role does batch size play in training?
- A22: Smaller batches produce noisier gradient estimates (sometimes better generalization) and affect memory usage and training speed.

Q23: How to perform model explainability for text classifiers?
- A23: Use LIME, SHAP, or attention weights to highlight words that influenced predictions.

Q24: How to save and load a TF-IDF vectorizer and model?
- A24: Persist the vectorizer with `pickle`/joblib and save the Keras model with `model.save()`; load both at inference.

Q25: What is early stopping and why use it?
- A25: Early stopping halts training when validation performance stops improving to avoid overfitting.

Q26: How to perform cross-validation with text data?
- A26: Use stratified K-fold (preserving label ratios) with proper preprocessing performed inside each fold to avoid leakage.

Q27: Why might TF-IDF lead to very high memory usage?
- A27: TF-IDF with large vocabularies produces large dense arrays; use sparse representations or reduce `max_features`.

Q28: What is subword tokenization (e.g., Byte-Pair Encoding)?
- A28: Subword methods split words into frequent subunits to handle rare words and reduce OOV by composing words from subwords.

Q29: How to build a production API for sentiment analysis?
- A29: Save model and vectorizer, create an API endpoint that preprocesses input, vectorizes text, and returns predicted label and confidence.

Q30: What are common pitfalls in NLP pipelines?
- A30: Data leakage, improper preprocessing order, using test data for hyperparameter tuning, and ignoring class imbalance.

Q31: Practical viva tip: how to explain embedding dimensions?
- A31: Embedding dimension is a hyperparameter controlling vector size; too small may underfit semantics, too large increases parameters and risk of overfitting.
