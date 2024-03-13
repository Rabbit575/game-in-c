/*
Ini adalah program game sedehana menggunakan bahasa c,
peraturannya sederhana yaitu jika player yang bersimbol "0" bersentuhan dengan
target yang bersimbol "v" maka skor bertambah, jika player tidak dapat
menangkap target maka player kalah, hope you enjoyed :3 
*/

//made by rasyid
//semoga mudah dipahami:)

#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//variabel x dan y sebagai player
int x, y, score;
int i , j, o, replay;
//variabel targety dan targetx sebagai target
int targety, targetx;
int gameovers;


/*function starts mengisi nilai awal, y diisi 30 maka player akan selalu
berada di posisi bawah, x diisi 10 adalah posisi awal player*/

void Starts()
{
    x = 10;
    y = 30;
    o = 1;
    score = 0;
    targety = 0;
}

/*function berikut berfungsi membaca input keyboard,
jika user memencet a maka nilai x akan berkurang dan 
jika user memencet d maka nilai x akan bertambah, sedangkan 
c berfungsi untuk menghentikan permainan(lihat fungsi Event dan playandReplay).
Nilai x berisi informasi tentang koordinat player(0), jika x berkurang player akan 
bergerak kekiri jika x bertambah maka akan terjadi sebaliknya*/

void Hit()
{

    if (kbhit())
    {
        switch (getch())
        {
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'c':
                o = 0;
                printf("\n");
                printf ("Quitted...");
                break;
        }
        
    }
}

/*function ini mengulang nilai i secara horizontal dan nilai j secara vertikal
, menampilkan player yaitu huruf "0" jika nilainya sama dengan i dan j, 
menampilkan target yaitu huruf "v" jika nilainya sama dengan i dan j,
jika keduanya bernilai tidak sama dengan i dan j maka ditampilkan whitespace*/

void Event()
{
    Starts();
    
    targety = 0;
    while (o)
    {
        //kecepatan game
        sleep(0.1);
        //target akan terus kebawah
        targety += 1;
        system("cls");
        for (i = 0; i < 40; i++)
        {
            for(j = 0; j < 20; j++ )
            {
                if (j == x && i == y)
                    printf("0");
                else if (targetx == j && targety == i)
                    printf("v");
                else 
                    printf(" ");
                
                //mengacak posisi target pada sumbu horizontal dan menambah skor
                if (targetx == x && targety == y)
                {
                    srand(time(NULL));
                    targetx = rand() %20;
                    score++;
                    targety = 0;
                }
            }
            printf("\n");
        }
            
        //menampilkan skor
        printf("\n");
        printf("score = %d \n", score );
        printf("press c to exit \n");

        //membuat player tidak bisa keluar dari area yang ditentukan
        if (x < 0)
            x = 0;
        else if (x > 19)
            x = 19;

        //jika target sudah melebihi nilai yang ditentukan maka player dikalahkan
        if (targety > 31)
        {
            printf("GameOver \n");
            break;
        }

        Hit();
    }
}

//function untuk memulai, memulai ulang dan mengakhiri permainan
void PlayandReplay()
{
    replay = 0;
    //memulai permainan dengan memanggil fungsi Event
    Event();
    if ( o == 1)
    {
        //jika user mengenter angka 1 maka permainan akan dimulai ulang
        printf("Ingin mengulang(1) : ");
        scanf ("%d", & replay);
        if (replay == 1)
        {
            PlayandReplay();
        }
        //jika player menekan yang lain maka permainan selesai
        else
        {
            return;
        }
        }
        else if (o == 0)
    {
        return;
    }
}

//function utama untuk menjalankan setiap permainan
int main()
{
    PlayandReplay();
    return 0;
}
