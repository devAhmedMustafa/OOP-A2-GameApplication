#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

class LabelGenerator {
protected:
    int label;
    string prefix;
public:
    LabelGenerator(string prefix, int initial) : label(initial), prefix(prefix) {}

    string nextLabel() {
        return prefix + to_string(label++);
    }
};

class FileLabelGenerator : public LabelGenerator {
private:

    string file;
    queue<string> captions;

public:
    FileLabelGenerator(string prefix, int initial, string file) : LabelGenerator(prefix, initial), file(file) {
        fstream f(file);
        if (!f.is_open()) {
            cout << "Error opening file!" << endl;
            f.close();
            return;
        }
        string line;
        while (getline(f, line)) {
            captions.push(line);
        }
        f.close();
    }

    string nextLabel() {
        auto caption = captions.empty() ? "........." : captions.front();

        if (!captions.empty())
            captions.pop();

        return prefix + to_string(label++) + ' ' + caption;
    }
};

int main() {

    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;

    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }

    return 0;
}
