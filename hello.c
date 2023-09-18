#include <iostream>
#include <chrono>

int main()
{
  // Start the timer
  auto start = std::chrono::high_resolution_clock::now();

  // Your code to measure goes here
  // For example, a time-consuming loop:
  for (int i = 0; i < 1000000; i++)
  {
    // Some code to run
  }

  // Stop the timer
  auto stop = std::chrono::high_resolution_clock::now();

  // Calculate the duration in milliseconds
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

  std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}