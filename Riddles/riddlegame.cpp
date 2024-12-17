#include "riddlegame.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

/** Constructor */
RiddleGame::RiddleGame(QWidget *parent)
    : QWidget(parent), currentRiddleIndex(0), score(0)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    /* Initialize UI elements */
    riddleLabel = new QLabel(this);
    answerInput = new QLineEdit(this);
    submitButton = new QPushButton("Submit", this);
    scoreLabel = new QLabel("Score: 0", this);

    /* Add widgets to layout */
    layout->addWidget(riddleLabel);
    layout->addWidget(answerInput);
    layout->addWidget(submitButton);
    layout->addWidget(scoreLabel);

    /* Set layout */
    setLayout(layout);

    /* Setup game logic */
    setupGame();
    loadNextRiddle();

    /* Connect signals and slots */
    connect(submitButton, &QPushButton::clicked, this, &RiddleGame::checkAnswer);
}

/** Destructor */
RiddleGame::~RiddleGame()
{
}

/** Setup riddles and answers */
void RiddleGame::setupGame()
{
    riddles = {"What has keys but can't open locks?",
               "What can travel around the world while staying in one spot?",
               "What has a head, a tail, but no body?"};
    answers = {"keyboard", "stamp", "coin"};
}

/** Load the next riddle */
void RiddleGame::loadNextRiddle()
{
    if (currentRiddleIndex < riddles.size())
    {
        riddleLabel->setText(riddles[currentRiddleIndex]);
        answerInput->clear();
    }
    else
    {
        QMessageBox::information(this, "Game Over",
                                  QString("Game Over! Your final score: %1").arg(score));
        close();
    }
}

/** Check user's answer */
void RiddleGame::checkAnswer()
{
    QString userAnswer = answerInput->text().trimmed();
    if (userAnswer.toLower() == answers[currentRiddleIndex].toLower())
    {
        score++;
        QMessageBox::information(this, "Correct!", "That's the right answer!");
    }
    else
    {
        QMessageBox::warning(this, "Incorrect", "Try again next time!");
    }

    scoreLabel->setText(QString("Score: %1").arg(score));
    currentRiddleIndex++;
    loadNextRiddle();
}
