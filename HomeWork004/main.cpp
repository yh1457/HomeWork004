#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(const string& title) const {
        bool found = false;
        for (const auto& book : books) { // ���� ��� for�� ���
            if (book.title == title) {
                cout << "å�� ã�ҽ��ϴ�: " << book.title << " by " << book.author << endl;
                found = true;
                break; // å�� ã���� ���� ����
            }
        }
        if (!found) {
            cout << "å�� ã�� �� �����ϴ�: " << title << endl;
        }
	}

    void searchByAuthor(const string& author) const {
        bool found = false;
        for (const auto& book : books) { // ���� ��� for�� ���
            if (book.author == author) {
                cout << "å�� ã�ҽ��ϴ�: " << book.title << " by " << book.author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "���ڿ� �ش��ϴ� å�� ã�� �� �����ϴ�: " << author << endl;
        }
	}
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
		cout << "3. å �˻�" << endl; // å ���� �Ǵ� ���ڸ����� å �˻�
        cout << "4. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;
        cout << endl;
        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            while (true)
            {
				cout << "å �˻� �ɼ��� �����ϼ���:" << endl;
				cout << "1. �������� �˻�" << endl;
				cout << "2. ���ڸ����� �˻�" << endl;
				cout << "3. �˻� ����" << endl;

                int choice;
                cout << "����: ";
				cin >> choice;
				cout << endl;
                if (choice == 1)
                {
                    cout << "å ������ �Է��ϼ���: ";
                    string title;
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, title); // ���� �Է� (���� ����)
                    manager.searchByTitle(title);
					cout << endl;
                }
                else if (choice == 2)
                {
                    cout << "�۰����� �Է��ϼ���: ";
                    string author;
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, author); // ���� �Է� (���� ����)

					manager.searchByAuthor(author);
                    cout << endl;
                }
                else if(choice == 3)
                {
                    cout << "�˻��� �����մϴ�." << endl;
                    break;
                    cout << endl;
				}
                else
                {
                    cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
					continue;
                    cout << endl;
                }
            }
        }
        else if (choice == 4) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
