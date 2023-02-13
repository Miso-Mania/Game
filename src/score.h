# ifndef SCORE_H
# define SCORE_H

#include <string>
#include <fstream>
using namespace std;

class Score {
    Score();
    ~Score();
    void setScore(int score);
    int getScore() const;
    bool load(const string& filename);
    bool save(const string& filename) const;
private:
    int m_score;
};

# endif // SCORE_H