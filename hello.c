#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
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

int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};

  std::cout << "Original array:";
  for (int num : arr)
  {
    std::cout << " " << num;
  }
  std::cout << std::endl;

  selectionSort(arr);

  std::cout << "Sorted array:";
  for (int num : arr)
  {
    std::cout << " " << num;
  }
  std::cout << std::endl;

  return 0;
}
