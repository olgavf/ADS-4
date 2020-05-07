#include <iostream>
using namespace std;

#include <cassert>

template<typename N>
class TPQueue
{
private:
    N *arr;          // массив с данными
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin;       // начало очереди
    int end;         // конец очереди
    int countt;       // счетчик элементов
public:
    TPQueue(int =100);          // конструктор по умолчанию
    ~TPQueue();                 // деструктор

    void push(const N &); // добавить элемент в очередь
    N pop();              // удалить элемент из очереди
    N get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
};

// конструктор по умолчанию
template<typename N>
TPQueue<N>::TPQueue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), end(0), countt(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new N[size + 1];
}

// деструктор класса Queue
template<typename N>
TPQueue<N>::~TPQueue()
{
    delete [] arr;
}


// функция добавления элемента в очередь
template<typename N>
void TPQueue<N>::push(const N & item)
{
    // проверяем, ести ли свободное место в очереди
    assert( count < size );

    arr[end] = item;

    for (int i = end; i > 0; i--)
    {
        if (arr[i].prior > arr[i-1].prior)
        {
            N tmp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = tmp;
        }
    }


    countt++;
    end++;

    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}

// функция удаления элемента из очереди
template<typename N>
N TPQueue<N>::pop()
{
    // проверяем, есть ли в очереди элементы
    assert( countt > 0 );

    N item = arr[begin++];
    countt--;

    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди

    return item;
}

// функция чтения элемента на первой позиции
template<typename N>
N TPQueue<N>::get() const 
{
    // проверяем, есть ли в очереди элементы
    assert( countt > 0 );
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename N>
bool TPQueue<N>::isEmpty() const
{
  return countt==0;
}

// функция проверки очереди на заполненность
template<typename N>
bool TPQueue<N>::isFull() const
{
  return countt==size;
}

struct SYM
{
	char ch;
	int prior;
};
