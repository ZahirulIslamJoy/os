#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a page exists in the frame
bool isPageExist(vector<int>& frame, int page) {
    return find(frame.begin(), frame.end(), page) != frame.end();
}

// Function to perform LFU page replacement
void simulateLFU(vector<int>& pages, int frameSize) {
    vector<int> frame;
    vector<int> pageFrequency;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];
        bool pageFound = isPageExist(frame, currentPage);

        // If the page is not already in the frame
        if (!pageFound) {
            // If the frame is full
            if (frame.size() == frameSize) {
                int leastFrequentPage = frame[0];
                int minFrequency = pageFrequency[0];

                // Find the least frequently used page
                for (int j = 1; j < frame.size(); j++) {
                    if (pageFrequency[j] < minFrequency) {
                        leastFrequentPage = frame[j];
                        minFrequency = pageFrequency[j];
                    }
                }

                // Replace the least frequently used page
                auto it = find(frame.begin(), frame.end(), leastFrequentPage);
                *it = currentPage;
                pageFrequency[it - frame.begin()] = 1;
            } else {
                // Add the page to the frame
                frame.push_back(currentPage);
                pageFrequency.push_back(1);
            }

            pageFaults++;
        } else {
            // Increment the frequency of the existing page
            int index = find(frame.begin(), frame.end(), currentPage) - frame.begin();
            pageFrequency[index]++;
        }

        // Display the current frame
        cout << "Page: " << currentPage << " | Frame: ";
        for (int j = 0; j < frame.size(); j++) {
            cout << frame[j] << " ";
        }
        cout << endl;
    }

    cout << "Total page faults: " << pageFaults << endl;
}

int main() {
    int frameSize;
    vector<int> pages;

    // Read the frame size
    cout << "Enter the frame size: ";
    cin >> frameSize;

    // Read the pages (enter -1 to stop)
    cout << "Enter the pages (enter -1 to stop): ";
    int page;
    while (cin >> page && page != -1) {
        pages.push_back(page);
    }

    // Simulate LFU page replacement algorithm
    simulateLFU(pages, frameSize);

    return 0;
}
