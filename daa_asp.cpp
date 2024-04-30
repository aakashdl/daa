#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare activities based on their finish times
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

// Function to find the maximum number of non-overlapping activities
std::vector<Activity> activitySelection(const std::vector<Activity>& activities) {
    std::vector<Activity> selectedActivities;
    int lastFinish = std::numeric_limits<int>::min();

    // Sort activities based on finish times
    std::vector<Activity> sortedActivities = activities;
    std::sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);

    // Iterate through sorted activities
    for (const auto& activity : sortedActivities) {
        if (activity.start >= lastFinish) {
            // Select non-overlapping activity
            selectedActivities.push_back(activity);
            lastFinish = activity.finish;
        }
    }

    return selectedActivities;
}

int main() {
    // Example input: list of activities with start and finish times
    std::vector<Activity> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9}
    };

    // Find the maximum number of non-overlapping activities
    std::vector<Activity> selectedActivities = activitySelection(activities);

    // Output the selected activities
    std::cout << "Selected Activities:\n";
    for (const auto& activity : selectedActivities) {
        std::cout << "Start: " << activity.start << ", Finish: " << activity.finish << std::endl;
    }

    return 0;
}