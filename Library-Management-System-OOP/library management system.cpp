#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
class Library; 
class Book 
{
public:
    string title;
    string author;
    string isbn;
    int pub_Year;
    string type;

    Book(string t, string a, string i, int p, string ty)
        : title(t), author(a), isbn(i), pub_Year(p), type(ty) {}

    string getTitle() const 
	{
        return title;
    }
    string getAuthor() const 
	{
        return author;
    }
    string getIsbn() const 
	{
        return isbn;
    }
    int getPubYear() const 
	{
        return pub_Year;
    }
    string getType() const 
	{
        return type;
    }
        virtual void  borrow() 
	{
        cout<<"Book borrowed: " <<title<<" by "<<author<<endl;
    }

    virtual void returnBook() 
	{
        cout<<"Book returned: "<<title<<" by "<<author<<endl;
    } 
    void save() const 
	{
        ofstream file("books.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"title : "<<title<<" , "<<"author : "<<author<<" , "<<"Isbn : "<<isbn<<" , "<<"pub_Year : "<<pub_Year<<" , "<<"type : "<<type<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening books.txt for writing."<<endl;
        }
    }
    static void removeBook(const string& isbn) 
	{
        ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            if (line.find(isbn) == string::npos) 
			{
                temp<<line<<endl;
            }
        }
        file.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
    static void updateBook(const Book& updatedBook) 
	{
        ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            if (line.find(updatedBook.getIsbn()) == string::npos) 
			{
                temp << line << endl;
            } 
			else 
			{
                temp<<"title : "<<updatedBook.getTitle()<< ","<<"author : "<<updatedBook.getAuthor() << ","<<"Isbn : "<<updatedBook.getIsbn()<< ","<<"pub_Year : "<<updatedBook.getPubYear()<< ","<<"type : "<<updatedBook.getType()<<endl;
            }
        }
        file.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
};
class Fiction : public Book 
{
public:
    string genre;
    Fiction(string t, string a, string i, int p, string g)
        : Book(t, a, i, p, "Fiction"), genre(g) {}
    string getgenre() const 
	{
        return genre;
    }
    void save() const  
	{
        ofstream file("books.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"title : "<<title<<" , "<<"author : "<<author<<" , "<<"Isbn : "<<isbn<<" , "<<"pub_Year : "<<pub_Year<<" , "<<"type : Fiction"<<" , "<<"genre : "<<genre<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening books.txt for writing."<<endl;
        }
    }
    static void updateBook(const Fiction& updatedBook) 
    {
        ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
        {
            if (line.find(updatedBook.getIsbn()) == string::npos) 
            {
                temp << line << endl;
            } 
            else 
            {
                temp<<"title : "<<updatedBook.getTitle()<< ","<<"author : "<<updatedBook.getAuthor() << ","<<"Isbn : "<<updatedBook.getIsbn()<< ","<<"pub_Year : "<<updatedBook.getPubYear()<< ","<<"type : "<<updatedBook.getType()<<" , "<<"genre : "<<updatedBook.getgenre()<<endl;
            }
        }
        file.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
};
class NonFiction : public Book 
{
public:
    string subject;
    NonFiction(string t, string a, string i, int p, string s)
        : Book(t, a, i, p, "NonFiction"), subject(s) {}
    string getsubject() const 
	{
        return subject;
    }   
    void save() const  
	{
        ofstream file("books.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"title : "<<title<<" , "<<"author : "<<author<<" , "<<"Isbn : "<<isbn<<" , "<<"pub_Year : "<<pub_Year<<" , "<<"type : NonFiction"<<" , "<<"subject : "<<subject<<endl;
            file.close();
        } 
		else
		{
            cout<<"Error opening books.txt for writing."<<endl;
        }
    }
    static void updateBook(const NonFiction& updatedBook) 
    {
        ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
        {
            if (line.find(updatedBook.getIsbn()) == string::npos) 
            {
                temp << line << endl;
            } 
            else 
            {
                temp<<"title : "<<updatedBook.getTitle()<< ","<<"author : "<<updatedBook.getAuthor() << ","<<"Isbn : "<<updatedBook.getIsbn()<< ","<<"pub_Year : "<<updatedBook.getPubYear()<< ","<<"type : "<<updatedBook.getType()<<" , "<<"subject : "<<updatedBook.getsubject()<<endl;
            }
        }
        file.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
};
class Reference : public Book 
{
public:
    int edition;

