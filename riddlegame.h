#ifndef RIDDLEGAME_H
#define RIDDLEGAME_H

#include <QWidget>
#include <QString>
#include <QVector>

class RiddleGame : public QWidget
{
    Q_OBJECT

public:
    explicit RiddleGame(QWidget *parent = nullptr);
    ~RiddleGame();

private slots:
    void checkAnswer();

private:
    QVector<QString> riddles;
    QVector<QString> answers;
    int currentRiddleIndex;
    int score;
    void setupGame();
    void loadNextRiddle();

    /* UI Elements */
    QLabel *riddleLabel;
    QLineEdit *answerInput;
    QPushButton *submitButton;
    QLabel *scoreLabel;
};

#endif /* RIDDLEGAME_H */