// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the spacecraft class
class Space
{
public:
    // Constructor to initialize the spacecraft's position and direction
    Space(int m, int n, int q, char dir) : m(m), n(n), q(q), dir(dir) {}

    // Function to move the spacecraft forward or backward
    void move(char command)
    {
        switch (command)
        {
        case 'f':
            Forward();
            break;
        case 'b':
            Backward();
            break;
        default:
            break;
        }
    }

    // Function to turn the spacecraft left or right
    void turn(char command)
    {
        switch (command)
        {
        case 'l':
            Left();
            break;
        case 'r':
            Right();
            break;
        default:
            break;
        }
    }

    // Function to turn the spacecraft up or down
    void changeAngle(char command)
    {
        switch (command)
        {
        case 'u':
            Up();
            break;
        case 'd':
            Down();
            break;
        default:
            break;
        }
    }

    // Function to display the spacecraft's final position and direction
    void display()
    {
        cout << m << " " << n << " " << q << " " << dir << endl;
    }

    int m, n, q;
    char dir;

    void Forward()
    {
        switch (dir)
        {
        case 'N':
            n++;
            break;
        case 'S':
            n--;
            break;
        case 'E':
            m++;
            break;
        case 'W':
            m--;
            break;
        case 'U':
            q++;
            break;
        case 'D':
            q--;
            break;
        default:
            break;
        }
    }

    void Backward()
    {
        switch (dir)
        {
        case 'N':
            n--;
            break;
        case 'S':
            n++;
            break;
        case 'E':
            m--;
            break;
        case 'W':
            m++;
            break;
        case 'U':
            q--;
            break;
        case 'D':
            q++;
            break;
        default:
            break;
        }
    }

    void Left()
    {
        switch (dir)
        {
        case 'N':
            dir = 'W';
            break;
        case 'S':
            dir = 'E';
            break;
        case 'E':
            dir = 'N';
            break;
        case 'W':
            dir = 'S';
            break;
        case 'U':
            dir = 'N';
            break;
        case 'D':
            dir = 'S';
            break;
        default:
            break;
        }
    }

    void Right()
    {
        switch (dir)
        {
        case 'N':
            dir = 'E';
            break;
        case 'S':
            dir = 'W';
            break;
        case 'E':
            dir = 'S';
            break;
        case 'W':
            dir = 'N';
            break;
        default:
            break;
        }
    }

    void Up()
    {
        switch (dir)
        {
        case 'N':
        case 'S':
        case 'E':
        case 'W':
            dir = 'U';
            break;
        default:
            break;
        }
    }

    void Down()
    {
        switch (dir)
        {
        case 'N':
        case 'S':
        case 'E':
        case 'W':
            dir = 'D';
            break;
        default:
            break;
        }
    }
};

int main()
{
    int m, n, q;
    char dir;
    vector<string> commands;

    // Input the initial position and direction
    cout << "Enter Position ";
    cin >> m >> n >> q;
    cout << "Enter Direction ";
    cin >> dir;

    // Input the commands as a character array
    string commandStr;
    cout << "Enter Command ";
    cin >> commandStr;

    // Convert the string of commands to a vector of characters
    for (char command : commandStr)
    {
        commands.push_back(string(1, command));
    }

    // Create the spacecraft object
    Space space(m, n, q, dir);

    // Execute the commands
    for (const string &command : commands)
    {
        if (command == "f" || command == "b")
        {
            space.move(command[0]);
        }
        else if (command == "l" || command == "r")
        {

            space.turn(command[0]);
        }
        else if (command == "u" || command == "d")
        {
            space.changeAngle(command[0]);
        }
    }

    // Display the final position and direction
    cout<<"Output is ";
    space.display();

    return 0;
}