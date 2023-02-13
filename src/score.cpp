#include "score.h"
using namespace std;

Score::Score() {
    m_score = 0;
}

Score::~Score() {
}

void Score::setScore(int score) {
    m_score = score;
}

int Score::getScore() const {
    return m_score;
}

bool Score::load(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> m_score;
        file.close();
        return true;
    }
    return false;
}

bool Score::save(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << m_score;
        file.close();
        return true;
    }
    return false;
}

