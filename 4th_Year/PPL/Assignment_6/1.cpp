#include <bits/stdc++.h>

using namespace std;

class author
{
private:
    string author_name;

public:
    author(string a)
    {
        this->author_name = a;
    }
    string get_author_name()
    {
        return this->author_name;
    }
};

class book_publication : public author
{
private:
    string title;

public:
    book_publication(string a, string t) : author(a)
    {
        this->title = t;
    }
    string get_title()
    {
        return this->title;
    }
};

class paper_publication : public author
{
private:
    string title;

public:
    paper_publication(string a, string t) : author(a)
    {
        this->title = a;
    }

    string get_title()
    {
        return this->title;
    }
};

void display_error_message()
{
    cout << "Invalid Arguments. Arguments must follow following standards:" << endl;
    cout << "Enter 3 arguments for each record value." << endl;
    cout << "First argument should be either P or B which denotes Paper or Book respectively." << endl;
    cout << "Second argument must be Author Name." << endl;
    cout << "Third argument must be Title." << endl;
}

int main(int argc, char **argv)
{
    if (argc % 3 != 1)
    {
        display_error_message();
        return 0;
    }
    vector<paper_publication *> p;
    vector<book_publication *> b;
    int cnt = (argc - 1) / 3;
    for (int i = 0; i < cnt; i++)
    {
        string type = string(argv[i * 3 + 1]);
        string author_name = string(argv[i * 3 + 2]);
        string title = string(argv[i * 3 + 3]);
        if (type == "P")
        {
            p.push_back(new paper_publication(author_name, title));
        }
        else if (type == "B")
        {
            b.push_back(new book_publication(author_name, title));
        }
        else
        {
            display_error_message();
            return 0;
        }
    }

    cout<<"Enter Author Name : ";
    string author_name;
    cin >> author_name; 
    for(paper_publication* paper: p){
        author* a = paper;
        if(a->get_author_name()==author_name){
            cout<<"Paper Found : "<<paper->get_title()<<endl;
        }
    }
    for(book_publication* book: b){
        author* a = book;
        if(a->get_author_name()==author_name){
            cout<<"Book Found : "<<book->get_title()<<endl;
        }
    }
}