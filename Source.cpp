#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Function Prototypes
string encrypt(string, string);
string decrypt(string, string);

int main()
{
    // Variables
    int choice;
    string message;
    string keyword;
    string encryptedMessage;
    string decryptedMessage;

    // Menu
    do
    {
    cout << "\n\n1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Exit" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    // In case invalid input is inserted.
    if (cin.fail()) {
        // Clear input stream buffer
        cin.clear();

        // Ignore any remaining characters in the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice." << endl;
        continue;
    }

    switch (choice)
    {
    // Encrypt
    case 1:
        cout << "Enter a message to encrypt: ";
        cin.ignore();
        getline(cin, message);

        cout << "Enter a keyword: ";
        cin >> keyword;

        encryptedMessage = encrypt(message, keyword);
        cout << "Encrypted Message: " << encryptedMessage << endl;
        break;

    // Decrypt
    case 2:
        cout << "Enter a message to decrypt: ";
        cin.ignore();
        getline(cin, message);

        cout << "Enter a keyword: ";
        cin >> keyword;

        decryptedMessage = decrypt(message, keyword);
        cout << "Decrypted Message: " << decryptedMessage << endl;
        break;

    // Exit
    case 3:
        cout << "Goodbye!\n" << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
} while (choice != 3);



    return 0;
}

string encrypt(string message, string keyword)
{
    // length of encrypted message is where the encryption stops.
    // keyword = horizontal vector
    // message = vertical vector
    // go horizontal first, then vertically
    // Keyword: AYUSH
    // Message: GEEKSFORGEEKS
    // A = 0, Y = 24 ...
    // G = 6, E = 4 ...


    // Convert keyword to uppercase
    for (int i = 0; i < keyword.length(); i++)
    {
        keyword[i] = toupper(keyword[i]);
    }

    // Convert message to uppercase
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
    }

    // Initialize variables
    char userKeyArray[100];
    // Arrays to store integer values of keyword, message, and encrypted message.
    int keywordArray[keyword.length()];
    int messageArray[message.length()];
    int encryptedMessageArray[message.length()];

    // Convert keyword to integer
    // Must convert to integer in order to encrypt.
    // Subtract 65 in order to start at 0.

    // Storing integer values of keyword in keywordInt.
    for (int i = 0; i < keyword.length(); i++)
    {
        keywordArray[i] = keyword[i] - 65;
    }

    // Convert message to integer
    for (int i = 0; i < message.length(); i++)
    {
        messageArray[i] = message[i] - 65;
    }

    // Create userKeyArray
    // userKeyArray is the keyword repeated until it is the same length as the message.
    int j = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (j == keyword.length())
        {
            j = 0;
        }
        userKeyArray[i] = keyword[j];
        j++;
    }

    // Convert userKeyArray to integer
    for (int i = 0; i < message.length(); i++)
    {
        userKeyArray[i] = userKeyArray[i] - 65;
    }


    // Encrypt message
    for (int i = 0; i < message.length(); i++)
    {
        encryptedMessageArray[i] = (messageArray[i] + userKeyArray[i]) % 26;
    }

    // Convert encryptedMessageInt to encryptedMessage
    string encryptedMessage;
    for (int i = 0; i < message.length(); i++)
    {
        encryptedMessage += (char)(encryptedMessageArray[i] + 65);
    }

    // Return encryptedMessage
    return encryptedMessage;

}

string decrypt(string message, string keyword)
{
    // Convert keyword to uppercase
    for (int i = 0; i < keyword.length(); i++)
    {
        keyword[i] = toupper(keyword[i]);
    }

    // Convert message to uppercase
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
    }

    // Initialize variables
    char userKeyArray[100];
    // Arrays to store integer values of keyword, message, and encrypted message.
    int keywordArray[keyword.length()];
    int messageArray[message.length()];
    int decryptedMessageArray[message.length()];
    
    // Convert keyword to integer
    // Must convert to integer in order to encrypt.
    // Subtract 65 in order to start at 0.

    // Storing integer values of keyword in keywordInt.
    for (int i = 0; i < keyword.length(); i++)
    {
        keywordArray[i] = keyword[i] - 65;
    }

    // Convert message to integer
    for (int i = 0; i < message.length(); i++)
    {
        messageArray[i] = message[i] - 65;
    }

    // Create userKeyArray
    // userKeyArray is the keyword repeated until it is the same length as the message.
    int j = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (j == keyword.length())
        {
            j = 0;
        }
        userKeyArray[i] = keyword[j];
        j++;
    }

    // Convert userKeyArray to integer
    for (int i = 0; i < message.length(); i++)
    {
        userKeyArray[i] = userKeyArray[i] - 65;
    }

    // Decrypt message
    for (int i = 0; i < message.length(); i++)
    {
        decryptedMessageArray[i] = (messageArray[i] - userKeyArray[i] + 26) % 26;
    }

    // Convert decryptedMessageInt to decryptedMessage
    string decryptedMessage;
    for (int i = 0; i < message.length(); i++)
    {
        decryptedMessage += (char)(decryptedMessageArray[i] + 65);
    }

    // Return decryptedMessage
    return decryptedMessage;
}
