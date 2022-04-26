#include <bits/stdc++.h>

using namespace std;

class Book
{
    string name;
    int id, daysBorrowed;

public:
    friend istream &operator>>(istream &in, Book &b);
    friend ostream &operator<<(ostream &out, Book &b);
    friend void calcFine();
    int getId()
    {
        return id;
    }
};

vector<Book*> books;

Book* getBook()
{
    int id;
    cout<<"Enter book id: ";
    cin >> id;
    for (auto b : books)
    {
        if (b->getId() == id)
        {            
            return b;
        }
    }
    cout << "No book found\n";
    return nullptr;
}

void calcFine(){
    Book* book = getBook();
    if(!book){
        return;
    }
    int days;
    cout<<"Enter days borrowed: ";
    cin>>days;
    book->daysBorrowed = days;
    cout<<"Fine: ";
    if(book->daysBorrowed<=14) cout<<0;
    else cout<<(days-14)*5;
    cout<<endl;
}

istream &operator>>(istream &in, Book &b)
{
    cout << "Book id: ";
    cin >> b.id;
    cout << "Book title: ";
    cin >> b.name;
    b.daysBorrowed = 0;
}

ostream &operator<<(ostream &out, Book &b)
{
    cout << "Id: " << b.id << "\n";
    cout << "Title: " << b.name << "\n";
}

int main()
{
    int choice;
    do
    {
        printf("0 for help >>");
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "1 - Enter book details\n";
            cout << "2 - Get book details\n";
            cout << "3 - Calculate fine\n";
            break;
        }
        case 1:
        {
            Book* newBook = new Book;
            cin >> *newBook;
            books.push_back(newBook);
            break;
        }
        case 2:
        {
            Book* b = getBook();
            cout<<*b;
            break;
        }
        case 3:
            calcFine();
        }
    } while (choice != -1);
}