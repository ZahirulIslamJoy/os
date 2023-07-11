#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Function to check if a page exists in the frame
bool isPageExist(list<int>& frame, int page) {
    for (auto it = frame.begin(); it != frame.end(); it++) {
        if (*it == page)
            return true;
    }
    return false;
}

// Function to perform LRU page replacement
void simulateLRU(vector<int>& pages, int frameSize) {
    list<int> frame;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];

        // If the page is not already in the frame
        if (!isPageExist(frame, currentPage)) {
            // If the frame is full
            if (frame.size() == frameSize) {
                int leastRecentPage = frame.back();
                frame.pop_back();
                // cout << "Page " << leastRecentPage << " evicted" << endl;
            }

            frame.push_front(currentPage);
            pageFaults++;
        }
        // If the page is already in the frame
        else {
            frame.remove(currentPage);
            frame.push_front(currentPage);
        }

        // Display the current frame
        cout << "Page: " << currentPage << " | Frame: ";
        for (auto it = frame.rbegin(); it != frame.rend(); it++) {
            cout << *it << " ";
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

    // Simulate LRU page replacement algorithm
    simulateLRU(pages, frameSize);

    return 0;
}
