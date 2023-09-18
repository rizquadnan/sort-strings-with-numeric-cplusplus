// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int partition(std::vector<int> &arr, int low, int high)
{
  // Choose the median-of-three as the pivot
  int mid = low + (high - low) / 2;
  int pivot = arr[mid];

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
    std::swap(arr[i], arr[j]);
    i++;
    j--;
  }
  return j;
}

void quickSort(std::vector<int> &arr, int low, int high)
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

int stringToNumber(const std::string &str)
{
  std::string input = str;
  for (char &c : input)
  {
    c = std::toupper(c);
  }

  int result = 0;
  for (char c : input)
  {
    if ('A' <= c && c <= 'Z')
    {
      result = result * 27 + (c - 'A' + 1);
    }
    else
    {
      if (c == '@')
      {
        result = result * 27 + 27;
      }
    }
  }
  return result;
}

std::string numberToString(int number)
{
  std::string result = "";

  while (number > 0)
  {
    int remainder = (number - 1) % 27;
    if (remainder == 26)
    {
      result = '@' + result;
    }
    else
    {
      result = static_cast<char>(remainder + 'A') + result;
    }
    number = (number - remainder - 1) / 27;
  }

  return result;
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
  vector<int> numbers;

  // Read the file word by word using newline characters as delimiters
  string word;
  while (inputFile >> word)
  {
    // convert to number before pushing to vector
    numbers.push_back(stringToNumber(word));
  }

  // Close the file
  inputFile.close();

  int n = numbers.size();

  auto start = chrono::high_resolution_clock::now();
  quickSort(numbers, 0, n - 1);
  auto end = chrono::high_resolution_clock::now();

  // Calculating total time taken by the program.
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;

  cout << "Time taken to run code: " << time_taken << " seconds" << endl;

  // cout << "Sorted array: ";
  // for (const int &number : numbers)
  // {
  //   cout << numberToString(number) << " ";
  // }
  // cout << endl;

  return 0;
}