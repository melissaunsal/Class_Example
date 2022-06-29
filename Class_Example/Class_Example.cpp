
#include <iostream>
using namespace std;
class colon 
{
    int* data;
    int size;
   public:
    colon(int size = 1) : size(size)
    {
        data = new int[size];
        cout << size << "An array with elements is created." << endl;
          

    }
    //kopyalama kurucusu
    colon(const colon& c)
    {
        this->size = c.size;
        data = new int[size]; // iki farklı nesnenin aynı boyutta olması sağlandı 
        for (int i = 0; i < size; i++) 
        data[i] = c.data[i]; //datanın birinci elemanına parametre olarak gelen değere atadık
        cout << "Copy  constructor " << endl;
        //kopyalama son
    }
    //yıkıcı  çalisti ve dizi silindi
    ~colon()
    {
        delete[]data;
        cout << "The destructor function ran and the array was deleted." << endl;

    }
    void set(int indis, int value) {
        if (indis < size) {
            data[indis] = value;

        }
    

    }
    int* getData()const {
        return data;//verilen değeri sabit kalınması ve değştirimek istemiyorsak , herhangi bir değişim olmayacak

    }
    // yıkıcı son 

    int getSize()
    {
        return size;
    }
    void setSize(int size) {this->size = size;
}
    void print()const
    {
        for (int i = 0; i < size; i++)
        cout << data[i] << " ";
        cout << endl;
    }
    colon collect(const colon& c)const {
        if (size != c.size) {
            colon temp;
            temp.size = size;
            for (int i = 0; i < size; i++) {
                temp.data[i] = data[i] + c.data[i];
            }
            return temp;
        }
    }
    

};

int main()
{
    colon c(3);
    c.set(0, 5);
    c.set(1, 5);
    c.set(2, 10);
    colon c2 = c;
    c.print();
    c2.print();
    cout << endl << endl;
    (c.collect(c2)).print();

    return 0;
   
    
   // cout << c.getData()<<endl; //nesnelerin dataların farklı bellek gözlerini görmek
    //cout << c2.getData() << endl;
}
