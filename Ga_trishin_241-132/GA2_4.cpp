#include <iostream>

void sort(int numbers[], size_t start, size_t end)
{
    if (start >= end)
        return;
    size_t current{ start };
    for (size_t i{ start + 1 }; i <= end; i++)
    {
        if (numbers[i] < numbers[start])
        {
            swap(numbers, ++current, i);
        }
    }
    swap(numbers, start, current);
    if (current > start)
    {
        sort(numbers, start, current - 1);
    }
    if (end > current + 1)
    {
        sort(numbers, current + 1, end);
    }
}

void swap(int numbers[], size_t first, size_t second)
{
    auto temp{ numbers[first] };
    numbers[first] = numbers[second];
    numbers[second] = temp;
}

int main()
{
    int nums[1000];
    for (int i = 0; i < 1000; i++) {
        cin >> nums[i];
    }
    sort(nums, 0, std::size(nums) - 1);
    for (auto num : nums)
    {
        std::cout << num << "\t";
    }
    std::cout << std::endl;
}


