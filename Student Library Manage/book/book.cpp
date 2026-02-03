#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <limits>

using namespace std;
struct Book{
    int bookId,days;
    string title, author, issueDate, dueDate;

    bool isAvailable;
};
struct Student{
    string studentName, fatherName, issueDate, dueDate, email;
    char section;
    int rollNumber, days;
};
class LibraryBook{
    private:
        vector<Student>students;
        vector<Book>books;
    public:

        LibraryBook(){
            loadBooksFromFile();
        }
        
        // Add new book
        void addBook(){
            Book b;
            cout << "Enter Book ID : ";
            cin >> b.bookId;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
            cout << "Enter Book Title : ";
            getline(cin,b.title);
            
            cout << "Enter Author Name : ";
            getline(cin,b.author);
            
            b.isAvailable = true;
            books.push_back(b);
            saveBookToFile(b);
            
            
            cout << "Book added successfully!\n";
        }
        
        // View all books in the file
        void viewAllBooks(){
            if(books.empty()){
                cout << "No books available in the library\n";
                return;
            }
            
            cout << "\n------ Library Books ------\n";
            for(const Book& b: books){
                cout << "Book ID    : " << b.bookId << endl;
                cout << "Title      : " << b.title  << endl;
                cout << "Author     : " << b.author << endl;
                cout << "Status     : " << (b.isAvailable ? "Available" : "Issued") << endl;
                cout << "-----------------------------------\n";
                
            }
        }
        
