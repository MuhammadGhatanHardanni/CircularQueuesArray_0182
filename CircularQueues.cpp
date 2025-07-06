/**
 * @mainpage Dokumentasi Project Queue
 *
 * @addsecction introducton
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular array.
 *
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. insert
 * 2. delete
 * 3. display
 *
 * @section Cara penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 *
 *
 *
 * @author Muhammad Ghatan hardanni
 * @section Profile
 * - Nama : Muhammd Ghatan Hardanni
 * - nim : 20240140182
 * - kelas : D
 * @brief
 * @version 0.1
 * @date 2025-06-23
 *
 * @copyright Ghatan@umy.ac.id (c) 2025
 *
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 *
 *
 */

class queues
{
private:
    static const int max = 5; ///< variable private max untuk menyimpan ukuran pada antrian
    int front;                ///< variable private front untuk menyimpan posisi depan pada antrion
    int rear;                 ///< variable private rear untuk menyimpan posisi belakang pada antrion
    int queue_array[5];       ///< variable private queue_array untuk menyimpan elemen pada antrian

public:
    /**
     * @brief Construct a new queues object
     * Set default queues null
     * with front = -1 and rear = -1
     */
    queues()
    {
        front = -1;
        rear = -1;
    }
    /**
     * @brief Method untuk memasukkan data ke dalam antrian
     * Data dimasukkan dalam variabel queue_array
     */
    void insert()
    {
        int num; ///< variabel num untuk menyimpan nilai yang akan dimasukkan ke dalam antrian
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == -1)
                rear = 0;
            else
                rear = rear + 1;
        }
        queue_array[rear] = num;
    }

    /**
     * @brief Method untuk menghapus data dari antrian
     * Data yang dihapus adalah data pada posisi depan antrian
     */
    void remove()
    {
        if (front == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == max - 1)
                front = 0;
            else
                front = front + 1;
        }
    }
    /**
     * @brief Method untuk menampilkan data dalam antrian
     * Data yang ditampilkan adalah data pada posisi depan hingga belakang antrian
     */
    void display()
    {
        int front_position = front; ///< menyimpan posisi depan antrian
        int rear_position = rear;   ///< menyimpan posisi belakang antrian

        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElements in the queue are: ";

        if (front_position <= rear_position)
        {
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            cout << endl;
        }
        else
        {
            while (front_position <= max - 1)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            front_position = 0;

            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief Fungsi untuk menjalankan program
 *
 * @return int
 */
int main()
{
    queues q; ///< membuat objek q dari class queues
    char ch;  ///< variabel ch untuk menyimpan pilihan menu

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
