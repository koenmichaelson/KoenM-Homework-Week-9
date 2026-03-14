#include <iostream>
#include <cmath>
using namespace std;

// function protypes needed for dynamic arrays
void printArray(double arr[], int size);
void sortArray(double arr[], int size);

double mean(double arr[], int size);
double median(double sorted[], int size);
double range(double sorted[], int size);
double variance(double arr[], int size);
double stdDeviation(double arr[], int size);

void mode(double arr[], int size);


int main() {

	int size;

	cout << "Enter the number of Data Points: ";
	cin >> size;

	// creating a dynamic memory array
	double* data = new double[size];

	for (int i = 0; i < size; i++) {

		cout << "Enter value " << i + 1 << ": ";
		cin >> data[i];

	}


	// Make copy of array
	double* sorted = new double[size];

	for (int i = 0; i < size; i++) {
		sorted[i] = data[i];
	}

	sortArray(sorted, size);


	// Print Data
	cout << "Orignal Data" << endl;
	printArray(data, size);
	cout << "Sorted Data" << endl;
	printArray(sorted, size);

    // Stats to print
    cout << "\nStatistics:\n";
    cout << "Mean: " << mean(data, size) << endl;
    cout << "Median: " << median(sorted, size) << endl;
    cout << "Range: " << range(sorted, size) << endl;
    cout << "Variance: " << variance(data, size) << endl;
    cout << "Standard Deviation: " << stdDeviation(data, size) << endl;

    mode(data, size);

    // delete the not automatic variables for no memory leaks
    delete[] data;
    delete[] sorted;


	return 0;
}

void printArray(double arr[], int size) {

	for (int i = 0; i < size; i++) {

		cout << arr[i] << " ";
		
	}

	cout << endl;

}

void sortArray(double arr[], int size) {
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		double temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

double mean(double arr[], int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++) {

		sum += arr[i];

	}

	return sum / size;
}
double median(double sorted[], int size)
{
    if (size % 2 == 1)
        return sorted[size / 2];
    else
        return (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
}

double range(double sorted[], int size)
{
    return sorted[size - 1] - sorted[0];
}

double variance(double arr[], int size)
{
    double m = mean(arr, size);
    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += pow(arr[i] - m, 2);

    return sum / (size - 1);
}

double stdDeviation(double arr[], int size)
{
    return sqrt(variance(arr, size));
}

void mode(double arr[], int size)
{
    // make 2d array
    // first row is going to take the value of the data
    // second row is the frequency of that value
    int freq[2][100];
    int filled = 0;

    for (int i = 0; i < size; i++)
    {
        int index = -1;

        for (int j = 0; j < filled; j++)
        {
            if (freq[0][j] == arr[i])
            {
                index = j;
                break;
            }
        }

        if (index != -1)
            freq[1][index]++;
        else
        {
            freq[0][filled] = arr[i];
            freq[1][filled] = 1;
            filled++;
        }
    }

    int maxFreq = 0;

    for (int i = 0; i < filled; i++)
    {
        if (freq[1][i] > maxFreq)
            maxFreq = freq[1][i];
    }

    bool foundMode = false;

    cout << "Mode: ";

    for (int i = 0; i < filled; i++)
    {
        if (freq[1][i] == maxFreq && maxFreq > 1)
        {
            cout << freq[0][i] << " ";
            foundMode = true;
        }
    }

    if (!foundMode)
        cout << "None";

    cout << endl;
}