#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if a page exists in the frame
bool isPageExist(vector<int>& frame, int page) {
    for (int i = 0; i < frame.size(); i++) {
        if (frame[i] == page)
            return true;
    }
    return false;
}

// Function to find the page to be replaced using FIFO
int findReplacementPage(queue<int>& fifoQueue) {
    int replacementPage = fifoQueue.front();
    fifoQueue.pop();
    return replacementPage;
}

// Function to simulate FIFO page replacement algorithm
void simulateFIFO(vector<int>& pages, int frameSize) {
    vector<int> frame;
    queue<int> fifoQueue;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];

        // If the page is not already in the frame
        if (!isPageExist(frame, currentPage)) {
            // If the frame is not full
            if (frame.size() < frameSize) {
                frame.push_back(currentPage);
            }
            else {
                int replacementPage = findReplacementPage(fifoQueue);
                for (int j = 0; j < frame.size(); j++) {
                    if (frame[j] == replacementPage) {
                        frame[j] = currentPage;
                        break;
                    }
                }
            }

            fifoQueue.push(currentPage);
            pageFaults++;
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

    // Simulate FIFO page replacement algorithm
    simulateFIFO(pages, frameSize);

    return 0;
}
