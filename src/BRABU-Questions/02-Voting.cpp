#include <iostream>
#include <stdlib.h>
using namespace std;
class Election
{
    int voteCount[5];
    int spoiltBallot;
    int voterCounter;
    void counter(int vote)
    {
        vote--;
        if (vote >= 0 && vote <= 4)
            voteCount[vote]++;
    }

    int whoIsWinner()
    {
        int max = voteCount[0];
        int lastMax = -1;
        short winner = 0;
        for (int i = 0; i < 5; i++)
            if (max <= voteCount[i])
            {
                lastMax = max; // saving last max votes
                winner = i;
                max = voteCount[i];
            }
        if (lastMax == max)
            return -1;
        return ++winner;
    }

public:
    void voting()
    {
        int choice;
        do
        {
            cout << "Press 1 to vote for candidate 1." << endl;
            cout << "Press 2 to vote for candidate 2." << endl;
            cout << "Press 3 to vote for candidate 3." << endl;
            cout << "Press 4 to vote for candidate 4." << endl;
            cout << "Press 5 to vote for candidate 5." << endl;
            cout << "Press 0 to exit." << endl;
            cout << "Write your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                counter(choice);
                break;
            case 2:
                counter(choice);
                break;
            case 3:
                counter(choice);
                break;
            case 4:
                counter(choice);
                break;
            case 5:
                counter(choice);
                break;
            default:
                if (choice != 0)
                    spoiltBallot++;
            }

            if (choice >= 1 && choice <= 5)
            {
                voterCounter++;
                cout << "Voted to candidate " << choice << " successfully......" << endl;
                system("pause");
                system("cls");
            }
            else if (choice == 0)
            {
                cout << "Voting over........." << endl;
                cout << "Exit Successfully......." << endl;
            }
            else
            {
                voterCounter++;
                cout << "Spoilt........" << endl;
                system("pause");
                system("cls");
            }
        } while (choice != 0);
    }

    void displayResult()
    {
        cout << "\n==============Result==============" << endl;
        cout << "Total number of voters: " << voterCounter << endl;
        cout << "Each candidate get following votes: " << endl;
        for (int i = 0; i < 5; i++)
            cout << "Candidate " << i + 1 << ": " << voteCount[i] << endl;
        cout << "\nTotal Number of Spoilt Ballot: " << spoiltBallot << endl;
        int status = whoIsWinner();
        if (status == -1)
            cout << "No One wins!" << endl;
        else
            cout << "\nWINNER: Candidate " << whoIsWinner() << endl
                 << endl;
    }
    Election()
    {
        spoiltBallot = 0;
        voterCounter = 0;
        for (short i = 0; i < 5; i++)
            voteCount[i] = 0;
    }
};

int main()
{
    Election elect;
    elect.voting();
    elect.displayResult();
    return 0;
}