        void findBook()
        {
            string searchTitle;
            // cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter Book Title: ";
            getline(cin,searchTitle);

            bool found = false;
            for(const auto& b : books){
                if(b.title == searchTitle){
                    cout << "Book Found!\n";
                    cout << "Book ID    : " << b.bookId << endl;
                    cout << "Title      : " << b.title  << endl;
                    cout << "Author     : " << b.author  << endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "Book not found.\n";
            }
        };

        void issueBook()
        {
            
            string searchBook;
            cout << "Enter Book Title : ";
            getline(cin,searchBook);
            bool found = false;
            for(auto& b : books){
                if(b.title == searchBook)
                {
                    found = true;
                    
                    if(b.isAvailable){
                        cout << "\t\t\tYes this book is available you can issue it\n";
                        Student s;
                        cout << "Enter Student Name : ";

                        getline(cin,s.studentName);
                        cout << "Enter Roll Number  : ";
                        cin >> s.rollNumber;

                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Enter Student Class Section : ";
                        cin >> s.section;

                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Enter Father's Name : ";
                        getline(cin,s.fatherName);

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter your gmail : ";
                        getline(cin,s.email);

                        if(s.email.find("@gmail.com") == string::npos){
                            cout << "Invalid Gmail address. Please enter a valid Gmail.\n";
                            return;
                        }

                        cout << "Enter number of days to issue: ";
                        cin >> s.days;

                        s.issueDate = getCurrentDate();
                        s.dueDate   = calculateDueDate(s.days);

                        cout << "Issue Date: " << s.issueDate << endl;
                        cout << "Due Date  : " << s.dueDate   << endl;

                        b.isAvailable = false;
                        rewriteBooksFile(); //UPDATE THE FILE
                        cout << "Book issued successfully\n";
                        saveIssueBook(s);
                        generateReceiptHTML(s,b);
                        convertHTMLtoPDF();
                        cout << "Receipt generated successfully (PDF)\n";
                        string cmd = "python send_email.py \"" + s.email + "\"";
                        system(cmd.c_str());



                        //and also we have to make another file where we will put that student data those get book from the library and also we have to make one more function when the student return the book we will write the the student roll no and section and if the rollnumber and section get match then we will get the book and mark the student status returned and also we have to update that the book is avaialbe in our book.txt.

                        //and the advance fuction we have to implement that if student not return till due date then the next day the fine will apply on the student and the student get a sms on his number or else gmail 
                        
                        break;
                    }else{
                        cout << "Sorry this book is not available for issue";
                        break;
                    }
                    return;
                }
            }
            if(!found){
                cout << "Book not fund in library\n";
            }

        };
        
        
        private:
        void generateReceiptHTML(const Student&s, const Book& b)
        {
            ofstream html("receipt.html");
                html << "<!DOCTYPE html>\n";
                html << "<html><head><meta charset='UTF-8'>\n";
                html << "<title>Library Receipt</title>\n";
            
                html << "<style>\n";
                html << "body{font-family:Arial;background:#f4f4f4;}\n";
                html << ".receipt{width:600px;margin:auto;background:#fff;padding:20px;border:1px             solid #ccc;}\n";
                html << "h2{text-align:center;}\n";
                html << "p{font-size:14px;}\n";
                html << "</style>\n";
            
                html << "</head><body>\n";
            
                html << "<div class='receipt'>\n";
                html << "<h2>Library Book Issue Receipt</h2><hr>\n";
            
                html << "<p><b>Student Name:</b> " << s.studentName << "</p>\n";
                html << "<p><b>Father Name:</b> " << s.fatherName << "</p>\n";
                html << "<p><b>Student Gmail:</b> " << s.email << "</p>\n";
                html << "<p><b>Roll Number:</b> " << s.rollNumber << "</p>\n";
                html << "<p><b>Section:</b> " << s.section << "</p>\n";
            
                html << "<hr>\n";
            
                html << "<p><b>Book ID:</b> " << b.bookId << "</p>\n";
                html << "<p><b>Book Title:</b> " << b.title << "</p>\n";
                html << "<p><b>Author:</b> " << b.author << "</p>\n";
            
                html << "<hr>\n";
            
                html << "<p><b>Issue Date:</b> " << s.issueDate << "</p>\n";
                html << "<p><b>Due Date:</b> " << s.dueDate << "</p>\n";
            
                html << "<hr>\n";
                html << "<p style='text-align:center;'>Please return the book on time.</p>\n";
            
                html << "</div></body></html>\n";
            
                html.close();
        }

        void convertHTMLtoPDF(){
            system("wkhtmltopdf receipt.html receipt.pdf");
        }



        string getCurrentDate(){
            time_t now = time(nullptr);
            tm* ltm = localtime(&now);

            return to_string(ltm->tm_mday)+"/" +
                   to_string(ltm->tm_mon + 1) + "/" +
                   to_string(ltm->tm_year + 1900);
        }

        string calculateDueDate(int days){
            time_t now = time(nullptr);
            tm *ltm = localtime(&now);

            ltm->tm_mday += days; // add days
            mktime(ltm);    // normalize date

            int day = ltm->tm_mday;
            int month = ltm->tm_mon + 1;
            int year = ltm->tm_year + 1900;

            return to_string(day) + "/" +
                   to_string(month) + "/" +
                   to_string(year);
        }


        void loadBooksFromFile(){
            ifstream file("book.txt");
            if(!file.is_open()){
                return;
            }
            string line;
            while(getline(file,line)){
                if(line.empty())continue;
                if(line.find('|') == string::npos)continue;
                Book b;
                size_t pos;
    
                pos = line.find('|');
                b.bookId = stoi(line.substr(0,pos));
                line.erase(0,pos+1);
    
                pos = line.find('|');
                b.title = line.substr(0,pos);
                line.erase(0,pos+1);
    
                pos = line.find('|');
                b.author = line.substr(0,pos);
                line.erase(0,pos+1);
    
                b.isAvailable = (line == "1");
                books.push_back(b);
            }
            file.close();
        }
    
    
        void saveBookToFile(const Book& b){
            ofstream file("book.txt",ios::app);
            file << b.bookId << "|"
                 << b.title << "|"
                 << b.author << "|"
                 << b.isAvailable << endl;
            file.close();
        }

        void rewriteBooksFile(){
            ofstream file("book.txt");
            for(const auto& b : books){
                file << b.bookId << "|"
                     << b.title << "|"
                     << b.author << "|"
                     << b.isAvailable << endl;
            }
            file.close();
        }

        void saveIssueBook(const Student&s){
            ofstream file("issueBookRecord.txt",ios::app);
            file << s.studentName << "|"
                 << s.fatherName << "|"
                 << s.rollNumber << "|"
                 << s.section << "|"
                 << s.days << "|"
                 << s.issueDate << "|"
                 << s.email << "|"
                 << s.dueDate << endl;
        }
    };

int main()
{
    LibraryBook l;
    l.issueBook();

    return 0;
}