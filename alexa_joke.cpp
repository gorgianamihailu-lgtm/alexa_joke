
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>

using namespace std;

struct Joke {
    string question;
    string answer;
};

// Convert text to lowercase
string toLowerCase(string text) {
    for (char &c : text) {
        c = static_cast<char>(
            tolower(static_cast<unsigned char>(c))
        );
    }
    return text;
}

int main() {

    vector<Joke> jokes = {
        {"Why did the chicken cross the road?", "To get to the other side."},
        {"What happens if you boil a clown?", "You get a laughing stock."},
        {"Why did the car get a flat tire?", "Because there was a fork in the road!"},
        {"How did the hipster burn his mouth?", "He ate his pizza before it was cool."},
        {"What did the janitor say when he jumped out of the closet?", "SUPPLIES!!!!"},
        {"Have you heard about the band 1023MB?", "It's probably because they haven't got a gig yet..."},
        {"Why does the golfer wear two pants?", "Because he's afraid he might get a Hole-in-one."},
        {"Why should you wear glasses to maths class?", "Because it helps with division."},
        {"Why does it take pirates so long to learn the alphabet?", "Because they could spend years at C."},
        {"Why did the woman go on the date with the mushroom?", "Because he was a fun-ghi."},
        {"Why do bananas never get lonely?", "Because they hang out in bunches."},
        {"What did the buffalo say when his kid went to college?", "Bison."},
        {"Why shouldn't you tell secrets in a cornfield?", "Too many ears."},
        {"What do you call someone who doesn't like carbs?", "Lack-Toast Intolerant."},
        {"Why did the can crusher quit his job?", "Because it was soda pressing."},
        {"Why did the birthday boy wrap himself in paper?", "He wanted to live in the present."},
        {"What does a house wear?", "A dress."},
        {"Why couldn't the toilet paper cross the road?", "Because it got stuck in a crack."},
        {"Why didn't the bike want to go anywhere?", "Because it was two-tired!"},
        {"Want to hear a pizza joke?", "Nahhh, it's too cheesy!"},
        {"Why are chemists great at solving problems?", "Because they have all of the solutions!"},
        {"Why is it impossible to starve in the desert?", "Because of all the sand which is there!"},
        {"What did the cheese say when it looked in the mirror?", "Halloumi!"},
        {"Why did the developer go broke?", "Because he used up all his cache."},
        {"Did you know that ants are the only animals that don't get sick?", "It's true! It's because they have little antibodies."},
        {"Why did the donut go to the dentist?", "To get a filling."},
        {"What do you call a bear with no teeth?", "A gummy bear!"},
        {"What does a vegan zombie like to eat?", "Graaains."},
        {"What do you call a dinosaur with only one eye?", "A Do-you-think-he-saw-us!"},
        {"Why should you never fall in love with a tennis player?", "Because to them... love means NOTHING!"},
        {"What did the full glass say to the empty glass?", "You look drunk."},
        {"What's a potato's favorite form of transportation?", "The gravy train."},
        {"What did one ocean say to the other?", "Nothing, they just waved."},
        {"What did the right eye say to the left eye?", "Honestly, between you and me something smells."},
        {"What do you call a dog that's been run over by a steamroller?", "Spot!"},
        {"What's the difference between a hippo and a Zippo?", "One's pretty heavy and the other's a little lighter."},
        {"Why don't scientists trust atoms?", "They make up everything."}
    };

    cout << "Alexa is ready!\n";
    cout << "Type: Alexa, tell me a joke\n";
    cout << "Type: exit to quit\n\n";

    // Random number generator
    random_device randomDevice;
    mt19937 generator(randomDevice());

    uniform_int_distribution<int> randomIndex(
        0, static_cast<int>(jokes.size()) - 1
    );

    int previousIndex = -1;

    while (true) {

        cout << "You: ";

        string input;
        if (!getline(cin, input)) {
            cout << "\nAlexa: Goodbye!\n";
            break;
        }

        string command = toLowerCase(input);

        // Ignore empty input
        if (command.empty()) {
            continue;
        }

        // Exit commands
        if (command == "exit" || command == "quit") {
            cout << "Alexa: Goodbye!\n";
            break;
        }

        // Joke commands
        if (command.find("joke") != string::npos) {

            int index;

            // Avoid repeating the previous joke
            do {
                index = randomIndex(generator);
            } while (jokes.size() > 1 && index == previousIndex);

            previousIndex = index;

            cout << "\nAlexa: " << jokes[index].question << "\n";
            cout << "Alexa: " << jokes[index].answer << "\n\n";

        } else {

            cout << "Alexa: Sorry, I can only tell jokes right now.\n";
            cout << "Try saying: Alexa, tell me a joke\n\n";

        }
    }

    return 0;
}
