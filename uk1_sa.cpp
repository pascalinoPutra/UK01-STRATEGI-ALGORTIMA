#include <iostream>
#include <numeric>

using namespace std;

// fungsi untuk mencari koin palsu menggunakan divide and conquer
int searchFakeCoin(int arr[], int low, int high)
{
    // base case jika hanya ada satu koin
    if (low == high)
        return low;

    // hitung indeks tengah
    int mid = low + (high - low) / 2;

    // jika jumlah elemen di array genap, maka bagi array menjadi dua bagian sama besar
    // dan bandingkan jumlah berat di setiap bagian.
    if ((high - low + 1) % 2 == 0)
    {
        int leftSum = accumulate(arr + low, arr + mid + 1, 0);
        int rightSum = accumulate(arr + mid + 1, arr + high + 1, 0);
        if (leftSum < rightSum)
            return searchFakeCoin(arr, low, mid);
        else if (leftSum > rightSum)
            return searchFakeCoin(arr, mid + 1, high);
        else
            return -1; // jika tidak ada koin palsu
    }
    // jika jumlah elemen di array ganjil, maka bagi array menjadi dua bagian
    // dengan mempertahankan elemen palsu di satu bagian.
    else
    {
        int leftSum = accumulate(arr + low, arr + mid, 0);
        int rightSum = accumulate(arr + mid + 1, arr + high + 1, 0);
        if (leftSum < rightSum)
            return searchFakeCoin(arr, low, mid - 1);
        else if (leftSum > rightSum)
            return searchFakeCoin(arr, mid + 1, high);
        else
            return mid; // indeks koin palsu ditemukan
    }
}

int main()
{
    int n = 1001;
    int coins[n];
    for (int i = 1; i <= n; i++)
    {
        if (i == 791) // koin palsu pada indeks ke-501
            coins[i] = 4;
        else
            coins[i] = 5;
    }

    int fakeCoinIndex = searchFakeCoin(coins, 1, n - 1);

    if (fakeCoinIndex == -1)
        cout << "Tidak ada koin palsu." << endl;
    else
        cout << "Koin palsu terletak pada indeks ke-" << fakeCoinIndex << endl;

    return 0;
}
