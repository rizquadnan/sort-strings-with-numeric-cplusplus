// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Function to partition the vector of strings into two sub-vectors
int partition(vector<string> &arr, int low, int high)
{
  // Choose the median-of-three as the pivot
  int mid = low + (high - low) / 2;
  string pivot = arr[mid];

  // Rearrange elements so that pivot is in its correct position
  int i = low;
  int j = high;
  while (true)
  {
    while (arr[i] < pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i >= j)
    {
      break;
    }
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
  return j;
}

// Function to perform Quick Sort on a vector of strings
void quickSort(vector<string> &arr, int low, int high)
{
  if (low < high)
  {
    // Partition the vector into two sub-vectors and get the pivot index
    int pivotIndex = partition(arr, low, high);

    // Recursively sort the sub-vectors
    quickSort(arr, low, pivotIndex);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main(int argc, char *argv[])
{
  string file_name = argv[1];

  // Specify the path to your input text file
  string source = file_name + ".txt";

  cout << "Dataset soure: " << source << endl;

  // Open the file for reading
  ifstream inputFile(source);

  if (!inputFile.is_open())
  {
    cerr << "Error: Unable to open the file." << endl;
    return 1;
  }

  // Create a vector to store the words
  vector<string> words;

  // Read the file word by word using newline characters as delimiters
  string word;
  while (inputFile >> word)
  {
    // Store the word in the vector
    words.push_back(word);
  }

  // Close the file
  inputFile.close();

  int n = words.size();

  auto start = chrono::high_resolution_clock::now();
  quickSort(words, 0, n - 1);
  auto end = chrono::high_resolution_clock::now();

  // Calculating total time taken by the program.
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;

  cout << "Time taken to run code: " << time_taken << " seconds" << endl;

  // cout << "Sorted array: ";
  // for (const string &str : words)
  // {
  //   cout << str << " ";
  // }
  // cout << endl;

  return 0;
}