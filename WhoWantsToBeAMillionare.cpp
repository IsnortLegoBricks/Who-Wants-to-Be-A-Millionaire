#include <iostream>

bool didLifeline1 = false;
bool didLifeline2 = false;
bool didLifeline3 = false;

void useLifeline(char answerKey[], int i, std::string name) {

    if (didLifeline1 && didLifeline2 && didLifeline3) {
        std::cout << "Unfortunately, it looks like you've used all 3 of your lifelines.\n";
        return;
    }

    std::cout << "Wanna use a lifeline? You can only use each one once!\n";
    std::cout << "Type [1] to ask the audience\n";
    std::cout << "Type [2] for 50/50\n";
    std::cout << "Type [3] to phone a friend\n";

    char LifeChoice;
    do {
        std::cin >> LifeChoice;
    } while (LifeChoice < '1' || LifeChoice > '3');
    
    // Apparently the switch gets very angry if i declare the string inside of it, so I just put it out here...
    // Quite unfortunate since I put all the other variables directly inside and there's this random one chilling outsied

    // Lifeline 1 variables
    srand(time(NULL));
    int num1 = rand() % 5 + 1;
    int num2 = rand() % 5 + 1;
    int num3 = rand() % 5 + 1;
    int num4 = rand() % 5 + 1;

    // Lifeline 2 variables
    int randName = rand() % 5 + 1;
    std::string friendName;

    // Lifeline 3 variables
    int answerPosition = rand() % 2;
    char randLetter;

    switch (LifeChoice)
    {
    case '1':
        if (didLifeline1) {
            std::cout << "Looks like you've already used this lifeline.\n";
            break;
        }


        std::cout << "A: ";
        for (int i = 0; i < num1; i++) {
            std::cout << "*";
        }
        std::cout << '\n';

        std::cout << "B: ";
        for (int i = 0; i < num2; i++) {
            std::cout << "*";
        }
        std::cout << '\n';

        std::cout << "C: ";
        for (int i = 0; i < num3; i++) {
            std::cout << "*";
        }
        std::cout << '\n';

        std::cout << "D: ";
        for (int i = 0; i < num4; i++) {
            std::cout << "*";
        }
        std::cout << '\n';

        didLifeline1 = true;
        std::cout << "What do you think the answer is now?\n";
        break;

    case '2':
        if (didLifeline2) {
            std::cout << "Looks like you've already used this lifeline.\n";
            break;
        }

        do {
            randLetter = 'A' + rand() % 4;
        } while (randLetter == answerKey[i]);

        if (answerPosition == 0) {
            std::cout << "One of the possible answers is " << randLetter << " or " << answerKey[i] << '\n';
        } else {
            std::cout << "One of the possible answers is " << answerKey[i] << " or " << randLetter << '\n';
        }

        didLifeline2 = true;
        std::cout << "What do you think the answer is now?\n";
        break;

    case '3':
        if (didLifeline3) {
            std::cout << "Looks like you've already used this lifeline.\n";
            break;
        }

        if (randName == 1) {
            friendName = "Bob";
        }
        else if (randName == 2) {
            friendName = "Jeffrey";
        }
        else if (randName == 3) {
            friendName = "Adonis";
        }
        else if (randName == 4) {
            friendName = "Vsauce";
        }

        std::cout << name << ": Hello, friend! I need help with this question.\n";
        std::cout << friendName << ": Sure, what is the question?\n";
        std::cout << name << ": *Says the question*" << '\n';
        std::cout << friendName << ": I think I got it, it's " << answerKey[i] << "!\n";

        didLifeline3 = true;
        std::cout << "What do you think the answer is now?\n";
        break;

    default:
        break;
    }

}
int main() {
    std::string questions[] = { "1. What is the main language spoken in Brazil?\n",
                                "2. Who invented the telephone?\n",
                                "3. In what year did the Titanic sink?\n",
                                "4. How many bones are in the human body?\n",
                                "5. What element has the chemical symbol Hg?\n",
                                "6. What is the name for a group of turkeys?\n",
                                "7. What is the name of the worlds largest flower?\n",
                                "8. Which country is the largest producer of coffee in the world?\n",
                                "9. What is the chemical formula for sulfric acid?\n",
                                "10. What is the longest bone in the human body?\n",
                                "11. What is the name of the enzyme that breaks down carbohydrates in the human digestive system?\n",
                                "12. Who is the first person to orbit Earth in a spacecraft?\n",
                                "13. What is the term used to describe the phenomenon where light bends as it passes through different mediums?\n",
                                "14. What is the capital city of Kazakhstan?\n"
                                "15. In what year was the United Nations founded?\n",
    };
    std::string options[][4] = { {"A.Brazilian\t", "B.Spanish", "C.Portuguese", "D.Quecha"},
                                {"A. Bill Clinton", "B. Philip Reihs", "C. Alexander Graham Bell", "D. Amos Dolleber"},
                                {"A.1923", "B. 1910", "C. 1912", "D.1922"},
                                {"A. 205", "B. 204", "C. 208", "D. 206"},
                                {"A. Iron", "B. Magnesium", "C. Potassium\t", "D. Mercury"},
                                {"A. Rafter\t", "B. Flock", "C. Goggle\t", "D. Herd"},
                                {"A. Sunflower\t", "B. Rafflesia arnoldii", "C. Dahlia\t", "D. Tree Peony"},
                                {"A. Colombia\t", "B. Vietnam", "C. Brazil\t", "D. Argentina"},
                                {"A. H₂SO₄\t", "B. HNO₃", "C. HNO2\t", "D. HCl"},
                                {"A. Tibia\t", "B. Humerus", "C. Femur\t", "D. Fibula"},
                                {"A. Ligase\t", "B. Protease", "C. Lipase\t", "D. Amylase"},
                                {"A. John Glenn\t", "B. Yuri Gagargin", "C. Neil Armstrong\t", "D. Vladmir Komarov"},
                                {"A. Refraction\t", "B. Reflection", "C. Aurora\t", "D. Mirage"},
                                {"A. Almaty\t", "B. Kokshet", "C. Astana\t", "D. Bishkek"},
                                {"A. 1947\t", "B. 1946", "C. 1944\t", "D. 1945"},
    };


    char answerKey[] = { 'C', 'C', 'B', 'D', 'D', 'A', 'B', 'C', 'A', 'C', 'D', 'B', 'A', 'C', 'D' };
    char userGuess;
    int money = 100;
    std::string name;
    char join;
    int size = sizeof(questions) / sizeof(questions[0]);

    std::cout << "****************************************" << '\n';
    std::cout << "Welcome to Who Wants to Be A Millionare!" << '\n';
    std::cout << "****************************************" << '\n';
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << " you will be asked 15 questions and will be given 3 lifelines.\nIf you ever wish to use a lifeline, enter the letter E.\n" << "Press Y to proceed\n";
    std::cin >> join;
    while (toupper(join) == 'Y')
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "*******************************\n";
            std::cout << questions[i] << '\n';
            std::cout << "*******************************\n";

            for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
                std::cout << options[i][j] << '\n';
            }

            do {
                std::cin >> userGuess;
                userGuess = toupper(userGuess);
            } while (userGuess < 'A' || userGuess > 'E');

            if (userGuess == 'E') {
                useLifeline(answerKey, i, name);
                do {
                    std::cin >> userGuess;
                    userGuess = toupper(userGuess);
                } while (userGuess < 'A' || userGuess > 'D');
            }

            if (userGuess == answerKey[i]) {
                money = money * 2;
                std::cout << "Correct! You won " << money << '\n';
            }
            else {
                std::cout << "You got a question WRONG! Would you want to play another game? Press Y to play again.\n";
                std::cin >> join;
                break;
            }
        }
    }

    std::cout << "Bye " << name << " you win " << money;
}