    Reference(string t, string a, string i, int p, int e)
        : Book(t, a, i, p, "Reference"), edition(e) {}
    int getedition() const 
	{
        return edition;
    }  
    void save() const  
	{
        ofstream file("books.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"title : "<<title<<" , "<<"author : "<<author<<" , "<<"Isbn : "<<isbn<<" , "<<"pub_Year : "<<pub_Year<<" , "<<"type : Reference"<<" , "<<"edition : "<<edition<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening books.txt for writing."<<endl;
        }
    }
    static void updateBook(const Reference& updatedBook) 
    {
        ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
        {
            if (line.find(updatedBook.getIsbn()) == string::npos) 
            {
                temp << line << endl;
            } 
            else 
            {
                temp<<"title : "<<updatedBook.getTitle()<< ","<<"author : "<<updatedBook.getAuthor() << ","<<"Isbn : "<<updatedBook.getIsbn()<< ","<<"pub_Year : "<<updatedBook.getPubYear()<< ","<<"type : "<<updatedBook.getType()<<" , "<<"edition : "<<updatedBook.getedition()<<endl;
            }
        }
        file.close();
        temp.close();
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
};
class Member 
{
public:
    string name;
    int id;
    string membership_type;
    Book* borrowedBooks; 
    int maxBooks; 
    int numBooks; 
public:
    Member(string n, int i, string m_type)
    : name(n), id(i), membership_type(m_type) {}
    string getName() const 
	{
        return name;
    }
    int getId() const 
	{
        return id;
    }
    string getMembershipType() const 
	{
        return membership_type;
    }
      void borrowBook(const Book& book) 
	  {
        if (numBooks < maxBooks) 
		{
            borrowedBooks[numBooks++] = book;
            cout << "Book borrowed: " << book.getTitle() << " by " << book.getAuthor() << endl;
        } 
		else 
		{
            cout << "Member has borrowed the maximum number of books." << endl;
        }
    }
    void returnBook(const Book& book) 
	{
        int index = -1;
        for (int i = 0; i < numBooks; ++i) 
		{
            if (borrowedBooks[i].getTitle() == book.getTitle() &&
            borrowedBooks[i].getAuthor() == book.getAuthor()) 
			{
                index = i;
                break;
            }
        }
        if (index != -1) 
		{
            for (int j = index; j < numBooks - 1; ++j) 
			{
                borrowedBooks[j] = borrowedBooks[j + 1];
            }
            numBooks--;
            cout << "Book returned: " << book.getTitle() << " by " << book.getAuthor() << endl;
        } 
		else 
		{
            cout << "Book not borrowed by this member." << endl;
        }
    }
    virtual void save() const 
	{
        ofstream file("members.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Name : "<<name<<" , "<<"Id : "<<id<<" , "<<"membership_type : "<<membership_type<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening members.txt for writing."<<endl;
        }
    }
    static void removeMember(int id) 
	{
        ifstream file("members.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            int memberId;
            ss >> memberId;
            if (memberId != id) 
			{
                temp<<line<<endl;
            }
        }
        file.close();
        temp.close();
        remove("members.txt");
        rename("temp.txt", "members.txt");
    }
   static void updateMember(int id, const Member& updatedMember) 
	{
        ifstream file("members.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ','); 
            stringstream id_ss(token);
            int memberId;
            id_ss >> memberId;
            if (memberId != id) 
			{
                temp<<line<<endl; 
            } 
			else 
			{
                temp<<updatedMember.name<<" , "<<updatedMember.id<< " , "<<updatedMember.membership_type<<endl;
            }
        }
        file.close();
        temp.close();
        remove("members.txt");
        rename("temp.txt", "members.txt");
    }
};
class Student : public Member 
{
private:
    string grade;
public:
    Student(string n, int i, string m_type, string g)
        : Member(n, i, m_type), grade(g) {}
    void save() const  
	{
        ofstream file("members.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Name : "<<getName()<<" , "<<"Id : "<<getId()<<" , "<<"membership_type : "<<getMembershipType()<<" , "<<"grade : "<<grade<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening members.txt for writing."<<endl;
        }
    }
};
class Faculty : public Member 
{
private:
    string department;
public:
    Faculty(string n, int i, string m_type, string dept)
        : Member(n, i, m_type), department(dept) {}
    void save() const  
	{
        ofstream file("members.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Name : "<<getName()<<" , "<<"Id : "<<getId()<<" , "<<"membership_type : "<<getMembershipType()<<" , "<<"department : "<<department<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening members.txt for writing."<<endl;
        }
    }
};
class Staff 
{
protected:
    string name;
    string role;
    int id;
    double salary;
public:
    Staff(string n, string r, int i, double s)
        : name(n), role(r), id(i), salary(s) {}
    string getName() const 
	{
        return name;
    }

