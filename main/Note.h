#pragma once
#include <iostream>

using namespace std;

enum class PasswordState { None, Locked, Unlocked };

class Note
{
private:
	string title;
	string contents;
	string password;
	string path;
	bool isPasswordProtected;
	PasswordState passwordState;

	static const string tempFileName;
	static const string openingBrackets;
	static const string closingBrackets;
	static const char encryptionChar;

	void SetPath(string);
	void WritetoFile();
	static void ReadNoteField(string, string&, fstream&);

public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	Note();
	/// <summary>
	/// Parameterized Note Constructor
	/// </summary>
	/// <param name="title"></param>
	/// <param name="contents"></param>
	Note(string, string);
	/// <summary>
	/// Parameterized Note Constructor
	/// </summary>
	/// <param name="title"></param>
	/// <param name="contents"></param>
	/// <param name="isEncrypted"></param>
	/// <param name="password"></param>
	Note(string, string, string);
	/// <summary>
	/// Destructor
	/// </summary>
	~Note();

	/// <summary>
	/// Get the Note's title
	/// </summary>
	/// <returns>Title of Note</returns>
	string GetTitle();
	/// <summary>
	/// Get the Note's contents, returns the PasswordState.
	/// Given string is not altered if PasswordState is Locked
	/// </summary>
	/// <param name="">becomes contents of Note if unlocked</param>
	/// <returns>State of the Password</returns>
	PasswordState GetContents(string&);
	/// <summary>
	/// Get the Note's password state, if locked contents are not accessible
	/// </summary>
	/// <returns>PasswordState of Note</returns>
	PasswordState GetPasswordState();

	/// <summary>
	/// Set the password
	/// </summary>
	/// <param name="password"></param>
	void SetPassword(string);
	
	/// <summary>
	/// Opens the given file and returns the Note read from file
	/// </summary>
	/// <param name="filePath"></param>
	/// <returns>read Note</returns>
	static Note Open(string);

	/// <summary>
	/// Writes the Note to a file
	/// </summary>
	/// <param name="directoryPath"></param>
	void WritetoFile(string);
	/// <summary>
	/// Open the contents of a Note in a text editor
	/// </summary>
	void Edit();
	/// <summary>
	/// Deletes the physical Note file
	/// </summary>
	void Delete();
	/// <summary>
	/// Check a given password to the actual password
	/// </summary>
	/// <param password="">given password entry</param>
	/// <returns>State of the Password after comparing to given password</returns>
	PasswordState CheckPassword(string);

	/// <summary>
	/// Checks if the Note has contents and title
	/// </summary>
	/// <returns>true if title or contents are empty</returns>
	bool IsEmptyNote();
};

