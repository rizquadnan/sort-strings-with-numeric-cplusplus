// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

void selectionSort(std::vector<std::string> &arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      // Compare strings using '<=' to sort in non-decreasing order
      if (arr[j] <= arr[minIndex])
      {
        minIndex = j;
      }
    }

    if (minIndex != i)
    {
      std::swap(arr[i], arr[minIndex]);
    }
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
  selectionSort(words);
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