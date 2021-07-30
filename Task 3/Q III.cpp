#include <bits/stdc++.h>

using namespace std;

/*
  Program for Question III - Digging Gold Loops

  Variant used: 18 -> reverse order of 4

  Student info:
    Name: Horizon Chaser
    ID: [ERASED]

  Algorithm:
    1. get n as input from the user
    2. dynamically allocate memory for the matrix
    3. generate the matrix by filling with random number
    4. display the matrix
    5. generate and store coordinates of the points on the required loop in a list A
    6. traverse all the coordinates in A, and store corresponding value it points to in another list B
    7. sort the list B ascendingly
    8. traverse all the coordinates (named currPos) in A and values (named currVal) in B ,
       and store currVal to where currPos points to inside the matrix
    9. display the changed matrix and exit
*/

// the data structure used to store coordinates of elements in matrix
class Point {
   public:
    int x, y;

    Point(int xx, int yy) {
        this->x = xx;
        this->y = yy;
    }
};

// the list which holds coordinates of all points on the required loop
vector<Point *> path;

// the two-dimension matrix, as a two level pointer
int **mat = NULL;  // now it's uninitialized, so it should be NULL

/**
 * print elements of the matrix
 * @param matPointer a two-level pointer to the matrix
 * @param n size of the matrix
 */
void printMatrix(int **matPointer, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matPointer[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * generate the path of required variant - reverse of variant 4
 * @param n size of the matrix
 */
void generatePath(int n) {
    for (int x = 0; x < n / 2 + 1; ++x) { // path 5
        path.push_back(new Point(x, x));
    }
    for (int i = n / 2 + 1; i < n; i++) {// path 8
        path.push_back(new Point(i, n / 2));
    }
    for (int j = n / 2 - 1; j >= 0; j--) {// path 3
        path.push_back(new Point(n - 1, j));
    }
    for (int i = n - 2; i > 0; i--) {// path 4
        path.push_back(new Point(i, 0));
    }
}

int main() {
    cout << "Question III - Digging Gold Loops" << endl;
    cout << "Please input the size of the matrix (must be odd) first," << endl;
    cout << "then the elements and their indices on a given loop would be printed, \nand then sorted and printed, " << endl;
    cout << "finally the changed matrix would be printed" << endl;
    cout << "\nPlease input the size of the matrix: " << flush;

    // size of the matrix
    int n = 2;
    // loop until we get an odd size as required
    while (!(n % 2)) {
        cin >> n;
        if (!(n % 2)) {
            cout << "the matrix size must be odd, while the input " << n << " doesn't match..." << endl;
            system("pause");
        }
    }

    // dynamically allocate the memory for the matrix
    // as the matrix has two dimensions,
    // the first dimension should be an array of pointers, elements of which points to an array of int
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    // set the seed for the random number generator using current time
    // and fill the matrix with random value ranging from 10 to 81
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand() % 72 + 10;
        }
    }

    cout << endl << "The Matrix Generated:" << endl;
    printMatrix(mat, n);
    system("pause");
    cout << endl;

    int pathVar = -1, inputPathVar = 18; // my number is 18
    int isReversed = 0;

    // map the input variant to an existing one,
    // and determine whether reversing list A (vector path) is needed
    if (inputPathVar > 28) {
        pathVar = inputPathVar % 28 + 1;
        cout << "My number is " << inputPathVar << ", therefore it has been mapped to " << pathVar << " with n%28+1"
             << endl;
    } else {
        pathVar = inputPathVar;
    }
    if (pathVar > 14 && pathVar < 29) {
        cout << "My number is " << pathVar << ", and the reversed path of variant " << pathVar - 14 << " will be used" << endl;
        pathVar -= 14;
        isReversed = 1;
    }

    generatePath(n);
    if (isReversed) {
        // reverse the path list
        // note that the start point shouldn't be changed
        reverse(path.begin() + 1, path.end());
    }

    cout << endl
         << "Elements and their indices of the required loop:" << endl;
    vector<int> sortList;
    for (unsigned int i = 0; i < path.size(); i++) {
        // print coordinates of elements on the loop
        // and store their value in list B (vector sortList)
        Point *currPoint = path[i];
        sortList.push_back(mat[currPoint->x][currPoint->y]);
        cout << "a[" << currPoint->x << "][" << currPoint->y << "] = " << mat[currPoint->x][currPoint->y] << endl;
    }
    system("pause");

    // sort the list using the library function
    sort(sortList.begin(), sortList.end());
    for (unsigned int i = 0; i < path.size(); i++) {
        // sort elements on the given loop
        mat[path[i]->x][path[i]->y] = sortList[i];
    }

    cout << endl << "Now the matrix has been changed to:" << endl;
    printMatrix(mat, n);
    system("pause");

    return 0;
}