# IMDB Practical — Theory & Viva Questions

Topics: text preprocessing, TF-IDF, binary classification with a feed-forward network.

Viva Q&A:
- Q: What does TF-IDF capture?
  - A: Importance of a word in a document relative to corpus frequency; downweights common words.
- Q: Why choose `binary_crossentropy` for loss?
  - A: For binary classification with sigmoid outputs; it measures the difference between predicted probabilities and labels.
- Q: How to deal with class imbalance?
  - A: Use class weights, resampling, or evaluate with precision/recall and ROC-AUC.

Practical tips:
- Keep `max_features` tuned to avoid extremely large dense arrays.
- For larger datasets, use sparse TF-IDF matrices or streaming data pipelines.
