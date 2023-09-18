#include <iostream>
#include <vector>

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

int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  int n = arr.size();

  std::cout << "Original array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  quickSort(arr, 0, n - 1);

  std::cout << "Sorted array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}