    string getRole() const 
	{
        return role;
    }

    int getId() const 
	{
        return id;
    }

    double getSalary() const 
	{
        return salary;
    }
    virtual double calculateSalary() const = 0;
    void recordStaff() const 
	{
        ofstream file("staff.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Name : "<<name<<" , "<<"Role : "<<role<<" , "<<"Id : "<<id<<" , "<<"salary : "<<salary<<endl;
            file.close();
        } 
		else 
		{
            cout<<"Error opening staff.txt for writing."<<endl;
        }
    }
    static void readStaffFromFile() 
	{
        ifstream file("staff.txt");
        if (file.is_open()) 
		{
            string line;
            while (getline(file, line)) 
			{
                cout<<line<<endl;
            }
            file.close();
        } 
		else 
		{
            cout<<"Error opening staff.txt for reading."<<endl;
        }
    }
    static void removestaff(int id) 
	{
        ifstream file("staff.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ','); 
            stringstream id_ss(token);
            int memberId;
            id_ss >> memberId; 
            if (memberId != id) 
			{
                temp<<line<<endl; 
            }
        }
        file.close();
        temp.close();
        remove("staff.txt");
        rename("temp.txt", "staff.txt");
    }
};
class Librarian : public Staff 
{
public:
    Librarian(string n, string r, int i, double s)
        : Staff(n, r, i, s) {}
    double calculateSalary() const  
	{
        return salary;
    }
};
class Assistant : public Staff 
{
public:
    Assistant(string n, string r, int i, double s)
        : Staff(n, r, i, s) {}
    double calculateSalary() const  
	{
        return salary;
    }
};
class Transaction 
{
protected:
    int t_id;
    int m_id;
    string b_isbn;
    string b_date;
    string r_date;
    double fine;
    string m_type;
public:
    Transaction(int t, int m, string b, string d, string r, string ty)
        : t_id(t), m_id(m), b_isbn(b), b_date(d), r_date(r), m_type(ty), fine(0.0)  {}
    int getTid() const 
	{
        return t_id;
    }
    int getMid() const 
	{
        return m_id;
    }
    string getBIsbn() const 
	{
        return b_isbn;
    }
    string getBDate() const 
	{
        return b_date;
    }
    string getRDate() const 
	{
        return r_date;
    }
      int daysDifference(const string& date1, const string& date2) 
    {
        int year1 = stringToInt(date1.substr(0, 4));
        int month1 = stringToInt(date1.substr(5, 2));
        int day1 = stringToInt(date1.substr(8, 2));
        int year2 = stringToInt(date2.substr(0, 4));
        int month2 = stringToInt(date2.substr(5, 2));
        int day2 = stringToInt(date2.substr(8, 2));

        int totalDays1 = year1 * 360 + month1 * 30 + day1;
        int totalDays2 = year2 * 360 + month2 * 30 + day2;
        int daysDiff = abs(totalDays2 - totalDays1);
        
        return daysDiff;
    }
double calculateFine() 
{
    int allowedDaysStudent = 8;
    int allowedDaysFaculty = 30; 

    int daysBorrowed = daysDifference(b_date, r_date);
    
    if (m_type == "Student")
    {
        if (daysBorrowed > allowedDaysStudent)
        {
            fine = (daysBorrowed - allowedDaysStudent) * 500;
        }
        else
        {
            fine = 0;
        }
    }
    else if (m_type == "Faculty")
    {
        if (daysBorrowed > allowedDaysFaculty)
        {
            fine = (daysBorrowed - allowedDaysFaculty) * 500;
        }
        else
        {
            fine = 0;
        }
    }
    return fine;
}
    void generateReport() const 
	{
        cout<<"Transaction Report:"<<endl;
        cout<<"Transaction ID: "<<t_id <<endl;
        cout<<"Member ID: "<<m_id<<endl;
        cout<<"Book ISBN: "<<b_isbn<<endl;
        cout<<"Borrow Date: "<<b_date<<endl;
        cout<<"Return Date: "<<r_date<<endl;
        cout<<"Fine: Rs "<<fine<<endl;
    }
    void recordTransaction() const 
	{
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"transaction Id : "<<t_id<<" , "<<"member Id : "<<m_id<<" , "<<"book Isbn : "<<b_isbn<<" , "<<"borrow date : "<<b_date<< " , "<<"return date : "<< r_date<<" , "<<"fine : "<<fine<<" , "<<"member type : "<<m_type<<endl;
            file.close();
        } 
		else
		{
            cout<<"Error opening transactions.txt for writing."<<endl;
        }
    }
    void recordBorrowTransaction() const {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << "Borrow book : " << endl;
            file << "Transaction Id : " << t_id << " , " << "Member Id : " << m_id << " , " << "Book Isbn : " << b_isbn << " , " << "Borrow date : " << b_date << endl;
            file.close();
        } else {
            cout << "Error opening transactions.txt for writing." << endl;
        }
    }
    void recordReturnTransaction() const 
	{
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Return book : "<<endl;
			file<<"transaction Id : "<<t_id<<" , "<<"member Id : "<<m_id<<" , "<<"book Isbn : "<<b_isbn<<" , "<<"return date : "<<r_date<<endl;
            file.close();
        } 
		else
		{
            cout<<"Error opening transactions.txt for writing."<<endl;
        }
    }
    int stringToInt(const string& str) const
    {
        int result = 0;
        for (size_t i = 0; i < str.length(); ++i)
        {
            char c = str[i];
            if (c >= '0' && c <= '9')
            {
                result = result * 10 + (c - '0');
            }
            else{}
        }
        return result;
    }  
    
};
class Library 
{
public:
    string name;
    string address;
    Book* books[100]; 
    Member* members[100]; 
    Staff* staffs[100]; 
    int bookCount;
    int memberCount;
    int staffCount;
    Library(string n, string a)
        : name(n), address(a), bookCount(0), memberCount(0), staffCount(0) {}
    ~Library() 
	{
        for (int i=0; i<bookCount; ++i) 
		{
            delete books[i];
        }
        for (int i=0; i<memberCount; ++i) 
		{
            delete members[i];
        }
        for (int i=0; i<staffCount; ++i) 
		{
            delete staffs[i];
        }
    }
    void addBook(Book* b) 
	{
        if (bookCount < 100) 
		{
            books[bookCount++] = b;
        } 
		else 
		{
            cout<<"Book array is full."<<endl;
        }
    }
    void addMember(Member* m) 
	{
        if (memberCount < 100) 
		{
            members[memberCount++] = m;
        } 
		else 
		{
            cout<<"Member array is full."<<endl;
        }
    }
    void addStaff(Staff* s) 
	{
        if (staffCount < 100) 
		{
            staffs[staffCount++] = s;
        } 
		else 
		{
            cout<<"Staff array is full."<<endl;
        }
    }
    void removeBook(const string& isbn) 
	{
        int index = -1;
        for (int i=0; i<bookCount; ++i) 
		{
            if (books[i]->getIsbn() == isbn) 
			{
                index = i;
                break;
            }
        }
        if (index != -1) 
		{
            delete books[index];
            for (int i = index; i < bookCount - 1; ++i) 
			{
                books[i] = books[i + 1];
            }
            bookCount--;
            Book::removeBook(isbn);
        } 
		else 
		{
            cout<<"Book not found."<<endl;
        }
    }
    void removeMember(int id) 
	{
        int index = -1;
        for (int i = 0; i < memberCount; ++i) 
		{
            if (members[i]->getId() == id) 
			{
                index = i;
                break;
            }
        }
        if (index != -1) 
		{
            delete members[index];
            for (int i = index; i < memberCount - 1; ++i) 
			{
                members[i] = members[i + 1];
            }
            memberCount--;
            Member::removeMember(id);
        } 
		else 
		{
            cout<<"Member not found."<<endl;
        }
    }
    void removeStaff(int id) 
	{
        int index = -1;
        for (int i = 0; i < staffCount; ++i) 
		{
            if (staffs[i]->getId() == id) 
			{
                index = i;
                break;
            }
        }
        if (index != -1) 
		{
            delete staffs[index];
            for (int i = index; i < staffCount - 1; ++i) 
			{
                staffs[i] = staffs[i + 1];
            }
            staffCount--;
        } 
		else 
		{
            cout<<"Staff not found."<<endl;
        }
    }
    void updateStaff(int id, const Staff& updatedStaff) 
	{
        for (int i = 0; i < staffCount; ++i) 
		{
            if (staffs[i]->getId() == id) 
			{
                *staffs[i] = updatedStaff;
                return;
            }
        }
        cout<<"Staff not found."<<endl;
    }
    void listBooks() const 
	{
        for (int i = 0; i < bookCount; ++i) 
		{
            cout<<books[i]->getTitle()<<" by "<<books[i]->getAuthor()<<endl;
        }
    }
    void listMembers() const 
	{
        for (int i = 0; i < memberCount; ++i) 
		{
            cout<<members[i]->getName()<<" (ID: "<<members[i]->getId()<<")"<<endl;
        }
    }
    void listStaff() const 
	{
        for (int i = 0; i < staffCount; ++i) 
		{
            cout<<staffs[i]->getName()<<" (ID: "<<staffs[i]->getId()<< ")"<<endl;
        }
    }
};
int main() 
{
 Library myLibrary("Central Library", "123 Library St");
   string input;
    bool exit = false;
    while (!exit) 
	{
        cout<<"Choose an option:"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Add Member"<<endl;
        cout<<"3. Add Librarian"<<endl;
        cout<<"4. Add Assistant"<<endl;
        cout<<"5. Add Transaction"<<endl;
        cout<<"6. List Books, Members, and Staff"<<endl;
        cout<<"7. Remove Book"<<endl;
        cout<<"8. Remove Member"<<endl;
        cout<<"9. Remove Staff"<<endl;
        cout<<"10. Borrow book"<<endl;
        cout<<"11. Return book"<<endl;
        cout<<"12. update book"<<endl;
        cout<<"13. update member"<<endl;
        cout<<"14. Exit"<<endl;
        cout<<"Enter your choice: ";
        getline(cin, input);

        int choice;
        stringstream(input) >> choice;

        switch (choice) 
		{
            case 1: 
			{        
                string bookTitle, bookAuthor, bookIsbn, bookType;
                int bookPubYear;
                cout<<"Enter book title: ";
                getline(cin, bookTitle);
                cout<<"Enter book author: ";
                getline(cin, bookAuthor);
                cout<<"Enter book ISBN: ";
                getline(cin, bookIsbn);
                cout<<"Enter book publication year: ";
                cin>>bookPubYear;
                cin.ignore(); 
                cout<<"Enter book type (Fiction, NonFiction, Reference): ";
                getline(cin, bookType);
                if (bookType == "Fiction") 
	            {
                    string genre;
                    cout<<"Enter genre: ";
                    getline(cin, genre);
                    Fiction* newBook = new Fiction(bookTitle, bookAuthor, bookIsbn, bookPubYear, genre);
                    myLibrary.addBook(newBook);
                    newBook->save(); 
                } 
	           else if (bookType == "NonFiction") 
            	{
                    string subject;
                    cout<<"Enter subject: ";
                    getline(cin, subject);
                    NonFiction* newBook = new NonFiction(bookTitle, bookAuthor, bookIsbn, bookPubYear, subject);
                    myLibrary.addBook(newBook);
                    newBook->save(); 
                } 
	          else if (bookType == "Reference") 
	           {
                    int edition;
                    cout<<"Enter edition: ";
                    cin>>edition;
                    cin.ignore(); 
                    Reference* newBook = new Reference(bookTitle, bookAuthor, bookIsbn, bookPubYear, edition);
                    myLibrary.addBook(newBook);
                    newBook->save(); 
                } 
	           else 
	           {
                    cout<<"Invalid book type. Book not added."<<endl;
               }
               break;
            }
            case 2: 
			{
                string memberName, memberType;
                int memberId;
                cout<<"Enter member name: ";
                getline(cin, memberName);
                cout<<"Enter member ID: ";
                cin>>memberId;
                cin.ignore(); 
                cout<<"Enter membership type (Student/Faculty): ";
                getline(cin, memberType);
                if (memberType == "Student") 
				{
                    string grade;
                    cout<<"Enter grade: ";
                    getline(cin, grade);
                    Member* member1 = new Student(memberName, memberId, memberType, grade);
                    myLibrary.addMember(member1);
                    member1->save();
                }  
				else if (memberType == "Faculty") 
				{
                    string department;
                    cout<<"Enter department: ";
                    getline(cin, department);
                    Member* member1 = new Faculty(memberName, memberId, memberType, department);
                    myLibrary.addMember(member1);
                    member1->save();
                }  
				else 
				{
                    cout<<"Invalid membership type. Member not added."<<endl;
                }
                break;
            }
            case 3: 
			{
                string staffName, staffRole;
                int staffId;
                double staffSalary;
                cout<<"Enter librarian name: ";
                getline(cin, staffName);
                cout<<"Enter librarian ID: ";
                cin>>staffId;
                cout<<"Enter librarian salary: ";
                cin>>staffSalary;
                cin.ignore(); 
                staffRole = "Librarian";
                Staff* librarian1 = new Librarian(staffName, staffRole, staffId, staffSalary);
                myLibrary.addStaff(librarian1);
                librarian1->recordStaff();
                break;
            }
            case 4: 
			{
                string staffName, staffRole;
                int staffId;
                double staffSalary;
                cout<<"Enter assistant name: ";
                getline(cin, staffName);
                cout<<"Enter assistant ID: ";
                cin>>staffId;
                cout<<"Enter assistant salary: ";
                cin>>staffSalary;
                cin.ignore(); 
                staffRole = "Assistant";
                Staff* assistant1 = new Assistant(staffName, staffRole, staffId, staffSalary);
                myLibrary.addStaff(assistant1);
                assistant1->recordStaff();
                break;
            }
            case 5: 
			{
                int transId, memId;
                string bookIsbnTrans, borrowDate, returnDate, memType;
                double fine;
                cout<<"Enter transaction ID: ";
                cin>>transId;
                cout<<"Enter member ID for the transaction: ";
                cin>>memId;
                cin.ignore(); 
                cout<<"Enter book ISBN for the transaction: ";
                getline(cin, bookIsbnTrans);
                cout<<"Enter borrow date (YYYY-MM-DD): ";
                getline(cin, borrowDate);
                cout<<"Enter return date (YYYY-MM-DD): ";
                getline(cin, returnDate);
                cout<<"Enter member type: ";
                getline(cin, memType);
                Transaction transaction1(transId, memId, bookIsbnTrans, borrowDate, returnDate, memType);
                fine = transaction1.calculateFine();
                cout<<"Fine: " <<fine<<endl;
                transaction1.generateReport();
                transaction1.recordTransaction();
                break;
            }
            case 6:
			{
                cout<<"Books in library:"<<endl;
                myLibrary.listBooks();
                cout<<endl<<"Members in library:"<<endl;
                myLibrary.listMembers();
                cout<<endl<<"Staff in library:"<<endl;
                myLibrary.listStaff();
                break;
            }   
            case 7: 
			{
                string isbnToRemove;
                Book* b;
                cout<<"Enter ISBN of the book to remove: ";
                getline(cin, isbnToRemove);
                myLibrary.removeBook(isbnToRemove);
                b->removeBook(isbnToRemove);
                
                break;
            }
            case 8: 
			{
                int memberIdToRemove;
                Member* m;
                cout<<"Enter ID of the member to remove: ";
                cin>>memberIdToRemove;
                cin.ignore(); 
                myLibrary.removeMember(memberIdToRemove);
                m->removeMember(memberIdToRemove);
                break;
            }
            case 9: 
			{
                int staffIdToRemove;
                Staff* s;
                cout<<"Enter ID of the staff to remove: ";
                cin>>staffIdToRemove;
                cin.ignore(); 
                myLibrary.removeStaff(staffIdToRemove);
                s->removestaff(staffIdToRemove);
                break;
            }
            case 10:
            {
            	int memberId,transactionId;
                string bookIsbn;
                string borrowDate;
                cout<<"Enter transaction ID: ";
                cin>>transactionId;
                cout<<"Enter member ID: ";
                cin>>memberId;
                cin.ignore();
                cout << "Enter book ISBN: ";
                getline(cin, bookIsbn);
                cout << "Enter borrow date (YYYY-MM-DD): ";
                getline(cin, borrowDate);
                Member* member = 0;
                for (int i = 0; i < myLibrary.memberCount; ++i) 
				{
                    if (myLibrary.members[i]->getId() == memberId) 
					{
                        member = myLibrary.members[i];
                        break;
                    }
                }
                if (member!= 0) 
				{
                    Book* book = 0;
                    for (int i = 0; i < myLibrary.bookCount; ++i) 
					{
                        if (myLibrary.books[i]->getIsbn() == bookIsbn) 
						{
                            book = myLibrary.books[i];
                            break;
                        }
                    }
                    if (book!= 0) 
					{
                        if (book->getTitle() != "") 
						{
                            member->borrowBook(*book);
                            Transaction t(transactionId,memberId, bookIsbn, borrowDate, "", "Borrow");
                            t.recordBorrowTransaction();
                            cout << "Book borrowed successfully." << endl;
                        }  
						else  
						{
                            cout << "Book is not available." << endl;
                        }
                    } 
					else 
					{
                        cout << "Book not found." << endl;
                    }
                } 
				else 
				{
                    cout << "Member not found." << endl;
                }
            }
            break;	
            case 11:
            {
            	int memberId,transactionId;
                string bookIsbn;
                string returnDate;
                cout<<"Enter transaction ID: ";
                cin>>transactionId;
                cout << "Enter member ID: ";
                cin >> memberId;
                cin.ignore();
                cout << "Enter book ISBN: ";
                getline(cin, bookIsbn);
                cout << "Enter return date (YYYY-MM-DD): ";
                getline(cin, returnDate);
                Member* member = 0;
                for (int i = 0; i < myLibrary.memberCount; ++i) 
				{
                    if (myLibrary.members[i]->getId() == memberId) 
					{
                        member = myLibrary.members[i];
                        break;
                    }
                }
                if (member!= 0) 
				{
                    Book* book = 0;
                    for (int i = 0; i < myLibrary.bookCount; ++i) 
					{
                        if (myLibrary.books[i]->getIsbn() == bookIsbn) 
						{
                            book = myLibrary.books[i];
                            break;
                        }
                    }
                    if (book!= 0) 
					{
                        member->returnBook(*book);
                        Transaction t(transactionId,memberId, bookIsbn, "", returnDate, "Return");
                        t.recordReturnTransaction();
                        cout << "Book returned successfully." << endl;
                    } 
				    else 
				    {
                        cout << "Book not found." << endl;
                    }
                } 
				else 
				{
                    cout << "Member not found." << endl;
                }
			}
            break;
            case 12:
            {
		       string title, author, isbn, type;
               int pub_Year;
			   cout<<"Enter the book ISBN to update: ";
			   cin>>isbn;
			   cout<<"Enter new title: ";
			   cin.ignore();
			   getline(cin, title);
			   cout<<"Enter new author: ";
			   getline(cin, author);
			   cout<<"Enter new publication year: ";
			   cin>>pub_Year;
			   cout<<"Enter new type: ";
			   cin.ignore();
			   getline(cin, type);
			   Book updatedBook(title, author, isbn, pub_Year, type);
			   Book::updateBook(updatedBook);
			    if (type == "Fiction") 
	            {
                    string genre;
                    cout<<"Enter genre: ";
                    getline(cin, genre);
                    Fiction updatedBook(title, author, isbn, pub_Year, genre);
                    Fiction::updateBook(updatedBook);
                } 
	           else if (type == "NonFiction") 
            	{
                    string subject;
                    cout<<"Enter subject: ";
                    getline(cin, subject);
                    NonFiction updatedBook(title, author, isbn, pub_Year, subject);
                    NonFiction::updateBook(updatedBook);
                } 
	          else if (type == "Reference") 
	           {
                    int edition;
                    cout<<"Enter edition: ";
                    cin>>edition;
                    Reference updatedBook(title, author, isbn, pub_Year, edition);
                    Reference::updateBook(updatedBook);
                } 
			   cout<<"Book updated successfully."<<endl;
			}
			break; 
            case 13:
            {
            	string name, membership_type, grade, department;
                int id;
                cout<<"Enter the member ID to update: ";
                cin>>id;
				cout<<"Enter new name: ";
				cin.ignore();
				getline(cin, name);
				cout<<"Enter new membership type: ";
				getline(cin, membership_type);
				cout<<"Enter member type (1 for Student, 2 for Faculty): ";
				int memberType;
				cin>>memberType;
                if (memberType == 1) 
			   {
                    cout<<"Enter new grade: ";
                    cin.ignore();
                    getline(cin, grade);
                    Student updatedMember(name, id, membership_type, grade);
                    Member::updateMember(id,updatedMember);
                } 
			   else if (memberType == 2) 
			   {
                    cout<<"Enter new department: ";
                    cin.ignore();
                    getline(cin, department);
                    Faculty updatedMember(name, id, membership_type, department);
                    Member::updateMember(id,updatedMember);
                }
			}
			break; 
            case 14:
                exit = true;
                break;
            default:
                cout<<"Invalid option. Please try again."<<endl;
                break;
        }
    }
    return 0;
}

