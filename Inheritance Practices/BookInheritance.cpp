#include <iostream>
#include <string>
using namespace std;

class publication{
private:
    string Title;
    float price;

public:
    void getdata(){
        cout << "Enter the tittle of the book:";  cin >> Title;
        cout << "Enter the Price of the book:"; cin >> price;



    }

    void putdata(){
        cout << "=== Display of Book Info === " <<endl;
        cout << "Book Title: " << Title << endl;
        cout << "Books Price: " << price << endl;

    }


};

class book : public publication {
private:
    int page_count;

public:
    void getdata(){

        publication::getdata();
        cout << "Enter the book number of pages:"; cin >> page_count;


    }

    void putdata(){
        publication::putdata();
        cout << "Books Number of Pages: " << page_count << endl;
    }


};

class tape : public book{
private:
    float playing_time;
public:
    void getdata(){
        //publication::getdata();
        book::getdata();
        cout << "Enter the book audio playing time:"; cin >> playing_time;


    }
    void putdata(){
        //publication::putdata();
        book::putdata();
        cout << "Book Playing Card: " << playing_time << endl;

    }

};

int main()
{
    publication book_1;
    book_1.getdata();
    book_1.putdata();


    tape tape_1;
    tape_1.getdata();
    tape_1.putdata();

    return 0;
}
