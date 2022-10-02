#include "src/transaction.cpp"

void write_to_file(string file_path, transaction* t) {
    ofstream write(file_path, std::ios_base::app);
    write << t->amount << "," << t->description << endl;
    write.close();
}

vector<transaction*> read_from_file() {
    vector<transaction*> transactions;
    io::CSVReader<2> in("./accountpp.csv");
    in.read_header(io::ignore_extra_column, "amount", "description");
    double amount;
    string description;
    while (in.read_row(amount, description)) {
        transaction* t = new transaction(amount, description);
        transactions.push_back(t);
    }
    return transactions;
}

void run() {
    cout << "1) Islem Ekle" << endl;
    cout << "2) Islem Gecmisi" << endl;
    cout << "3) Guncel Durum" << endl;
    cout << "4) Cikis" << endl;
    cout << ">> ";
    int sel;
    cin >> sel;
    if (sel == 1) {
        double amount;
        string description;
        cout << "Islem Tutari: ";
        cin >> amount;
        cout << "Islem Aciklamasi: ";
        cin >> description;
        transaction* t = new transaction(amount, description);
        write_to_file("./accountpp.csv", t);
        cout << description << " islemi eklendi." << endl << "------" << endl;
        run();
    } else if (sel == 2) {
        vector<transaction*> transactions = read_from_file();
        if (transactions.size() == 0) {
            cout << "Herhangi bir islem yok." << endl;
            run();
        } else {
            for (int i = 0;i < transactions.size();i++) {
                cout << "Islem Tutari: " << transactions.at(i)->amount << ", Islem Aciklamasi: " << transactions.at(i)->description << endl;
            }
            cout << "------" << endl;
        }
        run();
    } else if (sel == 3) {
        double status = 0.0;
        vector<transaction*> transactions = read_from_file();
        for (int i = 0;i < transactions.size();i++) {
            status += transactions.at(i)->amount;
        }
        cout << "Mevcut Durum: " << status << endl << "------" << endl;
        run();
    } else if (sel == 4) {
        exit(0);
    }
}

int main() {
    try {
        run();
    }
    catch (string exception) {
        cerr << exception << endl;
        return -1;
    }
    return 0;
}