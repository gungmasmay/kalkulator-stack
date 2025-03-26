#include<stdio.h>
#include<stdlib.h>

#define KAPASITAS 5

typedef struct {
    int data[KAPASITAS];
    int front;
    int rear;
} Queue;

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->rear == KAPASITAS;
}

void enqueue(Queue *q, int element)
{
    if(isFull(q))
    {
        printf("QUEUE PENUH\n");
    }
    else
    {
        q->data[q->rear] = element;
        q->rear++;
        printf("%d telah ditambahkan dalam queue\n", element);
    }
}

void dequeue(Queue *q)
{
    int i, ele;
    if(isEmpty(q))
    {
        printf("QUEUE KOSONG\n");
    }
    else
    {
        ele = q->data[q->front];
        printf("%d telah dihapus\n", ele);
        for(i = 0; i < q->rear-1; i++)
            q->data[i] = q->data[i+1];
        q->rear--;
    }
}

void tampilkan(Queue *q)
{
    int i;
    if(isEmpty(q))
    {
        printf("QUEUE KOSONG\n");
    }
    else
    {
        printf("Isi Queue: ");
        for(i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

void cari(Queue *q, int element)
{
    int i;
    for(i = q->front; i < q->rear; i++)
    {
        if(q->data[i] == element)
        {
          printf("Angka %d ditemukan pada posisi ke-%d\n", element, i + 1);
          return;
        }
    }
    printf("Angka %d tidak ditemukan dalam queue\n", element);
}

void edit(Queue *q, int anklama, int ankbaru)
{
    int i;
    for(i = q->front; i < q->rear; i++)
    {
        if(q->data[i] == anklama)
        {
          q->data[i] = ankbaru;
          printf("Angka %d telah diganti menjadi %d\n", anklama, ankbaru);
          return;
        }
    }
    printf("Angka %d tidak ditemukan dalam queue\n", anklama);
}

void operasi(Queue *q)
{
    if(isEmpty(q))
    {
        printf("QUEUE KOSONG\n");
        return;
    }
    int i, total = 0, min = q->data[q->front], max = q->data[q->front];
    float rata;
    
    for(i = q->front; i < q->rear; i++)
    {
        total += q->data[i];
        if(q->data[i] > max)
            max = q->data[i];
        if(q->data[i] < min)
            min = q->data[i];
    }
    
    rata = (float)total / (q->rear - q->front);
    printf("Nilai Total \t: %d\n", total);
    printf("Rata-rata \t: %.2f\n", rata);
    printf("Nilai Terbesar \t: %d\n", max);
    printf("Nilai Terkecil \t: %d\n", min);
}

int main()
{
    system("cls");
    Queue q;
    q.front = 0;
    q.rear = 0;
    int pil, ele, lama, baru;
    while(1)
    {
        printf("======================================\n");
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Hapus\n");
        printf("3. Tampilkan\n");
        printf("4. Cari\n");
        printf("5. Edit\n");
        printf("6. Operasi Perhitungan\n");
        printf("7. Keluar\n");
        printf("======================================\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pil);
        system("cls");
        
        switch(pil)
        {
            case 1: 
                printf("Tambahkan angka: ");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;
            case 2: 
                dequeue(&q);
                break; 
            case 3:
                tampilkan(&q);
                break;
            case 4: 
                printf("Masukkan angka yang ingin dicari: ");
                scanf("%d", &ele);
                cari(&q, ele);
                break;
            case 5:
                printf("Masukkan angka yang ingin di edit: ");
                scanf("%d", &lama);
                printf("Masukkan angka baru: ");
                scanf("%d", &baru);
                edit(&q, lama, baru);
                break;
            case 6:
                operasi(&q);
                break;
            case 7: 
                exit(0);
            default: 
                printf("Pilihan tidak tersedia\n");
        }
    }
    return 0;
}
