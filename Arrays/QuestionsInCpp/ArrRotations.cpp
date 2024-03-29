/*
  ------MENU DRIVEN--------
PROGRAM TO ROTATE THE ARRAY LEFT AND RIGHT BY ONE BIT,INCLUDES BRUTE FORCE APPROACAH WITH IT's TIME COMPLEXCITES

ALSO CONATIANS THE OPTIAML SOUTLION TO ROTATE THE ARRAY BY 'D' PLACES WITH OPTIMAL TIME COMPLEXCITY

PROGRMA ALSO CONTAINS THE CODE TO MOVE ALL THE ARRAY ZEROS TO END OF ARRAY HAS BRUTE AND OPTIMAL SOULTION WITH THEIR TIME COMPLEXCITIES
*/

#include <iostream>
using namespace std;

class ArrayOperations
{
public:
    // function to take input
    void read(int arr[], int n)
    {
        cout << "Enter the array elements : ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // function to display
    void display(int arr[], int n)
    {
        cout << "Array elements after rotation : ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    // Left rotation of an array by one position  BRUTE FROCE approach time complex = O(n)
    void leftRotate(int arr[], int n)
    {
        int temp = arr[0];
        for (int j = 0; j < n; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;

        // to print the array
        display(arr, n);
    }

    // right rotaion of an array BRUTE FORCE APPROACH time complex -- O(n)
    void RightRotate(int arr[], int n)
    {
        int lastElement = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = lastElement;
        // to print the array
        display(arr, n);
    }

    //  left rotaion of an array by 'd' places  BRUTE FORCE METHOD
    void LeftRotation(int arr[], int d, int n)
    {
        d = d % n;
        int *temp = new int[d];

        // loop to add the d number of elements to temp
        for (int i = 0; i < d; i++)
        {
            temp[i] = arr[i];
        }

        // loop to shift the elements
        for (int j = d; j < n; j++)
        {
            arr[j - d] = arr[j];
        }

        // loop to add back the temp elements to main array
        for (int i = (n - d); i < n; i++)
        {
            arr[i] = temp[i - (n - d)];
        }

        delete[] temp;
    }

    // OPTIMAL SOLUTION TO ROTATE THE ARRAY BY 'D' PLACES WITH OPTIMAL TIME COMPLEXCTY -- O(N)

    // supproting function ....
    void reverse(int arr[], int start, int end)
    {
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    // main OPTIMAL SOLUTION FUNCTION
    void optimalLeftRotation(int arr[], int d, int n)
    {
        d = d % n;
        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);

        display(arr, n);
    }

    // brute force approch to move all non zero elements at the last of an array
    void moveZero(int arr[], int n)
    {
        int *temp = new int[n];

        int tempSize = 0;

        // loop to add non zero elements to temp array
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
                temp[tempSize++] = arr[i];
        }
        // add back the temp array elements to array
        for (int i = 0; i < tempSize; i++)
        {
            arr[i] = temp[i];
        }

        // add zero to remaning space
        for (int i = tempSize; i < n; i++)
        {
            arr[i] = 0;
        }
        display(arr, n);
    }

    // optimal approach to move all zeros at the end

    void optimalMoveZero(int arr[], int n)
    {
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;
        //
        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        display(arr, n);
    }
};

int main()
{
    ArrayOperations arr;
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;

    int a[n];
    int choice;
    do
    {
        cout << "\nMENU\n";
        cout << "1. To read the array elements\n";
        cout << "2. Rotations of an array by one bit\n";
        cout << "3.To rotate the array by d place\n";
        cout << "4.Move all zero to end of a array\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr.read(a, n);
            break;

        case 2:
            cout << "Right Rotation : ";
            arr.RightRotate(a, n);
            cout << "\nLeft Rotation : ";
            // arr.leftRotate(a, n);
            break;
        case 3:
            int d;
            cout << "Enter the d value to rotate the array : ";
            cin >> d;
            arr.optimalLeftRotation(a, d, n);
            break;
        case 4:
            arr.optimalMoveZero(a, n);
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 5); // Adjusted loop condition to match menu options

    return 0;
}
