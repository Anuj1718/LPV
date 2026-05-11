# Fashion Dataset Practical — Viva Questions & Answers (30+)

Q1: What preprocessing steps are standard for fashion image classification?
- A1: Resize, rescale pixel values, normalize, and optionally apply augmentations like flip/rotation and color jitter.

Q2: What is top-k accuracy and why use it?
- A2: Top-k accuracy counts a prediction correct if the true label is in the top k predicted probabilities; useful when multiple labels are plausible.

Q3: How to handle class imbalance in fashion categories?
- A3: Use class weights, oversample minority classes, or use focal loss to focus learning on hard examples.

Q4: Differences between one-hot and label encoding?
- A4: One-hot yields binary vector per class; label encoding assigns integer labels (not suitable for non-ordinal categories in many models).

Q5: What is transfer learning and which models are often used?
- A5: Transfer learning reuses pretrained backbones (e.g., MobileNet, ResNet, EfficientNet) and fine-tunes them on the fashion dataset.

Q6: How to evaluate model fairness when classes represent fashion types across demographics?
- A6: Analyze per-group metrics, check for biased errors, and ensure training data diversity.

Q7: How to use data augmentation responsibly?
- A7: Use realistic transforms that reflect expected variation; avoid augmentations that change label semantics.

Q8: When is multi-label classification necessary?
- A8: When items can have multiple attributes simultaneously (e.g., color + type + pattern), model outputs multiple binary labels.

Q9: How to set up a production inference pipeline for images?
- A9: Standardize preprocessing, batch inference, optimize model (quantize/prune), and serve via a REST/gRPC endpoint.

Q10: How to detect mislabeled data?
- A10: Use confusion matrices, high-loss examples, or active learning loops to surface likely mislabeled samples.

Q11: Why might transfer learning be better than training from scratch?
- A11: Pretrained models have learned generic visual features; fine-tuning needs less data and trains faster with better generalization.

Q12: How to perform hyperparameter tuning for CNNs?
- A12: Use grid/random search, Bayesian optimization, or tools like Keras Tuner across learning rate, batch size, architecture depth.

Q13: What is class activation mapping (CAM) used for?
- A13: CAM visualizes spatial regions responsible for predictions to interpret model behavior.

Q14: How to compress models for mobile deployment?
- A14: Use quantization (post-training or QAT), pruning, knowledge distillation, and architecture optimization.

Q15: What is knowledge distillation?
- A15: Training a smaller student model to mimic a larger teacher model's outputs to retain performance with fewer parameters.

Q16: How to measure model robustness to occlusion and noise?
- A16: Evaluate on perturbed validation sets with occlusions, noise, and domain shifts to measure degradation.

Q17: Why use stratified splits for train/validation/test?
- A17: To preserve class proportions across splits and ensure balanced evaluation.

Q18: How to use ensemble methods for image classification?
- A18: Average predictions from multiple models or use stacking to improve accuracy and robustness.

Q19: How to interpret confusion matrices for closely related fashion classes?
- A19: High off-diagonal values indicate confusion; inspect samples and consider merging or refining class definitions.

Q20: What are common data augmentation techniques for clothing images?
- A20: Random flips, rotations, scale, translation, color jitter, random cropping, and mixup/cutmix.

Q21: How to choose input resolution for CNNs?
- A21: Based on trade-off between preserving discriminative details and computational limits; validate performance vs cost.

Q22: How to debug exploding/vanishing gradients in CNN training?
- A22: Check learning rate, weight initialization, use BatchNorm, adjust architecture depth, or use gradient clipping.

Q23: What metrics to monitor during training besides accuracy?
- A23: Loss, validation loss, per-class precision/recall, F1-score, and training time per epoch.

Q24: What is mixup and why use it?
- A24: Mixup linearly combines pairs of images and labels to regularize the model and improve robustness.

Q25: How to perform dataset versioning and reproducibility?
- A25: Use dataset snapshots, record preprocessing steps, and track random seeds and environment details.

Q26: What is the role of the validation set versus test set?
- A26: Validation is for model/hyperparameter tuning; test is for final unbiased performance evaluation.

Q27: How to reduce inference latency when serving models?
- A27: Batch requests, use model acceleration libraries (TensorRT), and reduce model size via quantization.

Q28: When to use metric learning for fashion retrieval tasks?
- A28: For similarity search and retrieval, metric learning (triplet loss, contrastive loss) learns embedding spaces where similar items are close.

Q29: How to adapt models to new fashion seasons or styles?
- A29: Use continual learning, fine-tuning on new labeled data, or active learning to label new examples.

Q30: Practical viva tip: how to present model performance improvements?
- A30: Show validation curves, ablation studies isolating changes, and evaluation on a consistent test set with metrics and visual examples.
