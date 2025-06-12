#include <iostream>
using namespace std;

class Queues {
    private:
    static const int max = 5;
    int FRONT, REAR;
    int queues_array[5];

    public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

void insert() 
    {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;

    //1. cek apakah antrian penuh
    if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) 
    {
        cout << "\nQueue overflow\n"; // 1.a
        return;// 1.b
    }
    //2. cek apakah antrian kosong
    if (FRONT == -1)
    {
        FRONT = 0; // 2.a
        REAR = 0; // 2.B
    }
    else
    {
        //jika rear berada di posisi terakhri array kembali ke awal array
        if (REAR == max - 1)
            REAR = 0;
        else
            REAR = REAR + 1;
    }
    queues_array[REAR] = num;

    }

    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queues_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display()
    {
        
    }



};