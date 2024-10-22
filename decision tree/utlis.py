import pandas as pd
import numpy as np


def entropy(y):
    # Count the occurrences of each class label
    class_counts = np.bincount(y)
    # Calculate probabilities
    probabilities = class_counts / len(y)
    # Compute entropy
    entropy_value = -np.sum([p * np.log2(p) for p in probabilities if p > 0])
    return entropy_value


def information_gain(X, y, feature_index):
    # Calculate the entropy of the original dataset
    entropy_before = entropy(y)
    # Get the unique values of the feature
    values, counts = np.unique(X[:, feature_index], return_counts=True)

    # Calculate the weighted entropy after splitting
    weighted_entropy_after = 0
    for i, v in enumerate(values):
        # Subset of data where feature == value
        subset = y[X[:, feature_index] == v]
        weighted_entropy_after += (counts[i] /
                                   np.sum(counts)) * entropy(subset)

    # Calculate information gain
    info_gain = entropy_before - weighted_entropy_after
    return info_gain


def find_best_split(data, feature):
    # Sort the data by the feature
    sorted_data = data.sort_values(by=feature)

    # Initialize variables to track the best split
    best_threshold = None
    best_info_gain = -1  # Negative value for initial comparison

    # Loop through sorted data and find thresholds between values
    for i in range(1, len(sorted_data)):
        # Calculate the candidate threshold as the midpoint between consecutive values
        threshold = (sorted_data[feature].iloc[i-1] +
                     sorted_data[feature].iloc[i]) / 2

        # Split the data based on this threshold
        left_subset = sorted_data[sorted_data[feature] <= threshold]
        right_subset = sorted_data[sorted_data[feature] > threshold]

        # Calculate information gain for this split
        info_gain = calculate_information_gain(data, left_subset, right_subset)

        # If this split is better, update the best threshold
        if info_gain > best_info_gain:
            best_info_gain = info_gain
            best_threshold = threshold

    return best_threshold, best_info_gain


def calculate_information_gain(parent, left_child, right_child):
    # Calculate parent entropy
    parent_entropy = entropy(parent)

    # Calculate weighted child entropies
    left_weight = len(left_child) / len(parent)
    right_weight = len(right_child) / len(parent)

    weighted_child_entropy = left_weight * \
        entropy(left_child) + right_weight * entropy(right_child)

    # Information gain is parent entropy minus weighted child entropy
    return parent_entropy - weighted_child_entropy


# Example use for continuous variable 'Age'
best_threshold, info_gain = find_best_split(data, 'Age')


def continousData(df):
    numericalColumns = df.select_dtypes(include=np.number).columns
    for i in numericalColumns:
        maxVal = df[i]
