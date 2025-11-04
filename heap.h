//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size >= 64) {
            cout << "Error" << endl;
            return;
        }

        // Inserts new element at the end of the array
        data[size] = idx;
        // Restore heap order
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Error" << endl;
            return -1;
        }
        int minIdx = data[0];
        size--;
        data[0] = data[size];
        downheap(0, weightArr);
        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parentPos = (pos - 1) / 2;
            if (weightArr[data[parentPos]] > weightArr[data[pos]]) {
                swap(data[pos], data[parentPos]);
                pos = parentPos;
            } else break;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int minIdx = pos;
            // Pick smaller child
            if (leftChild < size && weightArr[data[leftChild]] > weightArr[data[minIdx]]) {
                minIdx = leftChild;
            }
            if (rightChild < size && weightArr[data[rightChild]] > weightArr[data[minIdx]]) {
                minIdx = rightChild;
            }
            // If child is smaller than parent, move smaller up, move continue down checking
            if (minIdx != pos) {
                swap(data[pos], data[minIdx]);
                pos = minIdx;
            } else break;
        }
    }
};

#endif